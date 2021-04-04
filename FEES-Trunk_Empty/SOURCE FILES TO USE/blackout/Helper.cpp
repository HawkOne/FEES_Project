//------- COMPILING SETTINGS ----------//




//#ifdef WINDOWS
//#ifdef LINUX

#define BAREMETAL  //ST's HAL LIBRARIES
//#define ARDUPILOT
//#define FREERTOS
//#define CHIBIOS

//#define UNIT_TESTING

//------- ------- ------- ------ ----- //






#ifdef WINDOWS

#endif // WINDOWS


#ifdef LINUX

#endif // LINUX


#ifdef BAREMETAL

#endif // BAREMETAL


#ifdef ARDUPILOT

#endif // ARDUPILOT


#ifdef FREERTOS

#endif // FREERTOS


#ifdef CHIBIOS

#endif // CHIBIOS

#ifdef STUB

#endif // STUB


#ifdef UNIT_TESTING

#endif // UNIT_TESTING


HAL_UART_Transmit(&huart3, DATA, sizeof(DATA), 100);
