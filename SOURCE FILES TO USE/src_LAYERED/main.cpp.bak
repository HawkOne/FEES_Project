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
 * File: main.cpp
 *
 *  Created on: 14 feb 2019
 *      Author: Stefano Ampolo
 */


//------- COMPILING SETTINGS ----------//

//#define WINDOWS
//#define LINUX

#define BAREMETAL  //ST's HAL LIBRARIES
//#define ARDUPILOT
//#define FREERTOS
//#define CHIBIOS

//#define UNIT_TESTING

//------- ------- ------- ------ ----- //




#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <limits.h>

#include "1_Hardware&Drivers.hpp"
#include "2_Threads&Handlers.hpp"
#include "3_Application&FSM.hpp"

using namespace std;



//void FSM();


void print_SystemTime();

///////////////////////////////////////////
// // //   GLOBAL STATE VARIABLEs  // // //
///////////////////////////////////////////

clock_t startTime;
float deltaTime;

finiteStateMachine fsm; // Finite State Machine definition



int main() {

	cout << " - The FEES System has Started - " << endl << endl;

	startTime = clock(); // Samples the start time (needed to calculate the SystemTime)

	fsm.print_StateList(); 	// Prints out the State list of the FEES System
	fsm.print_Menu();		// Prints out the User-Menu for keyboard Control over the System

	cout << endl;

	cin.get(); 	// Keyboard Sampling


	//System Threads

	thread threadADCS( thread_ADCS);		// Thread for Attitude Determination and Control System.
	thread threadBatteryPID( thread_BatteryPID);	// Thread for Battery thermal management (PID control)
	thread threadHardwareWD( thread_HardwareWD);	// Thread for cyclical reset of the Hardware Watchdog
	thread threadTransmissionWD(thread_TransmissionWD);	// Thread for cyclical sending of the Radio Ping ( Space law requirement)

	thread threadFSM(thread_Fsm); // This thread Handles the FiniteStateMachine and the Pinmask - it Handles the full Housekeeping of the Satellite.

	// User - Testing Threads

	thread threadUserShell(thread_UserShell); // This tread handles the output on screen (PC)



	while(1)
		{
		cout << "--> Dai un comando - Esegui un evento: " << endl << endl;
		int input;
		cin >> input;
		while (!cin.good())
			{
		    cin.clear();
		    cin.ignore(INT_MAX, '\n');
		    cout << " Non e' stato inserito un valore corretto! (int)" << endl << flush ;
		    cout << "Esegui un evento: " << endl;
		    cin >> input;
			}
		fsm.human_event_Handler(input);
	    }
}


// end main







// Thread for FiniteStateMachine update-handling
void thread_Fsm(){ // 1Hz Thread loop
	while(1){
    	fsm.event_Handler();
		// Sleep this thread for 1000 MilliSeconds (to time all 1 second)
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1000
	}
}


// Thread for user Screen Visualization
void thread_UserShell(){ // 24hrz Thread loop
	while(1)
		{
		print_SystemTime();
    	fsm.print_State();
    	fsm.print_Variables();
    	print_ThreadsAndManagers();
		print_PinMask();

		fsm.print_Menu();
		// Sleep this thread for 500 MilliSeconds
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1000


#ifdef WINDOWS
		system("CLS");
#endif // WINDOWS

#ifdef LINUX
		std::system("clear");
#endif // LINUX

	}
}



void print_SystemTime(){
	deltaTime = (( std::clock() - startTime )) / (float) CLOCKS_PER_SEC;
	cout << "\r  System Time is:  "<< deltaTime << endl;
}

