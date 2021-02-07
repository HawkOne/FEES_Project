/*
 * CatchTest.cpp
 *
 *  Created on: 18 apr 2020
 *      Author: Stefano
 */


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <limits.h>

#include "../src/finiteStateMachine.h"
#include "../src/GpioMapper.h"
#include "../src/GpiosAndFunctions.h"


using namespace std;



// Creazione dell'Oggetto da testare
finiteStateMachine fsm;

//Testing Delle funzioni FSM.cpp

//TEST_CASE( "TEST Update_Pin_Mask (a) " ) {
//	Update_Pin_Mask(a);
//	REQUIRE( ... );
//}


TEST_CASE( "TEST finiteStateMachine::set(state_t a) " ) {
	fsm->state=IN_VECTOR;
	 REQUIRE( fsm->state == IN_VECTOR; );
	fsm.set(WAIT_FIRST_TIMER);
	 REQUIRE( fsm->previous_state == WAIT_FIRST_TIMER; );
}


TEST_CASE( "TEST finiteStateMachine::get()" ) {
	fsm.set(WAIT_FIRST_TIMER);
	REQUIRE( fsm->previous_state == WAIT_FIRST_TIMER; );
	REQUIRE( fsm.get() == WAIT_FIRST_TIMER; );
}

TEST_CASE( "TEST finiteStateMachine::event_Handler()" ) {

	//Unknown Phase

	fsm->state=RECOVER_PREV_STATE;
	fsm->previous_state=TRANSMISSION;

	fsm.event_Handler(); // TEST FUNCTION
	REQUIRE( fsm->state == TRANSMISSION; );
	REQUIRE( fsm->previous_state == TRANSMISSION; );




	//Launch Phase Test


	fsm->state=IN_VECTOR;
	fsm->previous_state=IN_VECTOR;

	fsm->switch_vector= 1;
	fsm.event_Handler(); // TEST FUNCTION


	REQUIRE( fsm->state == WAIT_FIRST_TIMER; );
	REQUIRE( fsm->previous_state == WAIT_FIRST_TIMER; );



	fsm->state=WAIT_FIRST_TIMER;
	fsm->previous_state=WAIT_FIRST_TIMER;

	fsm->first_timer = 0;
	fsm.event_Handler(); // TEST FUNCTION


	REQUIRE( fsm->state == DETUMBLE_SECOND_TIMER; );
	REQUIRE( fsm->previous_state == DETUMBLE_SECOND_TIMER; );




	fsm->state=DETUMBLE_SECOND_TIMER;
	fsm->previous_state=DETUMBLE_SECOND_TIMER;

	fsm->second_timer = 0;
	fsm.event_Handler(); // TEST FUNCTION


	REQUIRE( fsm->state == NOMINAL; );
	REQUIRE( fsm->previous_state == NOMINAL; );


	//w>wLim
	fsm->state=DETUMBLE_SECOND_TIMER;
	fsm->previous_state=DETUMBLE_SECOND_TIMER;

	fsm->angular_velocity()= 3500;
	fsm.event_Handler(); // TEST FUNCTION

	REQUIRE( fsm->state == NOMINAL; );
	REQUIRE( fsm->previous_state == NOMINAL; );

	//w<wLim
	fsm->state=DETUMBLE_SECOND_TIMER;
	fsm->previous_state=DETUMBLE_SECOND_TIMER;

	fsm->angular_velocity()= 49;
	fsm.event_Handler(); // TEST FUNCTION

	REQUIRE( fsm->state == NOMINAL; );
	REQUIRE( fsm->previous_state == NOMINAL; );



	// ORBIT PHASE

	// From Nominal to Transmission
	fsm->state=NOMINAL;
	fsm->previous_state=NOMINAL;


	fsm->beacon_received=true;
	fsm->transmission_finished=false;
	fsm->trx_timer = CONST_TRX_TIMER;

	fsm.event_Handler();  // TEST FUNCTION

	REQUIRE( fsm->state == TRANSMISSION; );
	REQUIRE( fsm->previous_state == TRANSMISSION; );

	// From Nominal to Transmission
	fsm->state=NOMINAL;
	fsm->previous_state=NOMINAL;

	fsm->beacon_received=true;

	fsm.event_Handler();  // TEST FUNCTION

	REQUIRE( fsm->state == TRANSMISSION; );
	REQUIRE( fsm->previous_state == TRANSMISSION; );






	//From Nominal to Radex

	fsm->state=NOMINAL;
	fsm->previous_state=NOMINAL;


	fsm->timer_for_radex ;
	fsm->radex_scheduled=true;
	fsm->radex_finished=false;

	fsm.event_Handler();  // TEST FUNCTION

	REQUIRE( fsm->state == RADEX_MODE; );
	REQUIRE( fsm->previous_state == RADEX_MODE; );




	// Test  From Transmission to Nominal

	fsm->state=TRANSMISSION;
	fsm->previous_state=TRANSMISSION;

	fsm->transmission_finished=true;

	fsm.event_Handler();  // TEST FUNCTION

	REQUIRE( fsm->state == NOMINAL; );
	REQUIRE( fsm->previous_state == NOMINAL; );



	// Test  From Radex to Nominal

	fsm->state=RADEX_MODE;
	fsm->previous_state=RADEX_MODE;

	fsm->radex_finished=true;

	fsm.event_Handler();  // TEST FUNCTION

	REQUIRE( fsm->state == NOMINAL; );
	REQUIRE( fsm->previous_state == NOMINAL; );



}




