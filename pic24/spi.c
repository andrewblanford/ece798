#include <p24HJ128GP502.h>

#include "spi.h"

void configSPI1(void) {
  SPI1CON1 = SPI1_CONFIG;
    /*
    PRI_PRESCAL_16_1 |     //4:1 primary prescale
    SEC_PRESCAL_1_1 |     //1:1 secondary prescale
    CLK_POL_ACTIVE_HIGH   | //clock active high (CKP = 0)
    SPI_SMP_ON          | // 
    SPI_CKE_ON          | // CKE=1
    SPI_MODE8_ON        | //8-bit mode
    MASTER_ENABLE_ON;     //master mode
*/
  // SDO = RB13 digital output
  SDO_RP = RPSDO1;
  SDO_TRIS = 0;
  SDO_CFG = 1;
  
  // SCK = RB12 digital output
  SCK_RP = RPSCK1; 
  SCK_TRIS = 0;
  SCK_CFG = 1;
  
  // SDI = RB14 digital input
  SDI_RP = RPSDI1;
  SDI_TRIS = 1;
  SDI_CFG = 1;
  
  //chip select CSN config
  CSN_CFG = 1;                 // digital
  CSN_TRIS = 0;                // output
  SLAVE_DISABLE();             //disable the chip select
  SPI1STATbits.SPIEN = 1;      //enable SPI mode
}

/**
 * Writes a value to the SPIx output buffer, and returns the SPIx
 * input value. This function waits until the entire transmission
 * is complete so it can return the new input value. Whether or not
 * 8-bits or 16-bits is sent depends on how the SPIx module is
 * configured.
 * \param u16_c Value to write to SPI TXBUF
 * \return Value read from SPI RXBUF
 */
uint16_t writeSPI1(uint16_t u16_c) {
  // check for error and clear it
  if (SPI1STATbits.SPIROV) {
    //clear the error
    SPI1STATbits.SPIROV = 0;
  }

  //clear interrupt flag since we are about to write new value
  _SPI1IF = 0;
  // put new value into SPI buffer for output
  SPI1BUF = u16_c;
  //wait for operation to complete - interrupt flag will get set
  while (!_SPI1IF) { 
  }
  // return value is in buffer
  return(SPI1BUF);
}