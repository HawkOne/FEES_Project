OLD MAIN.C




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
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
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

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* Definitions for T_HdwWatchDog */
osThreadId_t T_HdwWatchDogHandle;
const osThreadAttr_t T_HdwWatchDog_attributes = {
  .name = "T_HdwWatchDog",
  .priority = (osPriority_t) osPriorityRealtime7,
  .stack_size = 128 * 4
};
/* Definitions for T_DEBUG */
osThreadId_t T_DEBUGHandle;
const osThreadAttr_t T_DEBUG_attributes = {
  .name = "T_DEBUG",
  .priority = (osPriority_t) osPriorityRealtime6,
  .stack_size = 128 * 4
};
/* Definitions for T_BatteryPID */
osThreadId_t T_BatteryPIDHandle;
const osThreadAttr_t T_BatteryPID_attributes = {
  .name = "T_BatteryPID",
  .priority = (osPriority_t) osPriorityRealtime5,
  .stack_size = 128 * 4
};
/* Definitions for T_FSM */
osThreadId_t T_FSMHandle;
const osThreadAttr_t T_FSM_attributes = {
  .name = "T_FSM",
  .priority = (osPriority_t) osPriorityRealtime4,
  .stack_size = 128 * 4
};
/* Definitions for T_RadioWatchdog */
osThreadId_t T_RadioWatchdogHandle;
const osThreadAttr_t T_RadioWatchdog_attributes = {
  .name = "T_RadioWatchdog",
  .priority = (osPriority_t) osPriorityNormal7,
  .stack_size = 128 * 4
};
/* Definitions for T_Telecom */
osThreadId_t T_TelecomHandle;
const osThreadAttr_t T_Telecom_attributes = {
  .name = "T_Telecom",
  .priority = (osPriority_t) osPriorityNormal6,
  .stack_size = 128 * 4
};
/* Definitions for T_SensorsSample */
osThreadId_t T_SensorsSampleHandle;
const osThreadAttr_t T_SensorsSample_attributes = {
  .name = "T_SensorsSample",
  .priority = (osPriority_t) osPriorityNormal4,
  .stack_size = 128 * 4
};
/* Definitions for T_GndStatSearch */
osThreadId_t T_GndStatSearchHandle;
const osThreadAttr_t T_GndStatSearch_attributes = {
  .name = "T_GndStatSearch",
  .priority = (osPriority_t) osPriorityNormal4,
  .stack_size = 128 * 4
};
/* Definitions for T_ADCS */
osThreadId_t T_ADCSHandle;
const osThreadAttr_t T_ADCS_attributes = {
  .name = "T_ADCS",
  .priority = (osPriority_t) osPriorityNormal3,
  .stack_size = 128 * 4
};
/* Definitions for T_RasbyWtchdog */
osThreadId_t T_RasbyWtchdogHandle;
const osThreadAttr_t T_RasbyWtchdog_attributes = {
  .name = "T_RasbyWtchdog",
  .priority = (osPriority_t) osPriorityNormal2,
  .stack_size = 128 * 4
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

void TASK_HardwareWatchDog(void *argument);
void TASK_DEBUG(void *argument);
void TASK_BatteryPID(void *argument);
void TASK_FSM(void *argument);
void TASK_RadioWatchdog(void *argument);
void TASK_Telecomunication(void *argument);
void TASK_SensorsSampling(void *argument);
void TASK_GroundStationSearch(void *argument);
void TASK_ADCS(void *argument);
void TASK_WatchdogRasby(void *argument);


/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void pintoggle(char port , int pin){
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
	HAL_GPIO_WritePin(PORT__BASE, pin_number, 1);
    HAL_Delay(10);
    HAL_GPIO_WritePin(PORT__BASE, pin_number, 0);
    HAL_Delay(10);
}

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
  /* USER CODE BEGIN 2 */

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
  /* creation of T_HdwWatchDog */
  T_HdwWatchDogHandle = osThreadNew(TASK_HardwareWatchDog, NULL, &T_HdwWatchDog_attributes);

  /* creation of T_DEBUG */
  T_DEBUGHandle = osThreadNew(TASK_DEBUG, NULL, &T_DEBUG_attributes);

  /* creation of T_BatteryPID */
  T_BatteryPIDHandle = osThreadNew(TASK_BatteryPID, NULL, &T_BatteryPID_attributes);

  /* creation of T_FSM */
  T_FSMHandle = osThreadNew(TASK_FSM, NULL, &T_FSM_attributes);

  /* creation of T_RadioWatchdog */
  T_RadioWatchdogHandle = osThreadNew(TASK_RadioWatchdog, NULL, &T_RadioWatchdog_attributes);

  /* creation of T_Telecom */
  T_TelecomHandle = osThreadNew(TASK_Telecomunication, NULL, &T_Telecom_attributes);

  /* creation of T_SensorsSample */
  T_SensorsSampleHandle = osThreadNew(TASK_SensorsSampling, NULL, &T_SensorsSample_attributes);

  /* creation of T_GndStatSearch */
  T_GndStatSearchHandle = osThreadNew(TASK_GroundStationSearch, NULL, &T_GndStatSearch_attributes);

  /* creation of T_ADCS */
  T_ADCSHandle = osThreadNew(TASK_ADCS, NULL, &T_ADCS_attributes);

  /* creation of T_RasbyWtchdog */
  T_RasbyWtchdogHandle = osThreadNew(TASK_WatchdogRasby, NULL, &T_RasbyWtchdog_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */


	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);

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
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
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
                          |RSBY_ON_Pin|DIR_COIL_X_Pin|DIR_COIL_Y_Pin|DIR_COIL_Z_Pin
                          |CS_GYRO_Pin|EN_ADC1_Pin|EN_ADC3_Pin|EN_ADC2_Pin
                          |SBD_SER_RI_Pin|SBD_SER_NET_Pin|ANA_PWR_ON_Pin|RAD_PWR_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, UHF_RESET_Pin|RADFET_OWB_Pin|RAD_RESET_Pin|PSD1_SEL0_Pin
                          |PSD2_SEL1_Pin|PSD2_SEL0_Pin|PSD1_AMP_CS_Pin|PSD2_AMP_CS_Pin
                          |EX_SPI_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PSD1_SEL1_GPIO_Port, PSD1_SEL1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EX_GPIO3_Pin|CS_RADFET_Pin|EX_GPIO4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RSBY_KEEP_EN_Pin|EX_GPIO1_Pin|EX_GPIO2_Pin|WATCHDOG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, CS_EEPROM_Pin|CS_FRAM_Pin|CS_GYROD12_Pin|INT_GYRO_Pin
                          |CS_GYRO2_Pin|INT_GYRO2_Pin|SBD_SER_DCD_Pin|SBD_SER_DSR_Pin
                          |SBD_SER_DTR_Pin|SBD_SER_CTS_Pin|SBD_SER_RTS_Pin|SBD_ON_OFF_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : GPS_PWR_ON_Pin SBD_PWR_ON_Pin CS_NAND_Pin CS_LORA_Pin
                           RSBY_ON_Pin DIR_COIL_X_Pin DIR_COIL_Y_Pin DIR_COIL_Z_Pin
                           CS_GYRO_Pin EN_ADC1_Pin EN_ADC3_Pin EN_ADC2_Pin
                           SBD_SER_RI_Pin SBD_SER_NET_Pin ANA_PWR_ON_Pin RAD_PWR_ON_Pin */
  GPIO_InitStruct.Pin = GPS_PWR_ON_Pin|SBD_PWR_ON_Pin|CS_NAND_Pin|CS_LORA_Pin
                          |RSBY_ON_Pin|DIR_COIL_X_Pin|DIR_COIL_Y_Pin|DIR_COIL_Z_Pin
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
                          |PSD1_SEL0_Pin|PSD2_SEL1_Pin|PSD2_SEL0_Pin|PSD1_AMP_CS_Pin
                          |PSD2_AMP_CS_Pin|EX_SPI_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PWM_X_COIL_Pin PWM_Y_COIL_Pin PWM_Z_COIL_Pin */
  GPIO_InitStruct.Pin = PWM_X_COIL_Pin|PWM_Y_COIL_Pin|PWM_Z_COIL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
  GPIO_InitStruct.Pin = CS_EEPROM_Pin|CS_FRAM_Pin|CS_GYROD12_Pin|INT_GYRO_Pin
                          |CS_GYRO2_Pin|INT_GYRO2_Pin|SBD_SER_DCD_Pin|SBD_SER_DSR_Pin
                          |SBD_SER_DTR_Pin|SBD_SER_CTS_Pin|SBD_SER_RTS_Pin|SBD_ON_OFF_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PWM_HEATER_Pin */
  GPIO_InitStruct.Pin = PWM_HEATER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
  HAL_GPIO_Init(PWM_HEATER_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PGOOD_Pin */
  GPIO_InitStruct.Pin = PGOOD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PGOOD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
void TASK_HardwareWatchDog(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
  osDelay(100);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
  osDelay(900);

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
void TASK_DEBUG(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);
	  osDelay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0);
	  osDelay(900);
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
void TASK_BatteryPID(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for(;;)
  {
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
void TASK_FSM(void *argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the TASK_Trasmissio thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void TASK_RadioWatchdog(void *argument)
{
  /* USER CODE BEGIN StartTask05 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask05 */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the TASK_Telecomuni thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void TASK_Telecomunication(void *argument)
{
  /* USER CODE BEGIN StartTask06 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask06 */
}

/* USER CODE BEGIN Header_StartTask08 */
/**
* @brief Function implementing the TASK_SensorsSam thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask08 */
void TASK_SensorsSampling(void *argument)
{
  /* USER CODE BEGIN StartTask08 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask08 */
}

/* USER CODE BEGIN Header_StartTask09 */
/**
* @brief Function implementing the TASK_GroundStat thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask09 */
void TASK_GroundStationSearch(void *argument)
{
  /* USER CODE BEGIN StartTask09 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask09 */
}

/* USER CODE BEGIN Header_StartTask10 */
/**
* @brief Function implementing the TASK_ADCS thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask10 */
void TASK_ADCS(void *argument)
{
  /* USER CODE BEGIN StartTask10 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask10 */
}

/* USER CODE BEGIN Header_StartTask11 */
/**
* @brief Function implementing the TASK_WatchdogRa thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask11 */
void TASK_WatchdogRasby(void *argument)
{
  /* USER CODE BEGIN StartTask11 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask11 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
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
