ARRAY_FSM_HANDLER


// HELPER
// 
//  STATE_VECTOR[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// 0- HW WATCHDOG Thread
// 1- TMTC WATCHDOG Thread
// 2- Ground-Station Lookout Thread
// 3- Beacon Trasmission Thread
// 4- PID BATTERY TEMP Thread
// 5- ADCS Thread
// 6- FSM Thread
// 7- RADEX Thread
// 8- Ground-Station Lookout Thread
// 9- Beacon Trasmission Thread

// 10- Analog_Power_ON
// 11- RAD_Power_ON
// 12- GPS_Power_ON
// 13- IRIDIUM_Power_ON
// 14- 
// 15- 
// 16- 
// 17- 
// 18- 
// 19- 
// 20- 
// 21- 
// 22- 
// 23- 
// 24- 
// 25- RAD_Reset



uint8_t IN_VECTOR[30]=	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t WAIT[30]=		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t DETHUMBLE[30]=	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t NOMINAL[30]=	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t TRASMISSION[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t RADEX[30]=		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t ERROR[30]=		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t EXTRA[30]=		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

