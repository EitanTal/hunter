#pragma once

enum // ! Arduino
{
    INPUT,
    OUTPUT,
    INPUT_PULLUP
};

enum
{
    LOW,
    HIGH
};

void gpio_init(void);

void pinMode(int pin, int val);

void digitalWrite(int pin, int val);

int digitalRead(int port_and_pin);

void bitClear(int port, int pin);

void bitSet(int port, int pin);

int bitRead(int port, int pin);
