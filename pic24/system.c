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