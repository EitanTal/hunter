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
F 2 "parts:CC1101RGPR" H 3250 5540 60  0001 C CNN
F 3 "" H 1850 5300 60  0000 C CNN
F 4 "C29953" H 1850 5300 50  0001 C CNN "LCSC"
	1    1850 5300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW1
U 1 1 61519882
P 7100 1150
F 0 "SW1" H 7100 1435 50  0000 C CNN
F 1 "SW_Light" H 7100 1344 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 7100 1350 50  0001 C CNN
F 3 "~" H 7100 1350 50  0001 C CNN
F 4 "C271750" H 7100 1150 50  0001 C CNN "LCSC"
	1    7100 1150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW2
U 1 1 6151A26D
P 6600 1600
F 0 "SW2" H 6600 1885 50  0000 C CNN
F 1 "SW_LightUp" H 6600 1794 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 6600 1800 50  0001 C CNN
F 3 "~" H 6600 1800 50  0001 C CNN
F 4 "C271750" H 6600 1600 50  0001 C CNN "LCSC"
	1    6600 1600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW3
U 1 1 6151AB9D
P 7650 1550
F 0 "SW3" H 7650 1835 50  0000 C CNN
F 1 "SW_LightDown" H 7650 1744 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 7650 1750 50  0001 C CNN
F 3 "~" H 7650 1750 50  0001 C CNN
F 4 "C271750" H 7650 1550 50  0001 C CNN "LCSC"
	1    7650 1550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW4
U 1 1 6151B5C8
P 7050 3350
F 0 "SW4" H 7050 3635 50  0000 C CNN
F 1 "SW_Fan" H 7050 3544 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 7050 3550 50  0001 C CNN
F 3 "~" H 7050 3550 50  0001 C CNN
F 4 "C271750" H 7050 3350 50  0001 C CNN "LCSC"
	1    7050 3350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW5
U 1 1 6151C131
P 6600 3750
F 0 "SW5" H 6600 4035 50  0000 C CNN
F 1 "SW_FanUp" H 6600 3944 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 6600 3950 50  0001 C CNN
F 3 "~" H 6600 3950 50  0001 C CNN
F 4 "C271750" H 6600 3750 50  0001 C CNN "LCSC"
	1    6600 3750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW6
U 1 1 6151D401
P 7600 3750
F 0 "SW6" H 7600 4035 50  0000 C CNN
F 1 "SW_FanDown" H 7600 3944 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-100xP" H 7600 3950 50  0001 C CNN
F 3 "~" H 7600 3950 50  0001 C CNN
F 4 "C271750" H 7600 3750 50  0001 C CNN "LCSC"
	1    7600 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 615222B5
P 800 7400
F 0 "#PWR0101" H 800 7150 50  0001 C CNN
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
Wire Wire Line
	2000 800  5950 800 
Wire Wire Line
	1900 700  6050 700 
$Comp
L power:GND #PWR0102
U 1 1 61535B0C
P 6800 1600
F 0 "#PWR0102" H 6800 1350 50  0001 C CNN
F 1 "GND" H 6805 1427 50  0000 C CNN
F 2 "" H 6800 1600 50  0001 C CNN
F 3 "" H 6800 1600 50  0001 C CNN
	1    6800 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 61536017
P 7300 1150
F 0 "#PWR0103" H 7300 900 50  0001 C CNN
F 1 "GND" H 7305 977 50  0000 C CNN
F 2 "" H 7300 1150 50  0001 C CNN
F 3 "" H 7300 1150 50  0001 C CNN
	1    7300 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 6153682C
P 7850 1550
F 0 "#PWR0104" H 7850 1300 50  0001 C CNN
F 1 "GND" H 7855 1377 50  0000 C CNN
F 2 "" H 7850 1550 50  0001 C CNN
F 3 "" H 7850 1550 50  0001 C CNN
	1    7850 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 61537254
P 7800 3750
F 0 "#PWR0105" H 7800 3500 50  0001 C CNN
F 1 "GND" H 7805 3577 50  0000 C CNN
F 2 "" H 7800 3750 50  0001 C CNN
F 3 "" H 7800 3750 50  0001 C CNN
	1    7800 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 6153769A
