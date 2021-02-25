/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
	// Battery Heater PWM
#define PWM_HEATER_Pin GPIO_PIN_8
#define PWM_HEATER_GPIO_Port GPIOC


	// PWM COILS - MagnetoTorquers
#define PWM_X_COIL_Pin GPIO_PIN_0
#define PWM_X_COIL_GPIO_Port GPIOA
#define PWM_Y_COIL_Pin GPIO_PIN_1
#define PWM_Y_COIL_GPIO_Port GPIOA
#define PWM_Z_COIL_Pin GPIO_PIN_2
#define PWM_Z_COIL_GPIO_Port GPIOA

// Direction PWM Magnetometers
#define DIR_X_COIL_Pin GPIO_PIN_7
#define DIR_X_COIL_GPIO_Port GPIOE
#define DIR_Y_COIL_Pin GPIO_PIN_8
#define DIR_Y_COIL_GPIO_Port GPIOE
#define DIR_Z_COIL_Pin GPIO_PIN_9
#define DIR_Z_COIL_GPIO_Port GPIOE

//GPIO DI CONTROLLO E WATCHDOG
#define WATCHDOG_Pin GPIO_PIN_5
#define WATCHDOG_GPIO_Port GPIOB

#define UHF_RESET_Pin GPIO_PIN_13
#define UHF_RESET_GPIO_Port GPIOC

#define RAD_RESET_Pin GPIO_PIN_15
#define RAD_RESET_GPIO_Port GPIOC

#define TMTC_MCU_WD_Pin GPIO_PIN_12
#define TMTC_MCU_WD_GPIO_Port GPIOD

#define RSBY_KEEP_EN_Pin GPIO_PIN_0
#define RSBY_KEEP_EN_GPIO_Port GPIOB


//GPIO DI CONTROLLO Alimentazione (Power Control)
#define ANA_PWR_ON_Pin GPIO_PIN_0
#define ANA_PWR_ON_GPIO_Port GPIOE

#define RAD_PWR_ON_Pin GPIO_PIN_1
#define RAD_PWR_ON_GPIO_Port GPIOE

#define GPS_PWR_ON_Pin GPIO_PIN_2
#define GPS_PWR_ON_GPIO_Port GPIOE

#define SBD_PWR_ON_Pin GPIO_PIN_3
#define SBD_PWR_ON_GPIO_Port GPIOE

#define RSBY_ON_Pin GPIO_PIN_6
#define RSBY_ON_GPIO_Port GPIOE

// SPI SMART PINS - Sensors
#define CS_NAND_Pin GPIO_PIN_4
#define CS_NAND_GPIO_Port GPIOE

#define CS_LORA_Pin GPIO_PIN_5
#define CS_LORA_GPIO_Port GPIOE

#define CS_RADFET_Pin GPIO_PIN_4
#define CS_RADFET_GPIO_Port GPIOA

#define CS_EEPROM_Pin GPIO_PIN_10
#define CS_EEPROM_GPIO_Port GPIOD

#define CS_FRAM_Pin GPIO_PIN_11
#define CS_FRAM_GPIO_Port GPIOD

#define CS_PSD1_AMP_Pin GPIO_PIN_4
#define CS_PSD1_AMP_GPIO_Port GPIOC
#define CS_PSD2_AMP_Pin GPIO_PIN_5
#define CS_PSD2_AMP_GPIO_Port GPIOC

#define CS_GYRO_Pin GPIO_PIN_10
#define CS_GYRO_GPIO_Port GPIOE

#define CS_GYRO2_Pin GPIO_PIN_14
#define CS_GYRO2_GPIO_Port GPIOD

#define EN_ADC1_Pin GPIO_PIN_11
#define EN_ADC1_GPIO_Port GPIOE

#define EN_ADC2_Pin GPIO_PIN_13
#define EN_ADC2_GPIO_Port GPIOE

#define EN_ADC3_Pin GPIO_PIN_12
#define EN_ADC3_GPIO_Port GPIOE

