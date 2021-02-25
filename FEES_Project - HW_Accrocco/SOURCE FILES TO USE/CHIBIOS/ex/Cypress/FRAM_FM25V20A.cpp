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
 * FRAM.cpp
 *
 *  Created on: 26/ott/2018
 *  Author: Stefano Ampolo
 *
 *  Device: FM25V20A-G
 *  Company: Cypress
 *
 *
 */

#include "FRAM_FM25V20A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>


// FUNZIONE HIGH LEVEL - STAMPA SR - Status Register
static void FRAM_PrintSR(){
	uint8_t var = FRAM_SPI_Ex1Byte(FRAM_STATUS_REGISTER_READ);
	char buffer[8];
	itoa(var,buffer,2);
	chprintf((BaseSequentialStream*)&SD3,
	        "FERAM SR:  0b %s \n\r" , buffer);
}

// FUNZIONE HIGH LEVEL - STAMPA ID
static void FRAM_PrintID(){
	uint8_t var = FRAM_SPI_Ex1Byte(FRAM_READ_ID);
	char buffer[8];
	itoa(var,buffer,2);
	chprintf((BaseSequentialStream*)&SD3,
	        "FERAM ID:  0b %s \n\r" , buffer);
}



// FUNZIONE LOW LEVEL - Scambia 2 byte sul bus SPI (uno in andata ed uno in ritorno)
static uint8_t FRAM_SPI_Ex1Byte(uint8_t OPCODE)
{
	spiStart(&USED_SPI_DRIVER_FRAM ,&FERAM_SPI_Config);
    uint8_t cmd=OPCODE;   	/* Sending the OPCODE */
    uint8_t received[2];
    spiAcquireBus(&USED_SPI_DRIVER_FRAM);
    spiSelect(&USED_SPI_DRIVER_FRAM);  		/* Lowers the chip select pin  */
    spiStartExchange(&USED_SPI_DRIVER_FRAM, 2, &cmd , &received );
    chThdSleepMilliseconds(1);
    spiUnselect(&USED_SPI_DRIVER_FRAM);
    spiReleaseBus(&USED_SPI_DRIVER_FRAM);
    spiStop(&USED_SPI_DRIVER_FRAM);
    return received[1];
}


// FUNZIONE LOW LEVEL - Abilita la scrittura sulla Fram - WREN = 1
static void FRAM_WriteEnable()
{
	spiStart(&USED_SPI_DRIVER_FRAM ,&FERAM_SPI_Config);
    uint8_t cmd = FRAM_WRITE_ENABLE;   		/* Sending the OPCODE */
    uint8_t rec;
    spiAcquireBus(&USED_SPI_DRIVER_FRAM);
    spiSelect(&USED_SPI_DRIVER_FRAM);  		/* Lowers the chip select pin  */
    spiStartExchange(&USED_SPI_DRIVER_FRAM, 1, &cmd , &rec );

    chThdSleepMilliseconds(1);

    spiUnselect(&USED_SPI_DRIVER_FRAM);
    spiReleaseBus(&USED_SPI_DRIVER_FRAM);
    spiStop(&USED_SPI_DRIVER_FRAM);
}

// FUNZIONE HIGH LEVEL -
static void FRAM_PrintNbyte(uint8_t N, uint32_t address){

	spiStart(&USED_SPI_DRIVER_FRAM ,&FERAM_SPI_Config);
    uint8_t cmd[4 + N];
    uint8_t received[4+N];
    cmd[0]=FRAM_READ;   	/* Sending the OPCODE */
    cmd[1]=address>>16;
    cmd[2]=address>>8;
	cmd[3]=address;

    spiAcquireBus(&USED_SPI_DRIVER_FRAM);
    spiSelect(&USED_SPI_DRIVER_FRAM);  	/* Lowers the chip select pin  */
    spiStartExchange(&USED_SPI_DRIVER_FRAM, 5+N, &cmd , &received );
	chThdSleepMilliseconds(1+N/2);
    spiUnselect(&USED_SPI_DRIVER_FRAM);
    spiReleaseBus(&USED_SPI_DRIVER_FRAM);
    spiStop(&USED_SPI_DRIVER_FRAM);


    for(uint8_t i=0; i<N; i++){
    	char buffer[8];
    	char buffer2[8];
    	itoa(address+i,buffer,16);
    	itoa(received[4+i],buffer2,2);
    	for(uint8_t i=0; i<sizeof(buffer);i++){
    		buffer[i]=toupper(buffer[i]); }	// Rende Maiuscole le Lettere
    	chprintf((BaseSequentialStream*)&SD3,
    			"IND: %08s \t dato: %08s \n\r", buffer, buffer2);
    	}
}





