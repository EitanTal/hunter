#include "time.h"

void delayMicroseconds(int time)
{
    // ! Arduino
    int i = 0;
    for (i = 0; i < time; i++)
    {
        __asm("NOP");
    }
}

void delay(int time)
{
    // ! Arduino
}
