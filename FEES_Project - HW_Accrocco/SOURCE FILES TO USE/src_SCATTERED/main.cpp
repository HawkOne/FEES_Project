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
 *      Author: Stefano
 */

#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <limits.h>

#include "finiteStateMachine.h"
#include "GpiosAndFunctions.h"

using namespace std;



//void FSM();


//  This part of the code is needed to create the wait function
void wait ( int seconds ){
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}


void print_SystemTime();

///////////////////////////////////////////
// // //   GLOBAL STATE VARIABLE   // // //
///////////////////////////////////////////
clock_t startTime;
double deltaTime;

finiteStateMachine fsm;

int main() {

	cout << " - The FEES System has Started - " << endl << endl;
	startTime = clock();

	fsm.print_StateList();
	fsm.print_Menu();
	cout << endl;

	cin.get();

	thread threadFSM(thread_Fsm); // Gestisce la macchina a stati (E la PinMask)

	thread threadUserShell(thread_UserShell); // Gestisce l'output a stampa su schermo


	//ThreadS che gestiscono le funzioni di sistema

	thread threadADCS( thread_ADCS);
	thread threadBatteryPID( thread_BatteryPID);
	thread threadHardwareWD( thread_HardwareWD);
	thread threadTransmissionWD(thread_TransmissionWD);


	    while(1){
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



// Thread for FiniteStateMachine Handling Creation
void thread_Fsm(){ // 1Hz Thread loop
	while(1){
    	fsm.event_Handler();
		// Sleep this thread for 1000 MilliSeconds (to time all 1 second)
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1000
	}
}

// Thread for user Screen Visualization
void thread_UserShell(){ // 24hrz Thread loop
	while(1){
		//th.lock
		print_SystemTime();
    	fsm.print_State();
    	fsm.print_Variables();
    	print_ThreadsAndManagers();
		print_PinMask();

		cout << endl;
		fsm.print_Menu();
		//th.lock
		// Sleep this thread for 1000 MilliSeconds (to time all 1 second)
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); //1000

		system("CLS");

	}
}




void print_SystemTime(){
	deltaTime = ( std::clock() - startTime ) / (double) CLOCKS_PER_SEC;
	cout << "  System Time is:  "<< deltaTime << endl;
}