P 7250 3350
F 0 "#PWR0106" H 7250 3100 50  0001 C CNN
F 1 "GND" H 7255 3177 50  0000 C CNN
F 2 "" H 7250 3350 50  0001 C CNN
F 3 "" H 7250 3350 50  0001 C CNN
	1    7250 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 61537DED
P 6800 3750
F 0 "#PWR0107" H 6800 3500 50  0001 C CNN
F 1 "GND" H 6805 3577 50  0000 C CNN
F 2 "" H 6800 3750 50  0001 C CNN
F 3 "" H 6800 3750 50  0001 C CNN
	1    6800 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1550 7450 1550
$Comp
L power:GND #PWR0108
U 1 1 6153CDA6
P 2500 3050
F 0 "#PWR0108" H 2500 2800 50  0001 C CNN
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
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1350 1650 50  0001 C CNN
F 3 "~" H 1350 1650 50  0001 C CNN
	1    1350 1650
	-1   0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR0109
U 1 1 61551E0B
P 1650 1350
F 0 "#PWR0109" H 1650 1200 50  0001 C CNN
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
L power:GND #PWR0110
U 1 1 61557D91
P 1650 2000
F 0 "#PWR0110" H 1650 1750 50  0001 C CNN
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
L power:+3V0 #PWR0111
U 1 1 6156DBD9
P 4550 1500
F 0 "#PWR0111" H 4550 1350 50  0001 C CNN
F 1 "+3V0" H 4565 1673 50  0000 C CNN
F 2 "" H 4550 1500 50  0001 C CNN
F 3 "" H 4550 1500 50  0001 C CNN
	1    4550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2450 4550 2450
$Comp
L power:GND #PWR0112
U 1 1 6153AC58
P 800 6000
F 0 "#PWR0112" H 800 5750 50  0001 C CNN
F 1 "GND" H 805 5827 50  0000 C CNN
F 2 "" H 800 6000 50  0001 C CNN
F 3 "" H 800 6000 50  0001 C CNN
	1    800  6000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C51
U 1 1 6153B52F
P 800 5850
F 0 "C51" H 915 5896 50  0000 L CNN
F 1 "100nF" H 915 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 838 5700 50  0001 C CNN
F 3 "~" H 800 5850 50  0001 C CNN
F 4 "C129131" H 800 5850 50  0001 C CNN "LCSC"
	1    800  5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C81
U 1 1 6153B8E3
P 1650 7200
F 0 "C81" H 1765 7246 50  0000 L CNN
F 1 "27pF" H 1765 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1688 7050 50  0001 C CNN
F 3 "~" H 1650 7200 50  0001 C CNN
F 4 "C1656" H 1650 7200 50  0001 C CNN "LCSC"
	1    1650 7200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C101
U 1 1 6153C5FD
P 2050 7200
F 0 "C101" H 2165 7246 50  0000 L CNN
F 1 "27pF" H 2165 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2088 7050 50  0001 C CNN
F 3 "~" H 2050 7200 50  0001 C CNN
F 4 "C1656" H 2050 7200 50  0001 C CNN "LCSC"
	1    2050 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal_GND24 Y1
U 1 1 6153D000
P 1850 6900
F 0 "Y1" H 1850 7168 50  0000 C CNN
F 1 "25MHz" H 1850 7077 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 1850 6900 50  0001 C CNN
F 3 "~" H 1850 6900 50  0001 C CNN
F 4 "C90913" H 1850 6900 50  0001 C CNN "LCSC"
	1    1850 6900
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 6153F5DB
P 1650 7350
F 0 "#PWR0113" H 1650 7100 50  0001 C CNN
F 1 "GND" H 1655 7177 50  0000 C CNN
F 2 "" H 1650 7350 50  0001 C CNN
F 3 "" H 1650 7350 50  0001 C CNN
	1    1650 7350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 6153FE04
P 2050 7350
F 0 "#PWR0114" H 2050 7100 50  0001 C CNN
F 1 "GND" H 2055 7177 50  0000 C CNN
F 2 "" H 2050 7350 50  0001 C CNN
F 3 "" H 2050 7350 50  0001 C CNN
	1    2050 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 6200 1850 6450
Wire Wire Line
	1850 6450 2050 6450
Wire Wire Line
	2050 6450 2050 6900
Wire Wire Line
	2000 6900 2050 6900
