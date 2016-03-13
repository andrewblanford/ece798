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
#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#include <stdint.h>

// 40MHz based on FRCPLL selection
// FCY = Fosc / 2
// define FCY before libpic30 so the delay functions can be used
#define FCY     20000000L
#include <libpic30.h>

#define DELAY_MS(ms) __delay_ms(ms)
#define DELAY_US(us) __delay_us(us)

// address select lines
#define ADDRESS0              _RA2
#define ADDRESS0_TRIS         _TRISA2
#define ADDRESS1              _RA3
#define ADDRESS1_TRIS         _TRISA3
// if RB4 is available for 3rd address bit it can be used
#ifdef USE_3_ADDRESS_BITS
#define ADDRESS2_TRIS         _TRISB4
#define ADDRESS2              _RB4
#endif

// LED is RA0 / AN0 on pin 2
#define LED                   _RA0
#define LED_CFG               _PCFG0
#define LED_TRIS              _TRISA0
#define LED_ON()              _LATA0 = 1
#define LED_OFF()             _LATA0 = 0

/**
 * Initialize basic system functions (digital, analog, SPI)
 */
void systemInit();

/**
 * Get the numeric value represented by user configurable address select bits
 * @return node address value 0-7
 */
uint8_t getNodeAddress();

#endif	/* SYSTEM_H */

