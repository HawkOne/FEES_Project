/***********************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                             *
 *    FFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS      *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S     *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S     *
 *    FF:::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS     *
 *      F::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                 *
 *      F::::F               E:::::E               E:::::E             S:::::S                 *
 *      F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS              *
 * ---- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS    ---- *
 * -::- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS  -::- *
 * ---- F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S ---- *
 *      F::::F               E:::::E               E:::::E                         S:::::S     *
 *      F::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S     *
 *    FF::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS      *
 *    FFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS        *
 *                                                                                             *
 *             ____    ___     __      ___    ___    __  ___ __       ___   ___                *
 *             |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |           *
 *             |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___        *
 *                      ___     __  ___ __  __  ___ __     __     ________                     *
 *                      |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|                *
 *                      |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |                *
 *                                                                                             *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                              *                                              *
 *                                        FEES Project                                         *
 *                      URL: https://github.com/ferrandi/DEIB-DAER-project                     *
 *                               Politecnico di Milano - DEIB                                  *
 *                                  Stefano Ampolo                                   *
 *         ************************************************************************            *
 *                  Copyright (c) 2018-2019 Politecnico di Milano                              *
 *                                                                                             *
 *          This file is part of the FEES framework.                                           *
 *                                                                                             *
 *          The FEES framework is free software; you can redistribute it and/or modify         *
 *          it under the terms of the GNU General Public License as published by               *
 *          the Free Software Foundation; either version 3 of the License, or                  *
 *          (at your option) any later version.                                                *
 *                                                                                             *
 *          This program is distributed in the hope that it will be useful,                    *
 *          but WITHOUT ANY WARRANTY; without even the implied warranty of                     *
 *          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      *
 *          GNU General Public License for more details.                                       *
 *                                                                                             *
 *          You should have received a copy of the GNU General Public License                  *
 *          along with this program.  If not, see <http://www.gnu.org/licenses/>.              *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/*
 * LM75B.h
 *
 *  Created on: 15/ott/2018
 *  Author: Stefano Ampolo
 *
 *  Device: TSL2561
 *  Company: Taos
 *
 */
#ifndef OS_EX_TAOS_TSL2561_H_
#define OS_EX_TAOS_TSL2561_H_


/*
 * Questo dispositivo ha un pin ADD_SEL che puo' essere messo a
 *  Gnd , Floating o Vdd per scegliere l'indirizzo del protocollo I2C
 *
 *  ADC0 ha sensibilità nel range Ottico e IR
 *  ADC1 ha sensibilità nel range solo IR
 *
 */


//     TSL2561 INDIRIZZO I2C     //
#define    TSL2561_AddrLow        	0b0101001
#define    TSL2561_AddrFloating     0b0111001
#define    TSL2561_AddrHigh        	0b1001001


//     TSL2561 REGISTRI UTILI    //

#define		TSL2561_CONTROL        	0x00
#define   	TSL2561_TIMING       	0x01
#define   	TSL2561_THRESHLOWLOW    0x02
#define   	TSL2561_THRESHLOWHIGH   0x03
#define		TSL2561_THRESHHIGHLOW   0x04
#define   	TSL2561_THRESHHIGHHIGH  0x05
#define   	TSL2561_INTERRUPT       0x06
//#define   	TSL2561_RESERVED    0x07 - RESERVED
#define		TSL2561_CRC        		0x08
//#define   	TSL2561_RESERVED    0x09 - RESERVED
#define   	TSL2561_ID        		0x0A
//#define   	TSL2561_RESERVED	0x0B - RESERVED
#define		TSL2561_DATA0LOW        0x0C
#define   	TSL2561_DATA0HIGH       0x0D
#define   	TSL2561_DATA1LOW        0x0E
#define   	TSL2561_DATA1HIGH      	0x0F

/*
 * I2C frequency - 400000  for 400 khz - FAST I2C  ( CAN ALSO USE 100000  for 100Khz - SLOW I2C )
 */
#define TSL2561_I2C_FREQ 		400000

/*
 * Using I2CD2
 * I2C2_SDA PB10
 * I2C2_SCL PB11
 */

#define TSL2561_BUS_I2C			I2CD2

/**
 * @brief   Supported modes for the I2C bus.
typedef enum {
  OPMODE_I2C = 1,
  OPMODE_SMBUS_DEVICE = 2,
  OPMODE_SMBUS_HOST = 3,
} i2copmode_t;
 *
 * @brief   Supported duty cycle modes for the I2C bus.
 *
typedef enum {
  STD_DUTY_CYCLE = 1,
  FAST_DUTY_CYCLE_2 = 2,
  FAST_DUTY_CYCLE_16_9 = 3,
} i2cdutycycle_t;
*/

/* Configuration of the the I2C driver ( FOR TSL2561 ) */
static const I2CConfig TSL2561_I2CConfig = {
		OPMODE_I2C,  //
  TSL2561_I2C_FREQ,   //0
  FAST_DUTY_CYCLE_2   //0
};




//  Definizione della classe   //


 class TSL2561 {
 public:
	 // Metodi Costruttore.
	 TSL2561(I2CDriver *i2cp  ,int address, char* nome);

	 /*!
	  Metodo Distruttore.
	  */
	  ~TSL2561();

	  // Altri metodi globali


	  void turnOn();
	  void turnOff();
	  void setConfig();
	  void disableInterrupt();
	  void init();

	  void setGainHigh();
	  void setGainLow();
	  void setIntegrationShort();
	  void setIntegrationMedium();
	  void setIntegrationLong();

	  void printTestAllGainIntegration();


	  void printID();

	  uint16_t getAdc0();
	  uint16_t getAdc1();
	  void printAdc0();
	  void printAdc1();

	  void printAll();
	  void getData(uint16_t* adc0,uint16_t* adc1);
	  void printData();






 private:

   char *name;

   int8_t 		I2C_Address;
   I2CDriver * 	I2C_Driver;

   int8_t	config;

   uint16_t val0;
   uint16_t val1;
 };


 uint16_t light_sensors[16];


char comandi[16][40]{
	 "CONTROL",
	 "TIMING",
	 "THRESHLOWLOW",
	 "THRESHLOWHIGH",
	 "THRESHHIGHLOW",
	 "THRESHHIGHHIGH",
	 "INTERRUPT",
	 "RESERVED",
	 "CRC",
	 "RESERVED",
	 "ID",
	 "RESERVED",
	 "DATA0LOW",
	 "DATA0HIGH",
	 "DATA1LOW",
	 "DATA1HIGH",
};

#endif /* OS_EX_TAOS_TSL2561_H_ */
