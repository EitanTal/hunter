# Intro

This is a recreation of an Old-school Hunter fan remote

## Digital signals

Every packet is as follows:

   [`address`][`opcode`]

address is 5 bits long, opcode is 8 bits long. Address used = 0b01111

### Packets & Opcodes

* light:    0x0F (01111) 0x1 (00000001)
* fan off:  0x0F (01111) 0x2 (00000010)
* fan rev:                   (00000100)
* fan 3:                     (00001000)
* fan 2:                     (00010000)
* fan 1:    0x0F             (00100000)

## Pulse layout

short pulse: (0)

      _
    __

long pulse: (1)

     __
    _

## Pulse timing

length of each character: 328.4us (0.3284ms)

every 1 bit = 8us.
41 bits = one unit.
~16 bytes per triplet.

This equals a baudrate of 3045

The bit burst must repeat 16 times.
There must be exactly 10ms gap between each bit burst.

## Radio notes

### Carrier

The chosen carrier is 302MHz. The original remote is inconsistent on its carrier wave, ranging from 300 to 305.

### Modulation

On-off-keying modulation is used. (AM)

### RF backend

This implementation utilizes TI CC1101 as the RF backend. The original hunter remote presumably used a ferrite core antenna. More details are available in eariler revisions.

As an antenna, a 30cm wire is used.

For power, 0db is currently used

## Breadboard notes

CC1101 operates on 3v3 max. Resistor divider used on Arduino -> CC1101

Relevant pins on the pinheader of the eval board of CC1101:
| Color   | Pin   |  |   Pin  | Color   |
|---------|-------|--|--------|---------|
|  Brown  | VCC   |  | VCC    | Red     |
|  Orange | SCK   |  | MOSI   | Yellow  |
|  Green  | GDO2  |  | MISO   | Blue    |
|  Purple | GDO0  |  | CSN    | Grey    |
|  White  | GND   |  | GND    | Black   |


The pins as they connect to my breadboard:
| Color   | Pin   |  |   Pin  | Color   |
|---------|-------|--|--------|---------|
| (Black) |GND    |  |    VCC |   (Red) |
| (Blue)  |MISO   |  |   MOSI |(Yellow) |
| (Orange)|SCK    |  |    CSN |  (Grey) |
|         |       |  |   GDO0 |(Purple) |

Relevant pins on the arduino:
|Number|Function|Comment                  |
|------|--------|-------------------------|
|10    | SS     | (Active low)            |
|11    | MOSI   |                         |
|12    | MISO   |                         |
|13    | SCLK   |                         |
|2     | GDO0   | (Interrupt line 0, PD2) |

Breadboard jumper cables:
arduino-breadboard line
2-21
7-19
10-15
11-13
12-17
13-9

## STM8 pins

|Arduino|Function|207K (Eval board)   |101F (Target)  |
|-------|--------|--------------------|---------------|
|10     | SS     |PE5 (D10)           |PB4            |
|11     | MOSI   |PC6 (D11)           |PB6            |
|12     | MISO   |PC7 (D12)           |PB7            |
|13     | SCLK   |PC5 (D13)           |PB5            |
|2      | GDO0   |PD0 (D2)            |PC0            |