TEST_CASE( "TEST della FSM - Passaggi di Stato", "[FSM-]" ) {

	fsm->state=IN_VECTOR;

	 REQUIRE( fsm->state == IN_VECTOR; );
	 REQUIRE( fsm->previous_state == 0; );

}




TEST_CASE( "TEST della FSM - Passaggi di Stato", "[FSM-]" ) {

//    Modifica:     ES  std::vector<int> v( 5 );
//    Condizioni :  ES  REQUIRE( v.size() == 5 );

    GIVEN( "Partendo da IN_VECTOR" ) {
        fsm->state=IN_VECTOR;

        REQUIRE( fsm->state == IN_VECTOR; );
        REQUIRE( fsm->previous_state == 0; );



        WHEN( "Se faccio scattare il switch_vector" ) {
            fsm->switch_vector = 1;

            THEN( "Allora passerá automaticamente a WAIT_FIRST_TIMER" ) {
                REQUIRE( fsm->state == WAIT_FIRST_TIMER; );
                REQUIRE( fsm->previous_state == WAIT_FIRST_TIMER; );
            }
        }
    }
}




//
// SECTION( "resizing bigger changes size and capacity" ) {
//         v.resize( 10 );
//    
//         REQUIRE( v.size() == 10 );
//         REQUIRE( v.capacity() >= 10 );
//     }


//TEST_CASE( "Factorial of 0 is 1 (fail)", "[single-file]" ) {

//    Modifica:         std::vector<int> v( 5 );
//    Condizioni :      REQUIRE( v.size() == 5 );
//
// SECTION( "resizing bigger changes size and capacity" ) {
//         v.resize( 10 );
//    
//         REQUIRE( v.size() == 10 );
//         REQUIRE( v.capacity() >= 10 );
//     }

//}

//TEST_CASE( "Factorials of 1 and higher are computed (pass)", "[single-file]" ) {
//    Modifica:         std::vector<int> v( 5 );
//    Condizioni :      REQUIRE( v.size() == 5 );
//
// SECTION( "resizing bigger changes size and capacity" ) {
//         v.resize( 10 );
//    
//         REQUIRE( v.size() == 10 );
//         REQUIRE( v.capacity() >= 10 );
//     }

//}










// SCENARIO( "vectors can be sized and resized", "[vector]" ) {

//     GIVEN( "A vector with some items" ) {
//         std::vector<int> v( 5 );

//         REQUIRE( v.size() == 5 );
//         REQUIRE( v.capacity() >= 5 );

//         WHEN( "the size is increased" ) {
//             v.resize( 10 );

//             THEN( "the size and capacity change" ) {
//                 REQUIRE( v.size() == 10 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "the size is reduced" ) {
//             v.resize( 0 );

//             THEN( "the size changes but not capacity" ) {
//                 REQUIRE( v.size() == 0 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//         WHEN( "more capacity is reserved" ) {
//             v.reserve( 10 );

//             THEN( "the capacity changes but not the size" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "less capacity is reserved" ) {
//             v.reserve( 0 );

//             THEN( "neither size nor capacity are changed" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//     }
// }
