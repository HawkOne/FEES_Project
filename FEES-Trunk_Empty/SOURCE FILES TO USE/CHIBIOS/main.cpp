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
 * main.cpp
 *
 *  Created on: 3/Nov/2017
 *      Author: Stefano Ampolo
 */

/*===========   SYSTEM And OS HEADERS ================*/

#include <stddef.h>

#include "../../../os/ex/Cypress/FRAM_FM25V20A.cpp"
#include "../../../os/ex/Taos/TSL2561.cpp"
#include "../../../os/ex/Taos/TSL2561.h"
#include "../../../os/ex/TexasInstruments/ADC128S022.cpp"
#include "../../../os/ex/TexasInstruments/LM75B.cpp"
#include "../../../os/ex/TexasInstruments/LM75B.h"
#include "../../../os/hal/include/hal_pal.h"
#include "../../../os/hal/include/hal_serial.h"
#include "../../../os/hal/include/hal_streams.h"
#include "../../../os/hal/lib/streams/chprintf.h"
#include "../../../os/hal/ports/AVR/XMEGA/LLD/USARTv1/hal_serial_lld.h"
#include "../../../os/rt/include/chschd.h"
#include "../../../os/rt/include/chthreads.h"
#include "FEES_libs/FEES.h"


#define cls(chp) chprintf(chp, "\033[2J\033[1;1H")  //terminal clean function

/*=========== FEES DEMO HEADERS =======================*/
#include "FEES_libs/Threads_Definitions.h"
#include "FEES_libs/MPU9250_FEES_SPI.h"
/*====================================================*/


/*===========   TEST   HEADERS =======================*/

//#include "../../../os/ex/Cypress/FM25V20A-G.h"
//#include "../../../os/ex/Cypress/FM25V20A-G.cpp"

/*====================================================*/


using namespace std;


// TEST ZONE //

//////

/* Application entry point. */

int main(void)
{
	/* Instanzio l'oggetto FEES - Il cui Costruttore si occupa degli Init  */
    FEES FEES;

    /* Instanzio l'oggetto LM75B */
    LM75B LM75B;

    /* Instanzio l'oggetto FERAM sul bus SPI2*/
    //FERAM feram(&SPID2);

    /* Instanzio l'oggetto TSL2561 sul bus I2C2*/
    TSL2561 TSL2561_TEST(&I2CD2, 2, "Sensore X TEST");

    //TSL2561_TEST.init();



    //** Starting the Blinker thread.**//
    chThdCreateStatic(Blinker_wa, sizeof(Blinker_wa), NORMALPRIO-1, Blinker, NULL);

    //** Starting the WatchdogUpdater thread.**//
    chThdCreateStatic(WatchdogUpdater_wa, sizeof(WatchdogUpdater_wa), NORMALPRIO-1,WatchdogUpdater, NULL);


    //////// TEST THREADS ///////

    //** Starting the BUZZER thread // GPIO3.**//
    //chThdCreateStatic(TestBuzzer_wa, sizeof(TestBuzzer_wa), NORMALPRIO-1, TestBuzzer, NULL);

    //** Starting the blinkerGPIO1/2/3 thread.**//
    chThdCreateStatic(Blink_ex_GPIO123_wa, sizeof(Blink_ex_GPIO123_wa),NORMALPRIO-1, Blink_ex_GPIO123, NULL);

    ////	////	//// TEST ZONE pre-loop ////		////	////	////

    /////////////////////////////////////////////////////////////


    // LOOP
    while (1)
       {
    	// Test IMU (s)
    	printImus();

    	// TEST ADC//
        // ACCENDO LA PARTE ANALOG -
        palSetLine(PAL_LINE(GPIOE, GPIOE_ANA_PWR_ON));

        //ADC12_PrintRAW();
        //ADC12_PrintVoltage();
        //ADC12_PrintALL();
        //ADC12_PrintALLExtended();
       	//ADC12_Print(e,a);

        ADC12_PrintALLExtended();
        /////////////////////////////////////////////////////


    	// TEST FRAM//

        FRAM_PrintTest(3);




        /// TEST SUN SENSOR

    	//TSL2561_TEST.turnOn();
        TSL2561_TEST.setGainHigh();
        TSL2561_TEST.setIntegrationShort();

        TSL2561_TEST.init();
        //TSL2561_TEST.printID();
        //TSL2561_TEST.printAdc0();
        //TSL2561_TEST.printAdc1();
        //TSL2561_TEST.printAll();
        //TSL2561_TEST.printTestAllGainIntegration();

        TSL2561_TEST.printData();

        //TSL2561_TEST.turnOff();
        ////////////////////////


        // TEST Memoria Interna //

    /*
    	uint32_t BigArray[1024];
    	for(int i=0; i<1024 ; i++){ BigArray[i]=0xFFFFFFFF; }

        chThdSleepMilliseconds(2000);
    	for(int i=0; i<1024 ; i++){
    		if (BigArray[i] != 0xFFFFFFFF){
    	    	chprintf((BaseSequentialStream*)&SD3, "\r\n Errore della Memoria all'indirizzo " );
    	    	//chprintf((BaseSequentialStream*)&SD3, " %d \n\r " , BigArray[i] );
    		}
    	}
    */

        LM75B.printTemp();
        FEES.printTime();

        chprintf((BaseSequentialStream*)&SD3, "\n ======================= END TEST LOOP ========================== \n\r\n\r " );

        chThdSleepMilliseconds(500);
        cls((BaseSequentialStream*)&SD3);
    }
    return 0;
}
