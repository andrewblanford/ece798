/* 
 * File:   adc.h
 * Author: andrew
 *
 * Created on January 31, 2016, 3:29 PM
 */

#ifndef ADC_H
#define	ADC_H
#include <xc.h>
#include <stdint.h>

// Analog input RA1 / AN1
#define ANALOG1_TRIS    _TRISA1
#define ANALOG1_CFG     _PCFG1
#define ANALOG1_NUM     1       // AN1

void configAnalog();
uint16_t getADC1(void);

#endif	/* ADC_H */

