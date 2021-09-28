EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L cc1101:CC1101RGPR U1
U 1 1 6151024B
P 1850 5300
F 0 "U1" H 3250 5687 60  0000 C CNN
F 1 "CC1101RGPR" H 3250 5581 60  0000 C CNN
F 2 "RGP20_2P4X2P4" H 3250 5540 60  0001 C CNN
F 3 "" H 1850 5300 60  0000 C CNN
	1    1850 5300
	1    0    0    -1  
$EndComp
$Comp
L ul_STM8L101F3U6TR:STM8L101F3U6TR U2
U 1 1 6151131E
P 2500 1650
F 0 "U2" H 3400 2037 60  0000 C CNN
F 1 "STM8L101F3U6TR" H 3400 1931 60  0000 C CNN
F 2 "UFQFPN20_3x3x0p6" H 3400 1890 60  0001 C CNN
F 3 "" H 2500 1650 60  0000 C CNN
	1    2500 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D11
U 1 1 615166F6
P 7300 4400
F 0 "D11" V 7339 4282 50  0000 R CNN
F 1 "LED1" V 7248 4282 50  0000 R CNN
F 2 "" H 7300 4400 50  0001 C CNN
F 3 "~" H 7300 4400 50  0001 C CNN
	1    7300 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 615187D4
P 6750 4400
F 0 "D2" V 6789 4282 50  0000 R CNN
F 1 "LED2" V 6698 4282 50  0000 R CNN
F 2 "" H 6750 4400 50  0001 C CNN
F 3 "~" H 6750 4400 50  0001 C CNN
	1    6750 4400
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 61519882
P 7050 1800
F 0 "SW1" H 7050 2085 50  0000 C CNN
F 1 "SW_Light" H 7050 1994 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 7050 2000 50  0001 C CNN
F 3 "~" H 7050 2000 50  0001 C CNN
	1    7050 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 6151A26D
P 6600 2200
F 0 "SW2" H 6600 2485 50  0000 C CNN
F 1 "SW_LightUp" H 6600 2394 50  0000 C CNN
F 2 "" H 6600 2400 50  0001 C CNN
F 3 "~" H 6600 2400 50  0001 C CNN
	1    6600 2200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 6151AB9D
P 7650 2150
F 0 "SW3" H 7650 2435 50  0000 C CNN
F 1 "SW_LightDown" H 7650 2344 50  0000 C CNN
F 2 "" H 7650 2350 50  0001 C CNN
F 3 "~" H 7650 2350 50  0001 C CNN
	1    7650 2150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 6151B5C8
P 7050 3100
F 0 "SW4" H 7050 3385 50  0000 C CNN
F 1 "SW_Fan" H 7050 3294 50  0000 C CNN
F 2 "" H 7050 3300 50  0001 C CNN
F 3 "~" H 7050 3300 50  0001 C CNN
	1    7050 3100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 6151C131
P 6600 3500
F 0 "SW5" H 6600 3785 50  0000 C CNN
F 1 "SW_FanUp" H 6600 3694 50  0000 C CNN
F 2 "" H 6600 3700 50  0001 C CNN
F 3 "~" H 6600 3700 50  0001 C CNN
	1    6600 3500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 6151D401
P 7600 3500
F 0 "SW6" H 7600 3785 50  0000 C CNN
F 1 "SW_FanDown" H 7600 3694 50  0000 C CNN
F 2 "" H 7600 3700 50  0001 C CNN
F 3 "~" H 7600 3700 50  0001 C CNN
	1    7600 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 615222B5
P 800 7400
F 0 "#PWR?" H 800 7150 50  0001 C CNN
F 1 "GND" H 805 7227 50  0000 C CNN
F 2 "" H 800 7400 50  0001 C CNN
F 3 "" H 800 7400 50  0001 C CNN
	1    800  7400
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery J1
U 1 1 6152C555
P 800 7200
F 0 "J1" H 908 7246 50  0000 L CNN
F 1 "Battery" H 908 7155 50  0000 L CNN
F 2 "parts:MyBatteryConnector" V 800 7260 50  0001 C CNN
F 3 "~" V 800 7260 50  0001 C CNN
	1    800  7200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 VBAT