Connection ~ 2050 6900
Wire Wire Line
	2050 6900 2050 7050
Wire Wire Line
	1850 6000 1650 6000
Wire Wire Line
	1650 6000 1650 6900
Wire Wire Line
	1700 6900 1650 6900
Connection ~ 1650 6900
Wire Wire Line
	1650 6900 1650 7050
Wire Wire Line
	1850 5700 800  5700
$Comp
L power:+3V0 #PWR0115
U 1 1 6154F75E
P 800 4800
F 0 "#PWR0115" H 800 4650 50  0001 C CNN
F 1 "+3V0" H 815 4973 50  0000 C CNN
F 2 "" H 800 4800 50  0001 C CNN
F 3 "" H 800 4800 50  0001 C CNN
	1    800  4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5600 1100 5600
Wire Wire Line
	800  5600 800  4800
$Comp
L power:+3V0 #PWR0116
U 1 1 61552DBE
P 5050 4700
F 0 "#PWR0116" H 5050 4550 50  0001 C CNN
F 1 "+3V0" H 5065 4873 50  0000 C CNN
F 2 "" H 5050 4700 50  0001 C CNN
F 3 "" H 5050 4700 50  0001 C CNN
	1    5050 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5900 5050 5900
Wire Wire Line
	5050 5900 5050 5600
Wire Wire Line
	4650 6000 5050 6000
Wire Wire Line
	5050 6000 5050 5900
Connection ~ 5050 5900
Wire Wire Line
	1850 6100 1100 6100
Wire Wire Line
	1100 6100 1100 5600
Connection ~ 1100 5600
Wire Wire Line
	1100 5600 800  5600
Wire Wire Line
	4650 6300 5050 6300
Wire Wire Line
	5050 6300 5050 6000
Connection ~ 5050 6000
$Comp
L power:GND #PWR0117
U 1 1 6155DCD9
P 5150 6400
F 0 "#PWR0117" H 5150 6150 50  0001 C CNN
F 1 "GND" H 5155 6227 50  0000 C CNN
F 2 "" H 5150 6400 50  0001 C CNN
F 3 "" H 5150 6400 50  0001 C CNN
	1    5150 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5500 5150 5500
Wire Wire Line
	4650 5800 5150 5800
Connection ~ 5150 5800
Wire Wire Line
	5150 5800 5150 6400
Wire Wire Line
	4650 5300 5150 5300
Wire Wire Line
	5150 5300 5150 5500
Connection ~ 5150 5500
Wire Wire Line
	5150 5500 5150 5700
$Comp
L Device:C C131
U 1 1 61567E30
P 6850 5150
F 0 "C131" H 6965 5196 50  0000 L CNN
F 1 "6.8pF" H 6965 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6888 5000 50  0001 C CNN
F 3 "~" H 6850 5150 50  0001 C CNN
F 4 "C1679" H 6850 5150 50  0001 C CNN "LCSC"
	1    6850 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C121
U 1 1 61568A5D
P 7400 5700
F 0 "C121" V 7652 5700 50  0000 C CNN
F 1 "6.8pF" V 7561 5700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7438 5550 50  0001 C CNN
F 3 "~" H 7400 5700 50  0001 C CNN
F 4 "C1679" V 7400 5700 50  0001 C CNN "LCSC"
	1    7400 5700
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L131
U 1 1 6156979A
P 7400 5300
F 0 "L131" V 7590 5300 50  0000 C CNN
F 1 "33nH" V 7499 5300 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 7400 5300 50  0001 C CNN
F 3 "~" H 7400 5300 50  0001 C CNN
F 4 "C142201" V 7400 5300 50  0001 C CNN "LCSC"
	1    7400 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L121
U 1 1 6156A545
P 6850 5850
F 0 "L121" H 6903 5896 50  0000 L CNN
F 1 "33nH" H 6903 5805 50  0000 L CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 6850 5850 50  0001 C CNN
F 3 "~" H 6850 5850 50  0001 C CNN
F 4 "C142201" H 6850 5850 50  0001 C CNN "LCSC"
	1    6850 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:L L122
