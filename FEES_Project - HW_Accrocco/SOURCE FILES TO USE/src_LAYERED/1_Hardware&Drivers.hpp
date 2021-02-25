/***************************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
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
 *												   												   *
 *                  __    __     __     __   __    __  __ __       __    ___                       *
 *                 |_ |  |_ \_/||__)|  |_   |_ \_/|__)|_ |__)||\/||_ |\ | |  /\ |                  *
 *                 |  |__|__/ \||__)|__|__  |__/ \|   |__| \ ||  ||__| \| | /--\|__                *
 *                    __     __  __ __  __  __ __    __   ___ __       ___ __                      *
 *                   |_ |\/||__)|_ |  \|  \|_ |  \  (_  /\ | |_ |  |  | | |_                       *
 *                   |__|  ||__)|__|__/|__/|__|__/  __)/--\| |__|__|__| | |__                      *
 *                                                                                                 *
 *												    											   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
 *											FEES Project			 					           *
 *		    			URL: https://github.com/ferrandi/DEIB-DAER-project		                   *
 *				 					Politecnico di Milano - DEIB                                   *
 *			    						   Stefano Ampolo	    			                       *
 *		 			  ***********************************************************                  *
 *        		 	   		Copyright (c) 2018-2019 Politecnico di Milano				   		   *
 *                                                                                                 *
 *     This file is part of the FEES framework.                                                    *
 *                                                                                                 *
 *     The FEES framework is free software; you can redistribute it and/or modify                  *
 *     it under the terms of the GNU General Public License as published by                        *
 *     the Free Software Foundation; either version 3 of the License, or                           *
 *     (at your option) any later version.                                                         *
 *                                                                                                 *
 *     This program is distributed in the hope that it will be useful,                             *
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of                              *
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                               *
 *     GNU General Public License for more details.                                                *
 *                                                                                                 *
 *     You should have received a copy of the GNU General Public License                           *
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.                       *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 */

//============================================================================
// Name        : 1_Hardware&Drivers.h  - Former GpioMapper.h  - Former PinMap.h
// Author      : Stefano Ampolo
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : this file is needed to link The Schematics to the GPIO system
//
// DA MODIFICARE IL FILE HWDEFINITION di ARDUPILOT.
//============================================================================


#ifdef FREERTOS

#ifndef HARDWAREANDDRIVERS_HPP
#define HARDWAREANDDRIVERS_HPP


#endif // HARDWAREANDDRIVERS_HPP
#endif // FREERTOS



#ifdef BAREMETAL

#ifndef HARDWAREANDDRIVERS_HPP
#define HARDWAREANDDRIVERS_HPP

struct gpio_stm32 {
	char port;
	int number;
};



/*


# USB setup
USB_VENDOR 0x27AC
USB_PRODUCT 0x1152
USB_STRING_MANUFACTURER "Polimi - GPAdvancedProject - Laser Navigation"
USB_STRING_SERIAL  "%SERIAL%"


# only one I2C bus
I2C_ORDER I2C2 I2C1

# order of UARTs (and USB)
UART_ORDER OTG1 USART1 USART3 USART2
STDOUT_SERIAL SD3
STDOUT_BAUDRATE 57600


 PA0  TIM2_CH1 TIM2 PWM(1) 	GPIO(11)
 PA1  TIM2_CH2 TIM2 PWM(2)  GPIO(12)
 PA2  TIM2_CH3 TIM2 PWM(3)  GPIO(13)
 PA3  BUZZER OUTPUT LOW GPIO(32)
 PA4  CS_RADFET CS
 PA5  SPI1_SCK SPI1
 PA6  SPI1_MISO SPI1
 PA7  SPI1_MOSI SPI1
 PA8  PGOOD INPUT
 PA9  VBUS INPUT
 PA10 EX_GPIO_4 OUTPUT LOW GPIO(33)
 PA11 OTG_FS_DM OTG1
 PA12 OTG_FS_DP OTG1
 PA13 JTMS-SWDIO SWD
 PA14 JTCK-SWCLK SWD
#PA15

 PB0  RSBY_KEEP_EN OUTPUT LOW GPIO(4)
 PB1  EX_GPIO1 OUTPUT LOW GPIO(30)
#PB2
#PB3
#PB4
 PB5  WATCHDOG OUTPUT LOW GPIO(20)
 PB6  USART1_TX USART1
 PB7  USART1_RX USART1
 PB8  I2C1_SCL I2C1
 PB9  I2C1_SDA I2C1
 PB10 I2C2_SCL I2C2
 PB11 I2C2_SDA I2C2
 PB12 EX_GPIO2 OUTPUT LOW GPIO(31)
 PB13 SPI2_SCK SPI2
 PB14 SPI2_MISO SPI2
 PB15 SPI2_MOSI SPI2


 #PC0  PSD1_SEL_1 OUTPUT LOW GPIO(8)
 #PC1  PSD1_SEL_0 OUTPUT LOW GPIO(7)

 PC0  BATT_VOLTAGE_SENS ADC1
 PC1  BATT_CURRENT_SENS ADC1

 PC2  PSD2_SEL_1 OUTPUT LOW GPIO(10)
 PC3  PSD2_SEL_0 OUTPUT LOW GPIO(9)
 PC4  PSD1_AMP_CS CS
 PC5  PSD2_AMP_CS CS
 PC6  SDR_SER_TX USART6
 PC7  SDR_SER_RX USART6
 PC8  TIM8_CH3 TIM8 PWM(4)  GPIO(14)
 PC9  EX_SPI_EN CS
 PC10 SPI3_SCK SPI3
 PC11 SPI3_MISO SPI3
 PC12 SPI3_MOSI SPI3
 PC13 UHF_RESET OUTPUT HIGH GPIO(0)
 PC14 RADFET_OWB OUTPUT LOW GPIO(18)
 PC15 RAD_RESET OUTPUT HIGH GPIO(6)

 PD0  SBD_SER_DCD OUTPUT LOW GPIO(21)
 PD1  SBD_SER_DSR OUTPUT LOW GPIO(22)
 PD2  SBD_SER_DTR OUTPUT LOW GPIO(23)
 PD3  SBD_SER_CTS OUTPUT LOW GPIO(24)
 PD4  SBD_SER_RTS OUTPUT LOW GPIO(25)
 PD5  USART2_TX USART2
 PD6  USART2_RX USART2
 PD7  SDB_ON_OFF OUTPUT LOW GPIO(26)
 PD8  USART3_TX USART3
 PD9  USART3_RX USART3
 PD10 CS_EEPROM CS
 PD11 CS_FRAM CS
 PD12 TMTC_MCU_WD OUTPUT LOW GPIO(19)
 *PD13 INT_GYRO
 PD14 CS_GYRO2 CS
 *PD15 INT_GYRO2

 PE0  ANA_PWR_ON OUTPUT LOW GPIO(2)
 PE1  RAD_PWR_ON OUTPUT LOW GPIO(5)
 PE2  GPS_PWR_ON OUTPUT LOW GPIO(1)
 PE3  SBD_PWR_ON OUTPUT LOW GPIO(29)
 PE4  CS_NAND CS
 PE5  LORA_CS CS
 PE6  RASBY_ON OUTPUT LOW GPIO(3)
 PE7  DIR_X_COIL OUTPUT LOW GPIO(15)
 PE8  DIR_Y_COIL OUTPUT LOW GPIO(16)
 PE9  DIR_Z_COIL OUTPUT LOW GPIO(17)
 PE10 CS_GYRO CS
 PE11 EN_ADC1 CS
 PE12 EN_ADC2 CS
 PE13 EN_ADC3 CS
 PE14 SBD_SER_RI OUTPUT LOW GPIO(27)
 PE15 SBD_SER_NET OUTPUT LOW GPIO(28)

*/




// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define		UHF_RESET		0
#define		GPS_PWR_ON		1
#define		ANALOG_PWR_ON	2
#define		RASPY_ON		3
#define		RASPY_KEEP		4
#define		RAD_PWR_ON		5
#define		RAD_RESET		6

#define		PSD_0	7
#define		PSD_1	8
#define		PSD_2	9
#define		PSD_3	10


// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define		PWM_X			PWM(1)
#define		PWM_X_GPIO		11

#define		PWM_Y			PWM(2)
#define		PWM_Y_GPIO		12

#define		PWM_Z			PWM(3)
#define		PWM_Z_GPIO		13

#define	BATTERY_HEATER_PWM		PWM(4)
#define	BATTERY_HEATER_GPIO 	14

#define		DIR_X		15
#define		DIR_Y		16
#define		DIR_Z		17


#define		RADFET_OWB		18

#define		LED		19


#define WATCHDOG	20


// IRIDIUM - SDB (GPIO 60-68)

#define		SDB_0	21		// DCD
#define		SDB_1	22		// DSR
#define		SDB_2	23		// DTR
#define		SDB_3	24		// CTS
#define		SDB_4	25		// RTS
#define		SDB_5	26	// on-off?
#define		SDB_6	27		// RI
#define		SDB_7	28		// NET
#define		SDB_PWR_ON	29  // Iridium Pwr On


#define EX_GPIO_1	30
#define	EX_GPIO_2	31
#define	EX_GPIO_3	32
#define	EX_GPIO_4	33



// POWER "INPUTS"
//	PGOOD -
// 	VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1


// Here Will come the definitions of the sensor drivers.










#endif // HARDWARE&DRIVERS_HPP

#endif // BAREMETAL






#ifdef ARDUPILOT
// Questi dati sono necessari per il porting ad Ardupilot // Ardunaut

#ifndef MAPPER_H
#define MAPPER_H

// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define		UHF_RESET		0
#define		GPS_PWR_ON		1
#define		ANALOG_PWR_ON	2
#define		RASPY_ON		3
#define		RASPY_KEEP		4
#define		RAD_PWR_ON		5
#define		RAD_RESET		6

#define		PSD_0	7
#define		PSD_1	8
#define		PSD_2	9
#define		PSD_3	10


// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define		PWM_X			PWM(1)
#define		PWM_X_GPIO		11

#define		PWM_Y			PWM(2)
#define		PWM_Y_GPIO		12

#define		PWM_Z			PWM(3)
#define		PWM_Z_GPIO		13

#define	BATTERY_HEATER_PWM		PWM(4)
#define	BATTERY_HEATER_GPIO 	14

#define		DIR_X		15
#define		DIR_Y		16
#define		DIR_Z		17


#define		RADFET_OWB		18

#define		LED		19


#define WATCHDOG	20


// IRIDIUM - SDB (GPIO 60-68)

#define		SDB_0	21		// DCD
#define		SDB_1	22		// DSR
#define		SDB_2	23		// DTR
#define		SDB_3	24		// CTS
#define		SDB_4	25		// RTS
#define		SDB_5	26	// on-off?
#define		SDB_6	27		// RI
#define		SDB_7	28		// NET
#define		SDB_PWR_ON	29  // Iridium Pwr On


#define EX_GPIO_1	30
#define	EX_GPIO_2	31
#define	EX_GPIO_3	32
#define	EX_GPIO_4	33



// POWER "INPUTS"
//	PGOOD -
// 	VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1


// Here Will come the definitions of the sensor drivers.






#endif // HARDWAREANDDRIVERS_HPP

#endif // ARDUPILOT



