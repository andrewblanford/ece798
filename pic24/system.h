/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

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

void systemInit();
uint8_t getNodeAddress();

#endif	/* SYSTEM_H */

