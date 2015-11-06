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
#ifndef  _CONSOLE_H_
#define  _CONSOLE_H_

/************************ HEADERS **********************************/

#include "system_config.h"

#if defined(ENABLE_CONSOLE)

#define BAUD_RATE 19200

/************************ DEFINITIONS ******************************/
 #define CONSOLE_IsPutReady()        (U1STAbits.TRMT)
 #define CONSOLE_IsGetReady()        (IFS0bits.U1RXIF)


//Define UART TX and RX registers
#define TREG        U1TXREG
#define RREG        U1RXREG
#define UART_STA    U1STA
#define UART_MODE   U1MODE
#define UART_SPBRG  U1BRG
#define UART_IF     IFS0bits.U1RXIF
#define MODE_UARTEN U1MODEbits.UARTEN
#define STA_UTXEN   U1STAbits.UTXEN

//FUNCTION PROTOTYPES
/*********************************************************************
* Function:         void CONSOLE_Initialize(void)
*
* PreCondition:     none
*
* Input:	    none
*
* Output:	    none
*
* Side Effects:	    UART is configured
*
* Overview:         This function will configure the UART for use at
*                   in 8 bits, 1 stop, no flowcontrol mode
*
* Note:             None
********************************************************************/
 void CONSOLE_Initialize(void);


/*********************************************************************
* Function:         void CONSOLE_Put(uint8_t c)
*
* PreCondition:     none
*
* Input:            c - character to be printed
*
* Output:           none
*
* Side Effects:	    c is printed to the console
*
* Overview:	    This function will print the inputed character
*
* Note:		    Do not power down the microcontroller until
*                   the transmission is complete or the last
*                   transmission of the string can be corrupted.
********************************************************************/
 void CONSOLE_Put(uint8_t c);



/*********************************************************************
* Function:         void CONSOLE_PutString(ROM char* str)
*
* PreCondition:     none
*
* Input:            str - String that needs to be printed
*
* Output:           none
*
* Side Effects:	    str is printed to the console
*
* Overview:         This function will print the inputed ROM string
*
* Note:             Do not power down the microcontroller until
*                   the transmission is complete or the last
*                   transmission of the string can be corrupted.
********************************************************************/
void CONSOLE_PutString(char* str);

/*********************************************************************
* Function:         uint8_t CONSOLE_Get(void)
*
* PreCondition:     none
*
* Input:            none
*
* Output:           one byte received by UART
*
* Side Effects:	    none
*
* Overview:         This function will receive one byte from UART
*
* Note:             Do not power down the microcontroller until
*                   the transmission is complete or the last
*                   transmission of the string can be corrupted.
********************************************************************/
uint8_t CONSOLE_Get(void);



/*********************************************************************
* Function:         void CONSOLE_PrintHex(uint8_t toPrint)
*
* PreCondition:     none
*
* Input:            toPrint - character to be printed
*
* Output:           none
*
* Side Effects:	    toPrint is printed to the console
*
* Overview:         This function will print the inputed char to
*                   the console in hexidecimal form
*
* Note:             Do not power down the microcontroller until
*                   the transmission is complete or the last
*                   transmission of the string can be corrupted.
********************************************************************/
void CONSOLE_PrintHex(uint8_t);

/*********************************************************************
* Function:         void CONSOLE_PrintDec(uint8_t toPrint)
*
* PreCondition:     none
*
* Input:		    toPrint - character to be printed. Range is 0-99
*
* Output:		    none
*
* Side Effects:	    toPrint is printed to the console in decimal
*
*
* Overview:		    This function will print the inputed uint8_t to
*                   the console in decimal form
*
* Note:			    Do not power down the microcontroller until
*                   the transmission is complete or the last
*                   transmission of the string can be corrupted.
********************************************************************/
void CONSOLE_PrintDec(uint8_t);

//If console is not enabled
#else

#define CONSOLE_Initialize()
#define CONSOLE_IsPutReady()                 1
#define CONSOLE_IsGetReady()                 1
#define CONSOLE_Put(c)
#define CONSOLE_PutString(str)
#define CONSOLE_Get()                        'a'
#define CONSOLE_PrintHex(a)
#define CONSOLE_PrintDec(a)


#endif

#define Printf(x) CONSOLE_PutString((char*)x)

#endif