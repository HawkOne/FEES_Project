/***************************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   *
 *      FFFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS       *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S      *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S      *
 *      FF::::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS      *
 *        F:::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                  *
 *        F:::::F               E:::::E               E:::::E             S:::::S                  *
 *        F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS               *
 * ----   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS     ---- *
 * -::-   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS   -::- *
 * ----   F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S  ---- *
 *        F:::::F               E:::::E               E:::::E                         S:::::S      *
 *        F:::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S      *
 *      FF:::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS       *
 *      FFFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS         *
 *												   *
 *               ____    ___     __      ___    ___    __  ___ __       ___   ___        	   *
 *               |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |    	   *
 *               |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___ 	   *
 *                         ___     __  ___ __  __  ___ __     __     ________         		   *
 *                        |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|     		   *
 *                        |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |     		   *
 *                                                                                       	   *
 *												   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   *
 *												   *
 *					FEES Project 					           *
 *		    URL: https://github.com/ferrandi/DEIB-DAER-project		                   *
 *				 Politecnico di Milano - DEIB                                      *
 *			    Matteo Franceschini  & Stefano Ampolo	                           *
 *		   ***********************************************************                     *
 *             		Copyright (c) 2018-2019 Politecnico di Milano				   *
 *                                                                                                 *
 *   This file is part of the FEES framework.                                                      *
 *                                                                                                 *
 *   The FEES framework is free software; you can redistribute it and/or modify                    *
 *   it under the terms of the GNU General Public License as published by                          *
 *   the Free Software Foundation; either version 3 of the License, or                             *
 *   (at your option) any later version.                                                           *
 *                                                                                                 *
 *   This program is distributed in the hope that it will be useful,                           	   *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of                                *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                 *
 *   GNU General Public License for more details.                                                  *
 *                                                                                                 *
 *   You should have received a copy of the GNU General Public License                             *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.                         *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/**
 * @file  main.cc
 * @brief This is the main file
 * @author STAMP
 * @author 
 * $Revision$
 * $Date$
 * Last modified by STAMP
 *
 *
*/
/* Made by Stamp


/**************************************  Light Sensors   ****************************************/
/************************************************************************************************/

/*************	TSL2561 **********************  Light Sensors   *******(I2C1)****(+x , +y , +z)***/
// +x Address 0x29   
void Light_PlusX(); // issue a command to access the CONTROL register followed by the data value 03h to power up the device.
// +y Address 0x39
void Light_PlusY();
// +z Address 0x49
void Light_PlusZ();


/*************	TSL2561  *************  Light Sensors   ***********(I2C2)****(-x , -y , -z)*******/
// -x Address 0x29
void Light_MinusX();
// -y Address 0x39
void Light_MinusY();
// -z Address 0x49
void Light_MinusZ();
  
  
  /*Basic Operation - LIGHT SENSOR - From datasheet
After applying VDD, the device will initially be in the power-down state.
To operate the device, issue a command to access the CONTROL register followed
 by the data value 03h to power up the device. At this point, both ADC
channels will begin a conversion at the default integration time of 400 ms.
After 400 ms, the conversion results will be available in the DATA0 and DATA1 registers.
Use the following pseudo code to read the data registers:

// Read ADC Channels Using Read Word Protocol − RECOMMENDED
Address = 0x39 //Slave addr – also 0x29 or 0x49

//Address the Ch0 lower data register and configure for Read Word
Command = 0xAC //Set Command bit and Word bit //Reads two bytes from sequential registers 0x0C and 0x0D
//Results are returned in DataLow and DataHigh variables
ReadWord (Address, Command, DataLow, DataHigh)
Channel0 = 256 * DataHigh + DataLow
//Address the Ch1 lower data register and configure for Read Word
Command = 0xAE //Set bit fields 7 and 5
//Reads two bytes from sequential registers 0x0E and 0x0F
//Results are returned in DataLow and DataHigh variables
ReadWord (Address, Command, DataLow, DataHigh)
Channel1 = 256 * DataHigh + DataLow //Shift DataHigh to upper byte
// Read ADC Channels Using Read Byte Protocol
Address = 0x39 //Slave addr − also 0x29 or 0x49
Command = 0x8C //Address the Ch0 lower data register
ReadByte (Address, Command, DataLow) //Result returned in DataLow
Command = 0x8D //Address the Ch0 upper data register
ReadByte (Address, Command, DataHigh) //Result returned in DataHigh
Channel0 = 256 * DataHigh + DataLow //Shift DataHigh to upper byte
Command = 0x8E //Address the Ch1 lower data register
ReadByte (Address, Command, DataLow) //Result returned in DataLow
Command = 0x8F //Address the Ch1 upper data register
ReadByte (Address, Command, DataHigh) //Result returned in DataHigh
Channel1 = 256 * DataHigh + DataLow //Shift DataHigh to upper byte*/

  
  