U 1 1 6156B0EF
P 7850 5500
F 0 "L122" V 8040 5500 50  0000 C CNN
F 1 "18nH" V 7949 5500 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 7850 5500 50  0001 C CNN
F 3 "~" H 7850 5500 50  0001 C CNN
F 4 "C48590" V 7850 5500 50  0001 C CNN "LCSC"
	1    7850 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 5500 7700 5700
Wire Wire Line
	7700 5700 7550 5700
Connection ~ 7700 5500
Wire Wire Line
	4650 6100 5700 6100
Wire Wire Line
	4650 6200 5800 6200
Wire Wire Line
	5800 6200 5800 5700
Wire Wire Line
	5800 5700 6850 5700
$Comp
L Device:C C124
U 1 1 615830CD
P 6850 6150
F 0 "C124" H 6965 6196 50  0000 L CNN
F 1 "220pF" H 6965 6105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6888 6000 50  0001 C CNN
F 3 "~" H 6850 6150 50  0001 C CNN
F 4 "C1603" H 6850 6150 50  0001 C CNN "LCSC"
	1    6850 6150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C122
U 1 1 61583C31
P 8150 5650
F 0 "C122" H 8265 5696 50  0000 L CNN
F 1 "12pF" H 8265 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8188 5500 50  0001 C CNN
F 3 "~" H 8150 5650 50  0001 C CNN
F 4 "C38523" H 8150 5650 50  0001 C CNN "LCSC"
	1    8150 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:L L123
U 1 1 615848B3
P 8450 5500
F 0 "L123" V 8640 5500 50  0000 C CNN
F 1 "33nH" V 8549 5500 50  0000 C CNN
F 2 "Inductor_SMD:L_0402_1005Metric" H 8450 5500 50  0001 C CNN
F 3 "~" H 8450 5500 50  0001 C CNN
F 4 "C142201" V 8450 5500 50  0001 C CNN "LCSC"
	1    8450 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8150 5500 8300 5500
Wire Wire Line
	8150 5500 8000 5500
Connection ~ 8150 5500
Wire Wire Line
	5700 5300 6850 5300
Wire Wire Line
	5700 5300 5700 6100
Wire Wire Line
	7550 5300 7700 5300
Wire Wire Line
	7700 5300 7700 5500
$Comp
L Device:C C123
U 1 1 615B09E5
P 8700 5650
F 0 "C123" H 8815 5696 50  0000 L CNN
F 1 "6.8pF" H 8815 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8738 5500 50  0001 C CNN
F 3 "~" H 8700 5650 50  0001 C CNN
F 4 "C1679" H 8700 5650 50  0001 C CNN "LCSC"
	1    8700 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C125
U 1 1 615B1312
P 9150 5500
F 0 "C125" V 8898 5500 50  0000 C CNN
F 1 "220pF" V 8989 5500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9188 5350 50  0001 C CNN
F 3 "~" H 9150 5500 50  0001 C CNN
F 4 "C1603" V 9150 5500 50  0001 C CNN "LCSC"
	1    9150 5500
	0    1    1    0   
$EndComp
Wire Wire Line
	8600 5500 8700 5500
Connection ~ 8700 5500
$Comp
L Device:Antenna AE1
U 1 1 615B9901
P 9500 5300
F 0 "AE1" H 9580 5289 50  0000 L CNN
F 1 "Antenna" H 9580 5198 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9500 5300 50  0001 C CNN
F 3 "~" H 9500 5300 50  0001 C CNN
	1    9500 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5500 9500 5500
$Comp
L power:GND #PWR0118
U 1 1 615BE160
P 6850 6300
F 0 "#PWR0118" H 6850 6050 50  0001 C CNN
F 1 "GND" H 6855 6127 50  0000 C CNN
F 2 "" H 6850 6300 50  0001 C CNN
F 3 "" H 6850 6300 50  0001 C CNN
	1    6850 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 615BEA95
P 8150 5800
F 0 "#PWR0119" H 8150 5550 50  0001 C CNN
F 1 "GND" H 8155 5627 50  0000 C CNN
F 2 "" H 8150 5800 50  0001 C CNN
F 3 "" H 8150 5800 50  0001 C CNN
	1    8150 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 615BF277
P 8700 5800
F 0 "#PWR0120" H 8700 5550 50  0001 C CNN
F 1 "GND" H 8705 5627 50  0000 C CNN
F 2 "" H 8700 5800 50  0001 C CNN
F 3 "" H 8700 5800 50  0001 C CNN
	1    8700 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 615BFB2A
