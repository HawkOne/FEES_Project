
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


/*
 * FEESManagementSystem.h
 *
 *  Created on: Aug 27, 2020
 *      Author: stefano
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


#ifndef INC_FEESMANAGEMENTSYSTEM_H_
#define INC_FEESMANAGEMENTSYSTEM_H_



#ifdef FREERTOS

#ifndef HARDWAREANDDRIVERS_HPP
#define HARDWAREANDDRIVERS_HPP

/* Private defines -----------------------------------------------------------*/
#define GPS_PWR_ON_Pin GPIO_PIN_2
#define GPS_PWR_ON_GPIO_Port GPIOE
#define SBD_PWR_ON_Pin GPIO_PIN_3
#define SBD_PWR_ON_GPIO_Port GPIOE
#define CS_NAND_Pin GPIO_PIN_4
#define CS_NAND_GPIO_Port GPIOE
#define LORA_CS_Pin GPIO_PIN_5
#define LORA_CS_GPIO_Port GPIOE
#define RSBY_ON_Pin GPIO_PIN_6
#define RSBY_ON_GPIO_Port GPIOE
#define UHF_RESET_Pin GPIO_PIN_13
#define UHF_RESET_GPIO_Port GPIOC
#define RADFET_OWB_Pin GPIO_PIN_14
#define RADFET_OWB_GPIO_Port GPIOC
#define RAD_RESET_Pin GPIO_PIN_15
#define RAD_RESET_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define PSD1_SEL1_Pin GPIO_PIN_0
#define PSD1_SEL1_GPIO_Port GPIOC
#define PSD1_SEL0_Pin GPIO_PIN_1
#define PSD1_SEL0_GPIO_Port GPIOC
#define PSD2_SEL1_Pin GPIO_PIN_2
#define PSD2_SEL1_GPIO_Port GPIOC
#define PSD2_SEL0_Pin GPIO_PIN_3
#define PSD2_SEL0_GPIO_Port GPIOC
#define PWM_X_COIL_Pin GPIO_PIN_0
#define PWM_X_COIL_GPIO_Port GPIOA
#define PWM_Y_COIL_Pin GPIO_PIN_1
#define PWM_Y_COIL_GPIO_Port GPIOA
#define PWM_Z_COIL_Pin GPIO_PIN_2
#define PWM_Z_COIL_GPIO_Port GPIOA
#define EX_GPIO3_Pin GPIO_PIN_3
#define EX_GPIO3_GPIO_Port GPIOA
#define CS_RADFET_Pin GPIO_PIN_4
#define CS_RADFET_GPIO_Port GPIOA
#define PSD1_AMP_CS_Pin GPIO_PIN_4
#define PSD1_AMP_CS_GPIO_Port GPIOC
#define PSD2_AMP_CS_Pin GPIO_PIN_5
#define PSD2_AMP_CS_GPIO_Port GPIOC
#define RSBY_KEEP_EN_Pin GPIO_PIN_0
#define RSBY_KEEP_EN_GPIO_Port GPIOB
#define EX_GPIO1_Pin GPIO_PIN_1
#define EX_GPIO1_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define DIR_X_COIL_Pin GPIO_PIN_7
#define DIR_X_COIL_GPIO_Port GPIOE
#define DIR_Y_COIL_Pin GPIO_PIN_8
#define DIR_Y_COIL_GPIO_Port GPIOE
#define DIR_Z_COIL_Pin GPIO_PIN_9
#define DIR_Z_COIL_GPIO_Port GPIOE
#define CS_GYRO_Pin GPIO_PIN_10
#define CS_GYRO_GPIO_Port GPIOE
#define EN_ADC1_Pin GPIO_PIN_11
#define EN_ADC1_GPIO_Port GPIOE
#define EN_ADC3_Pin GPIO_PIN_12
#define EN_ADC3_GPIO_Port GPIOE
#define EN_ADC2_Pin GPIO_PIN_13
#define EN_ADC2_GPIO_Port GPIOE
#define SBD_SER_SI_Pin GPIO_PIN_14
#define SBD_SER_SI_GPIO_Port GPIOE
#define SBD_SER_NET_Pin GPIO_PIN_15
#define SBD_SER_NET_GPIO_Port GPIOE
#define EX_GPIO2_Pin GPIO_PIN_12
#define EX_GPIO2_GPIO_Port GPIOB
#define CS_EEPROM_Pin GPIO_PIN_10
#define CS_EEPROM_GPIO_Port GPIOD
#define CS_FRAM_Pin GPIO_PIN_11
#define CS_FRAM_GPIO_Port GPIOD
#define TMTC_MCU_WD_Pin GPIO_PIN_12
#define TMTC_MCU_WD_GPIO_Port GPIOD
#define INT_GYRO_Pin GPIO_PIN_13
#define INT_GYRO_GPIO_Port GPIOD
#define CS_GYRO2_Pin GPIO_PIN_14
#define CS_GYRO2_GPIO_Port GPIOD
#define INT_GYRO2_Pin GPIO_PIN_15
#define INT_GYRO2_GPIO_Port GPIOD
#define PWM_HEATER_Pin GPIO_PIN_8
#define PWM_HEATER_GPIO_Port GPIOC
#define EX_SPI_EN_Pin GPIO_PIN_9
#define EX_SPI_EN_GPIO_Port GPIOC
#define PGOOD_Pin GPIO_PIN_8
#define PGOOD_GPIO_Port GPIOA
#define VBUS_FS_Pin GPIO_PIN_9
#define VBUS_FS_GPIO_Port GPIOA
#define OTG_FS_ID_Pin GPIO_PIN_10
#define OTG_FS_ID_GPIO_Port GPIOA
#define OTG_FS_DM_Pin GPIO_PIN_11
#define OTG_FS_DM_GPIO_Port GPIOA
#define OTG_FS_DP_Pin GPIO_PIN_12
#define OTG_FS_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SBD_SER_DCD_Pin GPIO_PIN_0
#define SBD_SER_DCD_GPIO_Port GPIOD
#define SBD_SER_DSR_Pin GPIO_PIN_1
#define SBD_SER_DSR_GPIO_Port GPIOD
#define SBD_SER_DTR_Pin GPIO_PIN_2
#define SBD_SER_DTR_GPIO_Port GPIOD
#define SBD_ON_OFF_Pin GPIO_PIN_7
#define SBD_ON_OFF_GPIO_Port GPIOD
#define WATCHDOG_Pin GPIO_PIN_5
#define WATCHDOG_GPIO_Port GPIOB
#define ANA_PWR_ON_Pin GPIO_PIN_0
#define ANA_PWR_ON_GPIO_Port GPIOE
#define RAD_PWR_ON_Pin GPIO_PIN_1
#define RAD_PWR_ON_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */


// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI
#define    UHF_RESET    0
#define    GPS_PWR_ON    1
#define    ANA_PWR_ON    2
#define    RSBY_ON      3
#define    RSBY_KEEP_EN  4
#define    RAD_PWR_ON    5
#define    RAD_RESET    6

#define    PSD1_SEL0  7
#define    PSD1_SEL1  8
#define    PSD2_SEL0  9
#define    PSD2_SEL1  10

// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54
#define    PWM_X      PWM(1)
#define    PWM_X_COIL    11

#define    PWM_Y      PWM(2)
#define    PWM_Y_COIL    12

#define    PWM_Z      PWM(3)
#define    PWM_Z_COIL    13

#define    PWM_HEATER    PWM(4)
#define    PWM_HEATER     14

#define    DIR_X_COIL    15
#define    DIR_Y_COIL    16
#define    DIR_Z_COIL    17


#define    RADFET_OWB    18

#define    LED        19
#define    TMTC_MCU_WD    19

#define   WATCHDOG    20


// IRIDIUM - SBD (GPIO 60-68)
#define    SBD_PWR_ON    21  // Iridium Pwr On

#define    SBD_SER_DCD    22    // DCD
#define    SBD_SER_DSR    23    // DSR
#define    SBD_SER_DTR    24    // DTR
#define    SBD_SER_CTS   25    // CTS
#define    SBD_SER_RTS   26    // RTS
#define    SBD_SER_ON_OFF  27    // ON_OFF
#define    SBD_SER_RI    28    // RI
#define    SBD_SER_NET   29    // NET

#define EX_GPIO1  30
#define  EX_GPIO2  31
#define  EX_GPIO3  32
#define  EX_GPIO4  33



// POWER "INPUTS"
//  PGOOD -
//   VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1


// Here Will come the definitions of the sensor drivers.


#endif // HARDWAREANDDRIVERS_HPP
#endif // FREERTOS



#ifdef BAREMETAL

#ifndef HARDWAREANDDRIVERS_HPP
#define HARDWAREANDDRIVERS_HPP

struct gpio_stm32 {
	char port;
	int number;
};


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


/////////////////////  -- FILE2
/*
 *
 * FILE: 2_Threads&Handlers.h  - Former GpiosAndFunctions
 * Description: This file(s) Define and describe the core of the Housekeeping of the FEES System
 *
 *  Created on: 14 mar 2019
 *      Author: Stefano Ampolo
 */

#ifndef THREADSANDHANDLERS_HPP
#define THREADSANDHANDLERS_HPP

#include <iostream>
#include <cstdint>

using namespace std;



void Update_Pin_Mask(int NewState);

void Pin_Mask_All_OFF();
void Pin_Mask_InVector();
void Pin_Mask_Wait();
void Pin_Mask_Detumble();
void Pin_Mask_Nominal();
void Pin_Mask_Transmission();
void Pin_Mask_RADEX();

// There is an important difference Between Lowercase and UPPERCASE
// RESET is the action of turning off - waiting and on again a device
// Reset instead is for setting to 0 the GPIO pin.
void GpioSet(int pin);
void GpioReset(int pin);
// The 2 Funcions Above are used to Set==PUT TO 1 and Reset=PUT TO 0 the GPIO pins ATOMICALLY

