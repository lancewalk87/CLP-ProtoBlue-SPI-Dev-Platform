/*
 * main.h
 * ProtoBlue 
 * 
 * Created by Lance T. Walker on 10/6/2018 6:49:55 AM.
 * Copyright © 2018 CodeLife-Productions. All rights reserved.
--------------------------------------------------------------------------------------------
 * AVR: [ATmega644P 20AU]
 * --- Architecture:
 * Instructions = ^131
 * Instructions per second (MIPS) = 20 throughput@20MHz
 * Registers = 32 x 8
 * Cycle Modes = Idle, ADC Noise Reduction, Power-save, Power-down, Standby, Extended Standby 
 * --- Memory:
 * In-System Flash Memory = 64Kb
 * EEPROM = 2Kb
 * SRAM = 4Kb
 * Write/Erase Cycles: = 10000 Flash/100000 EEPROM
 * --- I/O:
 * Counters = Prescaler and Comparator x2
 * PWM Channels	= 6
 * ADC Channels = 10-bit x8
 * General Purpose I/O = 32
 * Total Pins = 44
 * --- Power: 
 * Voltage Range: = 1.8-5.5V
 * Speed@1.8V - 5.5V = 0 - 4MHz 
 * Speed@2.7V - 5.5V = 0 - 10MHz 
 * Speed@4.5V - 5.5V = 0 - 20MHz
 --- Power Consumption @ 1MHz,1.8V, 25°C:
 * Active Mode = 0.4mA
 * Power-down Mode = 0.1?A
 * Power-save Mode = 0.6?A (Including 32kHz RTC)		
--------------------------------------------------------------------------------------------
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "assets/definitions.h"
#include "interface/interface.h"

#endif 