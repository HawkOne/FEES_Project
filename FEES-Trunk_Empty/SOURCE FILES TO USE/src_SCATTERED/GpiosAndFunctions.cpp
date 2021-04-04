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
 * FILE:Pinmask.cpp
 *
 *  Created on: 14 mar 2019
 *      Author: Stefano
 */



#include "GpiosAndFunctions.h"

#include "finiteStateMachine.h"
#include <iostream>
#include <cstdint>
#include <thread>

using namespace std;


bool GPIO[34];

bool Flag_TELECOM_Active=0;
bool Flag_Analog_Active=0;
bool Flag_GPS_Active=0;
bool Flag_Iridium_Active=0;
bool Flag_Radex_Active=0;
bool Flag_RaspberryPi_WD_Active=0;
bool Flag_ADCS_Active=0;
bool Flag_BatteryManagement_Active=0;
bool Flag_Hardware_Watchdog_Active=0;
bool Flag_Transmission_Watchdog_Active=0;




void Update_Pin_Mask(state_t NewState){
	switch(NewState){

	    case RECOVER_PREV_STATE:
	    	Pin_Mask_All_OFF();
	    	break;

	    case IN_VECTOR:
	    	Pin_Mask_InVector();
	    	break;

	    case WAIT_FIRST_TIMER:
	    	Pin_Mask_Wait();
	    	break;

	    case DETUMBLE_SECOND_TIMER:
   	    	Pin_Mask_Detumble();
	    	 break;

	    case NOMINAL:
	    	Pin_Mask_Nominal();
	    	break;

	    case TRANSMISSION:
	    	Pin_Mask_Transmission();
	    	break;

	    case RADEX_MODE:
	    	Pin_Mask_RADEX();
	    	break;

	    default:
	    	Pin_Mask_All_OFF();
	    	break;
	}
	return;
}

