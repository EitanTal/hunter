#include "stm8l10x.h"
#include "io.h"

uint8_t arduinopin2pin[] =
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1
};

void* arduinopin2port[] =
{
    GPIOA, GPIOA, GPIOA, GPIOA,
    GPIOA, GPIOA, GPIOA, GPIOA,
    GPIOA, GPIOA, GPIOA, GPIOA,
    GPIOA, GPIOA, GPIOA, GPIOA,
};

void pinMode(int pin, int val)
{
    int mode = (val == OUTPUT) ? GPIO_Mode_Out_PP_High_Fast : GPIO_Mode_In_FL_No_IT;
    GPIO_Init(arduinopin2port[pin], 1 << arduinopin2pin[pin], mode);
}

void digitalWrite(int pin, int val)
{

}

int digitalRead(int port_and_pin)
{

}

void bitClear(int port, int pin)
{

}

void bitSet(int port, int pin)
{

}

int bitRead(int port, int pin)
{

}
