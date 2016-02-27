/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

#include "RF24_nRF24L01.h"
#include "RF24.h"
#include "spi.h"
#include <string.h>
#include "system.h"

// RF24 variables
static uint8_t payload_size = 32;
static uint8_t p_variant = 0;
static uint8_t dynamic_payloads_enabled = 0; /**< Whether dynamic payloads are enabled. */
static uint8_t pipe0_reading_address[5]; /**< Last address set on pipe 0 for reading. */
static uint8_t addr_width = 5; /**< The address width to use - 3,4 or 5 bytes. */
static uint32_t txRxDelay; /**< Var for adjusting delays depending on datarate */

// RF24 internal Functions
uint8_t RF24_read_registers(uint8_t reg, uint8_t* buf, uint8_t len);
uint8_t RF24_read_register(uint8_t reg);
uint8_t RF24_write_registers(uint8_t reg, const uint8_t* buf, uint8_t len);
uint8_t RF24_write_register(uint8_t reg, uint8_t value);
uint8_t RF24_write_payload(const void* buf, uint8_t data_len, const uint8_t writeType);
uint8_t RF24_read_payload(void* buf, uint8_t data_len);
void RF24_startFastWrite( const void* buf, uint8_t len, const uint8_t multicast, uint8_t startTx);
uint8_t RF24_flush_rx(void);
uint8_t RF24_flush_tx(void);
uint8_t RF24_WriteCommand(uint8_t command);
uint8_t RF24_get_status(void);
void RF24_toggle_features(void);

#define SEND_DATA(data) writeSPI1(data)

uint8_t RF24_read_registers(uint8_t reg, uint8_t* buf, uint8_t len)
{
  uint8_t status;

  SLAVE_ENABLE();
  status = SEND_DATA( R_REGISTER | ( REGISTER_MASK & reg ) );
  while ( len-- ){
    *buf++ = SEND_DATA(0xff);
  }
  SLAVE_DISABLE();

  return status;
}

uint8_t RF24_read_register(uint8_t reg)
{
  SLAVE_ENABLE();
  SEND_DATA(R_REGISTER | reg);
  uint8_t val = SEND_DATA(0x00);
  SLAVE_DISABLE();
  return val;
}

uint8_t RF24_write_registers(uint8_t reg, const uint8_t* buf, uint8_t len)
{
  uint8_t status;

  SLAVE_ENABLE();
  status = SEND_DATA( W_REGISTER | ( REGISTER_MASK & reg ) );
  while ( len-- )
    SEND_DATA(*buf++);
  SLAVE_DISABLE();

  return status;
}

uint8_t RF24_write_register(uint8_t reg, uint8_t value)
{
  uint8_t status;

  SLAVE_ENABLE();
  status = SEND_DATA( W_REGISTER | ( REGISTER_MASK & reg ) );
  SEND_DATA(value);
  SLAVE_DISABLE();

  return status;
}

uint8_t RF24_write_payload(const void* buf, uint8_t data_len, const uint8_t writeType)
{
  uint8_t status;
  const uint8_t* current = (const uint8_t*)(buf);

   data_len = rf24_min(data_len, payload_size);
   uint8_t blank_len = dynamic_payloads_enabled ? 0 : payload_size - data_len;

  SLAVE_ENABLE();
  status = SEND_DATA( writeType );
  while ( data_len-- ) {
    SEND_DATA(*current++);
  }
  while ( blank_len-- ) {
    SEND_DATA(0);
  }  
  SLAVE_DISABLE();

  return status;
}

uint8_t RF24_read_payload(void* buf, uint8_t data_len)
{
  uint8_t status;
  uint8_t* current = (uint8_t*)(buf);

  if(data_len > payload_size) data_len = payload_size;
  uint8_t blank_len = dynamic_payloads_enabled ? 0 : payload_size - data_len;
  
  SLAVE_ENABLE();
  status = SEND_DATA( R_RX_PAYLOAD );
  while ( data_len-- ) {
    *current++ = SEND_DATA(0xFF);
  }
  while ( blank_len-- ) {
    SEND_DATA(0xff);
  }
  SLAVE_DISABLE();

  return status;
}

uint8_t RF24_flush_rx(void)
{
  return RF24_WriteCommand( FLUSH_RX );
}