U 1 1 6152F877
P 800 7000
F 0 "VBAT" H 888 7083 50  0001 L CNN
F 1 "+3V0" H 888 7037 50  0000 L CNN
F 2 "" H 800 7000 50  0001 C CNN
F 3 "" H 800 7000 50  0001 C CNN
	1    800  7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2150 2000 2150
Wire Wire Line
	2000 2150 2000 800 
Wire Wire Line
	2000 800  6150 800 
Wire Wire Line
	6150 800  6150 1800
Wire Wire Line
	6150 1800 6850 1800
Wire Wire Line
	2500 2450 1900 2450
Wire Wire Line
	1900 2450 1900 700 
Wire Wire Line
	1900 700  6050 700 
Wire Wire Line
	6050 700  6050 2200
Wire Wire Line
	6050 2200 6400 2200
Wire Wire Line
	4300 1750 5950 1750
Wire Wire Line
	5950 1750 5950 2350
Wire Wire Line
	5950 2350 7300 2350
Wire Wire Line
	4300 1850 5850 1850
Wire Wire Line
	5850 1850 5850 3100
Wire Wire Line
	5850 3100 6850 3100
Wire Wire Line
	4300 2050 5750 2050
Wire Wire Line
	5750 2050 5750 3500
Wire Wire Line
	5750 3500 6400 3500
Wire Wire Line
	2500 1950 2100 1950
Wire Wire Line
	2100 1950 2100 900 
Wire Wire Line
	2100 900  5650 900 
Wire Wire Line
	5650 900  5650 3650
Wire Wire Line
	5650 3650 7300 3650
Wire Wire Line
	7300 3650 7300 3500
$Comp
L power:GND #PWR?
U 1 1 61535B0C
P 6800 2200
F 0 "#PWR?" H 6800 1950 50  0001 C CNN
F 1 "GND" H 6805 2027 50  0000 C CNN
F 2 "" H 6800 2200 50  0001 C CNN
F 3 "" H 6800 2200 50  0001 C CNN
	1    6800 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61536017
P 7250 1800
F 0 "#PWR?" H 7250 1550 50  0001 C CNN
F 1 "GND" H 7255 1627 50  0000 C CNN
F 2 "" H 7250 1800 50  0001 C CNN
F 3 "" H 7250 1800 50  0001 C CNN
	1    7250 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6153682C
P 7850 2150
F 0 "#PWR?" H 7850 1900 50  0001 C CNN
F 1 "GND" H 7855 1977 50  0000 C CNN
F 2 "" H 7850 2150 50  0001 C CNN
F 3 "" H 7850 2150 50  0001 C CNN
	1    7850 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61537254
P 7800 3500
F 0 "#PWR?" H 7800 3250 50  0001 C CNN
F 1 "GND" H 7805 3327 50  0000 C CNN
F 2 "" H 7800 3500 50  0001 C CNN
F 3 "" H 7800 3500 50  0001 C CNN
	1    7800 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6153769A
P 7250 3100
F 0 "#PWR?" H 7250 2850 50  0001 C CNN
F 1 "GND" H 7255 2927 50  0000 C CNN
F 2 "" H 7250 3100 50  0001 C CNN
F 3 "" H 7250 3100 50  0001 C CNN
	1    7250 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61537DED
P 6800 3500
F 0 "#PWR?" H 6800 3250 50  0001 C CNN
F 1 "GND" H 6805 3327 50  0000 C CNN
F 2 "" H 6800 3500 50  0001 C CNN
F 3 "" H 6800 3500 50  0001 C CNN
	1    6800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3500 7300 3500
Wire Wire Line
	7300 2350 7300 2150
Wire Wire Line
	7300 2150 7450 2150
$Comp
L power:GND #PWR?
U 1 1 6153CDA6
P 2500 3050
F 0 "#PWR?" H 2500 2800 50  0001 C CNN
F 1 "GND" H 2505 2877 50  0000 C CNN
F 2 "" H 2500 3050 50  0001 C CNN
F 3 "" H 2500 3050 50  0001 C CNN
	1    2500 3050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 6154F289
