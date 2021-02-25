/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

//------- COMPILING SETTINGS ----------//

//#define WINDOWS
//#define LINUX

//#define ARDUPILOT
//#define FREERTOS
//#define CHIBIOS

#define BAREMETAL  //ST's HAL LIBRARIES
#define FREERTOS
#define STM32HAL

//#define UNIT_TESTING

//------- ------- ------- ------ ----- //



//FEES RELATED INCLUDES

#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include <limits.h>


//#include "../1_Hardware&Drivers.hpp"
//#include "../2_Threads&Handlers.hpp"
//#include "../3_Application&FSM.hpp"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;
SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

PCD_HandleTypeDef hpcd_USB_OTG_FS;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for Task1 */
osThreadId_t Task1Handle;
uint32_t Task1Buffer[ 128 ];
osStaticThreadDef_t Task1ControlBlock;
const osThreadAttr_t Task1_attributes = {
  .name = "Task1",
  .stack_mem = &Task1Buffer[0],
  .stack_size = sizeof(Task1Buffer),
  .cb_mem = &Task1ControlBlock,
  .cb_size = sizeof(Task1ControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task2 */
osThreadId_t Task2Handle;
uint32_t Task2Buffer[ 128 ];
osStaticThreadDef_t Task2ControlBlock;
const osThreadAttr_t Task2_attributes = {
  .name = "Task2",
  .stack_mem = &Task2Buffer[0],
  .stack_size = sizeof(Task2Buffer),
  .cb_mem = &Task2ControlBlock,
  .cb_size = sizeof(Task2ControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task3 */
osThreadId_t Task3Handle;
uint32_t Task3Buffer[ 128 ];
osStaticThreadDef_t Task3ControlBlock;
const osThreadAttr_t Task3_attributes = {
  .name = "Task3",
  .stack_mem = &Task3Buffer[0],
  .stack_size = sizeof(Task3Buffer),
  .cb_mem = &Task3ControlBlock,
  .cb_size = sizeof(Task3ControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task4 */
osThreadId_t Task4Handle;
uint32_t Task4Buffer[ 128 ];
osStaticThreadDef_t Task4ControlBlock;
const osThreadAttr_t Task4_attributes = {
  .name = "Task4",
  .stack_mem = &Task4Buffer[0],
  .stack_size = sizeof(Task4Buffer),
  .cb_mem = &Task4ControlBlock,
  .cb_size = sizeof(Task4ControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task5 */
osThreadId_t Task5Handle;
uint32_t Task5Buffer[ 128 ];
osStaticThreadDef_t Task5ControlBlock;
const osThreadAttr_t Task5_attributes = {
  .name = "Task5",
  .stack_mem = &Task5Buffer[0],
  .stack_size = sizeof(Task5Buffer),
  .cb_mem = &Task5ControlBlock,
  .cb_size = sizeof(Task5ControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task6 */
osThreadId_t Task6Handle;
uint32_t TaskBuffer[ 128 ];
osStaticThreadDef_t TaskControlBlock;
const osThreadAttr_t Task6_attributes = {
  .name = "Task6",
  .stack_mem = &TaskBuffer[0],
  .stack_size = sizeof(TaskBuffer),
  .cb_mem = &TaskControlBlock,
  .cb_size = sizeof(TaskControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
static void MX_SPI3_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USB_OTG_FS_PCD_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
void StartDefaultTask(void *argument);
void Task01(void *argument);
void Task02(void *argument);
void Task03(void *argument);
void Task04(void *argument);
void Task05(void *argument);
void Task06(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include "main.h"
#include <string.h>



typedef struct{
    GPIO_TypeDef * PORT__BASE;
	int pin_number;
	uint8_t address;
}FEES_Pin;



// PWM_ CONTROL
FEES_Pin PWM_HEATER;
FEES_Pin PWM_X_COIL;
FEES_Pin PWM_Y_COIL;
FEES_Pin PWM_Z_COIL;
// GPIO DI DIREZIONE
FEES_Pin DIR_X_COIL;
FEES_Pin DIR_Y_COIL;
FEES_Pin DIR_Z_COIL;
//GPIO DI CONTROLLO
FEES_Pin WATCHDOG;
FEES_Pin UHF_RESET;
FEES_Pin RAD_RESET;
FEES_Pin RADFET_OWB;
FEES_Pin TMTC_WD;
FEES_Pin ANA_PWR_ON;
FEES_Pin RAD_PWR_ON;
FEES_Pin GPS_PWR_ON;
FEES_Pin SBD_PWR_ON;
FEES_Pin RSBY_PWR_ON;
FEES_Pin RSBY_KEEP_EN;
//CS_SPI_SENSORI
FEES_Pin CS_NAND;
FEES_Pin CS_LORA;
FEES_Pin CS_RADFET;
FEES_Pin EN_ADC1;
FEES_Pin EN_ADC2;
FEES_Pin EN_ADC3;
FEES_Pin EXT_SPI_EN;
FEES_Pin CS_EEPROM;
FEES_Pin CS_FRAM;
FEES_Pin CS_PSD1_AMP;
FEES_Pin CS_PSD2_AMP;
FEES_Pin CS_GYRO;
FEES_Pin CS_GYRO2;
// GPIO EXTRA
FEES_Pin EX_GPIO1;
FEES_Pin EX_GPIO2;
FEES_Pin EX_GPIO3;
FEES_Pin EX_GPIO4;
// Select
FEES_Pin PSD1_SEL0;
FEES_Pin PSD1_SEL1;
FEES_Pin PSD2_SEL0;
FEES_Pin PSD2_SEL1;
// IMU
FEES_Pin INT_GYRO1;
FEES_Pin INT_GYRO2;
// Radex
FEES_Pin RAD_RESET;
FEES_Pin RADFET_OWB;
//SDB
FEES_Pin SDB_ON_OFF;
FEES_Pin SDB_SER_RI;
FEES_Pin SDB_SER_NET;
FEES_Pin SDB_SER_DCD;
FEES_Pin SDB_SER_DSR;
FEES_Pin SDB_SER_DTR;
FEES_Pin SDB_SER_CTS;
FEES_Pin SDB_SER_RTS;
// Other
FEES_Pin USB_VBUS;
FEES_Pin PGOOD;

FEES_Pin JTAG_TMS;
FEES_Pin JTAG_TCK;


void FEES_Init(){

    // Battery Heater PWM
    PWM_HEATER.PORT__BASE = GPIOC ;
    PWM_HEATER.pin_number =  8;

    // PWM COILS - MagnetoTorquers
    PWM_X_COIL.PORT__BASE = GPIOA ;
    PWM_X_COIL.pin_number =  0;

    PWM_Y_COIL.PORT__BASE = GPIOA ;
    PWM_Y_COIL.pin_number =  1;

    PWM_Z_COIL.PORT__BASE = GPIOA ;
    PWM_Z_COIL.pin_number =  2;

    // Direction PWM Magnetometers
    DIR_X_COIL.PORT__BASE = GPIOE ;
    DIR_X_COIL.pin_number =  7;

    DIR_Y_COIL.PORT__BASE = GPIOE ;
    DIR_Y_COIL.pin_number =  8;

    DIR_Z_COIL.PORT__BASE = GPIOE ;
    DIR_Z_COIL.pin_number =  9;

    //GPIO DI CONTROLLO E WATCHDOG
    WATCHDOG.PORT__BASE = GPIOB ;
    WATCHDOG.pin_number =  5;

    UHF_RESET.PORT__BASE = GPIOC ;
    UHF_RESET.pin_number =  13;

    RAD_RESET.PORT__BASE = GPIOC ;
    RAD_RESET.pin_number =  15;

    TMTC_WD.PORT__BASE = GPIOD ;
    TMTC_WD.pin_number =  12;

    RSBY_KEEP_EN.PORT__BASE = GPIOB ;
    RSBY_KEEP_EN.pin_number =  0;


    //GPIO DI CONTROLLO Alimentazione (Power Control)
    ANA_PWR_ON.PORT__BASE = GPIOE ;
    ANA_PWR_ON.pin_number =  0;

    RAD_PWR_ON.PORT__BASE = GPIOE ;
    RAD_PWR_ON.pin_number =  1;

    GPS_PWR_ON.PORT__BASE = GPIOE ;
    GPS_PWR_ON.pin_number =  2;

    SBD_PWR_ON.PORT__BASE = GPIOE ;
    SBD_PWR_ON.pin_number =  3;

    RSBY_PWR_ON.PORT__BASE = GPIOE ;
    RSBY_PWR_ON.pin_number =  6;


    // SPI SMART PINS - Sensors
    CS_NAND.PORT__BASE = GPIOE ;
    CS_NAND.pin_number =  4;

    CS_LORA.PORT__BASE = GPIOE ;
    CS_LORA.pin_number =  5;

    CS_RADFET.PORT__BASE = GPIOA ;
    CS_RADFET.pin_number = 4 ;

    CS_EEPROM.PORT__BASE = GPIOD;
    CS_EEPROM.pin_number =  10;

    CS_FRAM.PORT__BASE =  GPIOD;
    CS_FRAM.pin_number =  11;

    CS_PSD1_AMP.PORT__BASE = GPIOC  ;
    CS_PSD1_AMP.pin_number =  4;

    CS_PSD2_AMP.PORT__BASE =  GPIOC;
    CS_PSD2_AMP.pin_number =  5;

    CS_GYRO.PORT__BASE =  GPIOE;
    CS_GYRO.pin_number =  10;

    CS_GYRO2.PORT__BASE =  GPIOD;
    CS_GYRO2.pin_number =  14;

    EN_ADC1.PORT__BASE = GPIOE ;
    EN_ADC1.pin_number =  11;

    EN_ADC2.PORT__BASE = GPIOE ;
    EN_ADC2.pin_number =  13 ;

    EN_ADC3.PORT__BASE = GPIOE ;
    EN_ADC3.pin_number =  12 ;

    EXT_SPI_EN.PORT__BASE = GPIOC ;
    EXT_SPI_EN.pin_number =  9 ;

    // GPIO EXTRA
    EX_GPIO1.PORT__BASE = GPIOB;
    EX_GPIO1.pin_number =  1;

    EX_GPIO2.PORT__BASE =  GPIOB;
    EX_GPIO2.pin_number =  12;

    EX_GPIO3.PORT__BASE =  GPIOA;
    EX_GPIO3.pin_number =  3;

    EX_GPIO4.PORT__BASE =  GPIOA;
    EX_GPIO4.pin_number =  10;


  		// Select
    PSD1_SEL0.PORT__BASE = GPIOC ;
    PSD1_SEL0.pin_number = 1 ;

    PSD1_SEL1.PORT__BASE = GPIOC ;
    PSD1_SEL1.pin_number = 0 ;

    PSD2_SEL0.PORT__BASE = GPIOC ;
    PSD2_SEL0.pin_number = 3 ;

    PSD2_SEL1.PORT__BASE = GPIOC ;
    PSD2_SEL1.pin_number = 2 ;

 		// IMU
    INT_GYRO1.PORT__BASE = GPIOD ;
    INT_GYRO1.pin_number = 13 ;

    INT_GYRO2.PORT__BASE = GPIOD;
    INT_GYRO2.pin_number = 15 ;
  		// Radex
    RAD_RESET.PORT__BASE = GPIOC  ;
    RAD_RESET.pin_number = 15 ;

    RADFET_OWB.PORT__BASE = GPIOC ;
    RADFET_OWB.pin_number = 14 ;
  		//SDB
    SDB_ON_OFF.PORT__BASE = GPIOD ;
    SDB_ON_OFF.pin_number =  7;

    SDB_SER_RI.PORT__BASE = GPIOE ;
    SDB_SER_RI.pin_number = 14 ;

    SDB_SER_NET.PORT__BASE = GPIOE ;
    SDB_SER_NET.pin_number = 15 ;

    SDB_SER_DCD.PORT__BASE = GPIOD ;
    SDB_SER_DCD.pin_number = 0 ;

    SDB_SER_DSR.PORT__BASE = GPIOD ;
    SDB_SER_DSR.pin_number = 1;

    SDB_SER_DTR.PORT__BASE = GPIOD ;
    SDB_SER_DTR.pin_number = 2 ;

    USB_VBUS.PORT__BASE = GPIOA ;
    USB_VBUS.pin_number = 9 ;
  		// Other
    PGOOD.PORT__BASE = GPIOA ;
    PGOOD.pin_number = 8 ;

    JTAG_TMS.PORT__BASE = GPIOA ;
    JTAG_TMS.pin_number = 13 ;

    JTAG_TCK.PORT__BASE = GPIOA ;
    JTAG_TCK.pin_number = 14 ;

}




void FEES_SPI_1(uint8_t* data, FEES_Pin FeesPinVariabile){
#ifdef STM32HAL
	HAL_SPI_Init(&hspi1);
	FEES_Pin_ON(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
	HAL_SPI_Transmit(&hspi1, sizeof(data), 10, 100);
	FEES_Pin_OFF(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
#endif
}

void FEES_SPI_2(uint8_t* data, FEES_Pin FeesPinVariabile){
#ifdef STM32HAL
	HAL_SPI_Init(&hspi2);
	FEES_Pin_ON(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
	HAL_SPI_Transmit(&hspi2, sizeof(data), 10, 100);
	FEES_Pin_OFF(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
#endif
}

void FEES_SPI_3(uint8_t* data, FEES_Pin FeesPinVariabile){
#ifdef STM32HAL
	HAL_SPI_Init(&hspi3);
	FEES_Pin_ON(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
	HAL_SPI_Transmit(&hspi3, sizeof(data), 10, 100);
	FEES_Pin_OFF(FeesPinVariabile.PORT__BASE, FeesPinVariabile.pin_number);
#endif
}


void FEES_I2C_1(uint8_t* data, FEES_Pin FeesPinVariabile){
#ifdef STM32HAL
	HAL_I2C_Init(&hi2c1);
	FeesPinVariabile.address;

	HAL_I2C_Master_Transmit(&hi2c1, 0x11, data, sizeof(data), 100);
#endif
}

void FEES_I2C_2(uint8_t* data){
#ifdef STM32HAL
	HAL_I2C_Init(&hi2c2);
	HAL_I2C_Master_Transmit(&hi2c2, 0x11, data, sizeof(data), 100);
#endif
}



//
//    uint8_t Buffer[15]={ 0xFF, 0xFF, 0xFF,0x00,0x00,0xFF,0xFF,0x00,0xFF,0x00, 0x55, 0xAA, 0x80, 0x80, 0xAA};
//
//    	// TEST I2C Busses
//    HAL_I2C_Init(&hi2c1);
//    HAL_I2C_Init(&hi2c2);
//
//    HAL_I2C_Master_Transmit(&hi2c1, 0x11, Buffer, 15, 100);
//    HAL_I2C_Master_Transmit(&hi2c2, 0x22, Buffer, 15, 100);
//    osDelay(1);
//
//        // TEST SPI
//    HAL_SPI_Init(&hspi1);
//    HAL_SPI_Init(&hspi2);
//    HAL_SPI_Init(&hspi3);
//
//    HAL_SPI_Transmit(&hspi1, Buffer, 10, 100);
//    HAL_SPI_Transmit(&hspi2, Buffer, 10, 100);
//    HAL_SPI_Transmit(&hspi3, Buffer, 10, 100);
//    osDelay(1);


// FEES_Printf s  Are custom-made functions to print out in one of the 4  serial busses.  (standard print is in serial bus 2 )

void FEES_Printf(char* string){
#ifdef STM32HAL
	HAL_UART_Transmit(&huart2, string, strlen(string), 100);
#endif
}

void FEES_Printf1(char* string){

#ifdef STM32HAL
	HAL_UART_Transmit(&huart1, string, strlen(string), 100);
#endif
}

void FEES_Printf2(char* string){

#ifdef STM32HAL
	HAL_UART_Transmit(&huart2, string, strlen(string), 100);
#endif
}

void FEES_Printf3(char* string){

#ifdef STM32HAL
	HAL_UART_Transmit(&huart3, string, strlen(string), 100);
#endif
}

void FEES_Printf4(char* string){

#ifdef STM32HAL
	HAL_UART_Transmit(&huart6, string, strlen(string), 100);
#endif
}


// FEES_Pin ON/OFF/Toggle are functions made for controlling GPIOS by PortLetter and Number
// You can also use the GPIOS by using the standard ST - HAL functions, for example:
// FEES_Pin_ON('A',0); // LED=PORTA0  // HAL_GPIO_WritePin(LEDX_GPIO_Port, LEDX_Pin , 1);

void FEES_Pin_ON( GPIO_TypeDef * PORT__BASE  ,  int pin_number){

#ifdef STM32HAL
	HAL_GPIO_WritePin(PORT__BASE, pin_number, 1);
#endif
}

void FEES_Pin_OFF( GPIO_TypeDef * PORT__BASE  ,  int pin_number){

#ifdef STM32HAL
	HAL_GPIO_WritePin(PORT__BASE, pin_number, 0);
#endif
}

void FEES_Pin_Toggle(char port , int pin, int delay){
	GPIO_TypeDef * PORT__BASE;
	uint16_t pin_number=0;

	switch (port){
		case 'a': PORT__BASE = GPIOA;
		break;
		case 'b': PORT__BASE = GPIOB;
		break;
		case 'c': PORT__BASE = GPIOC;
		break;
		case 'd': PORT__BASE = GPIOD;
		break;
		case 'e': PORT__BASE = GPIOE;
		break;
		default: PORT__BASE = GPIOA;
		break;
		}


	pin_number = 1<<pin;

	/*
	switch (pin){
		case 0: pin_number = 0x0001;
		break;
		case 1: pin_number = 0x0002;
		break;
		case 2: pin_number = 0x0004;
		break;
		case 3: pin_number = 0x0008;
		break;
		case 4: pin_number = 0x0010;
		break;
		case 5: pin_number = 0x0020;
		break;
		case 6: pin_number = 0x0040;
		break;
		case 7: pin_number = 0x0080;
		break;
		case 8: pin_number = 0x0100;
		break;
		case 9: pin_number = 0x0200;
		break;
		case 10: pin_number = 0x0400;
		break;
		case 11: pin_number = 0x0800;
		break;
		case 12: pin_number = 0x1000;
		break;
		case 13: pin_number = 0x2000;
		break;
		case 14: pin_number = 0x4000;
		break;
		case 15: pin_number = 0x8000;
		break;
		}
	*/

	FEES_Pin_ON(PORT__BASE, pin_number);
	osDelay(delay);
	FEES_Pin_OFF(PORT__BASE, pin_number);
    //osDelay(20);
}

void FEES_TestPins(int delay){
	   	  // PWM_ CONTROL
    FEES_Pin_Toggle('c',8,delay);  // PWM_HEATER - BATTERY

    FEES_Pin_Toggle('a',0,delay);  // PWM_X_COIL
    FEES_Pin_Toggle('a',1,delay);  // PWM_Y_COIL
    FEES_Pin_Toggle('a',2,delay);  // PWM_Z_COIL

         // GPIO DI DIREZIONE
    FEES_Pin_Toggle('e',7,delay);	// Dir_X
    FEES_Pin_Toggle('e',8,delay);	// Dir_Y
    FEES_Pin_Toggle('e',9,delay);	// Dir_Z

    	//GPIO DI CONTROLLO
    //FEES_Pin_Toggle('b',5,delay);	// WATCHDOG

    FEES_Pin_Toggle('c',13,delay); 	// UHF_RESET

    // FEES_Pin_Toggle('c',15,delay); 	//RAD RESET

    FEES_Pin_Toggle('d',12,delay); 	// TMTC_WD
    FEES_Pin_Toggle('e',0,delay);	// ANA_PWR_ON
    FEES_Pin_Toggle('e',1,delay);	// RAD_PWR_ON
    FEES_Pin_Toggle('e',3,delay);	// SBD_PWR_ON
    FEES_Pin_Toggle('e',2,delay);	// GPS_PWR_ON
    FEES_Pin_Toggle('e',6,delay);	// RSBY_PWR_ON
    FEES_Pin_Toggle('b',0,delay);	// RSBY_KEEP_EN


         //CS_SPI_SENSORI
    FEES_Pin_Toggle('e',4,delay);  	// CS_NAND
    FEES_Pin_Toggle('e',5,delay);  	// CS_LORA
    FEES_Pin_Toggle('a',4,delay);	// CS_RADFET
    FEES_Pin_Toggle('e',11,delay);	// EN_ADC1
    FEES_Pin_Toggle('e',13,delay);	// EN_ADC2
    FEES_Pin_Toggle('e',12,delay);	// EN_ADC3
    FEES_Pin_Toggle('c',9,delay);  	// EXT_SPI_EN
    FEES_Pin_Toggle('d',10,delay);	// CS_EEPROM
    FEES_Pin_Toggle('d',11,delay);	// CS_FRAM
    FEES_Pin_Toggle('c',4,delay);  	// CS_PSD1_AMP
    FEES_Pin_Toggle('c',5,delay);   // CS_PSD2_AMP
    FEES_Pin_Toggle('e',10,delay);  // CS_GYRO
    FEES_Pin_Toggle('d',14,delay);  // CS_GYRO2

    // GPIO EXTRA
	 FEES_Pin_Toggle('b',1,delay);	// EX_GPIO1
	 FEES_Pin_Toggle('b',12,delay);	// EX_GPIO2
	 FEES_Pin_Toggle('a',3,delay);	// EX_GPIO3
	 FEES_Pin_Toggle('a',10,delay);	// EX_GPIO4

     // Other Signals

	 if(1){
	 FEES_Pin_Toggle('c',1,delay); 	 // P1_S0
	 FEES_Pin_Toggle('c',0,delay); 	 // P1_S1
	 FEES_Pin_Toggle('c',3,delay); 	 // P2_S0
	 FEES_Pin_Toggle('c',2,delay); 	 // P2_S1
	 }


	 FEES_Pin_Toggle('c',2,delay); 	 // P2_S1
	 // PIN SBAGLIATI

	 FEES_Pin_Toggle('d',7,delay); 	// sdb on off
	 FEES_Pin_Toggle('d',13,delay);  // Int_Gyro

	 FEES_Pin_Toggle('c',15,delay);  // RAD_RESET
	 FEES_Pin_Toggle('c',14,delay);  // RADFET_OWB
	 FEES_Pin_Toggle('d',15,delay);  // Int_Gyro2

	 FEES_Pin_Toggle('e',14,delay); // sbd ser ri
	 FEES_Pin_Toggle('e',15,delay); // sdb ser net
	 FEES_Pin_Toggle('d',0,delay); 	// sdb ser dcd

	 FEES_Pin_Toggle('d',1,delay); 	// sdb ser dsr
	 FEES_Pin_Toggle('d',2,delay); 	// sdb ser dtr

//	 FEES_Pin_Toggle('a',9,delay); 	// usb_vbussdb ser dcd
//	 FEES_Pin_Toggle('a',13,delay); // JTAG  tms
//	 FEES_Pin_Toggle('a',14,delay); // JTAG  tck

	 FEES_Pin_Toggle('a',8,delay);  // PGOOD
}


void FEES_RandomPinToggle(){
	int numero = rand() % 16;
	int nporta = rand() % 6;
	char porta;
	if (nporta == 1 ) { 	porta= 'a';}
	if (nporta == 2 ) { 	porta= 'b';}
	if (nporta == 3 ) { 	porta= 'c';}
	if (nporta == 4 ) { 	porta= 'd';}
	if (nporta == 5 ) { 	porta= 'e';}

    FEES_Pin_Toggle(porta ,numero,50);
}

void FEES_RandomPinSwitch(){
	int numero = rand() % 16;
	int nporta = rand() % 6;
	char porta;
	if (nporta == 1 ) { 	porta= 'a';}
	if (nporta == 2 ) { 	porta= 'b';}
	if (nporta == 3 ) { 	porta= 'c';}
	if (nporta == 4 ) { 	porta= 'd';}
	if (nporta == 5 ) { 	porta= 'e';}

    FEES_Pin_Toggle(porta ,numero,50);
}

void FEES_RandomPinToggle4(){
	int numero = rand() % 16;

	FEES_Pin_Toggle('a',numero,50);
    FEES_Pin_Toggle('b',numero,50);
    FEES_Pin_Toggle('c',numero,50);
    FEES_Pin_Toggle('d',numero,50);
    FEES_Pin_Toggle('e',numero,50);
}

void FEES_TestBusses(){
		// TEST SERIALE
	uint8_t BufferPrint1[20]={"Seriale UNO 1!\n"};
	uint8_t BufferPrint2[20]={"Seriale DUE 2!\n"};
	uint8_t BufferPrint3[20]={"Seriale TRE 3!\n"};
	uint8_t BufferPrint6[20]={"Seriale SEI 6!\n"};

	HAL_UART_Transmit(&huart1, BufferPrint1, 20, 100);
	HAL_UART_Transmit(&huart2, BufferPrint2, 20, 100);
	HAL_UART_Transmit(&huart3, BufferPrint3, 20, 100);
	HAL_UART_Transmit(&huart6, BufferPrint6, 20, 100);
    osDelay(1);

    uint8_t Buffer[15]={ 0xFF, 0xFF, 0xFF,0x00,0x00,0xFF,0xFF,0x00,0xFF,0x00, 0x55, 0xAA, 0x80, 0x80, 0xAA};

    	// TEST I2C Busses
    HAL_I2C_Init(&hi2c1);
    HAL_I2C_Init(&hi2c2);

    HAL_I2C_Master_Transmit(&hi2c1, 0x11, Buffer, 15, 100);
    HAL_I2C_Master_Transmit(&hi2c2, 0x22, Buffer, 15, 100);
    osDelay(1);

        // TEST SPI
    HAL_SPI_Init(&hspi1);
    HAL_SPI_Init(&hspi2);
    HAL_SPI_Init(&hspi3);

    HAL_SPI_Transmit(&hspi1, Buffer, 10, 100);
    HAL_SPI_Transmit(&hspi2, Buffer, 10, 100);
    HAL_SPI_Transmit(&hspi3, Buffer, 10, 100);
    osDelay(1);
}


void FEES_PWM_STARTERS_T2_3_VariablePWM(){
	int i=1;
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);

	// variable PWM in TIM2_Chann3

	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
		TIM_OC_InitTypeDef sConfigOC = {0};
		sConfigOC.OCMode = TIM_OCMODE_PWM1;
		if(i==101){i=1;}
		sConfigOC.Pulse = i-1;
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();} // variable PWM in TIM2_Chann3
		i=i+10;
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
		osDelay(1);

		/*osDelay(100);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
		osDelay(100);

		  htim3.Init.Period = 0xFFFF; //

		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(100);
		  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
		  osDelay(100);

		  htim3.Init.Period = 0x1; //

		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(250);
		  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
		  osDelay(1000);*/
	}
}

void FEES_Startup_PWM_BATTERY(){
	  int i=1;
	  while(i<11){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 160-1;}
		  if(i==2){htim3.Init.Prescaler  = 150-1;}
		  if(i==3){htim3.Init.Prescaler  = 140-1;}
		  if(i==4){htim3.Init.Prescaler  = 130-1;}
		  if(i==5){htim3.Init.Prescaler  = 120-1;}
		  if(i==6){htim3.Init.Prescaler  = 110-1;}
		  if(i==7){htim3.Init.Prescaler  = 100-1;}
		  if(i==8){htim3.Init.Prescaler  = 90-1;}
		  if(i==9){htim3.Init.Prescaler  = 80-1;}
		  if(i==10){htim3.Init.Prescaler = 70-1;}

		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  HAL_Delay(50);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void FEES_StateChange_PWM_BATTERY(){
	  int i=1;
	  while(i<5){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 160-1;}
		  if(i==2){htim3.Init.Prescaler  = 150-1;}
		  if(i==3){htim3.Init.Prescaler  = 100-1;}
		  if(i==4){htim3.Init.Prescaler  = 120-1;}
		  if(i==5){htim3.Init.Prescaler  = 120-1;}


		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(50);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void FEES_Crescendo_PWM_BATTERY(){
	  int i=1;
	  while(i<11){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 160-1;}
		  if(i==2){htim3.Init.Prescaler  = 150-1;}
		  if(i==3){htim3.Init.Prescaler  = 140-1;}
		  if(i==4){htim3.Init.Prescaler  = 130-1;}
		  if(i==5){htim3.Init.Prescaler  = 120-1;}
		  if(i==6){htim3.Init.Prescaler  = 110-1;}
		  if(i==7){htim3.Init.Prescaler  = 100-1;}
		  if(i==8){htim3.Init.Prescaler  = 90-1;}
		  if(i==9){htim3.Init.Prescaler  = 80-1;}
		  if(i==10){htim3.Init.Prescaler = 70-1;}

		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(100);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void FEES_CrescendoParam_PWM_BATTERY(int a){
	  int i=1;
	  while(i<11){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 160-1;}
		  if(i==2){htim3.Init.Prescaler  = 150-1;}
		  if(i==3){htim3.Init.Prescaler  = 140-1;}
		  if(i==4){htim3.Init.Prescaler  = 130-1;}
		  if(i==5){htim3.Init.Prescaler  = 120-1;}
		  if(i==6){htim3.Init.Prescaler  = 110-1;}
		  if(i==7){htim3.Init.Prescaler  = 100-1;}
		  if(i==8){htim3.Init.Prescaler  = 90-1;}
		  if(i==9){htim3.Init.Prescaler  = 80-1;}
		  if(i==10){htim3.Init.Prescaler = 70-1;}

		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(a);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void FEES_Diminuendo_PWM_BATTERY(){
	  int i=0;
	  while(i<11){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 70-1;}
		  if(i==2){htim3.Init.Prescaler  = 80-1;}
		  if(i==3){htim3.Init.Prescaler  = 90-1;}
		  if(i==4){htim3.Init.Prescaler  = 100-1;}
		  if(i==5){htim3.Init.Prescaler  = 110-1;}
		  if(i==6){htim3.Init.Prescaler  = 120-1;}
		  if(i==7){htim3.Init.Prescaler  = 130-1;}
		  if(i==8){htim3.Init.Prescaler  = 140-1;}
		  if(i==9){htim3.Init.Prescaler  = 150-1;}
		  if(i==10){htim3.Init.Prescaler = 160-1;}

		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(100);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void FEES_DiminuendoParam_PWM_BATTERY(int a){
	  int i=0;
	  while(i<11){
		  TIM_MasterConfigTypeDef sMasterConfig = {0};
		  TIM_OC_InitTypeDef sConfigOC = {0};
		  htim3.Instance = TIM3;
		  if(i==1){htim3.Init.Prescaler  = 70-1;}
		  if(i==2){htim3.Init.Prescaler  = 80-1;}
		  if(i==3){htim3.Init.Prescaler  = 90-1;}
		  if(i==4){htim3.Init.Prescaler  = 100-1;}
		  if(i==5){htim3.Init.Prescaler  = 110-1;}
		  if(i==6){htim3.Init.Prescaler  = 120-1;}
		  if(i==7){htim3.Init.Prescaler  = 130-1;}
		  if(i==8){htim3.Init.Prescaler  = 140-1;}
		  if(i==9){htim3.Init.Prescaler  = 150-1;}
		  if(i==10){htim3.Init.Prescaler = 160-1;}

		  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
		  htim3.Init.Period = 100-1;
		  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK){Error_Handler();}

		  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK){ Error_Handler();}

		  sConfigOC.OCMode = TIM_OCMODE_PWM1;
		  sConfigOC.Pulse = 50-1;
		  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK){ Error_Handler();}
		  i++;
		  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		  osDelay(a);
		  }
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}


void FEES_Contatore_16(){
	// Contatore fino a 16  - Pin di selezione

		 	  //0
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(600);

		 	  //1
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);

		 	  //2
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //3
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //4
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //5
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //6
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //7
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //8
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(1000);
		 	  //9
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);

			  //10
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //11
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //12
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //13
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //14
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //15
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
}

void FEES_Contatore_30(){
	// Contatore fino a 16  - Pin di selezione

		 	  //0
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(100);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(600);

		 	  //1
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);

		 	  //2
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //3
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //4
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //5
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //6
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //7
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
		 	osDelay(1000);
		 	  //8
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
		 	HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
		 	osDelay(1000);
		 	  //9
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);

			  //10
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //11
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //12
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //13
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //14
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //15
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);

			//INVERTED

			  //16
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);

			  //17
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //18
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //19
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //20
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //21
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //22
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 1);
			osDelay(1000);
			  //23
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //24
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //25
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //26
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //27
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //28
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //29
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 1);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			osDelay(1000);
			  //30
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_1 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_0 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_3 , 0);
			HAL_GPIO_WritePin(GPIOC_BASE, GPIO_PIN_2 , 0);
			//osDelay(1000);
}



// TEST ZONE



// PID CONTROL ROUTINE (Battery Thermal Management)

/*
// Global Variables linked to PID
 Kp = 100 // Proptional Constant.
 Ki = 20  // Integral Constant.
 Kd = 20  // Derivative Constant.
 desired_temp = 0;
 turn_on_temp = -3;
 integral  = integral from previous loop + err; ( i.e. integral error )
 der  = err - err from previous loop; ( i.e. differential error)
 dt = execution time of loop.

//get value of setpoint from user
void PID_BATTERY_TEMP (){
	get_Battery_Temp(int bat_temp); 	// read the value of t-bat (Vtermocouple) from ADC.
	if (Flag_PID_BATTERY && bat_temp < turn_on_temp ) { 	// write code to escape loop on receiving a keyboard interrupt.
		bat_temp = GET_bat_temp();
		error = ( desired_temp - bat_temp );
	output = Kp * error + (Ki * integral * dt) + (Kd * der /dt);  // Calculate the output.
	output_scaled = SCALE_OUTPUT(output); 			// Scale output in range 0-100
	set_PWM_Battery(output_scaled); // Apply the calculated outpout.
	osDelay(50); // dt = 50 ms
}
*/


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */






  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_SPI3_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  FEES_Init();


  FEES_Startup_PWM_BATTERY(50); // STARTUP ALERT

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Task1 */
  Task1Handle = osThreadNew(Task01, NULL, &Task1_attributes);

  /* creation of Task2 */
  Task2Handle = osThreadNew(Task02, NULL, &Task2_attributes);

  /* creation of Task3 */
  Task3Handle = osThreadNew(Task03, NULL, &Task3_attributes);

  /* creation of Task4 */
  Task4Handle = osThreadNew(Task04, NULL, &Task4_attributes);

  /* creation of Task5 */
  Task5Handle = osThreadNew(Task05, NULL, &Task5_attributes);

  /* creation of Task6 */
  Task6Handle = osThreadNew(Task06, NULL, &Task6_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV6;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1600-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 50-1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 25-1;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 750-1;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1600-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 50-1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_PCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hpcd_USB_OTG_FS.Init.dev_endpoints = 4;
  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_OTG_FS.Init.Sof_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPS_PWR_ON_Pin|SBD_PWR_ON_Pin|CS_NAND_Pin|CS_LORA_Pin
                          |RSBY_ON_Pin|DIR_X_COIL_Pin|DIR_Y_COIL_Pin|DIR_Z_COIL_Pin
                          |CS_GYRO_Pin|EN_ADC1_Pin|EN_ADC3_Pin|EN_ADC2_Pin
                          |SBD_SER_RI_Pin|SBD_SER_NET_Pin|ANA_PWR_ON_Pin|RAD_PWR_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, UHF_RESET_Pin|RADFET_OWB_Pin|RAD_RESET_Pin|PSD1_SEL0_Pin
                          |PSD2_SEL1_Pin|PSD2_SEL0_Pin|CS_PSD1_AMP_Pin|CS_PSD2_AMP_Pin
                          |EX_SPI_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PSD1_SEL1_GPIO_Port, PSD1_SEL1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EX_GPIO3_Pin|CS_RADFET_Pin|EX_GPIO4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RSBY_KEEP_EN_Pin|EX_GPIO1_Pin|EX_GPIO2_Pin|WATCHDOG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, CS_EEPROM_Pin|CS_FRAM_Pin|INT_GYRO_Pin
                          |CS_GYRO2_Pin|INT_GYRO2_Pin|SBD_SER_DCD_Pin|SBD_SER_DSR_Pin
                          |SBD_SER_DTR_Pin|SBD_SER_CTS_Pin|SBD_SER_RTS_Pin|SBD_ON_OFF_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : GPS_PWR_ON_Pin SBD_PWR_ON_Pin CS_NAND_Pin CS_LORA_Pin
                           RSBY_ON_Pin DIR_COIL_X_Pin DIR_COIL_Y_Pin DIR_COIL_Z_Pin
                           CS_GYRO_Pin EN_ADC1_Pin EN_ADC3_Pin EN_ADC2_Pin
                           SBD_SER_RI_Pin SBD_SER_NET_Pin ANA_PWR_ON_Pin RAD_PWR_ON_Pin */
  GPIO_InitStruct.Pin = GPS_PWR_ON_Pin|SBD_PWR_ON_Pin|CS_NAND_Pin|CS_LORA_Pin
                          |RSBY_ON_Pin|DIR_X_COIL_Pin|DIR_Y_COIL_Pin|DIR_Z_COIL_Pin
                          |CS_GYRO_Pin|EN_ADC1_Pin|EN_ADC3_Pin|EN_ADC2_Pin
                          |SBD_SER_RI_Pin|SBD_SER_NET_Pin|ANA_PWR_ON_Pin|RAD_PWR_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : UHF_RESET_Pin RADFET_OWB_Pin RAD_RESET_Pin PSD1_SEL1_Pin
                           PSD1_SEL0_Pin PSD2_SEL1_Pin PSD2_SEL0_Pin PSD1_AMP_CS_Pin
                           PSD2_AMP_CS_Pin EX_SPI_EN_Pin */
  GPIO_InitStruct.Pin = UHF_RESET_Pin|RADFET_OWB_Pin|RAD_RESET_Pin|PSD1_SEL1_Pin
                          |PSD1_SEL0_Pin|PSD2_SEL1_Pin|PSD2_SEL0_Pin|CS_PSD1_AMP_Pin
                          |CS_PSD2_AMP_Pin|EX_SPI_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : EX_GPIO3_Pin CS_RADFET_Pin EX_GPIO4_Pin */
  GPIO_InitStruct.Pin = EX_GPIO3_Pin|CS_RADFET_Pin|EX_GPIO4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : RSBY_KEEP_EN_Pin EX_GPIO1_Pin EX_GPIO2_Pin WATCHDOG_Pin */
  GPIO_InitStruct.Pin = RSBY_KEEP_EN_Pin|EX_GPIO1_Pin|EX_GPIO2_Pin|WATCHDOG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : CS_EEPROM_Pin CS_FRAM_Pin CS_GYROD12_Pin INT_GYRO_Pin
                           CS_GYRO2_Pin INT_GYRO2_Pin SBD_SER_DCD_Pin SBD_SER_DSR_Pin
                           SBD_SER_DTR_Pin SBD_SER_CTS_Pin SBD_SER_RTS_Pin SBD_ON_OFF_Pin */
  GPIO_InitStruct.Pin = CS_EEPROM_Pin|CS_FRAM_Pin|INT_GYRO_Pin
                          |CS_GYRO2_Pin|INT_GYRO2_Pin|SBD_SER_DCD_Pin|SBD_SER_DSR_Pin
                          |SBD_SER_DTR_Pin|SBD_SER_CTS_Pin|SBD_SER_RTS_Pin|SBD_ON_OFF_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PGOOD_Pin */
  GPIO_InitStruct.Pin = PGOOD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PGOOD_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	 // FEES_FSM();
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_Task01 */
/**
* @brief Function implementing the Task1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task01 */
void Task01(void *argument)
{
  /* USER CODE BEGIN Task01 */
  /* Infinite loop */
  for(;;)
  {
	 // BATTERY_PID_FUNCTION();
	  osDelay(100);

	// FEES_Pin_Toggle('d',15);  	// CS_NAND - Led BLU ( D 5 )
	  int delayvar=100;
	  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port,WATCHDOG_Pin, 1);
	  osDelay(delayvar);
	  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port,WATCHDOG_Pin, 0);
	  osDelay(delayvar);
  }
  /* USER CODE END Task01 */
}

/* USER CODE BEGIN Header_Task02 */
/**
* @brief Function implementing the Task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task02 */
void Task02(void *argument)
{
  /* USER CODE BEGIN Task02 */
  /* Infinite loop */
  for(;;)
  {


	  //HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // BATTERY HEATER PWM

	  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);	// X-Coil PWM
	  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);	// Y-Coil PWM
	  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);	// Z-Coil PWM

	  osDelay(100);

	  /*osDelay(100);
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
	  osDelay(100);

	  htim3.Init.Period = 0xFFFF; //

	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	  osDelay(100);
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
	  osDelay(100);

	  htim3.Init.Period = 0x1; //

	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	  osDelay(250);
	  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
	  osDelay(1000);*/

  }
  /* USER CODE END Task02 */
}

/* USER CODE BEGIN Header_Task03 */
/**
* @brief Function implementing the Task3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task03 */
void Task03(void *argument)
{
  /* USER CODE BEGIN Task03 */
  /* Infinite loop */
  for(;;)
  {

	  osDelay(1000);
  }

  /* USER CODE END Task03 */
}

/* USER CODE BEGIN Header_Task04 */
/**
* @brief Function implementing the Task4 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task04 */
void Task04(void *argument)
{
  /* USER CODE BEGIN Task04 */
  /* Infinite loop */
  for(;;)
  {
	  osDelay(1000);

  }
  /* USER CODE END Task04 */
}

/* USER CODE BEGIN Header_Task05 */
/**
* @brief Function implementing the Task5 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task05 */
void Task05(void *argument)
{
  /* USER CODE BEGIN Task05 */
  /* Infinite loop */
  for(;;)
  {

	  FEES_Pin_Toggle('d',12, 20); 	// TMTC_WD
	  osDelay(50);


	  //TEST_TestPins();

	  //FEES_Pin_Toggle('b',5,20);	// WATCHDOG

	  //FEES_Pin_Toggle('c',13,20); 	// UHF_RESET

	  // FEES_Pin_Toggle('c',15,20); 	//RAD RESET


	  if(1){
		  FEES_TestPins(250);
	  }
  }
  /* USER CODE END Task05 */
}

/* USER CODE BEGIN Header_Task06 */
/**
* @brief Function implementing the Task6 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task06 */
void Task06(void *argument)
{
  /* USER CODE BEGIN Task06 */
  /* Infinite loop */
	for(;;)
	  {


		osDelay(100);



		// FEES_StateChange_PWM_BATTERY();	// Fast Bip
		// FEES_TestPins(); 		// Sequential Led Toggle

		//osDelay(1000);

		if(0){ // USART Testing
			char test[10] = "TESTING \r\n";
			FEES_Printf1(test);
			osDelay(500);
		}

		if( 0 )
		{
			FEES_RandomPinToggle();  // Very Christmas-y !
		}

		if( 0 ) // Modalità CONTATORE
		{
			FEES_CrescendoParam_PWM_BATTERY(100);
			FEES_Contatore_30();
			FEES_DiminuendoParam_PWM_BATTERY(100);
			FEES_Contatore_30();
		}

		if( 0 ) // Modalità ALLARME
		{
			FEES_CrescendoParam_PWM_BATTERY(50);
		}

		if( 0 ) // Modalità DISCOTECA
		{
			FEES_CrescendoParam_PWM_BATTERY(50);
			FEES_DiminuendoParam_PWM_BATTERY(50);
		}
	  }
  /* USER CODE END Task06 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