uint8_t RF24_flush_tx(void)
{
  return RF24_WriteCommand( FLUSH_TX );
}

uint8_t RF24_WriteCommand(uint8_t command)
{
  uint8_t status;
  SLAVE_ENABLE();
  status = SEND_DATA(command);
  SLAVE_DISABLE();
  return status;
}

uint8_t RF24_get_status(void)
{
  return RF24_WriteCommand(CMD_NOP);
}

void RF24_setChannel(uint8_t channel)
{
  const uint8_t max_channel = 127;
  RF24_write_register(RF_CH,rf24_min(channel,max_channel));
}

uint8_t RF24_getChannel()
{
  return RF24_read_register(RF_CH);
}

void RF24_setPayloadSize(uint8_t size)
{
  payload_size = rf24_min(size,32);
}

uint8_t RF24_getPayloadSize(void)
{
  return payload_size;
}

// startup
uint8_t RF24_begin(void)
{
  uint8_t setup=0;
  
  pipe0_reading_address[0] = 0;
  
  // Initialize pins
  // CE
  CE_CFG = 1;  // Digital
  CE_TRIS = 0; // Output
  CE_OFF();
  SLAVE_DISABLE();

  // Must allow the radio time to settle else configuration bits will not necessarily stick.
  // This is actually only required following power up but some settling time also appears to
  // be required after resets too. For full coverage, we'll always assume the worst.
  // Enabling 16b CRC is by far the most obvious case if the wrong timing is used - or skipped.
  // Technically we require 4.5ms + 14us as a worst case. We'll just call it 5ms for good measure.
  // WARNING: Delay is based on P-variant whereby non-P *may* require different timing.
  DELAY_MS(5);

  // Reset CONFIG and enable 16-bit CRC.
  RF24_write_register( CONFIG, 0b00001100 ) ;

  // Set 1500uS (minimum for 32B payload in ESB@250KBPS) timeouts, to make testing a little easier
  // WARNING: If this is ever lowered, either 250KBS mode with AA is broken or maximum packet
  // sizes must never be used. See documentation for a more complete explanation.
  RF24_setRetries(15,15);

  if( RF24_setDataRate( RF24_250KBPS ) )
  {
    p_variant = 1 ;
  }

  // Then set the data rate to the slowest (and most reliable) speed supported by all
  // hardware.
  RF24_setDataRate( RF24_1MBPS ) ;

  // Initialize CRC and request 2-byte (16bit) CRC
  //setCRCLength( RF24_CRC_16 ) ;

  // Disable dynamic payloads, to match dynamic_payloads_enabled setting - Reset value is 0
  RF24_toggle_features();
  RF24_write_register(FEATURE,0 );
  RF24_write_register(DYNPD,0);

  // Reset current status
  // Notice reset and flush is the last thing we do
  RF24_write_register(NRF_STATUS,_BV(RX_DR) | _BV(TX_DS) | _BV(MAX_RT) );

  // Set up default configuration.  Callers can always change it later.
  // This channel should be universally safe and not bleed over into adjacent
  // spectrum.
  RF24_setChannel(76);

  // Flush buffers
  RF24_flush_rx();
  RF24_flush_tx();

  RF24_powerUp(); //Power up by default when begin() is called

  // Enable PTX, do not write CE high so radio will remain in standby I mode ( 130us max to transition to RX or TX instead of 1500us from powerUp )
  // PTX should use only 22uA of power
  RF24_write_register(CONFIG, ( RF24_read_register(CONFIG) ) & ~_BV(PRIM_RX) );

  // if setup is 0 or ff then there was no response from module
  return ( setup != 0 && setup != 0xff );
}

void RF24_startListening(void)
{
  RF24_powerUp();
  RF24_write_register(CONFIG, RF24_read_register(CONFIG) | _BV(PRIM_RX));
  RF24_write_register(NRF_STATUS, _BV(RX_DR) | _BV(TX_DS) | _BV(MAX_RT) );
  CE_ON();
  // Restore the pipe0 adddress, if exists
  if (pipe0_reading_address[0] > 0){
    RF24_write_registers(RX_ADDR_P0, pipe0_reading_address, addr_width);	
  }else{
	RF24_closeReadingPipe(0);
  }

  // Flush buffers
  //flush_rx();
  if(RF24_read_register(FEATURE) & _BV(EN_ACK_PAY)){
	RF24_flush_tx();
  }

  // Go!
  //delayMicroseconds(100);
}

