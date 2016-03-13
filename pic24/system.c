// *****************************************************************************
//    Author: Andrew Blanford
//
//    Permission to use, copy, modify, and distribute this software and its
//    documentation for any purpose, without fee, and without written agreement is
//    hereby granted, provided that the above copyright notice, the following
//    two paragraphs and the authors appear in all copies of this software.
//
//    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
//    DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
//    OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
//    HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
//    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
//    AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
//    ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
//    PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
//
//    Please maintain this header in its entirety when copying/modifying
//    these files.
//
// *****************************************************************************
#include "system.h"
#include "spi.h"
#include "adc.h"

void configDigital();

void systemInit() {
    // config digital IO
    configDigital();
    // setup analog measuring
    configAnalog();
    // setup SPI1 for nRF radio
    configSPI1();
}

void configDigital() {
    // setup RA2, RA3 as digital input for address bits
    ADDRESS0_TRIS = 1;
    ADDRESS1_TRIS = 1;
#ifdef USE_3_ADDRESS_BITS
    // RB4 digital input also
    ADDRESS2_TRIS = 1;
#endif
    
    // configure the LED  as digital output
    LED_TRIS = 0;
    LED_CFG = 1;
    LED_ON();
}

uint8_t getNodeAddress() {
    uint8_t addr = 0;
#ifdef USE_3_ADDRESS_BITS
    addr |= (ADDRESS2 << 2);
#endif
    addr |= (ADDRESS1 << 1);
    addr |= (ADDRESS0 << 0);
    return addr;
}