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
 * LM75B.cpp
 *
 *  Created on: 15/ott/2018
 *  Author: Stefano Ampolo
 *
 *  Device: TSL2561
 *  Company: Taos
 *
 */
#include "TSL2561.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>





TSL2561::TSL2561(I2CDriver *i2cp  ,int address, char* name)
{
	if(address==0){ (I2C_Address=TSL2561_AddrLow);}
	else if (address==1){(I2C_Address=TSL2561_AddrHigh);}
	else {(I2C_Address=TSL2561_AddrFloating);}

	this->name = name;
	I2C_Driver = i2cp;
}


TSL2561::~TSL2561(){}


// Useful functions

// Per capire come utilizzare questo dispositivo bisogna per forza osservare il datasheet


 void TSL2561::turnOn()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[2];
    cmd[0] = 0xE0 | TSL2561_CONTROL; // comando con la maschera di controllo
    cmd[1] = 0x03;	// Comando di accenzione
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
    i2cStop(&TSL2561_BUS_I2C);
}
 void TSL2561::turnOff()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[2];
    cmd[0] = 0xE0 | TSL2561_CONTROL;
    cmd[1] = 0x00;	// Comando di spegnimento
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
    i2cStop(&TSL2561_BUS_I2C);

}

 void TSL2561::setGainHigh()
{
	this->config |= 1U << 4; 		// Setting bit 4 of Timing Reg to High
    this->setConfig();
}
 void TSL2561::setGainLow()
 {
	this->config &= ~(1U << 4);		// Setting bit 4 of Timing Reg to LOW
    this->setConfig();
 }
 void TSL2561::setIntegrationShort()
{
	this->config &= ~(1U << 1);
	this->config &= ~(1U << 0);
	// Setting bit of Timing Reg 1-0 to  00 of Timing Reg
    this->setConfig();
}
 void TSL2561::setIntegrationMedium()
 {
 	this->config |= 1U << 0;
 	this->config &= ~(1U << 1);
	// Setting bit of Timing Reg 1-0 to  01 of Timing Reg
     this->setConfig();
 }
 void TSL2561::setIntegrationLong()
 {
 	this->config |= 1U << 1;
 	this->config &= ~(1U << 0);
	// Setting bit of Timing Reg 1-0 to  10 of Timing Reg
     this->setConfig();
 }
 void TSL2561::disableInterrupt()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[2];
    cmd[0] = 0xE0 | TSL2561_INTERRUPT;
    cmd[1] = 0b00000000	;// Impostazione ADC - HIGH GAIN - INT TIME 101ms
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
    i2cStop(&TSL2561_BUS_I2C);
}
 void TSL2561::init(){
	 this->turnOn();
	 this->setConfig();
	 this->disableInterrupt();
 }

 void TSL2561::printID()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[1];
    cmd[0] = 0xE0 | TSL2561_ID; // comando con maschera
    uint8_t rec[1];
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&TSL2561_BUS_I2C, I2C_Address , rec, sizeof(rec), TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
	i2cStop(&TSL2561_BUS_I2C);

	char buffer[8];
    itoa(rec[0],buffer,2);

    chprintf((BaseSequentialStream*)&SD3,
        			"\n L'ID ricevuto è : %4d - %s \n\r" , rec[0], buffer);
}

void TSL2561::printAll()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[1];
    cmd[0] = 0b11010000 | 0x00; // Comando BLOCK con maschera al primo ind.
    uint8_t rec[16];
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&TSL2561_BUS_I2C, I2C_Address , rec, 16, TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
    i2cStop(&TSL2561_BUS_I2C);
    char buffer[8];
	chprintf((BaseSequentialStream*)&SD3,"\r\n\t ====  %s  ====\n\r", this->name);
    for(int i=0;i<16;i++){
    	itoa(rec[i],buffer,2);
    	chprintf((BaseSequentialStream*)&SD3," %s \t", comandi[i]);
    	if(i!=5){chprintf((BaseSequentialStream*)&SD3,"\t");}
    	if( (i==8) |(i==10) ){chprintf((BaseSequentialStream*)&SD3,"\t");}
    	chprintf((BaseSequentialStream*)&SD3,"%4d  -  %s \n\r", rec[i], buffer);
    }
    chprintf((BaseSequentialStream*)&SD3,"\n\r");
}
void TSL2561::printTestAllGainIntegration()
{
			this->setGainHigh();
	  	  	this->setIntegrationShort();
	        chThdSleepMilliseconds(1000);
	    	chprintf((BaseSequentialStream*)&SD3, "HighGain ShortIntegration\r\n");
	  	  	this->printData();

	        this->setGainHigh();
	  	  	this->setIntegrationMedium();
	        chThdSleepMilliseconds(1000);
	    	chprintf((BaseSequentialStream*)&SD3, "HighGain MediumIntegration\r\n");
	  	  	this->printData();

	        this->setGainHigh();
	  	  	this->setIntegrationLong();
	        chThdSleepMilliseconds(3000);
	    	chprintf((BaseSequentialStream*)&SD3, "HighGain LongIntegration\r\n");
	  	  	this->printData();

	        this->setGainLow();
	  	  	this->setIntegrationShort();
	        chThdSleepMilliseconds(1000);
	    	chprintf((BaseSequentialStream*)&SD3, "LowGain ShortIntegration\r\n");
	  	  	this->printData();

	        this->setGainLow();
	  	  	this->setIntegrationMedium();
	        chThdSleepMilliseconds(1000);
	    	chprintf((BaseSequentialStream*)&SD3, "LowGain MediumIntegration\r\n");
	  	  	this->printData();

	        this->setGainHigh();
	  	  	this->setIntegrationLong();
	        chThdSleepMilliseconds(3000);
	    	chprintf((BaseSequentialStream*)&SD3, "LowGain LongIntegration\r\n");
	  	  	this->printData();
}