static const uint8_t child_pipe_enable[] =
{
  ERX_P0, ERX_P1, ERX_P2, ERX_P3, ERX_P4, ERX_P5
};

void RF24_stopListening(void)
{  
  CE_OFF();

  DELAY_MS(txRxDelay);
  
  if(RF24_read_register(FEATURE) & _BV(EN_ACK_PAY)){
    DELAY_MS(txRxDelay); //200
	RF24_flush_tx();
  }
  //RF24_flush_rx();
  RF24_write_register(CONFIG, ( RF24_read_register(CONFIG) ) & ~_BV(PRIM_RX) );
 
  RF24_write_register(EN_RXADDR, RF24_read_register(EN_RXADDR) | _BV(child_pipe_enable[0])); // Enable RX on pipe0
  
  //DELAY_MS(100);
}

void RF24_powerDown(void)
{
  CE_OFF(); // Guarantee CE is low on powerDown
  RF24_write_register(CONFIG, RF24_read_register(CONFIG) & ~_BV(PWR_UP));
}

//Power up now. Radio will not power down unless instructed by MCU for config changes etc.
void RF24_powerUp(void)
{
   uint8_t cfg = RF24_read_register(CONFIG);

   // if not powered up then power up and wait for the radio to initialize
   if (!(cfg & _BV(PWR_UP))){
      RF24_write_register(CONFIG, RF24_read_register(CONFIG) | _BV(PWR_UP));

      // For nRF24L01+ to go from power down mode to TX or RX mode it must first pass through stand-by mode.
	  // There must be a delay of Tpd2stby (see Table 16.) after the nRF24L01+ leaves power down mode before
	  // the CEis set high. - Tpd2stby can be up to 5ms per the 1.0 datasheet
      DELAY_MS(5);
   }
}

//Similar to the previous write, clears the interrupt flags
uint8_t RF24_write_multicast( const void* buf, uint8_t len, const uint8_t multicast )
{
	//Start Writing
	RF24_startFastWrite(buf, len, multicast, 1);

	//Wait until complete or failed
	#if defined (FAILURE_HANDLING) || defined (RF24_LINUX)
		uint32_t timer = millis();
	#endif 
	
	while( ! ( RF24_get_status()  & ( _BV(TX_DS) | _BV(MAX_RT) ))) { 
		#if defined (FAILURE_HANDLING) || defined (RF24_LINUX)
			if(millis() - timer > 85){			
				errNotify();
				#if defined (FAILURE_HANDLING)
				  return 0;		
				#else
				  delay(100);
				#endif
			}
		#endif
	}
    
    CE_OFF();

	uint8_t status = RF24_write_register(NRF_STATUS,_BV(RX_DR) | _BV(TX_DS) | _BV(MAX_RT) );

  //Max retries exceeded
  if( status & _BV(MAX_RT)){
  	RF24_flush_tx(); //Only going to be 1 packet int the FIFO at a time using this method, so just flush
  	return 0;
  }
	//TX OK 1 or 0
  return 1;
}

uint8_t RF24_write( const void* buf, uint8_t len ){
	return RF24_write_multicast(buf,len,0);
}

//Per the documentation, we want to set PTX Mode when not listening. Then all we do is write data and set CE high
//In this mode, if we can keep the FIFO buffers loaded, packets will transmit immediately (no 130us delay)
//Otherwise we enter Standby-II mode, which is still faster than standby mode
//Also, we remove the need to keep writing the config register over and over and delaying for 150 us each time if sending a stream of data

void RF24_startFastWrite( const void* buf, uint8_t len, const uint8_t multicast, uint8_t startTx){ //TMRh20

	//write_payload( buf,len);
	RF24_write_payload( buf, len,multicast ? W_TX_PAYLOAD_NO_ACK : W_TX_PAYLOAD ) ;
	if(startTx){
		CE_ON();
	}
}

uint8_t RF24_rxFifoFull(){
	return RF24_read_register(FIFO_STATUS) & _BV(RX_FULL);
}