void Pin_Mask_All_OFF(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	//TELECOM_PowerON();
	TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	//Analog_PowerON();
	Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	//GPS_PowerON();
	GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	//Iridium_PowerON();
	Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	//Radex_PowerON();
	Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	//RaspberryPi_PowerON();
	RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	//ADCS_ON();
	ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	//BatteryThermal_Management_ON();
	BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso
	

	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);
}
void Pin_Mask_InVector(){
	Pin_Mask_All_OFF();
}
void Pin_Mask_Wait(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	//TELECOM_PowerON();
	TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	//Analog_PowerON();
	Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	//GPS_PowerON();
	GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	//Iridium_PowerON();
	Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	//Radex_PowerON();
	Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	//RaspberryPi_PowerON();
	RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	//ADCS_ON();
	ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	BatteryThermal_Management_ON();
	//BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso


	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);

}
void Pin_Mask_Detumble(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	//TELECOM_PowerON();
	TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	//Analog_PowerON();
	Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	//GPS_PowerON();
	GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	//Iridium_PowerON();
	Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	//Radex_PowerON();
	Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	//RaspberryPi_PowerON();
	RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	ADCS_ON();
	//ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	BatteryThermal_Management_ON();
	//BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso
	

	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);

}
void Pin_Mask_Nominal(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	TELECOM_PowerON();
	//TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	Analog_PowerON();
	//Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	GPS_PowerON();
	//GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	//Iridium_PowerON();
	Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	//Radex_PowerON();
	Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	//RaspberryPi_PowerON();
	RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	ADCS_ON();
	//ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	BatteryThermal_Management_ON();
	//BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso

	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);

}
void Pin_Mask_Transmission(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	TELECOM_PowerON();
	//TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	Analog_PowerON();
	//Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	GPS_PowerON();
	//GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	Iridium_PowerON();
	//Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	//Radex_PowerON();
	Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	RaspberryPi_PowerON();
	//RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	//ADCS_ON();
	ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	BatteryThermal_Management_ON();
	//BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	//GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso
	

	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);

}
void Pin_Mask_RADEX(){

	//	PAYLOAD CONTROL

	/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
	TELECOM_PowerON();
	//TELECOM_PowerOFF();
	//TELECOM_PowerRESET();

	/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
	//Analog_PowerON();
	Analog_PowerOFF();
	//Analog_PowerRESET();

	/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
	GPS_PowerON();
	//GPS_PowerOFF();
	//GPS_PowerRESET();

	/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
	//Iridium_PowerON();
	Iridium_PowerOFF();
	//Iridium_PowerRESET();
	// IRIDIUM	CONTROL
	GpioReset(SDB_0);
	GpioReset(SDB_1);
	GpioReset(SDB_2);
	GpioReset(SDB_3);
	GpioReset(SDB_4);
	GpioReset(SDB_5);
	GpioReset(SDB_6);
	GpioReset(SDB_7);

	/******************************| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
	Radex_PowerON();
	//Radex_PowerOFF();
	//Radex_PowerRESET();

	// RADEX SIGNAL
	RADEX(); // STARTING THE RADEX FUNCION

	//GpioReset(RADFET_OWB);	//Radex One-Wire Temp-Signal

	//Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc


	/*********************************** RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******/
	//RaspberryPi_PowerON();
	RaspberryPi_PowerOFF();
	//RaspberryPi_PowerRESET();
	//GpioReset(RASPY_ON);   // GPIO 3
	//GpioReset(RASPY_KEEP); 	//KeepON(AliveSignal)  - GPIO 4

	/******************************	MagnetoTorquerControl - ADCS SYSTEM   	*******/
	ADCS_ON();
	//ADCS_OFF();
	/*
	// PWM - GPIO  CONTROL
	GpioReset(PWM_X_GPIO);
	GpioReset(PWM_Y_GPIO);
	GpioReset(PWM_Z_GPIO);
	// PWM DIRECTION CONTROL
	GpioReset(DIR_X);
	GpioReset(DIR_Y);
	GpioReset(DIR_Z);
	*/

	/******************************	BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
	// BATTERY HEATER PWM - GPIO 14
	BatteryThermal_Management_ON();
	//BatteryThermal_Management_OFF();
	//GpioReset(BATTERY_HEATER_GPIO);

	/******************************	WatchDog  Control 	***************************/
	GpioReset(WATCHDOG);

	/******************************	EXTERNAL GPIO  Control ************************/
	//GpioSet(EX_GPIO_1);
	GpioReset(EX_GPIO_1);

	//GpioSet(EX_GPIO_2);
	GpioReset(EX_GPIO_2);

	//GpioSet(EX_GPIO_3);
	GpioReset(EX_GPIO_3);

	//GpioSet(EX_GPIO_4);
	GpioReset(EX_GPIO_4);


	/******************************	LED - TELECOM WATCHDOG  Control  (GPIO 19) ****/
	GpioReset(LED); // Led - Attivo Basso
	

	/******************************	PSD SELECTOR  Control  ******************* ****/
	GpioReset(PSD_0);
	GpioReset(PSD_1);
	GpioReset(PSD_2);
	GpioReset(PSD_3);

}

void GpioSet(int pin){
	//  - This is the real function - of ARDUPILOT
	//hal.gpio->write(pin, 1 );
	//  - REMOVE THE COMMENTS  and the stub when finishing

	//STUB FUNCTION
	//cout << " GPIO N " << pin << " set to HIGH - 1 \n";
	GPIO[pin]=1;
}
void GpioReset(int pin){
	//  - This is the real function - of ARDUPILOT
	//hal.gpio->write(pin, 0 );
	//  - REMOVE THE COMMENTS  and the stub when finishing

	//STUB FUNCTION ( THE REAL ACTION IS HERE )
	//cout << " GPIO N " << pin << " set to LOW - 0 \n";
	GPIO[pin]=0;
}

