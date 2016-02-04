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
    // setup RA2, RA3 and RB4 as digital input for address bits
    ADDRESS0_TRIS = 1;
    ADDRESS1_TRIS = 1;
}

uint8_t getNodeAddress() {
    uint8_t addr = 0;
    addr |= (ADDRESS1 << 1);
    addr |= (ADDRESS0 << 0);
    return addr;
}