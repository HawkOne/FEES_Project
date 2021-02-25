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
/*  This file describes how the MCU is connected to the devices and busses in this Project.
* 
*   This file Refeers to the portlist image portlist.jpg in the main folder of the project
*
*   Made by STAMP
*/

/*****************************ALL***********************************/
/**************PORT A******************/
typedef Gpio<GPIOA_BASE,0>      PWM_X_COIL;
typedef Gpio<GPIOA_BASE,1>      PWM_Y_COIL;
typedef Gpio<GPIOA_BASE,2>      PWM_Z_COIL;
typedef Gpio<GPIOA_BASE,3>      GPIO3;                    //
typedef Gpio<GPIOA_BASE,4>      CS_RADFET;
typedef Gpio<GPIOA_BASE,5>      SPI1_SCK;                 // ( MPU1-9250)
typedef Gpio<GPIOA_BASE,6>      SPI1_MISO;                // ( MPU1-9250)
typedef Gpio<GPIOA_BASE,7>      SPI1_MOSI;                // ( MPU1-9250)
typedef Gpio<GPIOA_BASE,8>      POWERGOOD;
typedef Gpio<GPIOA_BASE,9>      USB_VBUS;
typedef Gpio<GPIOA_BASE,10>     GPIO4;                    //
typedef Gpio<GPIOA_BASE,11>     USBM;
typedef Gpio<GPIOA_BASE,12>     USBP;
typedef Gpio<GPIOA_BASE,13>     JTAG_TMS;                 // Useful for programming the microcontroller
typedef Gpio<GPIOA_BASE,14>     JTAG_TCK;                 //
//typedef Gpio<GPIOA_BASE,15>;              UNCONNECTED


/**************PORT B******************/

typedef Gpio<GPIOB_BASE,0>      RASPBERRY_EN;             //
typedef Gpio<GPIOB_BASE,1>      GPIO1;
typedef Gpio<GPIOB_BASE,2>      BOOT1;                    // GROUNDED!
//typedef Gpio<GPIOB_BASE,3> ;              UNCONNECTED
//typedef Gpio<GPIOB_BASE,4> ;              UNCONNECTED
typedef Gpio<GPIOB_BASE,5>      WATCHDOG_RESET;
typedef Gpio<GPIOB_BASE,6>      UART1_Tx;                 //GPS
typedef Gpio<GPIOB_BASE,7>      UART1_Rx;                 //GPS
typedef Gpio<GPIOB_BASE,8>      I2C1_SCL;                 //LORA    (Negli schematici I2C2)
typedef Gpio<GPIOB_BASE,9>      I2C1_SDA;                 //LORA
typedef Gpio<GPIOB_BASE,10>     I2C2_SCL;                 //EEPROM1  (Negli schematici I2C1)
typedef Gpio<GPIOB_BASE,11>     I2C2_SDA;                 //EEPROM1
typedef Gpio<GPIOB_BASE,12>     GPIO2;                    //
typedef Gpio<GPIOB_BASE,13>     SPI2_SCK;                 //MPU2-9250
typedef Gpio<GPIOB_BASE,14>     SPI2_MISO;                //MPU2-9250
typedef Gpio<GPIOB_BASE,15>     SPI2_MOSI;                //MPU2-9250


/**************PORT C******************/