// User-friendly -STUB Functions
void print_PinMask(){

								  cout << "    __________________________________________________" << endl ;
								  cout << "   |                                                  |" << endl ;
								  cout << "   |   --- --- ---  The GPIO MASK IS :  --- --- ---   |" << endl ;
								  cout << "   |                                                  |" << endl ;
	for(int i=0 ; i<34 ; i++){
		if(i<10){if( (i%2) == 0){ cout << "   | - Gpio (0" << i << ") set to " << noboolalpha << GPIO[i] ;	}
				 if( (i%2) != 0){ cout << "   | - Gpio (0" << i << ") set to " << noboolalpha << GPIO[i] << "  - |" << endl ; }}
			else{if( (i%2) == 0){ cout << "   | - Gpio (" << i << ") set to " << noboolalpha << GPIO[i] ;}
				 if( (i%2) != 0){ cout << "   | - Gpio (" << i << ") set to " << noboolalpha << GPIO[i] << "  - |" << endl ; }}}
								  cout << "   |__________________________________________________|" << endl << endl ;
}
void print_ThreadsAndManagers(){
						  	   cout << endl << " |^^^^   FEES POWER and Threads  ^^^^|" << endl;
	    if(Flag_TELECOM_Active)		 { cout << " |   - Telecom Module Power ON	     |" << endl ;}
	    						else { cout << " |   - Telecom Module Power OFF	     |" << endl ;}
	    if(Flag_Analog_Active)		 { cout << " |   - The Analog Power ON           |" << endl ;}
	    						else { cout << " |   - The Analog Power OFF          |" << endl ;}
	    if(Flag_GPS_Active)			 { cout << " |   - GPS Module Power ON           |" << endl ;}
	    						else { cout << " |   - GPS Module Power OFF          |" << endl ;}
	    if(Flag_Iridium_Active)		 { cout << " |   - Iridium Module Power ON       |" << endl ;}
	    						else { cout << " |   - Iridium Module Power OFF      |" << endl ;}
	    if(Flag_Radex_Active)		 { cout << " |   - RADiation EXperiment ON       |" << endl ;}
	    						else { cout << " |   - RADiation EXperiment OFF      |" << endl ;}
	   if(Flag_RaspberryPi_WD_Active){ cout << " |   - Raspberry Pi Power ON         |" << endl ;}
	    						else { cout << " |   - Raspberry Pi Power OFF        |" << endl ;}
	    							   cout << " |                                   |" << endl;
	    if( Flag_ADCS_Active )		 { cout << " |   - ADCS Thread is  ACTIVE        |" << endl ;}
	    						else { cout << " |   - ADCS Thread is NOT ACTIVE     |" << endl ;}
	if(Flag_BatteryManagement_Active){ cout << " |   - Battery PID Th  ACTIVE        |" << endl ;}
	    						else { cout << " |   - Battery PID Th NOT ACTIVE     |" << endl ;}
	if(Flag_Hardware_Watchdog_Active){ cout << " |   - Hardware WD Th  ACTIVE        |" << endl ;}
	    						else { cout << " |   - Hardware WD Th NOT ACTIVE     |" << endl ;}
 if(Flag_Transmission_Watchdog_Active){cout << " |   - TMTC WD Thread  ACTIVE        |" << endl ;}
								else { cout << " |   - TMTC WD Thread NOT ACTIVE     |" << endl ;}
									   cout << " |___________________________________|" << endl;
}

// // // POWER MANAGEMENT Functions
void System_Reboot(){
	// Da scrivere qui una routine che spenga prima tutti i devices-Payloads,
	// Salvi in memoria FeRam (statica) tutto il buffer-ram e poi faccia un restart della STM32. Fermando il thread hardware watchdog
 Analog_PowerOFF();
 GPS_PowerOFF();
 TELECOM_PowerOFF();
 Iridium_PowerOFF();
 Radex_PowerOFF();
 RaspberryPi_PowerOFF();

// -> Memory Save --> RamBuffer
// Watchdog (?)
// return0;
}

/******************************| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
void TELECOM_PowerON(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 0 , 1 );
	GPIO[0]=1;
	Flag_TELECOM_Active=TRUE;

	// STUB PART
	cout << " GPS POWER ON " << endl;
}
void TELECOM_PowerOFF(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 0 , 0 );
	GPIO[0]=0;
	Flag_TELECOM_Active=0;

	// STUB PART
	cout << " GPS POWER ON " << endl;
}
void TELECOM_PowerRESET(){
	TELECOM_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	TELECOM_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	TELECOM_PowerON();
}

/******************************| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ********/
void Analog_PowerON(){

	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 2 , 1 );
	GPIO[2]=1;
	Flag_Analog_Active=TRUE;

	// STUB PART
	cout << " Turning ANALOG POWER ON " << endl;

}
void Analog_PowerOFF(){

	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 2 , 0 );
	GPIO[2]=0;
	Flag_Analog_Active=0;
	// STUB PART
	cout << " Turning ANALOG POWER OFF " << endl;

}
void Analog_PowerRESET(){
	Analog_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Analog_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Analog_PowerON();
}

