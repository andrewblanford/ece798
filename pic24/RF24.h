/* 
 * File:   RF24.h
 * Author: andrew
 *
 * Created on November 28, 2015, 11:54 AM
 */

#ifndef RF24_H
#define	RF24_H
#include <xc.h>
#include <stdint.h>

// CE is RB2/AN4
#define CE_TRIS     _TRISB2
#define CE_CFG      _PCFG4
#define CE_ON()     _LATB2 = 1
#define CE_OFF()    _LATB2 = 0


/**
 * Power Amplifier level.
 *
 * For use with setPALevel()
 */
typedef enum { RF24_PA_MIN = 0,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX, RF24_PA_ERROR } rf24_pa_dbm_e ;

/**
 * Data rate.  How fast data moves through the air.
 *
 * For use with setDataRate()
 */
typedef enum { RF24_1MBPS = 0, RF24_2MBPS, RF24_250KBPS } rf24_datarate_e;

/**
 * CRC Length.  How big (if any) of a CRC is included.
 *
 * For use with setCRCLength()
 */
typedef enum { RF24_CRC_DISABLED = 0, RF24_CRC_8, RF24_CRC_16 } rf24_crclength_e;

#define rf24_max(a,b) (a>b?a:b)
#define rf24_min(a,b) (a<b?a:b)
#define _BV(x) (1<<(x))

uint8_t RF24_begin(void);
void RF24_startListening(void);
void RF24_stopListening(void);
uint8_t RF24_available(void);
uint8_t RF24_available_pipe(uint8_t* pipe_num);
void RF24_openReadingPipe(uint8_t child, const uint8_t *address);
void RF24_openWritingPipe(const uint8_t *address);
void RF24_closeReadingPipe( uint8_t pipe );
void RF24_read( void* buf, uint8_t len );
uint8_t RF24_write_multicast( const void* buf, uint8_t len, const uint8_t multicast );
uint8_t RF24_write( const void* buf, uint8_t len );

void RF24_setChannel(uint8_t channel);
uint8_t RF24_getChannel();
void RF24_setPayloadSize(uint8_t size);
uint8_t RF24_getPayloadSize(void);
void RF24_setRetries(uint8_t delay, uint8_t count);
void RF24_setAddressWidth(uint8_t a_width);
void RF24_maskIRQ(uint8_t tx, uint8_t fail, uint8_t rx);
uint8_t RF24_getDynamicPayloadSize(void);
void RF24_setAutoAck_all(uint8_t enable);
void RF24_setAutoAck_pipe( uint8_t pipe, uint8_t enable );
void RF24_setPALevel(uint8_t level);
uint8_t RF24_getPALevel(void);
uint8_t RF24_setDataRate(rf24_datarate_e speed);
rf24_datarate_e RF24_getDataRate( void );
void RF24_setCRCLength(rf24_crclength_e length);
rf24_crclength_e RF24_getCRCLength(void);
void RF24_disableCRC( void );
void RF24_whatHappened(uint8_t* tx_ok, uint8_t* tx_fail, uint8_t* rx_ready);
void RF24_enableDynamicPayloads(void);
void RF24_enableAckPayload(void);
void RF24_enableDynamicAck(void);
void RF24_writeAckPayload(uint8_t pipe, const void* buf, uint8_t len);
uint8_t RF24_isAckPayloadAvailable(void);
void RF24_powerDown(void);
void RF24_powerUp(void);
uint8_t RF24_rxFifoFull();
uint8_t RF24_txStandBy();
uint8_t RF24_isPVariant(void);
uint8_t RF24_testCarrier(void);
uint8_t RF24_testRPD(void);

#endif	/* RF24_H */

