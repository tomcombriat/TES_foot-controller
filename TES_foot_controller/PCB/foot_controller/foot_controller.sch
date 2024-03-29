EESchema Schematic File Version 4
LIBS:foot_controller-cache
EELAYER 26 0
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
L bluepill_breakouts:BluePill_STM32F103C U2
U 1 1 5CA9E5CB
P 5150 3950
F 0 "U2" H 5175 2478 50  0000 C CNN
F 1 "BluePill_STM32F103C" H 5175 2387 50  0000 C CNN
F 2 "BluePill_breakouts:BluePill_STM32F103C" H 5200 2350 50  0001 C CNN
F 3 "www.rogerclark.net" H 5150 2450 50  0001 C CNN
	1    5150 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CA9E944
P 3450 4100
F 0 "#PWR0101" H 3450 3850 50  0001 C CNN
F 1 "GND" H 3455 3927 50  0000 C CNN
F 2 "" H 3450 4100 50  0001 C CNN
F 3 "" H 3450 4100 50  0001 C CNN
	1    3450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4100 3450 4100
Wire Wire Line
	3600 3750 3600 4100
Wire Wire Line
	3600 4100 3600 5150
Wire Wire Line
	3600 5150 3850 5150
Connection ~ 3600 4100
Wire Wire Line
	3700 3650 3700 3700
Wire Wire Line
	3700 3950 4300 3950
Wire Wire Line
	3600 3050 6050 3050
Wire Wire Line
	6050 3050 6050 3200
$Comp
L Diode:1N914 D1
U 1 1 5CA9EB2C
P 1300 3800
F 0 "D1" V 1254 3879 50  0000 L CNN
F 1 "1N914" V 1345 3879 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 1300 3625 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85622/1n914.pdf" H 1300 3800 50  0001 C CNN
	1    1300 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 3850 1450 3950
Wire Wire Line
	1450 3950 1300 3950
Wire Wire Line
	1300 3650 1000 3650
$Comp
L Device:R R1
U 1 1 5CA9F0A3
P 850 3650
F 0 "R1" V 643 3650 50  0000 C CNN
F 1 "220" V 734 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 780 3650 50  0001 C CNN
F 3 "~" H 850 3650 50  0001 C CNN
	1    850  3650
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP1
U 1 1 5CA9F164
P 700 3650
F 0 "TP1" V 895 3724 50  0000 C CNN
F 1 "MIn 4" V 804 3724 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 900 3650 50  0001 C CNN
F 3 "~" H 900 3650 50  0001 C CNN
	1    700  3650
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP3
U 1 1 5CA9F1FD
P 1300 3950
F 0 "TP3" V 1495 4024 50  0000 C CNN
F 1 "Min 5" V 1404 4024 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 1500 3950 50  0001 C CNN
F 3 "~" H 1500 3950 50  0001 C CNN
	1    1300 3950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CA9F2D0
P 2700 4750
F 0 "R2" H 2770 4796 50  0000 L CNN
F 1 "22" H 2770 4705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2630 4750 50  0001 C CNN
F 3 "~" H 2700 4750 50  0001 C CNN
	1    2700 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3850 3850 3850
Wire Wire Line
	3850 3850 3850 4600
Wire Wire Line
	3850 4600 3050 4600
$Comp
L Connector:TestPoint TP2
U 1 1 5CA9F524
P 2700 5150
F 0 "TP2" H 2642 5177 50  0000 R CNN
F 1 "Mout 5" H 2642 5268 50  0000 R CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 2900 5150 50  0001 C CNN
F 3 "~" H 2900 5150 50  0001 C CNN
	1    2700 5150
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5CA9F661
P 3900 4950
F 0 "R5" V 3693 4950 50  0000 C CNN
F 1 "33" V 3784 4950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3830 4950 50  0001 C CNN
F 3 "~" H 3900 4950 50  0001 C CNN
	1    3900 4950
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CA9F824
P 3050 4750
F 0 "R3" H 3120 4796 50  0000 L CNN
F 1 "22" H 3120 4705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2980 4750 50  0001 C CNN
F 3 "~" H 3050 4750 50  0001 C CNN
	1    3050 4750
	1    0    0    -1  
$EndComp
Connection ~ 3050 4600
Wire Wire Line
	3050 4600 2700 4600
Wire Wire Line
	3050 4900 2700 4900
Wire Wire Line
	2700 5150 2700 4900
Connection ~ 2700 4900
Wire Wire Line
	4300 4950 4050 4950
Wire Wire Line
	3750 4950 3400 4950