typedef Gpio<GPIOC_BASE,0>      PSD1_MUX_ADDR0;           //
typedef Gpio<GPIOC_BASE,1>      PSD1_MUX_ADDR1;           //
typedef Gpio<GPIOC_BASE,2>      PSD2_MUX_ADDR0;           //
typedef Gpio<GPIOC_BASE,3>      PSD2_MUX_ADDR1;           //
typedef Gpio<GPIOC_BASE,4>      PDS1_AMPLIFICATORE_CS;    //  
typedef Gpio<GPIOC_BASE,5>      PDS2_AMPLIFICATORE_CS;    //
typedef Gpio<GPIOC_BASE,6>      UART6_TX;                 // SDR
typedef Gpio<GPIOC_BASE,7>      UART6_RX;                 // SDR
typedef Gpio<GPIOC_BASE,8>      PWM_HEATER;               //To Heat up the battery
typedef Gpio<GPIOC_BASE,9>      SPI_EXT_EN;               // SPI EXTERNAL ENABLE ?=?
typedef Gpio<GPIOC_BASE,10>     SPI3_SCK;                 //EEPROM2 SPI3       
typedef Gpio<GPIOC_BASE,11>     SPI3_MISO;                //EEPROM2 SPI3       
typedef Gpio<GPIOC_BASE,12>     SPI3_MOSI;                //EEPROM2 SPI3       
typedef Gpio<GPIOC_BASE,13>     UHF_RESET;                //
typedef Gpio<GPIOC_BASE,14>     RADFET_OWB ;               //
typedef Gpio<GPIOC_BASE,15>     RADFET_RESET;             //


/**************PORT D******************/

typedef Gpio<GPIOD_BASE,0>      IRIDIUM_SER_DCD;          // SBD - CAN1?
typedef Gpio<GPIOD_BASE,1>      IRIDIUM_SER_DSR;          // SBD - CAN1?
typedef Gpio<GPIOD_BASE,2>      IRIDIUM_SER_DTR;          // SBD SERIALE UART5_RX
typedef Gpio<GPIOD_BASE,3>      IRIDIUM_SER_CTS_UART2;    // CLEAR TO SEND
typedef Gpio<GPIOD_BASE,4>      IRIDIUM_SER_RTS_UART2;    // REQUEST TO SEND
typedef Gpio<GPIOD_BASE,5>      IRIDIUM_SER_TX_UART2;     //PD5 (USART2_TX)
typedef Gpio<GPIOD_BASE,6>      IRIDIUM_SER_RX_UART2;     //PD6 (USART2_TX)
typedef Gpio<GPIOD_BASE,7>      IRIDIUM_ON_OFF;           //
typedef Gpio<GPIOD_BASE,8>      CONSOLE_TX;               //
typedef Gpio<GPIOD_BASE,9>      CONSOLE_RX;               //
typedef Gpio<GPIOD_BASE,10>     CS_EEPROM;                //
typedef Gpio<GPIOD_BASE,11>     CS_FRAM;                  //
typedef Gpio<GPIOD_BASE,12>     TMTC_MCU_WATCHDOG;        //
typedef Gpio<GPIOD_BASE,13>     MPU2_INTERRUPT;           //
typedef Gpio<GPIOD_BASE,14>     CS_MPU1;                  //
typedef Gpio<GPIOD_BASE,15>     MPU1_INTERRUPT;           //


/**************PORT E******************/

typedef Gpio<GPIOE_BASE,0>      ANOLOG_POWER_ON;          //
typedef Gpio<GPIOE_BASE,1>      RAD_POWER_ON;             //
typedef Gpio<GPIOE_BASE,2>      GPS_POWER_ON;             //
typedef Gpio<GPIOE_BASE,3>      SBD_POWER_ON;              //
typedef Gpio<GPIOE_BASE,4>      CS_NAND;                  //
typedef Gpio<GPIOE_BASE,5>      CS_LORA;                  //
typedef Gpio<GPIOE_BASE,6>      RASPBERRY_ON;             //
typedef Gpio<GPIOE_BASE,7>      DIR_COIL_X;               //
typedef Gpio<GPIOE_BASE,8>      DIR_COIL_Y;               //
typedef Gpio<GPIOE_BASE,9>      DIR_COIL_Z;               //
typedef Gpio<GPIOE_BASE,10>     CS_MPU2;                  //
typedef Gpio<GPIOE_BASE,11>     ADC1_EN;                  //
typedef Gpio<GPIOE_BASE,12>     ADC3_EN;                  //
typedef Gpio<GPIOE_BASE,13>     ADC2_EN;                  //
typedef Gpio<GPIOE_BASE,14>     IRIDIUM_SER_RI;           //
typedef Gpio<GPIOE_BASE,15>     IRIDIUM_SER_NET;          //

/*********************************************************************/