/******************************| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   *******/
void GPS_PowerON(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 1 , 1 );
	GPIO[1]=1;
	Flag_GPS_Active=1;

	// STUB PART
	cout << " GPS POWER ON " << endl;
}
void GPS_PowerOFF(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 1 , 0 );
	GPIO[1]=0;
	Flag_GPS_Active=0;

	// STUB PART
	cout << " Turning ANALOG POWER ON " << endl;
}
void GPS_PowerRESET(){
	GPS_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	GPS_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	GPS_PowerON();
}

/******************************| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
void Iridium_PowerON(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 29 , 1 );
	GPIO[29]=1;
	Flag_Iridium_Active= TRUE;

	// STUB PART
	cout << " Iridium POWER ON " << endl;
}
void Iridium_PowerOFF(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 29 , 0 );
	GPIO[29]=0;
	Flag_Iridium_Active= 0;

	// STUB PART
	cout << " Iridium POWER ON " << endl;
}
void Iridium_PowerRESET(){
	Iridium_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Iridium_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Iridium_PowerON();
}

/*********************************** RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )  ******/
void Radex_PowerON(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 5 , 1 );
	GPIO[5]=1;
	Flag_Radex_Active = TRUE;

	// STUB PART
	cout << " RadEX POWER ON " << endl;
}
void Radex_PowerOFF(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 5 , 0 );
	GPIO[5]=0;
	Flag_Radex_Active= FALSE;

	// STUB PART
	cout << " RadEX POWER OFF " << endl;
}
void Radex_PowerRESET(){
	Iridium_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Iridium_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Iridium_PowerON();
}
void Radex_SignalRESET(){
	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 6 , 1 );
	GPIO[6]=1;


	// STUB PART
	cout << " Radex ADC32bit ON " << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 6 , 0 );
	GPIO[6]=0;


	// STUB PART
	cout << " Radex ADC32bit OFF " << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	// ACTUAL CHIBIOS FUNCTION
	// hal.gpio->write( 6 , 1 );
	GPIO[6]=1;

	// STUB PART
	cout << " Radex ADC32bit ON " << endl;

}

// RADEX FUNCTION
void RADEX(){
	//This function will contain the RADEX Experiment
	Flag_Radex_Active=1;

	// This is the STUB PART
	cout << "The RadEX Execution has been Called." << endl;
}

/**********| RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******     ******/
void RaspberryPi_PowerON(){  // GPIO 3
	// ACTUAL CHIBIOS FUNCTION
		// hal.gpio->write( 3 , 1 );
		GPIO[3]=1;
		RaspberryPi_Watchdog(); // Fa partire il Thread-Watchdog

		// STUB PART
		cout << " RASPBERRY Pi POWER ON " << endl;
}
void RaspberryPi_PowerOFF(){
		// ACTUAL CHIBIOS FUNCTION
		// hal.gpio->write( 3 , 0 );
		GPIO[3]=0;


		// STUB PART
		cout << " RASPBERRY Pi POWER OFF " << endl;
}
void RaspberryPi_PowerRESET(){
	RaspberryPi_PowerON();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	RaspberryPi_PowerOFF();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	RaspberryPi_PowerON();
}
//GpioReset(RASPY_ON);
//RASPY_KEEP-on thread); 	//KeepON(AliveSignal)  - GPIO 4
void RaspberryPi_Watchdog(){ // Questa funzione fa partire il Thread tiene acceso il RaspberryPi
	Flag_RaspberryPi_WD_Active = TRUE;
	cout << "  Thread Watchdog Raspberry Pi Lanciato! " << endl;
}

