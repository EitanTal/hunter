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

## Radio notes

significant wide band activity in:
304MHz

some additional activity in:
609MHz
914MHz
1218MHz

### Circuit analysis

I measured all the testpoints with a power supply of 8.26V. I then measured the phase difference between points of interest. Reference phase is the XXXX testpoint, with a phase of zero.

#### Common
Entire duration of the transmission is ~12.5ms. Digital_OUT.png shows the waveform. It's a push-pull active-high spanning 0...9V

Below are measurements for various testpoints, as seen in waveforms/circuit.png

Each testpoint is defined `active` when the AC component (300MHz) is present. The phase and amplitude varies by the testpoint, and so is the DC level. It's active low when the AC is present while at the lower voltage, and vice versa.

a single cycle lenth of 300MHZ is approx 3380ps.

#### Point Base:
| what                 |  mV     |
| -                    |   -     |
| Volt low:            |   0     |
| Volt High:           |   3140  |
| Active on:           |   Hi    |
| peak2peak AC active: |   160   |
| peak2peak AC noise:  |   10    |
| Rise time:           |   --    |
| Fall time:           |   6us   |
| Phase:               |   ?     |

#### Point Emitter:
The emitter behavior is strange: Its falloff time is exremely slow, as seen in emitter_all.png.
Also, it has a 200mv spike every ~50us.
Oscillations decay after about 20ns, but the voltage falltime is very long.

| what                 |  mV     |
| -                    |   -     |
| Volt low:            |  0      |
| Volt High:           |  2400   |
| Active on:           |  Hi     |
| peak2peak AC active: |  140    |
| peak2peak AC noise:  |  10     |
| Rise time:           |  200ns  |
| Fall time:           |  long   |
| Phase:               |  ?      |

#### Point Collector:
This one is interesting: It is active-lo, and so are the testpoints that lead to it.

| what                 |  mV     |
| -                    |   -     |
| Volt low:            |  7000   |
| Volt High:           |  8320   |
| Active on:           |  Lo     |
| peak2peak AC active: |  224    |
| peak2peak AC noise:  |  60?    |
| Rise time:           |  100ns  |
| Fall time:           |  300ns  |
| Phase:               |  30?    |

#### Point 1:
| what                 |  mV     |
| -                    |   -     |
| Volt low:            |  7170   |
| Volt High:           |  8330   |
| Active on:           |  Lo     |
| peak2peak AC active: |  150    |
| peak2peak AC noise:  |  30     |
| Rise time:           |  20ns   |
| Fall time:           |  200ns  |
| Phase:               |  0      |

#### Point 2:
| what                 |  mV     |
| -                    |   -     |
| Volt low:            |  7170   |
| Volt High:           |  8330   |
| Active on:           |  Lo     |
| peak2peak AC active: |  270    |
| peak2peak AC noise:  |  30     |
| Rise time:           |  120ns  |
| Fall time:           |  200ns  |
| Phase:               |  180    |

#### Point diode:
This point is interesting. It's much different than the connected point E. (Emitter)

| what                 |  mV     |
| -                    |   -     |
| Volt low:            |  0      |
| Volt High:           |  530    |
| Active on:           |  Hi     |
| peak2peak AC active: |  125    |
| peak2peak AC noise:  |  15     |
| Rise time:           |  120ns  |
| Fall time:           |  200ns  |
| Phase:               |  -80    |

## Links

<https://www.circuit-diagram.org/editor/c/8aa76d7eb7214562b758d9756eb3f021>

<https://everycircuit.com/circuit/5273046325395456>