$Comp
L Connector:TestPoint TP4
U 1 1 5CAA00B5
P 3400 4950
F 0 "TP4" H 3342 4977 50  0000 R CNN
F 1 "Mout 4" H 3342 5068 50  0000 R CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 3600 4950 50  0001 C CNN
F 3 "~" H 3600 4950 50  0001 C CNN
	1    3400 4950
	-1   0    0    1   
$EndComp
$Comp
L Connector:TestPoint TP5
U 1 1 5CAA025B
P 3850 5150
F 0 "TP5" H 3792 5177 50  0000 R CNN
F 1 "Mout 2" H 3792 5268 50  0000 R CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4050 5150 50  0001 C CNN
F 3 "~" H 4050 5150 50  0001 C CNN
	1    3850 5150
	-1   0    0    1   
$EndComp
Connection ~ 3850 5150
Wire Wire Line
	3850 5150 4250 5150
$Comp
L Connector:TestPoint TP11
U 1 1 5CAA03C6
P 7200 3450
F 0 "TP11" V 7154 3638 50  0000 L CNN
F 1 "5V" V 7245 3638 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 7400 3450 50  0001 C CNN
F 3 "~" H 7400 3450 50  0001 C CNN
	1    7200 3450
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP12
U 1 1 5CAA049D
P 7200 3650
F 0 "TP12" V 7154 3837 50  0000 L CNN
F 1 "GND" V 7245 3837 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 7400 3650 50  0001 C CNN
F 3 "~" H 7400 3650 50  0001 C CNN
	1    7200 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 3450 6950 3450
Wire Wire Line
	6300 3650 6300 3350
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5CAA0D75
P 7250 4250
F 0 "J1" H 7278 4226 50  0000 L CNN
F 1 "prog" H 7278 4135 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7250 4250 50  0001 C CNN
F 3 "~" H 7250 4250 50  0001 C CNN
	1    7250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3450 6950 4150
Wire Wire Line
	6950 4150 7050 4150
Connection ~ 6950 3450
Wire Wire Line
	6950 3450 7200 3450
Wire Wire Line
	6850 3650 6850 4250
Wire Wire Line
	6850 4250 7050 4250
Connection ~ 6850 3650
Wire Wire Line
	6850 3650 6300 3650
Wire Wire Line
	6050 4550 6150 4550
Wire Wire Line
	6150 4550 6150 4350
Wire Wire Line
	6150 4350 7050 4350
Wire Wire Line
	7050 4450 6250 4450
Wire Wire Line
	6250 4450 6250 4650
Wire Wire Line
	6250 4650 6050 4650
Wire Wire Line
	4300 5050 4300 5150
Connection ~ 4300 5150
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5CAA2CDE
P 7250 4850
F 0 "J2" H 7277 4826 50  0000 L CNN
F 1 "Conn_01x04_Female" H 7277 4735 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7250 4850 50  0001 C CNN
F 3 "~" H 7250 4850 50  0001 C CNN
	1    7250 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3200 7750 3200
Wire Wire Line
	7750 3200 7750 4650
Wire Wire Line
	7750 4650 7000 4650
Wire Wire Line
	7000 4650 7000 4750
Wire Wire Line
	7000 4750 7050 4750
Connection ~ 6050 3200
Wire Wire Line
	6050 3200 6050 3250
Wire Wire Line
	7050 4850 6850 4850
Wire Wire Line
	6850 4850 6850 4250
Connection ~ 6850 4250
Wire Wire Line
	7050 4950 6400 4950
Wire Wire Line
	6400 4950 6400 3850
Wire Wire Line
	6400 3850 6050 3850
Wire Wire Line
	6050 3750 6500 3750
Wire Wire Line
	6500 3750 6500 5050
Wire Wire Line
	6500 5050 7050 5050
$Comp
L Connector:TestPoint TP6
U 1 1 5CAA53D7
P 4150 4150
F 0 "TP6" V 4345 4224 50  0000 C CNN
F 1 "1" V 4254 4224 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4350 4150 50  0001 C CNN
F 3 "~" H 4350 4150 50  0001 C CNN
	1    4150 4150
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP9
U 1 1 5CAA566E
P 4050 4250
F 0 "TP9" V 4245 4324 50  0000 C CNN
F 1 "2" V 4154 4324 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4250 4250 50  0001 C CNN
F 3 "~" H 4250 4250 50  0001 C CNN
	1    4050 4250
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP7
U 1 1 5CAA571F
P 4150 4350
F 0 "TP7" V 4345 4424 50  0000 C CNN
F 1 "3" V 4254 4424 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4350 4350 50  0001 C CNN
F 3 "~" H 4350 4350 50  0001 C CNN
	1    4150 4350
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP10
U 1 1 5CAA57D2
P 4250 4450
F 0 "TP10" V 4445 4524 50  0000 C CNN
F 1 "up" V 4354 4524 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4450 4450 50  0001 C CNN
F 3 "~" H 4450 4450 50  0001 C CNN
	1    4250 4450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP8