/********	LM75BIMM 	*************  Temp Sensors  *****(I2C1)******(“1001”)********************/

void Temp_PlusX();    //0b10011001     // PlusX
void Temp_PlusY();    //0b10011101     // PlusY
void Temp_PlusZ();    //0b10011110     // PlusZ
  
void Temp_MinusX();    //0b10011100     // MinusX
void Temp_MinusY();    //0b10011010     // MinusY
void Temp_MinusZ();    //0b10011011     // MinusZ

/* 7.5.2 Temperature Data Format
Temperature data can be read from the Temperature, TOS Set Point, and THYST Set Point registers;
and written to the TOS Set Point, and THYST Set Point registers. Temperature data is represented
by a 9-bit, two's complement word with an LSB (Least Significant Bit) equal to 0.5°C:

						------------------- Digital Output -----------------
						| Temperature  -|-    Binary         -|-     Hex   |
						| 125°C        -|-    0 1111 1010    -|-     0FAh  |
						| 25°C         -|-    0 0011 0010    -|-     032h  |
						| 0.5°C        -|-    0 0000 0001    -|-     001h  |
						| 0°C          -|-    0 0000 0000    -|-     000h  |
						| −0.5°C       -|-    1 1111 1111    -|-     1FFh  |
						| −25°C        -|-    1 1100 1110    -|-     1CEh  |
						| −55°C        -|-    1 1001 0010    -|-     192h  |
						----------------------------------------------------         
  */
  


/*******	UBLOX_NEO-8 	**************  GPS ********* ( UART 1 ) ***********************/
//  Tx PB6  - RX PB7








• PSD S5991-01              			        	SPI 1+CS

• ADC 8Chan 12Bit ADC128S022CIMTX/NOPB				SPI1 +CS	
• ADC 8Chan 12Bit ADC128S022CIMTX/NOPB				SPI1 +CS
• ADC 8Chan 12Bit ADC128S022CIMTX/NOPB		        	SPI1 +CS

• ADC 11Chan High Precision 32bit (RADEX) ADS1263IPW 
Che si interfaccia con STM32 Attraverso TS3A4751PWR    		SPI1 +CS +PowerOn +Reset

• Digital Temperature meter DS18B20U+ (RADEX)			RADFET OWB

• Digital Temp LM75BIMM 					I2C1



ACTUATORS:
• Brush Motor Driver BD6210F-E2 			DirX , PwmX  , IX_Coil(V) (ADC)
• Brush Motor Driver BD6210F-E2 			DirY , PwmY  , IY_Coil(V) (ADC)
• Brush Motor Driver BD6210F-E2 			DirZ , PwmZ  , IZ_Coil(V) (ADC)
  
• Battery Heater 						PWM_Heater (PC8)
Memories:
• EEPROM 2Mbit M95M02-DWMN3TP/K 				SPI3 +CS
• EEPROM 2Mbit M24M02-DWMN3TP/K 				I2C1
• 2M-bit FeRam FM25V20A-G					SPI2 +CS
• 2GB Nand Flash						SPI1 +CS
Payloads:
• Linkit-Lora 							I2C2+SPI2 +Other
• Iridium IRIDIUM_9603				        	Tx-Rx +RTS+CTS+Other
• Raspberry 							Tx-Rx +RaspOn +KeepEn
  
  
/*