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

#ifndef SPI_H
#define	SPI_H
#include <xc.h>
#include <stdint.h>

// CSN = RB3/AN5
// CSN is active low
#define CSN_TRIS              _TRISB3
#define CSN_CFG               _PCFG5
#define SLAVE_ENABLE()        _LATB3 = 0  
#define SLAVE_DISABLE()       _LATB3 = 1

// SDO = RB13/RP13/AN11
// SDO1 is RP function 7
#define SDO_TRIS              _TRISB13
#define SDO_CFG               _PCFG11
#define SDO_RP                _RP13R
#define RPSDO1                7

// SCK = RB12/RP12/AN12
// SCK1 is RP function 8
#define SCK_TRIS             _TRISB12
#define SCK_CFG              _PCFG12
#define SCK_RP               _RP12R
#define RPSCK1               8

// SDI = RB14/AN10/RP14
// SDI1 assigned to RP14 as input
#define SDI_TRIS             _TRISB14
#define SDI_CFG              _PCFG10
#define SDI_RP               _SDI1R
#define RPSDI1               14

// SPI1 Configuration (SPI1CON1))
//spi clock = 40MHz/16*1 = 40MHz/16 = 2.5 MHz
// primary prescale 16:1 (Bit 0:1 = 1)
#define SPI1_PRI_PRESCALE    0x0001
// secondary prescale 1:1 (Bit 4:2 = 111)
#define SPI1_SEC_PRESCALE    0x001c
// operate in master mode (Bit 5 = 1)
#define SPI1_MASTER_MODE     0x0020
// clock polarity active high (Bit 6 = 0)
#define SPI1_CLK_POLARITY    0x0000
// slave select disabled (Bit 7 = 0)
#define SPI1_SSEN            0x0000
// clock edge select active to idle (Bit 8 = 1)
#define SPI1_CKE             0x0100
// sample input at end  (Bit 9 = 1)
#define SPI1_SMP             0x0200
// operate in 8bit mode (Bit 10 = 0)
#define SPI1_MODE16          0x0000
// control SDO from SPI module (Bit 11 = 0)
#define SPI1_DISSDO          0x0000
// control SCK from SPI module (Bit 12 = 0)
#define SPI1_DISSCK          0x0000

#define SPI1_CONFIG (      \
    SPI1_PRI_PRESCALE   | \
    SPI1_SEC_PRESCALE   | \
    SPI1_MASTER_MODE    | \
    SPI1_CLK_POLARITY   | \
    SPI1_SSEN           | \
    SPI1_CKE            | \
    SPI1_SMP            | \
    SPI1_MODE16         | \
    SPI1_DISSDO         | \
    SPI1_DISSCK)

/** 
 * Configures the SPI1 module for use on the pins identified above 
 * SPI1_CONFIG includes all necessary bits for SPIxCON1 
 */
void configSPI1();

/**
 * Send / Receive from SPI1
 * @param u16_c data to send
 * @return data received
 */
uint16_t writeSPI1(uint16_t u16_c);

#endif	/* SPI_H */