uint8_t RF24_txStandBy(){

    #if defined (FAILURE_HANDLING) || defined (RF24_LINUX)
		uint32_t timeout = millis();
	#endif
	while( ! (RF24_read_register(FIFO_STATUS) & _BV(TX_EMPTY)) ){
		if( RF24_get_status() & _BV(MAX_RT)){
			RF24_write_register(NRF_STATUS,_BV(MAX_RT) );
			CE_OFF();
			RF24_flush_tx();    //Non blocking, flush the data
			return 0;
		}
		#if defined (FAILURE_HANDLING) || defined (RF24_LINUX)
			if( millis() - timeout > 85){
				errNotify();
				#if defined (FAILURE_HANDLING)
				return 0;	
				#endif
			}
		#endif
	}

	CE_OFF();			   //Set STANDBY-I mode
	return 1;
}


void RF24_maskIRQ(uint8_t tx, uint8_t fail, uint8_t rx)
{
	RF24_write_register(CONFIG, ( RF24_read_register(CONFIG) ) | fail << MASK_MAX_RT | tx << MASK_TX_DS | rx << MASK_RX_DR  );
}


uint8_t RF24_getDynamicPayloadSize(void)
{
  uint8_t result = 0;

  SLAVE_ENABLE();
  SEND_DATA( R_RX_PL_WID );
  result = SEND_DATA(0xff);
  SLAVE_DISABLE();
  
  if(result > 32) { RF24_flush_rx(); DELAY_MS(2); return 0; }
  return result;
}

uint8_t RF24_available(void)
{
  return RF24_available_pipe(NULL);
}

uint8_t RF24_available_pipe(uint8_t* pipe_num)
{
  if (!( RF24_read_register(FIFO_STATUS) & _BV(RX_EMPTY) )){

    // If the caller wants the pipe number, include that
    if ( pipe_num ){
	  uint8_t status = RF24_get_status();
      *pipe_num = ( status >> RX_P_NO ) & 0b111;
  	}
  	return 1;
  }

  return 0;
}


void RF24_read( void* buf, uint8_t len ){

  // Fetch the payload
  RF24_read_payload( buf, len );

  //Clear the two possible interrupt flags with one command
  RF24_write_register(NRF_STATUS,_BV(RX_DR) | _BV(MAX_RT) | _BV(TX_DS) );

}

void RF24_whatHappened(uint8_t* tx_ok, uint8_t* tx_fail, uint8_t* rx_ready)
{
  // Read the status & reset the status in one easy call
  // Or is that such a good idea?
  uint8_t status = RF24_write_register(NRF_STATUS,_BV(RX_DR) | _BV(TX_DS) | _BV(MAX_RT) );

  // Report to the user what happened
  *tx_ok = status & _BV(TX_DS);
  *tx_fail = status & _BV(MAX_RT);
  *rx_ready = status & _BV(RX_DR);
}

/****************************************************************************/
void RF24_openWritingPipe(const uint8_t *address)
{
  // Note that AVR 8-bit uC's store this LSB first, and the NRF24L01(+)
  // expects it LSB first too, so we're good.

  RF24_write_registers(RX_ADDR_P0, address, addr_width);
  RF24_write_registers(TX_ADDR, address, addr_width);

  RF24_write_register(RX_PW_P0,payload_size);
}

/****************************************************************************/
void RF24_setAddressWidth(uint8_t a_width){

	if(a_width -= 2){
		RF24_write_register(SETUP_AW,a_width%4);
		addr_width = (a_width%4) + 2;
	}

}

/****************************************************************************/

static const uint8_t child_pipe[] =
{
  RX_ADDR_P0, RX_ADDR_P1, RX_ADDR_P2, RX_ADDR_P3, RX_ADDR_P4, RX_ADDR_P5
};
static const uint8_t child_payload_size[] =
{
  RX_PW_P0, RX_PW_P1, RX_PW_P2, RX_PW_P3, RX_PW_P4, RX_PW_P5
};