P 6850 5000
F 0 "#PWR0121" H 6850 4750 50  0001 C CNN
F 1 "GND" H 6855 4827 50  0000 C CNN
F 2 "" H 6850 5000 50  0001 C CNN
F 3 "" H 6850 5000 50  0001 C CNN
	1    6850 5000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R171
U 1 1 615C9A78
P 4800 5700
F 0 "R171" V 4593 5700 50  0000 C CNN
F 1 "56k" V 4684 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4730 5700 50  0001 C CNN
F 3 "~" H 4800 5700 50  0001 C CNN
F 4 "C23206" V 4800 5700 50  0001 C CNN "LCSC"
	1    4800 5700
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 5600 5050 5600
Connection ~ 5050 5600
Wire Wire Line
	5050 5600 5050 4700
Wire Wire Line
	4950 5700 5150 5700
Connection ~ 5150 5700
Wire Wire Line
	5150 5700 5150 5800
$Comp
L power:GND #PWR0122
U 1 1 615D3738
P 3000 7350
F 0 "#PWR0122" H 3000 7100 50  0001 C CNN
F 1 "GND" H 3005 7177 50  0000 C CNN
F 2 "" H 3000 7350 50  0001 C CNN
F 3 "" H 3000 7350 50  0001 C CNN
	1    3000 7350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR0123
U 1 1 615D48DE
P 3000 7050
F 0 "#PWR0123" H 3000 6900 50  0001 C CNN
F 1 "+3V0" H 3015 7223 50  0000 C CNN
F 2 "" H 3000 7050 50  0001 C CNN
F 3 "" H 3000 7050 50  0001 C CNN
	1    3000 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5500 9000 5500
Connection ~ 6850 5300
Wire Wire Line
	6850 5300 7250 5300
Connection ~ 6850 5700
Wire Wire Line
	6850 5700 7250 5700
Wire Wire Line
	7450 2250 7450 2600
Connection ~ 7000 2600
Wire Wire Line
	7000 2600 7150 2600
Wire Wire Line
	7000 2600 7000 2650
Wire Wire Line
	6900 2600 7000 2600
$Comp
L power:GND #PWR0124
U 1 1 6155BCBA
P 7000 2650
F 0 "#PWR0124" H 7000 2400 50  0001 C CNN
F 1 "GND" H 7005 2477 50  0000 C CNN
F 2 "" H 7000 2650 50  0001 C CNN
F 3 "" H 7000 2650 50  0001 C CNN
	1    7000 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 615187D4
P 6750 2600
F 0 "D2" V 6789 2482 50  0000 R CNN
F 1 "LED2" V 6698 2482 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6750 2600 50  0001 C CNN
F 3 "~" H 6750 2600 50  0001 C CNN
F 4 "C125103" V 6750 2600 50  0001 C CNN "LCSC"
	1    6750 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D11
U 1 1 615166F6
P 7300 2600
F 0 "D11" V 7339 2482 50  0000 R CNN
F 1 "LED1" V 7248 2482 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 7300 2600 50  0001 C CNN
F 3 "~" H 7300 2600 50  0001 C CNN
F 4 "C125103" V 7300 2600 50  0001 C CNN "LCSC"
	1    7300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2250 7450 2250
Wire Wire Line
	5850 900  5850 1800
Wire Wire Line
	5850 1800 7300 1800
Wire Wire Line
	2100 900  5850 900 
Wire Wire Line
	7300 1550 7300 1800
Wire Wire Line
	4300 2050 5200 2050
Wire Wire Line
	4300 1850 5300 1850
Wire Wire Line
	4300 1750 5400 1750
Wire Wire Line
	5400 1750 5400 3250
Wire Wire Line
	5300 3750 6400 3750
Wire Wire Line
	5300 1850 5300 3750
Wire Wire Line
	5200 3900 7300 3900
Wire Wire Line
	5200 2050 5200 3900
$Comp
L Device:CP C61
U 1 1 61697E60
P 3000 7200
F 0 "C61" H 3118 7246 50  0000 L CNN
F 1 "10uF" H 3118 7155 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-18_Kemet-A" H 3038 7050 50  0001 C CNN
F 3 "~" H 3000 7200 50  0001 C CNN
F 4 "C139596" H 3000 7200 50  0001 C CNN "LCSC"
	1    3000 7200
	1    0    0    -1  
