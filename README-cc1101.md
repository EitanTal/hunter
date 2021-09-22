# cc1101-ook

Blog post can be found at (http://tamercelik.com/)
Contact: (http://tamercelik.com/iletisim/)

* this code provides a simple example to TX OOK with TI CC1101.
* arduino sketch included in repo.
* slightly modified version of panstamp cc1101 library.

**check docs/ for wiring**

## thanks
- [Mike](https://github.com/miek)
- [Samy](http://samy.pl/)
- #rfcat

## Pinout

(Black) GND    |  |    VCC    (Red)
-----------------------------------
(Blue)  MISO   |  |   MOSI (Yellow)
-----------------------------------
(Orange)SCK    |  |    CSN   (Grey)
-----------------------------------
               |  |   GDO0 (Purple)

### Arduino 

10 - SS        (Active low)
11 - MOSI
12 - MISO
13 - SCLK
2  - GDO0        (Interrupt line 0, PD2)
