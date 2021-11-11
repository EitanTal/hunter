#pragma once

enum // ! Arduino
{
    PINB,
    PIND,
    PORTB,
    PIN_A0 = 14,
    PIN_A1 = 15,
    PIN_Z0 = 16,
    PIN_Z1 = 17
};

#define SPI_SS   10     // PB2 = SPI_SS
#define SPI_MOSI 11     // PB3 = MOSI
#define SPI_MISO 12     // PB4 = MISO
#define SPI_SCK  13     // PB5 = SCK
#define GDO0	 2        // PD2 = INT0

#define PORT_SPI_MISO  PINB
#define BIT_SPI_MISO  4

#define PORT_SPI_SS  PORTB
#define BIT_SPI_SS   2

#define PORT_GDO0  PIND
#define BIT_GDO0  2

