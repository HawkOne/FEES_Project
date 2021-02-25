/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include <string.h>
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SERIAL_DEBUG 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
osThreadId myTask04Handle;
osThreadId myTask05Handle;
osThreadId myTask06Handle;
osThreadId myTask07Handle;

osMutexId uartMutexHandle;
/* USER CODE BEGIN PV */
uint8_t state = 0;
GPIO_PinState Flag_Telecom_Active;
GPIO_PinState Flag_Analog_Active;
GPIO_PinState Flag_GPS_Active;
GPIO_PinState Flag_Iridium_Active;
GPIO_PinState Flag_Radex_Active;
GPIO_PinState Flag_RaspberryPi_Active;
GPIO_PinState Flag_ADCS_Active;
GPIO_PinState Flag_BatteryPID_Active;

uint32_t current_time = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);
void StartTask04(void const * argument);
void StartTask05(void const * argument);
void StartTask06(void const * argument);
void StartTask07(void const * argument);

/* USER CODE BEGIN PFP */
void FEES_FSM(void);
void UpdatePinMask(void);
void TelecomPowerOFF(void);
void TelecomPowerON(void);
void AnalogPowerOFF(void);
void AnalogPowerON(void);
void GPSPowerOFF(void);
void GPSPowerON(void);
void IridiumPowerOFF(void);
void IridiumPowerON(void);
void RadexPowerOFF(void);
void RadexPowerON(void);
void RaspberryPiPowerOFF(void);
void RaspberryPiPowerON(void);
void ADCSPowerOFF(void);
void ADCSPowerON(void);
void BatteryPIDPowerOFF(void);
void BatteryPIDPowerON(void);
void PinMaskAllOFF(void);
void PinMaskInVector(void);
void PinMaskWait(void);
void PinMaskDetumble(void);
void PinMaskNominal(void);
void PinMaskTransmission(void);
void PinMaskRadex(void);
void PrintSystemTime(void);
void PrintCurrentState(void);
void PrintThreadsAndHandlers(void);
void PrintMenu(void);
void BatteryPIDControl(void);
void ADCSControl(void);
void HardwareWD(void);
void TransmissionWD(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Create the mutex(es) */
  /* definition and creation of uartMutex */
  osMutexDef(uartMutex);
  uartMutexHandle = osMutexCreate(osMutex(uartMutex));

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 512);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 512);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, StartTask03, osPriorityNormal, 0, 512);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, StartTask04, osPriorityNormal, 0, 512);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* definition and creation of myTask05 */
  osThreadDef(myTask05, StartTask05, osPriorityNormal, 0, 512);
  myTask05Handle = osThreadCreate(osThread(myTask05), NULL);

  osThreadDef(myTask06, StartTask06, osPriorityNormal, 0, 512);
  myTask06Handle = osThreadCreate(osThread(myTask06), NULL);

  osThreadDef(myTask07, StartTask07, osPriorityNormal, 0, 512);
  myTask07Handle = osThreadCreate(osThread(myTask07), NULL);

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pins : PC13 PC14 PC15 PC0
                           PC1 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PH0 PH1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void FEES_FSM(void)
{
	UpdatePinMask();
}

void UpdatePinMask(void)
{
	GPIO_PinState satellite_separate;
	GPIO_PinState exp_starts;
	GPIO_PinState exp_ends;
	GPIO_PinState unexpected_error;
	GPIO_PinState beacon_received;
	GPIO_PinState tx_complete;
	uint8_t count;
	while(1)
	{
		switch(state)
		{
		case 0: // satellite has launched but never separated
			PinMaskInVector();
			satellite_separate = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
			if (satellite_separate == GPIO_PIN_RESET)
				state = 1;
			continue;
		case 1: // satellite separated state
			PinMaskWait();
			for(count = 0; count < 10; count++)
				osDelay(1000);
			state = 2;
			continue;
		case 2: // detumble state
			PinMaskDetumble();
			for(count = 0; count < 20; count++)
				osDelay(1000);
			state = 3;
			continue;
		case 3: // nominal state
			PinMaskNominal();

			exp_starts = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);

			unexpected_error = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);

			beacon_received = HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_1);

			if (exp_starts == GPIO_PIN_RESET)
				state = 4; // experiment state

			if (unexpected_error == GPIO_PIN_RESET)
				state = 5; // safe mode state

			if (beacon_received == GPIO_PIN_RESET)
				state = 6; // transmission state
			continue;
		case 4: // experiment state
			PinMaskRadex();
			exp_ends = HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_1);
			if (exp_ends == GPIO_PIN_RESET)
				state = 3; // nominal state
			continue;
		case 5: // safe mode state
			PinMaskAllOFF();
			beacon_received = HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_0);
			if (beacon_received == GPIO_PIN_RESET)
				state = 6; // transmission state
			continue;
		case 6: // transmission state
			PinMaskTransmission();
			tx_complete = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
			if (tx_complete == GPIO_PIN_RESET)
				state = 3;
			continue;
		default:
			PinMaskAllOFF();
			state = 0;
			continue;
		}
	}
}

