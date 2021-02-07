
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
 * FILE: 2_Threads&Handlers.h  - Former GpiosAndFunctions
 * Description: This file(s) Define and describe the core of the Housekeeping of the FEES System
 *
 *  Created on: 14 mar 2019
 *      Author: Stefano Ampolo
 */


void Update_Pin_Mask(int NewState);

void Pin_Mask_All_OFF();
void Pin_Mask_InVector();
void Pin_Mask_Wait();
void Pin_Mask_Detumble();
void Pin_Mask_Nominal();
void Pin_Mask_Transmission();
void Pin_Mask_RADEX();

// There is an important difference Between Lowercase and UPPERCASE
// RESET is the action of turning off - waiting and on again a device
// Reset instead is for setting to 0 the GPIO pin.
void GpioSet(int pin);
void GpioReset(int pin);
// The 2 Funcions Above are used to Set==PUT TO 1 and Reset=PUT TO 0 the GPIO pins ATOMICALLY

// User-friendly -STUB Functions
void print_PinMask();
void print_ThreadsAndManagers();

void print_ADCS_State();
void print_BatteryManagement_State();

// // // POWER MANAGEMENT Functions
void System_Reboot();  // Salva i dati critici nella memoria e resetta il sistema.

/**********| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
void TELECOM_PowerON();
void TELECOM_PowerOFF();
void TELECOM_PowerRESET();

/**********| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ******/
void Analog_PowerON();
void Analog_PowerOFF();
void Analog_PowerRESET();

/**********| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   ******/
void GPS_PowerON();
void GPS_PowerOFF();
void GPS_PowerRESET();

/**********| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
void Iridium_PowerON();
void Iridium_PowerOFF();
void Iridium_PowerRESET();

/**********| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )      ******/
void Radex_PowerON();
void Radex_PowerOFF();
void Radex_PowerRESET();
void Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc

// RADEX SIGNAL
void RADEX();

/**********| RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******     ******/
void RaspberryPi_PowerON();			// GPIO 3
void RaspberryPi_PowerOFF();
void RaspberryPi_PowerRESET();
//GpioReset(RASPY_ON);
//RASPY_KEEP-on thread); 	//KeepON(AliveSignal)  - GPIO 4
void RaspberryPi_Watchdog(); // Questa funzione fa partire il Thread tiene acceso il RaspberryPi

/**********| MagnetoTorquerControl - ADCS SYSTEM  ***** 	******/
void ADCS_ON();
void ADCS_OFF();

/**********| BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
// BATTERY HEATER PWM - GPIO 14
void BatteryThermal_Management_ON();
void BatteryThermal_Management_OFF();

/**********| WatchDog  Control 	**********************		******/
void Hardware_Watchdog_ON(); // Questa funzione fa partire il Thread che gestisce il Watchdog Hardware
void Hardware_Watchdog_OFF();

/**********| LED - TELECOM WATCHDOG  Control  (GPIO 19) *** ******/
void Transmission_Watchdog_ON(); // Questa funzione fa partire il Thread che gestisce Led-Watchdog
void Transmission_Watchdog_OFF();

// Thread for FiniteStateMachine Handling
void thread_Fsm(); // 1Hz Thread loop

// Thread for user Screen Visualization
void thread_UserShell(); // 24hrz Thread loop


void thread_ADCS();
void thread_BatteryPID();
void thread_HardwareWD();
void thread_TransmissionWD();

// FEES TESTING RELATED FUNCTIONS

void print_SystemTime();


// Thread for FiniteStateMachine update-handling
void thread_Fsm();

// Thread for user Screen Visualization
void thread_UserShell();

void pintoggle(char port , int pin);

void Hardware_Watchdog_Refresh();

void TestPins();

void TestBusses();

void PWM_STARTERS_T2_3_VariablePWM();

void Crescendo_PWM_BATTERY();

void Diminuendo_PWM_BATTERY();



#endif // THREADSANDHANDLERS_HPP


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
 * File:FiniteStateMachine.h
 *
 *  Created on: 10 apr 2019
 *      Author: Stefano
 */

#ifndef APPLICATIONSANDFSM_HPP
#define APPLICATIONSANDFSM_HPP

#define TRUE true
#define FALSE false



#include "1_HardwareAndDrivers.hpp"
#include "2_ThreadsAndHandlers.hpp"
#include "3_ApplicationAndFSM.hpp"




enum state_t {
	RECOVER_PREV_STATE = 0, 	// First State after BOOT.
    IN_VECTOR, 					// FEES inside the vector, both Switches still connected
    WAIT_FIRST_TIMER, 			// FEES out of the launcher - First Timer on, 30'
    DETUMBLE_SECOND_TIMER, 		// FEES Detumbling , Second Timer on, Angular speed limit to be decided.
    NOMINAL, 					// FEES NOMINAL STATE - Everything Good.
    TRANSMISSION, 				// FEES Transmission State, Everything else is off.
    RADEX_MODE, 				// FEES RADEX MODE - Programmed Experiment.
};



// DEFINIZIONE DELLE CONSTANTI (IMPOSTAZIONI DI MISSIONE)
const int CONST_SILENZIO_RADIO = 3600 ; // 30 min  --> Requisito di silenzio radio
const int DETHUMBLING_TIMER  = 600 ; 	// 10 min  --> Timer massimo di Dethumbling
const int CONST_RADEX_TIMER = 300;  	// 5 min --> Timer Time-Out del Rad-ex
const int CONST_TRX_TIMER = 300;		// 5 min --> Timer Time-Out Trasmissione
const float CONST_angular_velocity_Limit = 50;	// Valore di Angular_velocity_Limite (per concludere il dethumbling)



void Main_FEES();

void criticalMemoryRead();

void TripleMemoryCheck();

void ParityBitCheck();





class finiteStateMachine {

public:

	void set(state_t a);
	void setPrev(state_t a);
	state_t get();
	state_t getPrev();


	void print_State();
	void print_Menu();
	void print_StateList();
	void print_Variables();
	void event_Handler();
	void human_event_Handler(int a);
	float sample_angular_velocity();


	bool switch_vector;
	bool beacon_received;
	bool radex_scheduled;
	bool radex_finished;
	bool transmission_finished;


	float first_timer;
	float second_timer;
	float timer_for_radex;
	float trx_timer;
	float radex_timer;
	float angular_velocity;

	// Constructor - Destructor
	finiteStateMachine();
	virtual ~finiteStateMachine();

private:
	state_t state;
	state_t previous_state;
};




#endif 	/* APPLICATIONSANDFSM_HPP */