// FUNZIONE HIGH LEVEL -
static void FRAM_Print1byte(uint32_t address){
	uint8_t var = FRAM_SPI_Read1byte(address);
	char buffer[8];
	char buffer2[8];
	itoa(address,buffer,16);
	itoa(var,buffer2,2);
	for(uint8_t i=0; i<sizeof(buffer);i++){
	    buffer[i]=toupper(buffer[i]); }	// Rende Maiuscole le Lettere
	chprintf((BaseSequentialStream*)&SD3,
	         "IND: %08s \t dato: %08s \n\r", buffer, buffer2);
}

// FUNZIONE LOW LEVEL
static uint8_t FRAM_SPI_Read1byte( uint32_t address)
{
	spiStart(&USED_SPI_DRIVER_FRAM ,&FERAM_SPI_Config);
    uint8_t cmd[4];
    cmd[0]=FRAM_READ;   	/* Sending the OPCODE */
    cmd[1]=address>>16;
    cmd[2]=address>>8;
	cmd[3]=address;

    uint8_t received[5];
    spiAcquireBus(&USED_SPI_DRIVER_FRAM);
    spiSelect(&USED_SPI_DRIVER_FRAM);  		/* Lowers the chip select pin  */
    spiStartExchange(&USED_SPI_DRIVER_FRAM, 5, &cmd , &received );
    chThdSleepMilliseconds(1);
    spiUnselect(&USED_SPI_DRIVER_FRAM);
    spiReleaseBus(&USED_SPI_DRIVER_FRAM);
    spiStop(&USED_SPI_DRIVER_FRAM);
    return received[4];
}





// FUNZIONE LOW LEVEL
static void FRAM_Write(uint8_t* data , uint8_t size , uint32_t address)
{
	FRAM_WriteEnable();
	spiStart(&USED_SPI_DRIVER_FRAM ,&FERAM_SPI_Config);
    uint8_t cmd[4+size];
	cmd[0]=FRAM_WRITE;   	/* Sending the OPCODE */
	cmd[1]=address>>16;
	cmd[2]=address>>8;
	cmd[3]=address;

	for(uint8_t i=0; i<(size); i++){
		cmd[4+i] = *(data+i);
	}
    uint8_t lol[4+size];

    spiAcquireBus(&USED_SPI_DRIVER_FRAM);
    spiSelect(&USED_SPI_DRIVER_FRAM);  		// Lowers the chip select pin //
    spiStartExchange(&USED_SPI_DRIVER_FRAM, 4+size, &cmd , &lol );
    chThdSleepMilliseconds(1+size/2);
    spiUnselect(&USED_SPI_DRIVER_FRAM);
    spiReleaseBus(&USED_SPI_DRIVER_FRAM);
    spiStop(&USED_SPI_DRIVER_FRAM);
}


static void FRAM_TestWriteSingleCell(uint8_t quante_volte , uint32_t quale_indirizzo){
	// TEST FERAM LIBRARY C++
	for(uint8_t i=0; i<quante_volte; i++){

	    chprintf((BaseSequentialStream*)&SD3, "\n\r");

	    FRAM_PrintSR();
	    FRAM_Print1byte(quale_indirizzo);
	    uint8_t asd[2];
	    asd[0]= i;
	    FRAM_Write(asd , 1 , quale_indirizzo);
	    chprintf((BaseSequentialStream*)&SD3, "Write completed \n\r");
	    FRAM_Print1byte(quale_indirizzo);

	    chThdSleepMilliseconds(200);

		}
}



void FRAM_PrintTest(int num_celle){
	uint8_t increasing[num_celle];
	uint8_t decreasing[num_celle];
	uint8_t randomvalues[num_celle];

	for(int i=0; i< num_celle; i++){
		increasing[i]=i;
		decreasing[i]=(num_celle-i);
		randomvalues[i]= rand();
	}
	 chprintf((BaseSequentialStream*)&SD3,
	                               		"================= FRAM TEST ================== \n\r " );

	FRAM_Write(increasing, num_celle , 0x00);
	FRAM_PrintNbyte(num_celle, 0x00);

	FRAM_Write(decreasing, num_celle , 0x00);
	FRAM_PrintNbyte(num_celle, 0x00);

	FRAM_Write(randomvalues, num_celle , 0x00);
	FRAM_PrintNbyte(num_celle, 0x00);
}

 void FRAM_TestWriteIncremental(uint8_t quante_volte , uint32_t quale_indirizzo){
	uint8_t asd[quante_volte];
	for(int i=0; i< quante_volte; i++){ asd[i]=i;}
	FRAM_Write(asd, quante_volte , quale_indirizzo);
 	FRAM_PrintNbyte(quante_volte , quale_indirizzo );
 }