void TelecomPowerOFF(void)
{
	char str[22] = "TELECOM POWER IS OFF\n\r";
	Flag_Telecom_Active = GPIO_PIN_RESET;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);

#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, 22, 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void TelecomPowerON(void)
{
	char str[] = "TELECOM POWER IS ON\n\r";

	Flag_Telecom_Active = GPIO_PIN_SET;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void AnalogPowerOFF(void)
{
	char str[] = "ANALOG POWER IS OFF\n\r";
	Flag_Analog_Active = GPIO_PIN_RESET;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void AnalogPowerON(void)
{
	char str[] = "ANALOG POWER IS ON\n\r";
	Flag_Analog_Active = GPIO_PIN_SET;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);

#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void GPSPowerOFF(void)
{
	char str[] = "GPS POWER IS OFF\n\r";
	Flag_GPS_Active = GPIO_PIN_RESET;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void GPSPowerON(void)
{
	char str[] = "GPS POWER IS ON\n\r";
	Flag_GPS_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void IridiumPowerOFF(void)
{
	char str[] = "IRIDIUM POWER IS OFF\n\r";
	Flag_Iridium_Active = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void IridiumPowerON(void)
{
	char str[] = "IRIDIUM POWER IS ON\n\r";
	Flag_Iridium_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void RadexPowerOFF(void)
{
	char str[] = "RADEX POWER IS OFF\n\r";
	Flag_Radex_Active = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void RadexPowerON(void)
{
	char str[] = "RADEX POWER IS ON\n\r";
	Flag_Radex_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void RaspberryPiPowerOFF(void)
{
	char str[] = "RASPBERRY PI POWER IS OFF\n\r";
	Flag_RaspberryPi_Active = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void RaspberryPiPowerON(void)
{
	char str[] = "RASPBERRY PI POWER IS ON\n\r";
	Flag_RaspberryPi_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void ADCSPowerOFF(void)
{
	char str[] = "ADCS POWER IS OFF\n\r";
	Flag_ADCS_Active = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void ADCSPowerON(void)
{
	char str[] = "ADCS POWER IS ON\n\r";
	Flag_ADCS_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void BatteryPIDPowerOFF(void)
{
	char str[] = "BATTERY THERMAL MANAGEMENT POWER IS OFF\n\r";
	Flag_BatteryPID_Active = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void BatteryPIDPowerON(void)
{
	char str[] = "BATTERY THERMAL MANAGEMENT POWER IS ON\n\r";
	Flag_BatteryPID_Active = GPIO_PIN_SET;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
#ifdef SERIAL_DEBUG
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void PinMaskAllOFF(void)
{
	TelecomPowerOFF();
	AnalogPowerOFF();
	GPSPowerOFF();
	IridiumPowerOFF();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerOFF();
	BatteryPIDPowerOFF();
	osDelay(1000);
}

void PinMaskInVector(void)
{
	TelecomPowerOFF();
	AnalogPowerOFF();
	GPSPowerOFF();
	IridiumPowerOFF();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerOFF();
	BatteryPIDPowerOFF();
	osDelay(1000);
}

void PinMaskWait(void)
{
	TelecomPowerOFF();
	AnalogPowerOFF();
	GPSPowerOFF();
	IridiumPowerOFF();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerOFF();
	BatteryPIDPowerON();
	osDelay(1000);
}

void PinMaskDetumble(void)
{
	TelecomPowerOFF();
	AnalogPowerOFF();
	GPSPowerOFF();
	IridiumPowerOFF();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerON();
	BatteryPIDPowerON();
	osDelay(1000);
}

void PinMaskNominal(void)
{
	TelecomPowerON();
	AnalogPowerON();
	GPSPowerON();
	IridiumPowerOFF();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerON();
	BatteryPIDPowerON();
	osDelay(1000);
}

void PinMaskTransmission(void)
{
	TelecomPowerON();
	AnalogPowerON();
	GPSPowerON();
	IridiumPowerON();
	RadexPowerOFF();
	RaspberryPiPowerOFF();
	ADCSPowerOFF();
	BatteryPIDPowerON();
	osDelay(1000);
}

void PinMaskRadex(void)
{
	TelecomPowerON();
	AnalogPowerOFF();
	GPSPowerON();
	IridiumPowerOFF();
	RadexPowerON();
	RaspberryPiPowerOFF();
	ADCSPowerON();
	BatteryPIDPowerON();
	osDelay(1000);
}

void PrintSystemTime(void)
{
	char str1[] = "Current System Time = ";
	char str2[20];
	char str3[2] = "\n\r";
#ifdef SERIAL_DEBUG
	sprintf(str2, "%ld", current_time);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 10);
	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 10);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void PrintCurrentState(void)
{
	char str1[] = "Current State of the FSM is = ";
	char str2[2];
	char str3[2] = "\n\r";
#ifdef SERIAL_DEBUG
	sprintf(str2, "%d", state);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 10);
	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 10);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 10);
	xSemaphoreGive(uartMutexHandle);
#endif
}

void PrintThreadsAndHandlers(void)
{
	char str1[] = "TELECOM MODULE POWER ON\n\r";
	char str2[] = "TELECOM MODULE POWER OFF\n\r";
	char str3[] = "ANALOG MODULE POWER ON\n\r";
	char str4[] = "ANALOG MODULE POWER OFF\n\r";
	char str5[] = "GPS MODULE POWER ON\n\r";
	char str6[] = "GPS MODULE POWER OFF\n\r";
	char str7[] = "IRIDIUM MODULE POWER ON\n\r";
	char str8[] = "IRIDIUM MODULE POWER OFF\n\r";
	char str9[] = "RADIATION EXPERIMENT MODULE POWER ON\n\r";
	char str10[] = "RADIATION EXPERIMENT MODULE POWER OFF\n\r";
	char str11[] = "RASPBERRY PI MODULE POWER ON\n\r";
	char str12[] = "RASPBERRY PI MODULE POWER OFF\n\r";
	char str13[] = "ADCS MODULE POWER ON\n\r";
	char str14[] = "ADCS MODULE POWER OFF\n\r";
	char str15[] = "BATTERY PID MODULE POWER ON\n\r";
	char str16[] = "BATTERY PID MODULE POWER OFF\n\r";

	if (Flag_Telecom_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_Analog_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str4, strlen(str4), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_GPS_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str5, strlen(str5), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str6, strlen(str6), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_Iridium_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str7, strlen(str7), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str8, strlen(str8), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_Radex_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str9, strlen(str9), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str10, strlen(str10), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_RaspberryPi_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str11, strlen(str11), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str12, strlen(str12), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_ADCS_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str13, strlen(str13), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str14, strlen(str14), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	if (Flag_BatteryPID_Active == GPIO_PIN_SET) {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str15, strlen(str15), 10);
		xSemaphoreGive(uartMutexHandle);
	}
	else {
		xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t *)str16, strlen(str16), 10);
		xSemaphoreGive(uartMutexHandle);
	}
}

void PrintMenu(void)
{
	char str1[] = "Following are the commands for shifting the states\n\r";
	char str2[] = "Onboard switch: To separate satellite from launcher\n\r";
	char str3[] = "Switch connected to PC14: Radiation Experiment starts\n\r";
	char str4[] = "Switch connected to PH1: Radiation Experiment Ends\n\r";
	char str5[] = "Switch connected to PC15: Unexpected Error Occured\n\r";
	char str6[] = "Switch connected to PH0: Beacon from Earth received\n\r";
	char str7[] = "Switch connected to PC0: Transmission is Completed\n\r";

	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str4, strlen(str4), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str5, strlen(str5), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str6, strlen(str6), 10);
	xSemaphoreGive(uartMutexHandle);
	xSemaphoreTake(uartMutexHandle, portMAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)str7, strlen(str7), 10);
	xSemaphoreGive(uartMutexHandle);
}

void BatteryPIDControl(void)
{
	if (Flag_BatteryPID_Active == GPIO_PIN_SET)
	{
		//Logic Yet to be written
	}
}

void ADCSControl(void)
{
	if (Flag_ADCS_Active == GPIO_PIN_SET)
	{
		//Logic yet to be written
	}
}

void HardwareWD(void)
{

}

void TransmissionWD(void)
{

}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  FEES_FSM();
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
	  BatteryPIDControl();
	  osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for(;;)
  {
	ADCSControl();
    osDelay(1);
  }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void const * argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
	  HardwareWD();
	  osDelay(1);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the myTask05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void const * argument)
{
  /* USER CODE BEGIN StartTask05 */
  /* Infinite loop */
  for(;;)
  {
	  TransmissionWD();
	  osDelay(1);
  }
  /* USER CODE END StartTask05 */
}

void StartTask06(void const * argument)
{
  /* USER CODE BEGIN StartTask06 */
  /* Infinite loop */
  for(;;)
  {
	current_time++;
    osDelay(1000);
  }
  /* USER CODE END StartTask05 */
}

void StartTask07(void const * argument)
{
  /* USER CODE BEGIN StartTask06 */
  /* Infinite loop */
  for(;;)
  {
#ifdef SERIAL_DEBUG
	  PrintSystemTime();
	  PrintCurrentState();
	  PrintThreadsAndHandlers();
	  PrintMenu();
#endif
	  osDelay(1000);
  }
  /* USER CODE END StartTask05 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM3 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM3) {
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
