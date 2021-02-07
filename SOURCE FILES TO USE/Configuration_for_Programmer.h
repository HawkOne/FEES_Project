
#ifndef CONFIGURATION_FOR_PROGRAMMER_H
#define CONFIGURATION_FOR_PROGRAMMER_H

#define TRUE 1
#define FALSE 0


#define BARE_METAL  0
#define CHIBIOS  0
#define ARDUPILOT  0

#define STM32_HAL  1
#define STM32 IF(STM32_HAL)			// Useful for Inline mode.

#define FREERTOS  1


#define UNIT_TESTING  1			// Flag to switch to Debug Mode
#define TEST IF(UNIT_TESTING)		// Useful for Inline mode.


#define SERIAL_DEBUG  1			// Flag to switch to Debug Mode
#define DEBUG IF(SERIAL_DEBUG)		// Useful for Inline mode.


#endif //CONFIGURATION_FOR_PROGRAMMER_H