////// NEW FUNCTIONS ////////

void TSL2561::printData()
{
	uint16_t adc0;
	uint16_t adc1;
	char text[2][7]{"Adc0:" , "Adc1:" };

	this->getData(&adc0,&adc1);

    char buffer[16];
    char buffer2[16];

    itoa(adc0,buffer,2);
    itoa(adc1,buffer2,2);

    chprintf((BaseSequentialStream*)&SD3,"\n\r");
    chprintf((BaseSequentialStream*)&SD3," %s \n\r", this->name );
    chprintf((BaseSequentialStream*)&SD3," %s \t %4d  -  %s \n\r",text[0], adc0, buffer );
   	chprintf((BaseSequentialStream*)&SD3," %s \t %4d  -  %s \n\r",text[1], adc1, buffer2 );
    chprintf((BaseSequentialStream*)&SD3,"\n\r");
}


void TSL2561::printAdc0(){
	uint16_t output=this->getAdc0();
	char buffer[16];
	itoa(output,buffer,2);
	chprintf((BaseSequentialStream*)&SD3,
	   			" DATO Adc0: %4d - %s \n\r" , output, buffer);
}
void TSL2561::printAdc1(){
	uint16_t output=this->getAdc1();
	char buffer[16];
	itoa(output,buffer,2);
	chprintf((BaseSequentialStream*)&SD3,
	   			" DATO Adc1: %4d - %s \n\r" , output, buffer);
}

///	///	///	///	////	///	//////	///	//////	///	//////	///	///
///	///	///		LOW LEVEL FUNCTIONS		 ///	///		///		///
///	///	///	///	////	///	//////	///	//////	///	//////	///	///

void TSL2561::setConfig()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
	uint8_t cmd[2];
	cmd[0] = 0xA0 | TSL2561_TIMING;
	cmd[1] = this->config;		// Updating Config dell'oggetto
	i2cAcquireBus(&TSL2561_BUS_I2C);
	i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
	i2cReleaseBus(&TSL2561_BUS_I2C);
	i2cStop(&TSL2561_BUS_I2C);
}


uint16_t TSL2561::getAdc0()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
	uint8_t cmd[1];
    cmd[0] = 0xA0 | TSL2561_DATA0LOW; // Comando BLOCK con maschera al primo ind.
    uint8_t rec[2];
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&TSL2561_BUS_I2C, I2C_Address , rec, sizeof(rec), TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
	i2cStop(&TSL2561_BUS_I2C);
	uint16_t output =( (rec[1]<<8) | rec[0]);
	return output;
}


uint16_t TSL2561::getAdc1()
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
	uint8_t cmd[1];
    cmd[0] = 0xA0 | TSL2561_DATA1LOW; // Comando BLOCK con maschera al primo ind.
    uint8_t rec[2];
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&TSL2561_BUS_I2C, I2C_Address , rec, sizeof(rec), TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
	i2cStop(&TSL2561_BUS_I2C);
	uint16_t output = ( (rec[1]<<8) | rec[0]);
	return output;
}


void TSL2561::getData(uint16_t* adc0,uint16_t* adc1)
{
	i2cStart(&TSL2561_BUS_I2C, &TSL2561_I2CConfig);
    uint8_t cmd[1];
    cmd[0] = 0xD0 | TSL2561_ID; // Comando Read-BLOCK Masked -> indirizzo ID
    uint8_t rec[6];
    i2cAcquireBus(&TSL2561_BUS_I2C);
    i2cMasterTransmitTimeout(&TSL2561_BUS_I2C, I2C_Address, cmd, sizeof(cmd), NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&TSL2561_BUS_I2C, I2C_Address , rec, sizeof(rec), TIME_INFINITE);
    i2cReleaseBus(&TSL2561_BUS_I2C);
    i2cStop(&TSL2561_BUS_I2C);

    // L'ordine qui è inverso.
    *adc0= ((rec[5]<<8) | rec[4]);
    *adc1= ((rec[3]<<8) | rec[2]);
}

///	///	///	///	///	///	///	///	///	///	///	///	///	///	///	///	///
