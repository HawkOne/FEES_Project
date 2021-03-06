
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





#define Normal_MODE
//#define UNIT_TESTING



// FOR EXAMPLE  - BATTERY_PID_CONTROL



//                                                -5                  +2
int BATTERY_PID_CONTROL(int actual_temp, int Limit_temp_LOW, int Limit_temp_HIGH) {

#ifdef Normal_MODE
  if(actual_temp<Limit_temp_LOW){
   turn_ON_BatteryPWM;
  }

  if(actual_temp>Limit_temp_HIGH){
   turn_OFF_BatteryPWM;
  }
#endif


#ifdef UNIT_TESTING
  if(actual_temp<Limit_temp_LOW){
   printf("PWM_BATTERY HAS BEEN TURNED ON\n");
  }

  if(actual_temp>Limit_temp_HIGH){
  printf("PWM_BATTERY HAS BEEN TURNED OFF\n");
   }
#endif

}




//main.c

while(1){
  float temp;
    temp= readbatttemp();
    BATTERY_PID_CONTROL( temp , -5 , +2);

    #ifdef UNIT_TESTING
    // here I check if it actually has been turned on

    printf("PWM_BATTERY HAS BEEN TURNED OFF\n");


  #endif

}





// In test_my_sum.c
int main(int argc, char *argv[]) {
  assert(2 == my_sum(1, 1));
  assert(-2 == my_sum(-1, -1));
  assert(0 == my_sum(0, 0));
  // ...
  return(0);
}


/* Made by Stamp    */





//*******************************************    DATI IMU  *********************************************

typedef union {         // Struttura ImuSample che contiene i dati Imu.
    struct              // Forse ACDS preferisce avere i quaternioni - c'è da vedere come ottenerli.
    {
        struct accelerometer
        {
            float x;
            float y;
            float z;
        }
        struct gyroscope
        {
            float x;
            float y;
            float z;
        }
        struct magnetometer
        {
            float x;
            float y;
            float z;
        }

        float temperature;

    } 

    float vector[10];       // Secondo modo di indirizzarsi alla stessa struttura: vettore.
                            //3acc,3gyro,3Magn,1Temp


} ImuSample_t;



/************************************************ DATI **********************************************************/


typedef union {    		// Struttura ImuSample che contiene i dati Imu.
	
} GPSSample_t;



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
 desired = 0;
 error = ( desired - bat_temp )
 integral  = integral from previous loop + err; ( i.e. integral error )
 der  = err - err from previous loop; ( i.e. differential error)
 dt = execution time of loop.

//get value of setpoint from user
void PID_BATTERY_TEMP (){
	get_Battery_Temp(int bat_temp); 	// read the value of t-bat (Vtermocouple) from ADC.
	if (Flag_PID_BATTERY && bat_temp < 0 ) { 	// write code to escape loop on receiving a keyboard interrupt.
	output = Kp * error + (Ki * integral * dt) + (Kd * der /dt);  // Calculate the output.
	output_scaled = output 			// Scale output in range 0-100
	set_PWM_Battery(output_scaled); // Apply the calculated outpout.
	osDelay(50); // dt = 50 ms
}
*/


/* USER CODE END 0 */


// TEST ZONE


void FEES_HW_Watchdog(delayvar){
	  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port,WATCHDOG_Pin, 1);
	  osDelay(delayvar);
	  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port,WATCHDOG_Pin, 0);
	  osDelay(delayvar);
	}







































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


	  if(0){
		  FEES_TestPins(20);
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