/**********| MagnetoTorquerControl - ADCS SYSTEM  ***** 	******/
// Attitude Determination and Control System
void ADCS_ON(){
	Flag_ADCS_Active = 1;
	// ACTUAL FUNCTION STILL TO BE WRITTEN

	//STUB PART:
	cout<< "The Attitude Control System is Active" << endl;
}
void ADCS_OFF(){
	Flag_ADCS_Active=0;
	// ACTUAL FUNCTION STILL TO BE WRITTEN

	//STUB PART:
	cout<< "The Attitude Control System is Disattivated" << endl;
}

/**********| BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
// BATTERY HEATER PWM - GPIO 14
	// Battery Thermal Management
void BatteryThermal_Management_ON(){
	Flag_BatteryManagement_Active=1;
	// ACTUAL FUNCTION STILL TO BE WRITTEN
	// Fa partire il Thread con il Regolatore P-I-D che pilota il PWM4 - Gpio14
	Flag_BatteryManagement_Active= TRUE;
	cout << "  Battery ThermalManagement Thread Lanciato! " << endl;

}
void BatteryThermal_Management_OFF(){
	Flag_BatteryManagement_Active=0;
	// ACTUAL FUNCTION STILL TO BE WRITTEN
	// Ferma il Thread con il Regolatore P-I-D
	Flag_BatteryManagement_Active= FALSE;

	//STUB PART:
	cout << "  Battery ThermalManagement Thread Spento " << endl;

}

/**********| WatchDog  Control 	**********************		******/
void Hardware_Watchdog_ON(){ // Questa funzione fa partire il Thread che gestisce il Watchdog Hardware

	Flag_Hardware_Watchdog_Active = TRUE;
	cout << "  Thread Watchdog Hardware Lanciato! " << endl;
}

void Hardware_Watchdog_OFF(){ // Questa funzione ferma Thread che gestisce il Watchdog Hardware

	Flag_Hardware_Watchdog_Active = FALSE;
	cout << "  Thread Watchdog Hardware Fermato! " << endl;
	cout << "  Sistema in Spegnimento ...  " << endl;
}



/**********| LED - TELECOM WATCHDOG  Control  (GPIO 19) *** ******/
void Transmission_Watchdog_ON(){ // Questa funzione fa partire il Thread che gestisce Led-Watchdog
	Flag_Transmission_Watchdog_Active = TRUE;
	cout << "  Thread Watchdog Transmission-Module Lanciato! " << endl;
}
void Transmission_Watchdog_OFF(){ // Questa funzione Ferma il Thread che gestisce Led-Watchdog
	Flag_Transmission_Watchdog_Active = FALSE;
	cout << "  Thread Watchdog Transmission-Module Fermato! " << endl;
}


// Complex Systems - Thread Functions
void thread_ADCS(){
	if(Flag_ADCS_Active == 1){
		// ADCS Algorithm Zone

	}

}
void thread_BatteryPID(){
	if(Flag_BatteryManagement_Active==1){
		// PID Function Zone

	}

}

// Watchdog Thread Functions
void thread_HardwareWD(){ 		// GPIO 20
	// ACTUAL CHIBIOS FUNCTION
	while(1){
		if(Flag_Hardware_Watchdog_Active==1){
			//hal.gpio->write( 20 , 1 );
			//std::this_thread::sleep_for(std::chrono::milliseconds(50));
			//hal.gpio->write( 20, 0 );
			//std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}}
}
void thread_TransmissionWD(){ 	// GPIO 19
	// ACTUAL CHIBIOS FUNCTION
		while(1){
			if(Flag_Transmission_Watchdog_Active==1){
				//hal.gpio->write( 19 , 1 );
				//std::this_thread::sleep_for(std::chrono::milliseconds(50));
				//hal.gpio->write( 19, 0 );
				//std::this_thread::sleep_for(std::chrono::milliseconds(50));
				}
		}
		// Inserire la funzione
		// Trasmetti BEACON
		// Cerca GroundStationBeacon --> fsm.beacon_received=TRUE; //se trovata
}