#define EX_SPI_EN_Pin GPIO_PIN_9
#define EX_SPI_EN_GPIO_Port GPIOC


// GPIO EXTRA
#define EX_GPIO1_Pin GPIO_PIN_1
#define EX_GPIO1_GPIO_Port GPIOB
#define EX_GPIO2_Pin GPIO_PIN_12
#define EX_GPIO2_GPIO_Port GPIOB
#define EX_GPIO3_Pin GPIO_PIN_3
#define EX_GPIO3_GPIO_Port GPIOA
#define EX_GPIO4_Pin GPIO_PIN_10
#define EX_GPIO4_GPIO_Port GPIOA

	// Select
#define PSD1_SEL1_Pin GPIO_PIN_0
#define PSD1_SEL1_GPIO_Port GPIOC
#define PSD1_SEL0_Pin GPIO_PIN_1
#define PSD1_SEL0_GPIO_Port GPIOC
#define PSD2_SEL1_Pin GPIO_PIN_2
#define PSD2_SEL1_GPIO_Port GPIOC
#define PSD2_SEL0_Pin GPIO_PIN_3
#define PSD2_SEL0_GPIO_Port GPIOC

	// IMU
#define INT_GYRO_Pin GPIO_PIN_13
#define INT_GYRO_GPIO_Port GPIOD

#define INT_GYRO2_Pin GPIO_PIN_15
#define INT_GYRO2_GPIO_Port GPIOD

// Radex
#define RAD_RESET_Pin GPIO_PIN_15
#define RAD_RESET_GPIO_Port GPIOC

#define RADFET_OWB_Pin GPIO_PIN_14
#define RADFET_OWB_GPIO_Port GPIOC

	//SDB
#define SBD_ON_OFF_Pin GPIO_PIN_7
#define SBD_ON_OFF_GPIO_Port GPIOD

#define SBD_SER_RI_Pin GPIO_PIN_14
#define SBD_SER_RI_GPIO_Port GPIOE
#define SBD_SER_NET_Pin GPIO_PIN_15
#define SBD_SER_NET_GPIO_Port GPIOE
#define SBD_SER_DCD_Pin GPIO_PIN_0
#define SBD_SER_DCD_GPIO_Port GPIOD
#define SBD_SER_DSR_Pin GPIO_PIN_1
#define SBD_SER_DSR_GPIO_Port GPIOD
#define SBD_SER_DTR_Pin GPIO_PIN_2
#define SBD_SER_DTR_GPIO_Port GPIOD

#define SBD_SER_CTS_Pin GPIO_PIN_3
#define SBD_SER_CTS_GPIO_Port GPIOD
#define SBD_SER_RTS_Pin GPIO_PIN_4
#define SBD_SER_RTS_GPIO_Port GPIOD

// USB
#define OTG_FS_DM_Pin GPIO_PIN_11
#define OTG_FS_DM_GPIO_Port GPIOA
#define OTG_FS_DP_Pin GPIO_PIN_12
#define OTG_FS_DP_GPIO_Port GPIOA

	// Other
#define PGOOD_Pin GPIO_PIN_8
#define PGOOD_GPIO_Port GPIOA

#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA


#define BOOT1_Pin GPIO_PIN_2    	// GROUNDED!
#define BOOT1_GPIO_Port GPIOB 		// PUT IN TRI-STATE O OUT LOW at startup!

#define EMPTY_Pin GPIO_PIN_3		// Hanging - Tri-state
#define EMPTY_GPIO_Port GPIOB
#define EMPTY2_Pin GPIO_PIN_4		// Hanging - Tri-state
#define EMPTY2_GPIO_Port GPIOB

// JTAG
#define JTAG_TMS_Pin GPIO_PIN_13
#define JTAG_TMS_GPIO_Port GPIOA

#define JTAG_TCK_Pin GPIO_PIN_14
#define JTAG_TCK_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
