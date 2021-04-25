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
 *                          				Stefano Ampolo                             		   *
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
 *  Device: LM75B
 *  Company: TexasIstruments
 *
 */

#include "../Inc/LM75B.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>





LM75B::LM75B(){
	I2C_Address = LM75B_ADDR;
}

LM75B::LM75B(int address){
	I2C_Address = address;
}


LM75B::~LM75B(){}


float LM75B::getTemp()
{
	#ifdef FREERTOS
		char cmd_send[2];
		char cmd_receive[2];
		float a=0;

		cmd_send[0]= LM75B_Temp;
		cmd_send[1]= 0;

		cmd_receive[0]=0;
		cmd_receive[1]=0;
	  		
	  	HAL_I2C_Master_Transmit(&hi2c2,LM75B_ADDR<<1,cmd_send,2,100);
		HAL_I2C_Master_Receive(	&hi2c2,LM75B_ADDR<<1,cmd_receive,2,100);

		uint16_t bufferint = (cmd_receive[1] | (cmd_receive[0]<<8))>>5;
		if (bufferint > 2047 ) bufferint = (bufferint & 1111111111) | 100000000000000 ;// Test senza 2^11 con 2^15  ( sposto l'1 in avanti)
		a = (float)bufferint * 0.125;

		return (a);
    #endif



	#ifdef CHIBIOS
	i2cStart(&LM75B_BUS_I2C, &LM75B_i2cconfig);
    uint8_t cmd[2];
    cmd[0] = LM75B_Temp;
    i2cAcquireBus(&LM75B_BUS_I2C);
    i2cMasterTransmitTimeout(&LM75B_BUS_I2C, I2C_Address , cmd, 1, NULL, 0, TIME_INFINITE);
    i2cMasterReceiveTimeout(&LM75B_BUS_I2C, I2C_Address ,cmd ,2 ,TIME_INFINITE);
    i2cReleaseBus(&LM75B_BUS_I2C);
    i2cStop(&LM75B_BUS_I2C);

    return (   float((cmd[0]<<8)|cmd[1]) / 256.0   );
    #endif
}

/////////////////////////////////////EXTRA///////////////////////////////////////////////

void LM75B::printTemp(){

	#ifdef FREERTOS
		char cmd_send[2];
		char cmd_receive[2];
		float a=0;

		cmd_send[0]= LM75B_Temp;
		cmd_send[1]= 0;

		cmd_receive[0]=0;
		cmd_receive[1]=0;
	  		
	  	HAL_I2C_Master_Transmit(&hi2c2,LM75B_ADDR<<1,cmd_send,2,100);
		HAL_I2C_Master_Receive(	&hi2c2,LM75B_ADDR<<1,cmd_receive,2,100);

		uint16_t bufferint = (cmd_receive[1] | (cmd_receive[0]<<8))>>5;
		if (bufferint > 2047 ) bufferint = (bufferint & 1111111111) | 100000000000000 ;// Test senza 2^11 con 2^15  ( sposto l'1 in avanti)
		a = (float)bufferint * 0.125;

		char buffer[50];
		int buffer_len = sprintf(buffer,"\n La Temperatura � :  %.3f \n\r" , a);
		HAL_UART_Transmit( &huart3,buffer,buffer_len,100);
		return (a);
    #endif

	#ifdef CHIBIOS
		chprintf((BaseSequentialStream*)&SD3, "\n La Temperatura � : %.2f �\n\r" , this->getTemp());
    #endif
}




/*
void LM75B::shutdown()
{
#ifdef FREERTOS
	uint8_t cmd_send[1];
    cmd_send[0] = LM75B_REGISTER_CONFIG;
    uint8_t cmd_receive[1];
    
    HAL_I2C_Master_Transmit(&hi2c2,LM75B_ADDR<<1,cmd_send,1,100);
	HAL_I2C_Master_Receive(	&hi2c2,LM75B_ADDR<<1,cmd_receive,1,100);

	uint8_t config = read8bitRegister(LM75B_REGISTER_CONFIG);
	write8bitRegister(LM75B_REGISTER_CONFIG, (config & 0b11111110) | 0b1);
#endif
}

void LM75B::wakeup()
{
#ifdef FREERTOS
	uint8_t cmd[1];
    cmd[0] = LM75B_REGISTER_CONFIG;
    uint8_t rec[1];
    i2cAcquireBus(&I2CD2);
    i2cMasterReceiveTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
    rec[0]= ((rec[0] & 0b11111110));
	i2cMasterTransmitTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
	i2cReleaseBus(&I2CD2);

	//uint8_t config = read8bitRegister(LM75B_REGISTER_CONFIG);
	//write8bitRegister(LM75B_REGISTER_CONFIG, config & 0b11111110);
#endif

}



void LM75B::shutdown()
{
	uint8_t cmd[1];
    cmd[0] = LM75B_REGISTER_CONFIG;
    uint8_t rec[1];
    i2cAcquireBus(&I2CD2);

    i2cMasterReceiveTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
    rec[0]= ((rec[0] & 0b11111110) | 0b1);
	i2cMasterTransmitTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
	i2cReleaseBus(&I2CD2);

	//uint8_t config = read8bitRegister(LM75B_REGISTER_CONFIG);
	//write8bitRegister(LM75B_REGISTER_CONFIG, (config & 0b11111110) | 0b1);
}

void LM75B::wakeup()
{
	uint8_t cmd[1];
    cmd[0] = LM75B_REGISTER_CONFIG;
    uint8_t rec[1];
    i2cAcquireBus(&I2CD2);
    i2cMasterReceiveTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
    rec[0]= ((rec[0] & 0b11111110));
	i2cMasterTransmitTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, rec, 1, TIME_INFINITE);
	i2cReleaseBus(&I2CD2);

	//uint8_t config = read8bitRegister(LM75B_REGISTER_CONFIG);
	//write8bitRegister(LM75B_REGISTER_CONFIG, config & 0b11111110);
}

bool LM75B::isShutdown()
{
	uint8_t cmd[1];
	cmd[0] = LM75B_REGISTER_CONFIG;
	uint8_t rec[1];
	i2cAcquireBus(&I2CD2);
	i2cMasterTransmitTimeout(&BUS_I2C_LM75B, I2C_Address , cmd, 1, NULL, 0, TIME_INFINITE);

	i2cMasterReceiveTimeout(&BUS_I2C_LM75B, I2C_Address ,rec, 1, TIME_INFINITE);
	i2cReleaseBus(&I2CD2);
	
	return ((rec[0] & 0b1) ==1 );

	//return (read8bitRegister(LM75B_REGISTER_CONFIG) & 0b1) == 1;	

//	uint8_t M2M_LM75B::read8bitRegister(const uint8_t reg)
//	{
//		uint8_t result;
//
//		Wire.beginTransmission(_i2cAddress);
//		Wire.write(reg);
//		Wire.endTransmission();
//		Wire.requestFrom(_i2cAddress, (uint8_t)1);
//		result = Wire.read();
//		return result;
//	}
}*/
