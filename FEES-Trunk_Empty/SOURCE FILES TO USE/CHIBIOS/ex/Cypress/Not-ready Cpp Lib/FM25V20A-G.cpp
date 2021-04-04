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
 * FM25V20A-G.cpp
 *
 *  Created on: 24/ott/2018
 *  Author: Stefano Ampolo
 */

#include "FM25V20A-G.h"

FERAM::FERAM(SPIDriver* spip) {
	this->*spip = spip;
}

FERAM::~FERAM() {
}


// FUNZIONE HIGH LEVEL
static void PrintSR(){
	uint8_t var = SPI_Ex1Byte(0b00000101);
	        chprintf((BaseSequentialStream*)&SD3,
	        		"\n L' ID:  0b %d%d%d%d %d%d%d%d \n\r" ,
					var/128 ,
					var%128/64 ,
					var%128%64/32 ,
					var%128%64%32/16 ,
					var%128%64%32%16/8 ,
					var%128%64%32%16%8/4 ,
					var%128%64%32%16%8%4/2 ,
					var%128%64%32%16%8%4%2/1
					)
}


// FUNZIONE LOW LEVEL
static uint8_t SPI_Ex1Byte(uint8_t OPCODE)
{
	spiStart(&spip ,&FERAM_SPI_Config);
    uint8_t cmd=OPCODE;   	/* Sending the OPCODE */
    uint8_t received[2];
    spiAcquireBus(spip);
    spiSelect(spip);  		/* Lowers the chip select pin  */
    spiStartExchange(spip, 2, &cmd , &received );
    chThdSleepMilliseconds(1);
    spiUnselect(spip);
    spiReleaseBus(spip);
    spiStop(spip);
    return received[1];
}





/*
static uint16_t EXCANGE_DATA(SPIDriver *spip)
{
	spiStart(spip , &FERAM_SPI_Config);

    uint8_t cmd[2];
    uint8_t received[2];
    spiAcquireBus(spip);

    cmd[0] = 0x00 | ( 1 <<3 ) ; 	 Setting the channel to be read
    cmd[1] = 0x00;

    spiSelect(spip);					 Lowers the chip select pin

    spiStartExchange(spip, 2, &cmd , &received );

    chThdSleepMilliseconds(1);
    spiUnselect(spip);
    spiReleaseBus(spip);

    uint16_t valueback = (received[0]<<8) | received[1];

    spiStop(spip);
    return valueback;
}
*/