P 1350 1650
F 0 "J2" H 1268 1967 50  0000 C CNN
F 1 "JTAG" H 1268 1876 50  0000 C CNN
F 2 "" H 1350 1650 50  0001 C CNN
F 3 "~" H 1350 1650 50  0001 C CNN
	1    1350 1650
	-1   0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR?
U 1 1 61551E0B
P 1650 1350
F 0 "#PWR?" H 1650 1200 50  0001 C CNN
F 1 "+3V0" H 1665 1523 50  0000 C CNN
F 2 "" H 1650 1350 50  0001 C CNN
F 3 "" H 1650 1350 50  0001 C CNN
	1    1650 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1550 1650 1550
Wire Wire Line
	1650 1550 1650 1350
Wire Wire Line
	1550 1650 2500 1650
$Comp
L power:GND #PWR?
U 1 1 61557D91
P 1650 2000
F 0 "#PWR?" H 1650 1750 50  0001 C CNN
F 1 "GND" H 1655 1827 50  0000 C CNN
F 2 "" H 1650 2000 50  0001 C CNN
F 3 "" H 1650 2000 50  0001 C CNN
	1    1650 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1750 1650 1750
Wire Wire Line
	1650 1750 1650 2000
Wire Wire Line
	1550 1850 1750 1850
Wire Wire Line
	1750 1850 1750 1750
Wire Wire Line
	1750 1750 2500 1750
$Comp
L power:GND #PWR?
U 1 1 6155BCBA
P 7000 4450
F 0 "#PWR?" H 7000 4200 50  0001 C CNN
F 1 "GND" H 7005 4277 50  0000 C CNN
F 2 "" H 7000 4450 50  0001 C CNN
F 3 "" H 7000 4450 50  0001 C CNN
	1    7000 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4400 7000 4400
Wire Wire Line
	7000 4400 7000 4450
Wire Wire Line
	7000 4400 7150 4400
Connection ~ 7000 4400
Wire Wire Line
	2500 1850 2200 1850
Wire Wire Line
	2200 1000 5550 1000
Wire Wire Line
	5550 1000 5550 4400
Wire Wire Line
	5550 4400 6600 4400
Wire Wire Line
	2200 1000 2200 1850
Wire Wire Line
	4300 2250 5450 2250
Wire Wire Line
	5450 2250 5450 4050
Wire Wire Line
	5450 4050 7450 4050
Wire Wire Line
	7450 4050 7450 4400
Wire Wire Line
	2500 2850 1500 2850
Wire Wire Line
	1500 2850 1500 5400
Wire Wire Line
	1500 5400 1850 5400
Wire Wire Line
	2500 2750 1600 2750
Wire Wire Line
	1600 2750 1600 4800
Wire Wire Line
	1600 4800 4950 4800
Wire Wire Line
	4950 4800 4950 5400
Wire Wire Line
	4950 5400 4650 5400
Wire Wire Line
	2500 2650 1400 2650
Wire Wire Line
	1400 2650 1400 5300
Wire Wire Line
	1400 5300 1850 5300
Wire Wire Line
	2500 2550 1300 2550
Wire Wire Line
	1300 2550 1300 5900
Wire Wire Line
	1300 5900 1850 5900
Wire Wire Line
	4300 1650 4450 1650
Wire Wire Line
	4450 1650 4450 4700
Wire Wire Line
	4450 4700 1200 4700
Wire Wire Line
	1200 4700 1200 5800
Wire Wire Line
	1200 5800 1850 5800
$Comp
L power:+3V0 #PWR?
U 1 1 6156DBD9
P 4550 1500
F 0 "#PWR?" H 4550 1350 50  0001 C CNN
F 1 "+3V0" H 4565 1673 50  0000 C CNN
F 2 "" H 4550 1500 50  0001 C CNN
F 3 "" H 4550 1500 50  0001 C CNN
	1    4550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2450 4550 2450
Wire Wire Line
	4550 2450 4550 1500
$EndSCHEMATC
