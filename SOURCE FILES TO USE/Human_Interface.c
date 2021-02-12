uint8_t ALL_OFF_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t IN_VECTOR_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t 	WAIT_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t DETUMBLE_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t NOMINAL_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t TRASMISSION_Array[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t 	RADEX_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t 	ERROR_Array[] 	= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

enum state_name_t {
	RECOVER_PREV_STATE = 0, 	// First State after BOOT.
    IN_VECTOR, 					// FEES inside the vector, both Switches still connected
    WAIT_FIRST_TIMER, 			// FEES out of the launcher - First Timer on, 30'
    DETUMBLE_SECOND_TIMER, 		// FEES Detumbling , Second Timer on, Angular speed limit to be decided.
    NOMINAL, 					// FEES NOMINAL STATE - Everything Good.
    TRANSMISSION, 				// FEES Transmission State, Everything else is off.
    RADEX_MODE, 				// FEES RADEX MODE - Programmed Experiment.
};

struct FEES_State{
	state_name_t state_name;
	uint8_t* Pin_Mask;
	uint8_t* Thread_Mask;
}State;



// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define		ANALOG_PWR_ON	1
#define		GPS_PWR_ON		2

#define		SDB_PWR_ON		29  // Iridium Pwr On
			SDB_ON_OFF		26	// ON-SLEEP


#define		RASPY_ON		3
			RASPY_KEEP

#define		RAD_PWR_ON		5	
			RAD_RESET

			UHF_RESET		


// EX_GPIOS
#define EX_GPIO_1		30
#define	EX_GPIO_2		31
#define	EX_GPIO_3		32
#define	EX_GPIO_4		33

// NOT CONNECTED
#define		PSD_0		7
#define		PSD_1		8
#define		PSD_2		9
#define		PSD_3		10

#define		RADFET_OWB	18

#define		LED_TC_WD	19
#define 	WATCHDOG	20



// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define	BATTERY_HEATER_PWM		PWM(4)
#define	BATTERY_HEATER_GPIO 	14

#define		PWM_X			PWM(1)
#define		PWM_X_GPIO		11

#define		PWM_Y			PWM(2)
#define		PWM_Y_GPIO		12

#define		PWM_Z			PWM(3)
#define		PWM_Z_GPIO		13

#define		DIR_X		15
#define		DIR_Y		16
#define		DIR_Z		17



void Iridium_STUB(){
	int a = rand ();
	if ( a == 0)  FEES_TOGGLE(SDB_0); // DCD
	if ( a == 1 ) FEES_TOGGLE(SDB_1); // DSR
	if ( a == 2 ) FEES_TOGGLE(SDB_2); // DTR
	if ( a == 3 ) FEES_TOGGLE(SDB_3); // CTS
	if ( a == 4 ) FEES_TOGGLE(SDB_4); // RTS
	if ( a == 5 ) FEES_TOGGLE(SDB_5); // RI
	if ( a == 6 ) FEES_TOGGLE(SDB_6); 
}