void RF24_openReadingPipe(uint8_t child, const uint8_t *address)
{
  // If this is pipe 0, cache the address.  This is needed because
  // openWritingPipe() will overwrite the pipe 0 address, so
  // startListening() will have to restore it.
  if (child == 0){
    memcpy(pipe0_reading_address,address,addr_width);
  }
  if (child <= 6)
  {
    // For pipes 2-5, only write the LSB
    if ( child < 2 ){
      RF24_write_registers(child_pipe[child], address, addr_width);
    }else{
      RF24_write_registers(child_pipe[child], address, 1);
	}
    RF24_write_register(child_payload_size[child],payload_size);

    // Note it would be more efficient to set all of the bits for all open
    // pipes at once.  However, I thought it would make the calling code
    // more simple to do it this way.
    RF24_write_register(EN_RXADDR, RF24_read_register(EN_RXADDR) | _BV(child_pipe_enable[child]));
  }
}

/****************************************************************************/

void RF24_closeReadingPipe( uint8_t pipe )
{
  RF24_write_register(EN_RXADDR, RF24_read_register(EN_RXADDR) & ~_BV(child_pipe_enable[pipe]));
}

void RF24_toggle_features(void)
{
    SLAVE_ENABLE();
	SEND_DATA( ACTIVATE );
    SEND_DATA( 0x73 );
	SLAVE_DISABLE();
}

void RF24_enableDynamicPayloads(void)
{
  // Enable dynamic payload throughout the system
  RF24_write_register(FEATURE, RF24_read_register(FEATURE) | _BV(EN_DPL) );

  // Enable dynamic payload on all pipes
  //
  // Not sure the use case of only having dynamic payload on certain
  // pipes, so the library does not support it.
  RF24_write_register(DYNPD, RF24_read_register(DYNPD) | _BV(DPL_P5) | _BV(DPL_P4) | _BV(DPL_P3) | _BV(DPL_P2) | _BV(DPL_P1) | _BV(DPL_P0));

  dynamic_payloads_enabled = 1;
}

/****************************************************************************/

void RF24_enableAckPayload(void)
{
  //
  // enable ack payload and dynamic payload features
  //
  RF24_write_register(FEATURE, RF24_read_register(FEATURE) | _BV(EN_ACK_PAY) | _BV(EN_DPL) );

  //
  // Enable dynamic payload on pipes 0 & 1
  //

  RF24_write_register(DYNPD, RF24_read_register(DYNPD) | _BV(DPL_P1) | _BV(DPL_P0));
  dynamic_payloads_enabled = 1;
}

/****************************************************************************/

void RF24_enableDynamicAck(void){
  //
  // enable dynamic ack features
  //
  RF24_write_register(FEATURE, RF24_read_register(FEATURE) | _BV(EN_DYN_ACK) );
}

/****************************************************************************/

void RF24_writeAckPayload(uint8_t pipe, const void* buf, uint8_t len)
{
  const uint8_t* current = (const uint8_t*)(buf);

  uint8_t data_len = rf24_min(len,32);

  SLAVE_ENABLE();
  SEND_DATA(W_ACK_PAYLOAD | ( pipe & 0b111 ) );

  while ( data_len-- )
    SEND_DATA(*current++);
  SLAVE_DISABLE();
}

/****************************************************************************/

uint8_t RF24_isAckPayloadAvailable(void)
{
  return ! (RF24_read_register(FIFO_STATUS) & _BV(RX_EMPTY));
}

/****************************************************************************/

uint8_t RF24_isPVariant(void)
{
  return p_variant ;
}

/****************************************************************************/

void RF24_setAutoAck_all(uint8_t enable)
{
  if ( enable )
    RF24_write_register(EN_AA, 0b111111);
  else
    RF24_write_register(EN_AA, 0);
}

/****************************************************************************/

void RF24_setAutoAck_pipe( uint8_t pipe, uint8_t enable )
{
  if ( pipe <= 6 )
  {
    uint8_t en_aa = RF24_read_register( EN_AA ) ;
    if( enable )
    {
      en_aa |= _BV(pipe) ;
    }
    else
    {
      en_aa &= ~_BV(pipe) ;
    }
    RF24_write_register( EN_AA, en_aa ) ;
  }
}

/****************************************************************************/

uint8_t RF24_testCarrier(void)
{
  return ( RF24_read_register(CD) & 1 );
}

/****************************************************************************/

uint8_t RF24_testRPD(void)
{
  return ( RF24_read_register(RPD) & 1 ) ;
}

