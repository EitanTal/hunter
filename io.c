#include "stm8l10x.h"
#include "io.h"

#define USE_SET_1  0

#if 1   // Nucleo

uint8_t arduinopin2pin[] =
{
    6,   // D0
    5,   // D1
    0,   // D2
    1,   // D3
    2,   // D4
    2,   // D5
    3,   // D6
    1,   // D7
    2,   // D8
    4,   // D9
#if USE_SET_1
    4,   // D10 // also PD4,  PE5
    3,   // D11 // also PD3,  PC6
#else
    5,   // D10 // also PD4,  PE5
    6,   // D11 // also PD3,  PC6
#endif
    7,   // D12
    5,   // D13
    0,   // A0
    1,   // A1
    2,   // Z0
    3,   // Z1
    4,   // Z2
    5,   // Z3
    6,   // Z4
    7,   // Z5
    0,   // Z6
};

void* arduinopin2port[] =
{
    GPIOD,   // D0
    GPIOD,   // D1
    GPIOD,   // D2
    GPIOC,   // D3
    GPIOD,   // D4
    GPIOC,   // D5
    GPIOC,   // D6
    GPIOA,   // D7
    GPIOA,   // D8
    GPIOC,   // D9
#if USE_SET_1
    GPIOD,   // D10 // also PE5
    GPIOD,   // D11 // also PC6
#else
    GPIOE,   // D10 // also PE5
    GPIOC,   // D11 // also PC6
#endif
    GPIOC,   // D12
    GPIOC,   // D13
    GPIOB,   // A0
    GPIOB,   // A1
    GPIOB,   // Z0
    GPIOB,   // Z1
    GPIOB,   // Z2
    GPIOB,   // Z3
    GPIOB,   // Z4
    GPIOB,   // Z5
    GPIOC,   // Z6
};

#endif

void gpio_init(void)
{
#if 0
    uint8_t other_pin[] = {
    #if !USE_SET_1
        4,   // D10 // also PD4,  PE5
        3,   // D11 // also PD3,  PC6
    #else
        5,   // D10 // also PD4,  PE5
        6,   // D11 // also PD3,  PC6
    #endif
    };

    void* other_port[] = {
    #if !USE_SET_1
        GPIOD,   // D10 // also PE5
        GPIOD,   // D11 // also PC6
    #else
        GPIOE,   // D10 // also PE5
        GPIOC,   // D11 // also PC6
    #endif
    };
#else
    uint8_t other_pin[] = {
        4,   // CSN
        6,   // MOSI
    };

    void* other_port[] = {
        GPIOB,   // CSN
        GPIOB,   // MOSI
    };
#endif
    int i;
    for (i=0;i<2;i++)
    {
        GPIO_Init(other_port[i], 1 << other_pin[i], GPIO_Mode_In_FL_No_IT);
    }
}

void pinMode(int pin, int val)
{
    int mode = 0;
    if (val == OUTPUT)
        mode = GPIO_Mode_Out_PP_High_Fast;
    else if (val == INPUT)
        mode = GPIO_Mode_In_FL_No_IT;
    else if (val == INPUT_PULLUP)
        mode = GPIO_Mode_In_PU_IT;

    GPIO_Init(arduinopin2port[pin], 1 << arduinopin2pin[pin], mode);
}

void digitalWrite(int pin, int val)
{
    if (val)
        GPIO_SetBits(arduinopin2port[pin], (1 << arduinopin2pin[pin]));
    else
        GPIO_ResetBits(arduinopin2port[pin], (1 << arduinopin2pin[pin]));
}

int digitalRead(int port_and_pin)
{
    return !!GPIO_ReadInputDataBit(arduinopin2port[port_and_pin], (1 << arduinopin2pin[port_and_pin]));
}
