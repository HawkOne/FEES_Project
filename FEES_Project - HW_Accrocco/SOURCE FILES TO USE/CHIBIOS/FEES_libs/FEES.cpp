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
 * FEES.cpp
 *
 *  Created on: 25/ott/2018
 *      Author: Stefano Ampolo
 */


#include "FEES.h"

FEES::FEES() {
	/* System initializations.
	 * - HAL initialization, this also initializes the configured device drivers
	 *   and performs the board-specific initializations.
	 * - Kernel initialization, the main() function becomes a thread and the
	 *   RTOS is active.  */
	 halInit();
	 chSysInit();

    /* Starting the I2C driver 2. (Connesso al BUS I2C1 sul FEES) */
	// i2cStart(&I2CD2, &i2cconfig);  --> Moved to the library


	//     IMU1 - Init MPU9250 driver. - 1 -
	 mpu9250ObjectInit(&MPU9250D1);
	 mpu9250Start(&MPU9250D1, &mpu9250cfg1);
	 mpu9250GyroscopeSampleBias(&MPU9250D1);
	 mpu9250AccelerometerSetBias(&MPU9250D1,accBias1);
	//     IMU2 - Init MPU9250 driver. - 2 -
	 mpu9250ObjectInit(&MPU9250D2);
	 mpu9250Start(&MPU9250D2, &mpu9250cfg2);
	 mpu9250GyroscopeSampleBias(&MPU9250D2);
	 mpu9250AccelerometerSetBias(&MPU9250D2,accBias2);


	/*  Activates the serial driver 3 using the driver default configuration.  */
	 sdStart(&SD3, NULL);
	 chprintf((BaseSequentialStream*)&SD3, "\n %s \n\r" BOARD_NAME);

	 chThdSleepMilliseconds(1000);
	 cls((BaseSequentialStream*)&SD3);

}

FEES::~FEES() {
	// TODO Auto-generated destructor stub
}


float FEES::getTime(){
	return (( (float) chVTGetSystemTimeX()) / 10000);
}

void FEES::printTime(){
	chprintf((BaseSequentialStream*)&SD3,
	                "\n Tempo di sistema: %.3f  -  \n\r"
	                " %d ore, %d minuti, %d secondi. \n\r\n\r",
					(( (float) chVTGetSystemTimeX()) / 10000),
					(chVTGetSystemTimeX()/36000000),
					((chVTGetSystemTimeX()/600000)%60),
					((chVTGetSystemTimeX()/10000) %60)
					);
}


void FEES::Temp_Test(){

	chprintf((BaseSequentialStream*)&SD3,
			"\n==== SELF TEST PROCEDURE =====\n\r"
			"\t - FEES SYSTEM - \n\r");
	chThdSleepMilliseconds(200);
	chprintf((BaseSequentialStream*)&SD3,
	        "\n-- ALL the BUSses are correctly started! -- \n\r");
	        chThdSleepMilliseconds(100);

	chprintf((BaseSequentialStream*)&SD3,
			"\n-- THE ADCs are working! -- \n\r");
	chThdSleepMilliseconds(200);

	chprintf((BaseSequentialStream*)&SD3,
	        "\n-- THE IMUS are working! -- \n\r");
	chThdSleepMilliseconds(200);

	chprintf((BaseSequentialStream*)&SD3,
	        "\n-- THE FERAM is working! -- \n\r");
	chThdSleepMilliseconds(200);

	chprintf((BaseSequentialStream*)&SD3,
	        "\n-- THE SUN SENSORS are working! -- \n\r"
			"\n=========================================\n\r\n\r");
}

void FEES::Test(){
}





