/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

#ifndef SYSTEM_CONFIG_H
#define	SYSTEM_CONFIG_H

#include "miwi_config.h"          //MiWi Application layer configuration file
#include "miwi_config_p2p.h"      //MiWi Protocol layer configuration file
#include "config_89xa.h"         //Tranceiver configuration file

#define SOFTWARE_SECURITY

//TRANSCEIVER DEFINITIONS
#define PHY_IRQ1                    IFS1bits.INT2IF
#define PHY_IRQ1_En                 IEC1bits.INT2IE
//#define PHY_IRQ0                    IFS1bits.INT1IF
//#define PHY_IRQ0_En                 IEC1bits.INT1IE

#define IRQ1_INT_PIN                PORTBbits.RB7
#define IRQ1_INT_TRIS               TRISBbits.TRISB7
//#define IRQ0_INT_PIN                PORTEbits.RE8
//#define IRQ0_INT_TRIS               TRISEbits.TRISE8

#define PHY_IRQ1_TRIS               TRISBbits.TRISB7
#define Config_nCS                  LATBbits.LATB3
#define Config_nCS_TRIS             TRISBbits.TRISB3
#define Data_nCS                    LATBbits.LATB2
#define Data_nCS_TRIS               TRISBbits.TRISB2
#define RF_RESET                    LATAbits.LATA2
#define RF_RESET_TRIS               TRISAbits.TRISA2
//#define PHY_RESETn                  LATGbits.LATG2
//#define PHY_RESETn_TRIS             TRISGbits.TRISG2

//SPI DEFINITIONS
#define SPI_SDI                     PORTBbits.RB8
#define SDI_TRIS                    TRISBbits.TRISB8
#define SDI_RP_NUM                  8
#define SPI_SDO                     LATBbits.LATB9
#define SDO_TRIS                    TRISBbits.TRISB9
#define SPI_SCK                     LATBbits.LATB6
#define SCK_TRIS                    TRISBbits.TRISB6
      
//PUSH BUTTON, LED PIN DEFINITIONS
//#define PUSH_BUTTON_1               PORTDbits.RD6
//#define BUTTON_1_TRIS               TRISDbits.TRISD6
#define LED_1                       LATAbits.LATA0
#define LED_1_TRIS                  TRISAbits.TRISA0

#define TMRL TMR2

#endif	/* SYSTEM_CONFIG_H */