U 1 1 5CAA589E
P 4050 4550
F 0 "TP8" V 4245 4624 50  0000 C CNN
F 1 "dwn" V 4154 4624 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.2mm_L11.3mm_W3.0mm_Flat" H 4250 4550 50  0001 C CNN
F 3 "~" H 4250 4550 50  0001 C CNN
	1    4050 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4150 4150 4300 4150
Wire Wire Line
	4300 4350 4150 4350
Wire Wire Line
	4300 4450 4250 4450
NoConn ~ 6050 3550
NoConn ~ 6050 3650
NoConn ~ 6050 3950
NoConn ~ 6050 4050
NoConn ~ 6050 4150
NoConn ~ 6050 4250
NoConn ~ 6050 4350
NoConn ~ 6050 4450
NoConn ~ 6050 4750
NoConn ~ 6050 4850
NoConn ~ 6050 4950
NoConn ~ 6050 5050
NoConn ~ 6050 5150
NoConn ~ 4300 4850
NoConn ~ 4300 4750
NoConn ~ 4300 4650
NoConn ~ 4300 4050
NoConn ~ 4300 3750
NoConn ~ 4300 3650
NoConn ~ 4300 3550
NoConn ~ 4300 3450
NoConn ~ 4300 3350
NoConn ~ 4300 3250
Wire Wire Line
	6050 3350 6300 3350
NoConn ~ 5200 2050
NoConn ~ 5100 2050
Wire Wire Line
	4050 4550 4300 4550
Wire Wire Line
	4050 4250 4300 4250
Wire Wire Line
	7200 3650 7200 4000
Wire Wire Line
	7200 4000 8150 4000
Wire Wire Line
	8150 4000 8150 5700
Wire Wire Line
	8150 5700 4250 5700
Wire Wire Line
	4250 5700 4250 5150
Connection ~ 7200 3650
Connection ~ 4250 5150
Wire Wire Line
	4250 5150 4300 5150
Wire Wire Line
	7050 3650 7200 3650
Wire Wire Line
	6850 3650 7200 3650
Connection ~ 1300 3950
Connection ~ 1300 3650
Wire Wire Line
	3600 3050 3600 3300
$Comp
L Device:R R4
U 1 1 5CDC63CC
P 3750 3450
F 0 "R4" V 3543 3450 50  0000 C CNN
F 1 "220" V 3634 3450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3680 3450 50  0001 C CNN
F 3 "~" H 3750 3450 50  0001 C CNN
	1    3750 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 3300 3600 3300
Connection ~ 3600 3300
Wire Wire Line
	3600 3300 3600 3550
Wire Wire Line
	3750 3600 3750 3700
Wire Wire Line
	3750 3700 3700 3700
Connection ~ 3700 3700
Wire Wire Line
	3700 3700 3700 3950
$Comp
L PC900:PC900 U3
U 1 1 5CDCCCEB
P 2650 3650
F 0 "U3" H 2650 4115 50  0000 C CNN
F 1 "PC900" H 2650 4024 50  0000 C CNN
F 2 "PC900:PC900" H 2650 3650 50  0001 C CNN
F 3 "DOCUMENTATION" H 2650 3650 50  0001 C CNN
	1    2650 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3750 3450 3750
Wire Wire Line
	3450 3750 3450 3650
Wire Wire Line
	3450 3650 3400 3650
Wire Wire Line
	3600 3550 3400 3550
Wire Wire Line
	3500 3650 3500 3850
Wire Wire Line
	3500 3850 3400 3850
Wire Wire Line
	3400 3850 3400 3750
Wire Wire Line
	3500 3650 3700 3650
Wire Wire Line
	1700 3650 1700 3550
Wire Wire Line
	1700 3550 1900 3550
Wire Wire Line
	1300 3650 1700 3650
Wire Wire Line
	1450 3850 1800 3850
Wire Wire Line
	1800 3850 1800 3650
Wire Wire Line
	1800 3650 1900 3650
NoConn ~ 1900 3750
$EndSCHEMATC