/****************************************************************************/

void RF24_setPALevel(uint8_t level)
{
  uint8_t setup = RF24_read_register(RF_SETUP) & 0b11111000;

  if(level > 3){  						// If invalid level, go to max PA
	  level = (RF24_PA_MAX << 1) + 1;		// +1 to support the SI24R1 chip extra bit
  }else{
	  level = (level << 1) + 1;	 		// Else set level as requested
  }

  RF24_write_register( RF_SETUP, setup |= level ) ;	// Write it to the chip
}

/****************************************************************************/

uint8_t RF24_getPALevel(void)
{
  return (RF24_read_register(RF_SETUP) & (_BV(RF_PWR_LOW) | _BV(RF_PWR_HIGH))) >> 1 ;
}

/****************************************************************************/

uint8_t RF24_setDataRate(rf24_datarate_e speed)
{
  uint8_t result = 0;
  uint8_t setup = RF24_read_register(RF_SETUP) ;

  // HIGH and LOW '00' is 1Mbs - our default
  setup &= ~(_BV(RF_DR_LOW) | _BV(RF_DR_HIGH)) ;
  txRxDelay=250;
  if( speed == RF24_250KBPS )
  {
    // Must set the RF_DR_LOW to 1; RF_DR_HIGH (used to be RF_DR) is already 0
    // Making it '10'.
    setup |= _BV( RF_DR_LOW ) ;
    txRxDelay=450;
  }
  else
  {
    // Set 2Mbs, RF_DR (RF_DR_HIGH) is set 1
    // Making it '01'
    if ( speed == RF24_2MBPS )
    {
      setup |= _BV(RF_DR_HIGH);
      txRxDelay=190;
    }
  }
  RF24_write_register(RF_SETUP,setup);

  // Verify our result
  if ( RF24_read_register(RF_SETUP) == setup )
  {
    result = 1;
  }
  return result;
}

/****************************************************************************/

rf24_datarate_e RF24_getDataRate( void )
{
  rf24_datarate_e result ;
  uint8_t dr = RF24_read_register(RF_SETUP) & (_BV(RF_DR_LOW) | _BV(RF_DR_HIGH));

  // switch uses RAM (evil!)
  // Order matters in our case below
  if ( dr == _BV(RF_DR_LOW) )
  {
    // '10' = 250KBPS
    result = RF24_250KBPS ;
  }
  else if ( dr == _BV(RF_DR_HIGH) )
  {
    // '01' = 2MBPS
    result = RF24_2MBPS ;
  }
  else
  {
    // '00' = 1MBPS
    result = RF24_1MBPS ;
  }
  return result ;
}

/****************************************************************************/

void RF24_setCRCLength(rf24_crclength_e length)
{
  uint8_t config = RF24_read_register(CONFIG) & ~( _BV(CRCO) | _BV(EN_CRC)) ;

  // switch uses RAM (evil!)
  if ( length == RF24_CRC_DISABLED )
  {
    // Do nothing, we turned it off above.
  }
  else if ( length == RF24_CRC_8 )
  {
    config |= _BV(EN_CRC);
  }
  else
  {
    config |= _BV(EN_CRC);
    config |= _BV( CRCO );
  }
  RF24_write_register( CONFIG, config ) ;
}

/****************************************************************************/

rf24_crclength_e RF24_getCRCLength(void)
{
  rf24_crclength_e result = RF24_CRC_DISABLED;
  
  uint8_t config = RF24_read_register(CONFIG) & ( _BV(CRCO) | _BV(EN_CRC)) ;
  uint8_t AA = RF24_read_register(EN_AA);
  
  if ( config & _BV(EN_CRC ) || AA)
  {
    if ( config & _BV(CRCO) )
      result = RF24_CRC_16;
    else
      result = RF24_CRC_8;
  }

  return result;
}

/****************************************************************************/

void RF24_disableCRC( void )
{
  uint8_t disable = RF24_read_register(CONFIG) & ~_BV(EN_CRC) ;
  RF24_write_register( CONFIG, disable ) ;
}

/****************************************************************************/
void RF24_setRetries(uint8_t delay, uint8_t count)
{
 RF24_write_register(SETUP_RETR,(delay&0xf)<<ARD | (count&0xf)<<ARC);
}