// User-friendly -STUB Functions
void print_PinMask();
void print_ThreadsAndManagers();

void print_ADCS_State();
void print_BatteryManagement_State();

// // // POWER MANAGEMENT Functions
void System_Reboot();  // Salva i dati critici nella memoria e resetta il sistema.

/**********| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
void TELECOM_PowerON();
void TELECOM_PowerOFF();
void TELECOM_PowerRESET();

/**********| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ******/
void Analog_PowerON();
void Analog_PowerOFF();
void Analog_PowerRESET();

/**********| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   ******/
void GPS_PowerON();
void GPS_PowerOFF();
void GPS_PowerRESET();

/**********| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
void Iridium_PowerON();
void Iridium_PowerOFF();
void Iridium_PowerRESET();

/**********| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )      ******/
void Radex_PowerON();
void Radex_PowerOFF();
void Radex_PowerRESET();
void Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc

// RADEX SIGNAL
void RADEX();

/**********| RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******     ******/
void RaspberryPi_PowerON();			// GPIO 3
void RaspberryPi_PowerOFF();
void RaspberryPi_PowerRESET();
//GpioReset(RASPY_ON);
//RASPY_KEEP-on thread); 	//KeepON(AliveSignal)  - GPIO 4
void RaspberryPi_Watchdog(); // Questa funzione fa partire il Thread tiene acceso il RaspberryPi

/**********| MagnetoTorquerControl - ADCS SYSTEM  ***** 	******/
void ADCS_ON();
void ADCS_OFF();

/**********| BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
// BATTERY HEATER PWM - GPIO 14
void BatteryThermal_Management_ON();
void BatteryThermal_Management_OFF();

/**********| WatchDog  Control 	**********************		******/
void Hardware_Watchdog_ON(); // Questa funzione fa partire il Thread che gestisce il Watchdog Hardware
void Hardware_Watchdog_OFF();

/**********| LED - TELECOM WATCHDOG  Control  (GPIO 19) *** ******/
void Transmission_Watchdog_ON(); // Questa funzione fa partire il Thread che gestisce Led-Watchdog
void Transmission_Watchdog_OFF();

// Thread for FiniteStateMachine Handling
void thread_Fsm(); // 1Hz Thread loop

// Thread for user Screen Visualization
void thread_UserShell(); // 24hrz Thread loop


void thread_ADCS();
void thread_BatteryPID();
void thread_HardwareWD();
void thread_TransmissionWD();



#endif // THREADSANDHANDLERS_HPP


////////////////////////// File 3
/*
 * File:FiniteStateMachine.h
 *
 *  Created on: 10 apr 2019
 *      Author: Stefano
 */

#ifndef APPLICATIONSANDFSM_HPP
#define APPLICATIONSANDFSM_HPP

#define TRUE true
#define FALSE false



#include <iostream>
#include <cstdint>


using namespace std;



enum state_t {
	RECOVER_PREV_STATE = 0, 	// First State after BOOT.
    IN_VECTOR, 					// FEES inside the vector, both Switches still connected
    WAIT_FIRST_TIMER, 			// FEES out of the launcher - First Timer on, 30'
    DETUMBLE_SECOND_TIMER, 		// FEES Detumbling , Second Timer on, Angular speed limit to be decided.
    NOMINAL, 					// FEES NOMINAL STATE - Everything Good.
    TRANSMISSION, 				// FEES Transmission State, Everything else is off.
    RADEX_MODE, 				// FEES RADEX MODE - Programmed Experiment.
};



// DEFINIZIONE DELLE CONSTANTI (IMPOSTAZIONI DI MISSIONE)
const int CONST_SILENZIO_RADIO = 3600 ; // 30 min  --> Requisito di silenzio radio
const int DETHUMBLING_TIMER  = 600 ; 	// 10 min  --> Timer massimo di Dethumbling
const int CONST_RADEX_TIMER = 300;  	// 5 min --> Timer Time-Out del Rad-ex
const int CONST_TRX_TIMER = 300;		// 5 min --> Timer Time-Out Trasmissione
const float CONST_angular_velocity_Limit = 50;	// Valore di Angular_velocity_Limite (per concludere il dethumbling)





class finiteStateMachine {

public:
	void set(state_t a);
	void setPrev(state_t a);
	state_t get();
	state_t getPrev();

	void print_State();
	void print_Menu();
	void print_StateList();
	void print_Variables();
	void event_Handler();
	void human_event_Handler(int a);
	float sample_angular_velocity();

	bool switch_vector;
	bool beacon_received;
	bool radex_scheduled;
	bool radex_finished;
	bool transmission_finished;

	float first_timer;
	float second_timer;
	float timer_for_radex;
	float trx_timer;
	float radex_timer;
	float angular_velocity;

	// Constructor - Destructor
	finiteStateMachine();
	virtual ~finiteStateMachine();

private:
	state_t state;
	state_t previous_state;
};


void Update_Pin_Mask(state_t NewState);


#endif 	/* APPLICATIONSANDFSM_HPP */







#endif /* INC_FEESMANAGEMENTSYSTEM_H_ */
