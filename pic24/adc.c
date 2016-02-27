/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 * getADC1 copied and modified by Andrew Blanford
 */
#include "adc.h"
#include <stddef.h>


/*
 * Setup AN1, CH0 for analog sampling
 */
void configAnalog() {
    // ADC off for configuration
    AD1CON1bits.ADON = 0;
    // select RA1 for analog operation (input direction, disable resistors, analog mode)
    ANALOG1_CFG = 0;    // analog
    ANALOG1_TRIS = 1;   // input
    
    // start sample manually, conversion automatic after sample
    // force manual trigger for sampling
    AD1CON1bits.ASAM = 0;
    // start conversion automatically after sample
    AD1CON1bits.SSRC = 0x07; // (111)
    // 12 bit mode
    AD1CON1bits.AD12B = 1;
    // voltage reference from AVDD and AVSS
    AD1CON2bits.VCFG = 0x04; // (1xx)
    // use internal clock for sampling and max (31) sample ticks
    AD1CON3bits.ADRC = 1;
    AD1CON3bits.SAMC = 31;
    // set CH0 Sample/Hold A to sample AN1 (RA1) referenced to GND
    AD1CHS0bits.CH0NA = 0; // negative input from VREFL
    AD1CHS0bits.CH0SA = ANALOG1_NUM; 
    // turn on ADC
    AD1CON1bits.ADON = 1;
}

/** Performs an ADC conversion (assumes ADC is initialized properly
 *  to return integer results.
 *  \return Integer value (10- or 12-bit, depending on ADC configuration)
 *          corresponding to the ADC conversion result.
 */
uint16_t getADC1(void) {
  uint8_t u8_wdtState;
  uint16_t result;

  u8_wdtState = _SWDTEN;                  //save WDT state
  _SWDTEN = 1;                            //enable WDT since we block
  
  // enable the ADC
  AD1CON1bits.ADON = 1;
  
  AD1CON1bits.SAMP=1;                     //start sampling
  Nop();                                  //takes one clock to clear previous DONE flag, delay before checking.
  while(!AD1CON1bits.DONE);               //wait for conversion to finish
  _SWDTEN = u8_wdtState;                  //restore WDT
  
  // store the result locally
  result = ADC1BUF0;
  // disable the ADC to save power
  AD1CON1bits.ADON = 0;
  return(result);
}
