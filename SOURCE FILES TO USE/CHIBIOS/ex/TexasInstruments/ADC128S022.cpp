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
/**
 * @file    ADC12b_SPI_Driver.cpp
 * @brief   ADC12bit library code.
 *
 * @addtogroup ADC12bit
 * @ingroup EX_ADC
 * @{
 * Created on: 20/ott/2018
 * Author: Stefano Ampolo
 *
 *  Device: ADC128S022
 *  Company: TexasIstruments
 *
 */

#include "ADC128S022.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>



/*


///		ADC12 - SPI FUNCTIONS


 * @brief   MAIN FUNCTION - Excanges data on the SPI bus.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * @param[none] spip      pointer to the SPI interface is &SPID1 default.
 * @param[in] adc_number number of the adc device ( 0 to 2 ) on the FEES
 * @param[in] channel 	the channel number ( 0 to 7 )
 * @return 	returns the value received (it's a 12 bit number - as 16 bits)
 */


static uint16_t ADC12_SPIReadChannel( uint8_t adc_number, uint8_t channel )
{
	switch(adc_number)
	{
		case 0: spiStart(&ADC_SPI_Driver , &ADC1_SPI_config);
			break;
		case 1:	spiStart(&ADC_SPI_Driver , &ADC2_SPI_config);
			break;
		case 2: spiStart(&ADC_SPI_Driver , &ADC3_SPI_config);
			break;
		default:spiStart(&ADC_SPI_Driver , &ADC1_SPI_config);
			break;
	}
    uint8_t cmd[2];
    uint8_t rec[2];
    spiAcquireBus(&ADC_SPI_Driver);

    cmd[0] = 0x00 | ( channel <<3 ) ; 	/* Setting the channel to be read */
    cmd[1] = 0x00;

    rec[0] = 0x00;
    rec[1] = 0x00;

    spiSelect(&ADC_SPI_Driver); 									/*Lowers the chip select pin*/
    spiStartExchange(&ADC_SPI_Driver, 2, &cmd , &rec );
    chThdSleepMilliseconds(1);
    spiUnselect(&ADC_SPI_Driver);
    spiReleaseBus(&ADC_SPI_Driver);
    spiStop(&ADC_SPI_Driver);

    uint16_t valueback = 0x0000 | (rec[0]<<8) | rec[1];
    return valueback;
}


 void ADC12_ReadALL(){
	for(int i=0;i<3;i++){
				for(int j=0;j<8;j++){
			Adc12DataRAW[i][j]= ADC12_SPIReadChannel(i,j);
			Adc12DataNormalized[i][j]= (((float) Adc12DataRAW[i][j]) / FULLSCALE_12BIT);
			Adc12DataVoltage[i][j]= (3.3)*(Adc12DataNormalized[i][j]);
						}
					}
}


 void ADC12_PrintRAW(){
	ADC12_ReadALL();
    chprintf((BaseSequentialStream*)&SD3,
    		" The ADC RAW VALUES are: \n\r");

    for(int i=0;i<3;i++){
    	for(int j=0;j<8;j++){
    		chprintf((BaseSequentialStream*)&SD3,
						"%15s: %5d  \n\r" , Adc12_Channel_Name[i][j] , Adc12DataRAW[i][j]);
							}
					}
    chprintf((BaseSequentialStream*)&SD3,
                    		" \n =========================== \n\r");
}

 void ADC12_PrintNormalized(){
	ADC12_ReadALL();
    chprintf((BaseSequentialStream*)&SD3,
    		"  The ADC NORMALIZED VALUES are: \n\r");

    for(int i=0;i<3;i++){
    	for(int j=0;j<8;j++){
				chprintf((BaseSequentialStream*)&SD3,
						"%15s: %5d - %f \n\r" , Adc12_Channel_Name[i][j] , Adc12DataNormalized[i][j],
						Adc12DataNormalized[i][j]);
							}
					}
    chprintf((BaseSequentialStream*)&SD3,
                    		" \n =========================== \n\r");
}

 void ADC12_PrintVoltage(){
	ADC12_ReadALL();
    chprintf((BaseSequentialStream*)&SD3,
    		"  The ADC Voltage VALUES are: \n\r");

    for(int i=0;i<3;i++){
    	for(int j=0;j<8;j++){
				chprintf((BaseSequentialStream*)&SD3,
						"%15s:  %.3f V \n\r" , Adc12_Channel_Name[i][j] , Adc12DataVoltage[i][j]);
							}
					}
    chprintf((BaseSequentialStream*)&SD3, " \n =========================== \n\r");
}

 void ADC12_PrintALL(){
	ADC12_ReadALL();
    chprintf((BaseSequentialStream*)&SD3,
    		"\t\t    === === ===  The ADC VALUES are: === === === \n\n\r");

    for(int i=0;i<3;i++){
    	for(int j=0;j<8;j++){
				chprintf((BaseSequentialStream*)&SD3,
						" %15s: \t%.3f Volt, \t%5d RAW, \t%.5f Normalized \n\r" , Adc12_Channel_Name[i][j], Adc12DataVoltage[i][j],
						Adc12DataRAW[i][j], Adc12DataNormalized[i][j]);
							}
					}
    chprintf((BaseSequentialStream*)&SD3,
                    		" \n ========================================================================= \n\r");
}

 void ADC12_PrintALLShort(){
	ADC12_ReadALL();
    chprintf((BaseSequentialStream*)&SD3,
    		"\t\t    === === ===  The ADC VALUES are: === === === \n\n\r");

    for(int i=0;i<3;i++){
    	chprintf((BaseSequentialStream*)&SD3,
    	                    		" ADC: %d \n\r", i+1);
    	for(int j=0;j<8;j++){
				chprintf((BaseSequentialStream*)&SD3,
						" %15s: \t%.3f Volt, \t%5d RAW, \t%.5f Normalized \n\r" , Adc12_Channel_Name[i][j], Adc12DataVoltage[i][j],
						Adc12DataRAW[i][j], Adc12DataNormalized[i][j]);
							}
					}
    chprintf((BaseSequentialStream*)&SD3,
                    		" \n ========================================================================= \n\r");
}
 void ADC12_PrintALLExtended(){
	ADC12_ReadALL();
	char buffer[12];
    chprintf((BaseSequentialStream*)&SD3,
    		"\t\t    === === ===  The ADC VALUES are: === === === \n\n\r");

    for(int i=0;i<3;i++){
    	chprintf((BaseSequentialStream*)&SD3,
    	                    		" ADC: %d \n\r", i+1);
    	for(int j=0;j<8;j++){
    			itoa(Adc12DataRAW[i][j],buffer,2);
				chprintf((BaseSequentialStream*)&SD3,
						"  Ch%2d: %15s: \t%.3f Volt, \t%5d RAW, \t%.5f Normalized, %s RAW bin \n\r" ,j+1, Adc12_Channel_Name[i][j], Adc12DataVoltage[i][j],
						Adc12DataRAW[i][j], Adc12DataNormalized[i][j] , buffer );
							}
					}
    chprintf((BaseSequentialStream*)&SD3,
                    		" \n================================================================================= \n\r");
}



/**
 * @brief   MAIN FUNCTION - Excanges data on the SPI bus.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * THIS FUNCION HAS THE USER-FRIENDLY ENUMERATION
 *
 * @param[none] spip      pointer to the SPI interface is &SPID1 default.
 * @param[in] adc_number number of the adc device ( 1 to 3 ) on the FEES
 * @param[in] channel 	the channel number ( 1 to 8 )
 * @return 	returns the value received (it's a 12 bit number - as 16 bits)
 */


 void ADC12_Print(uint8_t adc_number, uint8_t channel){
	uint16_t asd = ADC12_SPIReadChannel( adc_number-1, channel-1);

	chprintf((BaseSequentialStream*)&SD3,
	         "%15s: %.4fV \n\r",
			 Adc12_Channel_Name[adc_number-1][channel-1],
			 3.3*(((float)asd)/FULLSCALE_12BIT ));
}





