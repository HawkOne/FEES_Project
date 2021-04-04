/*
 * TEST.h
 *
 *  Created on: 20 feb 2021
 *      Author: stefa
 */

#ifndef INC_FEES_H_
#define INC_FEES_H_

void Testiamo();

#include "main.h"
#include <string.h>
#include "main.h"
#include "cmsis_os.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <limits.h>


/* USER CODE BEGIN PD */
#define TRUE 1
#define FALSE 0

//#define TESTING 1
#define TEST if(TESTING)

//#define FLAG 1
extern const char newline[4];

extern char rx_buffer[2];


extern int TESTING;
extern int FLAG;

extern int RxData;


typedef struct{
    GPIO_TypeDef * PORT__BASE;
	int pin_number;
	uint8_t address;
}FEES_Pin;


// PWM_ CONTROL
extern FEES_Pin PWM_HEATER;
extern FEES_Pin PWM_X_COIL;
extern FEES_Pin PWM_Y_COIL;
extern FEES_Pin PWM_Z_COIL;
// GPIO DI DIREZIONE
extern FEES_Pin DIR_X_COIL;
extern FEES_Pin DIR_Y_COIL;
extern FEES_Pin DIR_Z_COIL;
//GPIO DI CONTROLLO
extern FEES_Pin WATCHDOG;
extern FEES_Pin UHF_RESET;
extern FEES_Pin RAD_RESET;
extern FEES_Pin RADFET_OWB;
extern FEES_Pin TMTC_WD;
extern FEES_Pin ANA_PWR_ON;
extern FEES_Pin RAD_PWR_ON;
extern FEES_Pin GPS_PWR_ON;
extern FEES_Pin SBD_PWR_ON;
extern FEES_Pin RSBY_PWR_ON;
extern FEES_Pin RSBY_KEEP_EN;
//CS_SPI_SENSORI
extern FEES_Pin CS_NAND;
extern FEES_Pin CS_LORA;
extern FEES_Pin CS_RADFET;
extern FEES_Pin EN_ADC1;
extern FEES_Pin EN_ADC2;
extern FEES_Pin EN_ADC3;
extern FEES_Pin EXT_SPI_EN;
extern FEES_Pin CS_EEPROM;
extern FEES_Pin CS_FRAM;
extern FEES_Pin CS_PSD1_AMP;
extern FEES_Pin CS_PSD2_AMP;
extern FEES_Pin CS_GYRO;
extern FEES_Pin CS_GYRO2;
// GPIO EXTRA
extern FEES_Pin EX_GPIO1;
extern FEES_Pin EX_GPIO2;
extern FEES_Pin EX_GPIO3;
extern FEES_Pin EX_GPIO4;
// Select
extern FEES_Pin PSD1_SEL0;
extern FEES_Pin PSD1_SEL1;
extern FEES_Pin PSD2_SEL0;
extern FEES_Pin PSD2_SEL1;
// IMU
extern FEES_Pin INT_GYRO1;
extern FEES_Pin INT_GYRO2;
// Radex
extern FEES_Pin RAD_RESET;
extern FEES_Pin RADFET_OWB;
//SDB
extern FEES_Pin SDB_ON_OFF;
extern FEES_Pin SDB_SER_RI;
extern FEES_Pin SDB_SER_NET;
extern FEES_Pin SDB_SER_DCD;
extern FEES_Pin SDB_SER_DSR;
extern FEES_Pin SDB_SER_DTR;
extern FEES_Pin SDB_SER_CTS;
extern FEES_Pin SDB_SER_RTS;
// Other
extern FEES_Pin USB_VBUS;
extern FEES_Pin PGOOD;

extern FEES_Pin JTAG_TMS;
extern FEES_Pin JTAG_TCK;

// Handlers

extern ADC_HandleTypeDef hadc1;

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;

extern PCD_HandleTypeDef hpcd_USB_OTG_FS;




void FEES_SOS(int delay);
void FEES_TEST(int delay);
void led_on();
void led_off();
void State_Updater();
void FEES_Init();

void FEES_SPI_1(uint8_t* data, FEES_Pin FeesPinVariabile);
void FEES_SPI_2(uint8_t* data, FEES_Pin FeesPinVariabile);
void FEES_SPI_3(uint8_t* data, FEES_Pin FeesPinVariabile);

void FEES_I2C_1(uint8_t* data, FEES_Pin FeesPinVariabile);
void FEES_I2C_2(uint8_t* data);

void FEES_Printf(char* string);
void FEES_Printf1(char* string);
void FEES_Printf2(char* string);
void FEES_Printf3(char* string);
void FEES_Printf4(char* string);

void FEES_Pin_ON( GPIO_TypeDef * PORT__BASE  ,  int pin_number);
void FEES_Pin_OFF( GPIO_TypeDef * PORT__BASE  ,  int pin_number);
void FEES_Pin_Toggle(char port , int pin, int delay);
void FEES_TestPins(int delay);

void FEES_RandomPinToggle();
void FEES_RandomPinSwitch();
void FEES_RandomPinToggle4();
void FEES_TestBusses();

void FEES_PWM_STARTERS_T2_3_VariablePWM();
void FEES_Startup_PWM_BATTERY();
void FEES_StateChange_PWM_BATTERY();
void FEES_Crescendo_PWM_BATTERY();
void FEES_CrescendoParam_PWM_BATTERY(int a);
void FEES_Diminuendo_PWM_BATTERY();
void FEES_DiminuendoParam_PWM_BATTERY(int a);

void FEES_Contatore_16();
void FEES_Contatore_30();


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




#endif /* INC_FEES_H_ */