$EndComp
NoConn ~ 1850 5500
$Comp
L ul_STM8L101F3U6TR:STM8L101F3U6TR U2
U 1 1 6151131E
P 2500 1650
F 0 "U2" H 3400 2037 60  0000 C CNN
F 1 "STM8L101F3U6TR" H 3400 1931 60  0000 C CNN
F 2 "parts:STM8L101F3U6TR" H 3400 1890 60  0001 C CNN
F 3 "" H 2500 1650 60  0000 C CNN
F 4 "C111168" H 2500 1650 50  0001 C CNN "LCSC"
	1    2500 1650
	1    0    0    -1  
$EndComp
NoConn ~ 2500 1850
NoConn ~ 2500 1950
Wire Wire Line
	4550 2450 4550 1500
Wire Wire Line
	4300 1950 5500 1950
Wire Wire Line
	5500 1950 5500 2600
Wire Wire Line
	5500 2600 6600 2600
Wire Wire Line
	2000 2450 2500 2450
Wire Wire Line
	2000 800  2000 2450
NoConn ~ 2500 2250
$Comp
L power:+3V0 #VBAT0101
U 1 1 6152F877
P 800 7000
F 0 "#VBAT0101" H 888 7083 50  0001 L CNN
F 1 "+3V0" H 888 7037 50  0000 L CNN
F 2 "" H 800 7000 50  0001 C CNN
F 3 "" H 800 7000 50  0001 C CNN
	1    800  7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1050 7300 1150
Connection ~ 7300 1150
Wire Wire Line
	7850 1450 7850 1550
Connection ~ 7850 1550
Wire Wire Line
	6800 1500 6800 1600
Connection ~ 6800 1600
Wire Wire Line
	7800 3650 7800 3750
Connection ~ 7800 3750
Wire Wire Line
	7250 3350 7250 3250
Connection ~ 7250 3350
Wire Wire Line
	6800 3650 6800 3750
Connection ~ 6800 3750
Wire Wire Line
	2500 2150 2100 2150
Wire Wire Line
	2100 2150 2100 900 
Wire Wire Line
	1900 2350 2500 2350
Wire Wire Line
	1900 700  1900 2350
$Comp
L Mechanical:MountingHole H1
U 1 1 6188D2ED
P 9400 1450
F 0 "H1" H 9500 1496 50  0000 L CNN
F 1 "MountingHole" H 9500 1405 50  0000 L CNN
F 2 "MountingHole:MountingHole_2mm" H 9400 1450 50  0001 C CNN
F 3 "~" H 9400 1450 50  0001 C CNN
	1    9400 1450
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 6188DD66
P 10250 1450
F 0 "H2" H 10350 1496 50  0000 L CNN
F 1 "MountingHole" H 10350 1405 50  0000 L CNN
F 2 "MountingHole:MountingHole_2mm" H 10250 1450 50  0001 C CNN
F 3 "~" H 10250 1450 50  0001 C CNN
	1    10250 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 700  6050 1150
Wire Wire Line
	6050 1150 6900 1150
Wire Wire Line
	5950 800  5950 1500
Wire Wire Line
	5950 1500 6400 1500
Wire Wire Line
	6850 3250 5400 3250
Wire Wire Line
	7300 3650 7400 3650
Wire Wire Line
	7300 3650 7300 3900
$Comp
L power:GND #PWR0125
U 1 1 617EC2A7
P 1850 7100
F 0 "#PWR0125" H 1850 6850 50  0001 C CNN
F 1 "GND" H 1855 6927 50  0000 C CNN
F 2 "" H 1850 7100 50  0001 C CNN
F 3 "" H 1850 7100 50  0001 C CNN
	1    1850 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 617FBC94
P 1850 6700
F 0 "#PWR0126" H 1850 6450 50  0001 C CNN
F 1 "GND" H 1855 6527 50  0000 C CNN
F 2 "" H 1850 6700 50  0001 C CNN
F 3 "" H 1850 6700 50  0001 C CNN
	1    1850 6700
	-1   0    0    1   
$EndComp
$EndSCHEMATC
