/*
 * TEST.c
 *
 *  Created on: 20 feb 2021
 *      Author: stefa
 */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdio.h>

#include "TEST.h"



UART_HandleTypeDef huart3;


void Testiamo(){

	char BUFFERTESTIAMO[] = "TEST ";
	HAL_UART_Transmit(&huart3, (uint8_t *)  BUFFERTESTIAMO, sizeof(BUFFERTESTIAMO)-1 , 100);
}
