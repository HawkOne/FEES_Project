/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/***********************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                             *
 *    FFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS      *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S     *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S     *
 *    FF:::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS     *
 *      F::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                 *
 *      F::::F               E:::::E               E:::::E             S:::::S                 *
 *      F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS              *
 * ---- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS    ---- *
 * -::- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS  -::- *
 * ---- F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S ---- *
 *      F::::F               E:::::E               E:::::E                         S:::::S     *
 *      F::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S     *
 *    FF::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS      *
 *    FFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS        *
 *                                                                                             *
 *             ____    ___     __      ___    ___    __  ___ __       ___   ___                *
 *             |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |           *
 *             |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___        *
 *                      ___     __  ___ __  __  ___ __     __     ________                     *
 *                      |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|                *
 *                      |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |                *
 *                                                                                             *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                              *                                              *
 *                                        FEES Project                                         *
 *                      URL: https://github.com/ferrandi/DEIB-DAER-project                     *
 *                               Politecnico di Milano - DEIB                                  *
 *                          Matteo Franceschini  & Stefano Ampolo                              *
 *         ************************************************************************            *
 *                  Copyright (c) 2018-2019 Politecnico di Milano                              *
 *                                                                                             *
 *          This file is part of the FEES framework.                                           *
 *                                                                                             *
 *          The FEES framework is free software; you can redistribute it and/or modify         *
 *          it under the terms of the GNU General Public License as published by               *
 *          the Free Software Foundation; either version 3 of the License, or                  *
 *          (at your option) any later version.                                                *
 *                                                                                             *
 *          This program is distributed in the hope that it will be useful,                    *
 *          but WITHOUT ANY WARRANTY; without even the implied warranty of                     *
 *          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      *
 *          GNU General Public License for more details.                                       *
 *                                                                                             *
 *          You should have received a copy of the GNU General Public License                  *
 *          along with this program.  If not, see <http://www.gnu.org/licenses/>.              *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

/**
 * @file  board.h
 * @brief This is the board.h file
 * @author Stefano Ampolo
 * @author
 * $Revision$
 * $Date$
 * Last modified by Stefano ampolo
 *
 *
*/


/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_LASERNAV_STM32F4_FEES
#define BOARD_NAME                  "LASER NAVIGATION STM32F407 FEES CUBESAT"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F407xx

/*
 * IO pins assignments.
 */
#define GPIOA_PWM_X                 0U
#define GPIOA_PWM_Y                 1U
#define GPIOA_PWM_Z                 2U
#define GPIOA_EX_GPIO3              3U
#define GPIOA_CS_RADFET             4U
#define GPIOA_SCL                   5U
#define GPIOA_MISO                  6U
#define GPIOA_MOSI                  7U
#define GPIOA_P_GOOD                8U
#define GPIOA_VBUS_FS               9U
#define GPIOA_EX_GPIO4              10U
#define GPIOA_USBM                  11U
#define GPIOA_USBP                  12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define GPIOB_RASPY_EN              0U
#define GPIOB_EX_GPIO1              1U
#define GPIOB_BOOT1                 2U
#define GPIOB_PIN3                  3U
#define GPIOB_PIN4                  4U
#define GPIOB_WATCHDOG              5U
#define GPIOB_GPS_TX                6U
#define GPIOB_GPS_RX                7U
#define GPIOB_SCL2                  8U
#define GPIOB_SDA2                  9U
#define GPIOB_SCL1                  10U
#define GPIOB_SDA1                  11U
#define GPIOB_EX_GPIO2              12U
#define GPIOB_SCK2                  13U
#define GPIOB_MOSI2                  14U
#define GPIOB_MISO2                  15U

#define GPIOC_PSD1_SEL1		        0U
#define GPIOC_PSD1_SEL0      		1U
#define GPIOC_PSD2_SEL1         	2U
#define GPIOC_PSD2_SEL0      		3U
#define GPIOC_CS_PSD1               4U
#define GPIOC_CS_PSD2               5U
#define GPIOC_SDR_TX                6U
#define GPIOC_SDR_RX                7U
#define GPIOC_PWM_HEATER            8U
#define GPIOC_EX_SPI_EN             9U
#define GPIOC_SCLK_3                10U
#define GPIOC_MISO_3                11U
#define GPIOC_MOSI_3				12U
#define GPIOC_UHF_RESET             13U
#define GPIOC_RADFET_OWB            14U
#define GPIOC_RAD_RESET             15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_RESET                 4U
#define GPIOD_OVER_CURRENT          5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_CONSOLE_TX            8U
#define GPIOD_CONSOLE_RX            9U
#define GPIOD_CS_EEPROM             10U
#define GPIOD_CS_FRAM               11U
#define GPIOD_LED_BLUE              12U
#define GPIOD_TMTC_WD               12U /*Pin with double function*/
#define GPIOD_LED3                  13U
#define GPIOD_CS_MPU1               14U
#define GPIOD_LED6                  15U

#define GPIOE_ANA_PWR_ON           0U
#define GPIOE_RAD_PWR_ON           1U
#define GPIOE_GPS_PWR_ON           2U
#define GPIOE_SBD_PWR_ON           3U
#define GPIOE_CS_NAND              4U
#define GPIOE_CS_LORA              5U
#define GPIOE_RSBY_ON              6U
#define GPIOE_DIR_X_COIL           7U
#define GPIOE_DIR_Y_COIL           8U
#define GPIOE_DIR_Z_COIL           9U
#define GPIOE_CS_IMU2              10U
#define GPIOE_CS_ADC1              11U
#define GPIOE_CS_ADC3              12U
#define GPIOE_CS_ADC2              13U
#define GPIOE_SBD_SER_RI           14U
#define GPIOE_SBD_SER_NET          15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_SCK1                    PAL_LINE(GPIOA, 5U)
#define LINE_SDO1                    PAL_LINE(GPIOA, 6U)
#define LINE_SDI1                    PAL_LINE(GPIOA, 7U)
#define LINE_LED_BLUE                PAL_LINE(GPIOD,GPIOD_LED_BLUE) 
#define LINE_CS_MPU1                 PAL_LINE(GPIOD, 14U)
#define LINE_CONSOLE_TX              PAL_LINE(GPIOD, 8U)
#define LINE_CONSOLE_RX              PAL_LINE(GPIOD, 9U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))         /*OUTPUT LOW.*/
#define PIN_ODR_HIGH(n)             (1U << (n))         /*OUTPUT HIGH.*/
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U)) /*ALTERNATE F.*/


/*
 * GPIOA setup:
 *
 * PA0  - PWM_X                     (timer output).
 * PA1  - PWM_Y                     (timer output).
 * PA2  - PWM_Z                     (timer output).
 * PA3  - EX_GPIO3                  (output pushpull maximum).
 * PA4  - CS_RADFET                 (output pushpull maximum). 
 * PA5  - SCL                       (alternate 5).
 * PA6  - MISO                       (alternate 5).
 * PA7  - MOSI                      (alternate 5).
 * PA8  - PGOOD                      (input pullup).
 * PA9  - VBUS_FS                   (input floating).
 * PA10 - EX_GPIO_4                 (alternate 10).
 * PA11 - OTG_FS_DM                 (alternate 10).
 * PA12 - OTG_FS_DP                 (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - PIN15                     (input pullup).
 */

#define VAL_GPIOA_MODER             (PIN_MODE_OUTPUT(GPIOA_PWM_X) |          \
                                     PIN_MODE_OUTPUT(GPIOA_PWM_Y) |          \
                                     PIN_MODE_OUTPUT(GPIOA_PWM_Z) |          \
                                     PIN_MODE_OUTPUT(GPIOA_EX_GPIO3) |       \
                                     PIN_MODE_OUTPUT(GPIOA_CS_RADFET)|    	 \
                                     PIN_MODE_ALTERNATE(GPIOA_SCL) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_MISO) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_MOSI) |        \
                                     PIN_MODE_INPUT(GPIOA_P_GOOD) |          \
                                     PIN_MODE_INPUT(GPIOA_VBUS_FS) |         \
                                     PIN_MODE_OUTPUT(GPIOA_EX_GPIO4 ) |   \
                                     PIN_MODE_ALTERNATE(GPIOA_USBM) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_USBP) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |       \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |       \
                                     PIN_MODE_INPUT(GPIOA_PIN15))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_PWM_X) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PWM_Y) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PWM_Z) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EX_GPIO3) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_CS_RADFET) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SCL) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MISO) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MOSI) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_P_GOOD) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_VBUS_FS) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EX_GPIO4 ) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USBM) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USBP) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN15))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_HIGH(GPIOA_PWM_X) |          \
                                     PIN_OSPEED_HIGH(GPIOA_PWM_Y) |          \
                                     PIN_OSPEED_HIGH(GPIOA_PWM_Z) |          \
                                     PIN_OSPEED_HIGH(GPIOA_EX_GPIO3) |       \
                                     PIN_OSPEED_HIGH(GPIOA_CS_RADFET) |      \
                                     PIN_OSPEED_HIGH(GPIOA_SCL) |         	 \
                                     PIN_OSPEED_HIGH(GPIOA_MISO) |         	 \
                                     PIN_OSPEED_HIGH(GPIOA_MOSI) |         	 \
                                     PIN_OSPEED_HIGH(GPIOA_P_GOOD) |         \
                                     PIN_OSPEED_HIGH(GPIOA_VBUS_FS) |        \
                                     PIN_OSPEED_HIGH(GPIOA_EX_GPIO4 ) |      \
                                     PIN_OSPEED_HIGH(GPIOA_USBM) |           \
                                     PIN_OSPEED_HIGH(GPIOA_USBP) |           \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |          \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |          \
                                     PIN_OSPEED_HIGH(GPIOA_PIN15))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_PWM_X) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PWM_Y) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PWM_Z) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_EX_GPIO3) |    \
                                     PIN_PUPDR_PULLUP(GPIOA_CS_RADFET) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_SCL) |        \
                                     PIN_PUPDR_FLOATING(GPIOA_MISO) |        \
                                     PIN_PUPDR_FLOATING(GPIOA_MOSI) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_P_GOOD) |        \
                                     PIN_PUPDR_FLOATING(GPIOA_VBUS_FS) |     \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EX_GPIO4 ) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_USBM) |        \
                                     PIN_PUPDR_FLOATING(GPIOA_USBP) |        \
                                     PIN_PUPDR_FLOATING(GPIOA_SWDIO) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_SWCLK) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN15))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_PWM_X) |             \
                                     PIN_ODR_HIGH(GPIOA_PWM_Y) |             \
                                     PIN_ODR_HIGH(GPIOA_PWM_Z) |             \
                                     PIN_ODR_HIGH(GPIOA_EX_GPIO3) |          \
                                     PIN_ODR_HIGH(GPIOA_CS_RADFET) |         \
                                     PIN_ODR_HIGH(GPIOA_SCL) |              \
                                     PIN_ODR_HIGH(GPIOA_MISO) |              \
                                     PIN_ODR_HIGH(GPIOA_MOSI) |              \
                                     PIN_ODR_HIGH(GPIOA_P_GOOD) |            \
                                     PIN_ODR_HIGH(GPIOA_VBUS_FS) |           \
                                     PIN_ODR_LOW(GPIOA_EX_GPIO4 ) |         \
                                     PIN_ODR_HIGH(GPIOA_USBM) |              \
                                     PIN_ODR_HIGH(GPIOA_USBP) |              \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |             \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |             \
                                     PIN_ODR_HIGH(GPIOA_PIN15))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_PWM_X, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PWM_Y, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PWM_Z, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_EX_GPIO3, 0U) |       \
                                     PIN_AFIO_AF(GPIOA_CS_RADFET, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_SCL, 5U) |           \
                                     PIN_AFIO_AF(GPIOA_MISO, 5U) |           \
                                     PIN_AFIO_AF(GPIOA_MOSI, 5U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_P_GOOD, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_VBUS_FS, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_EX_GPIO4 , 0U) |     \
                                     PIN_AFIO_AF(GPIOA_USBM, 10U) |          \
                                     PIN_AFIO_AF(GPIOA_USBP, 10U) |          \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN15, 0U))

/*
 * GPIOB setup:
 *
 * PB0  - RASPY_EN              	(input pullup)
 * PB1  - EX_GPIO1                  	(input pullup)
 * PB2  - BOOT1                     	(input pullup)
 * PB3  - PIN3                      	 (alternate 0)
 * PB4  - PIN4                      	(input pullup)
 * PB5  - WATCHDOG                  	(input pullup)
 * PB6  - GPS_TX             	(alternate 4)
 * PB7  - GPS_RX             	(input pullup)
 * PB8  - SCL2   (Riferito Schematici)  (alternate 4)
 * PB9  - SDA2   (Riferito Schematici)  (alternate 4)
 * PB10 - SCL1   (Riferito Schematici)  (alternate 4)
 * PB11 - SDA1   (Riferito Schematici)  (alternate 4)
 * PB12 - EX_GPIO2                  	(input pullup)
 * PB13 - SCK2                  	(Alternate 5)
 * PB14 - GPIOB_MOSI2                 	(Alternate 5)
 * PB15 - GPIOB_MISO2                 	(Alternate 5)
 */


#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB_RASPY_EN) |        \
                                     PIN_MODE_OUTPUT(GPIOB_EX_GPIO1) |        \
                                     PIN_MODE_INPUT(GPIOB_BOOT1) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_PIN3) |        \
                                     PIN_MODE_INPUT(GPIOB_PIN4) |            \
                                     PIN_MODE_OUTPUT(GPIOB_WATCHDOG) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_GPS_TX) |      \
                                     PIN_MODE_ALTERNATE(GPIOB_GPS_RX) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_SCL2) |            \
                                     PIN_MODE_ALTERNATE(GPIOB_SDA2) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_SCL1) |            \
                                     PIN_MODE_ALTERNATE(GPIOB_SDA1) |            \
                                     PIN_MODE_OUTPUT(GPIOB_EX_GPIO2) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_SCK2) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_MOSI2) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_MISO2))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_RASPY_EN) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_EX_GPIO1)|     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_BOOT1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN4) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_WATCHDOG) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_GPS_TX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_GPS_RX) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SCL2) |        \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_SDA2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SCL1) |        \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_SDA1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_EX_GPIO2) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SCK2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MOSI2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MISO2))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_RASPY_EN) |       \
                                     PIN_OSPEED_HIGH(GPIOB_EX_GPIO1) |       \
                                     PIN_OSPEED_HIGH(GPIOB_BOOT1) |          \
                                     PIN_OSPEED_HIGH(GPIOB_PIN3) |           \
                                     PIN_OSPEED_HIGH(GPIOB_PIN4) |           \
                                     PIN_OSPEED_HIGH(GPIOB_WATCHDOG) |       \
                                     PIN_OSPEED_HIGH(GPIOB_GPS_TX) |         \
                                     PIN_OSPEED_HIGH(GPIOB_GPS_RX) |         \
                                     PIN_OSPEED_HIGH(GPIOB_SCL2) |           \
                                     PIN_OSPEED_HIGH(GPIOB_SDA2) |           \
                                     PIN_OSPEED_HIGH(GPIOB_SCL1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_SDA1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_EX_GPIO2) |       \
                                     PIN_OSPEED_HIGH(GPIOB_SCK2) |           \
                                     PIN_OSPEED_HIGH(GPIOB_MOSI2) |           \
                                     PIN_OSPEED_HIGH(GPIOB_MISO2))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLUP(GPIOB_RASPY_EN) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_EX_GPIO1) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_BOOT1) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN3) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_PIN4) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_WATCHDOG) |      \
                                     PIN_PUPDR_FLOATING(GPIOB_GPS_TX) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_GPS_RX) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_SCL2) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_SDA2) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_SCL1) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_SDA1) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_EX_GPIO2) |      \
                                     PIN_PUPDR_FLOATING(GPIOB_SCK2) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_MOSI2) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_MISO2))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_RASPY_EN) |          \
                                     PIN_ODR_HIGH(GPIOB_EX_GPIO1) |          \
                                     PIN_ODR_HIGH(GPIOB_BOOT1) |             \
                                     PIN_ODR_HIGH(GPIOB_PIN3) |              \
                                     PIN_ODR_HIGH(GPIOB_PIN4) |              \
                                     PIN_ODR_HIGH(GPIOB_WATCHDOG) |          \
                                     PIN_ODR_HIGH(GPIOB_GPS_TX) |            \
                                     PIN_ODR_HIGH(GPIOB_GPS_RX) |            \
                                     PIN_ODR_HIGH(GPIOB_SCL2) |              \
                                     PIN_ODR_HIGH(GPIOB_SDA2) |              \
                                     PIN_ODR_HIGH(GPIOB_SCL1) |              \
                                     PIN_ODR_HIGH(GPIOB_SDA1) |              \
                                     PIN_ODR_HIGH(GPIOB_EX_GPIO2) |          \
                                     PIN_ODR_HIGH(GPIOB_SCK2) |              \
                                     PIN_ODR_HIGH(GPIOB_MOSI2) |              \
                                     PIN_ODR_HIGH(GPIOB_MISO2))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_RASPY_EN, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_EX_GPIO1, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_BOOT1, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN3, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_PIN4, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_WATCHDOG, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_GPS_TX, 4U) |         \
                                     PIN_AFIO_AF(GPIOB_GPS_RX, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_SCL2, 4U) |           \
                                     PIN_AFIO_AF(GPIOB_SDA2, 4U) |           \
                                     PIN_AFIO_AF(GPIOB_SCL1, 4U) |           \
                                     PIN_AFIO_AF(GPIOB_SDA1, 4U) |           \
                                     PIN_AFIO_AF(GPIOB_EX_GPIO2, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_SCK2, 5U) |           \
                                     PIN_AFIO_AF(GPIOB_MOSI2, 5U) |           \
                                     PIN_AFIO_AF(GPIOB_MISO2, 5U))

/*
 * GPIOC setup:
 *
 * PC0  - PSD1_SEL1           		(output pushpull maximum).
 * PC1  - PSD1_SEL0                 (output pushpull maximum).
 * PC2  - PSD2_SEL1                 (output pushpull maximum).
 * PC3  - PSD2_SEL0                 (output pushpull maximum).
 * PC4  - CS_PSD1                   (output pushpull maximum).
 * PC5  - CS_PSD2                   (output pushpull maximum).
 * PC6  - SDR_TX                    (output pushpull maximum).
 * PC7  - SDR_RX                    (input pullup).
 * PC8  - PWM_HEATER                (output pushpull maximum).
 * PC9  - EX_SPI_EN                 (output pushpull maximum).
 * PC10 - SCLK_3                    (alternate 6).
 * PC11 - MISO_3                    (alternate 6).
 * PC12 - MOSI_3                    (alternate 6).
 * PC13 - UHF_RESET                 (output pushpull maximum).
 * PC14 - RADFET_OWB                (output pushpull maximum).
 * PC15 - RAD_RESET             	(output pushpull maximum).
 */

#define VAL_GPIOC_MODER             (PIN_MODE_OUTPUT(GPIOC_PSD1_SEL1) |\
                                     PIN_MODE_OUTPUT(GPIOC_PSD1_SEL0) |           \
                                     PIN_MODE_OUTPUT(GPIOC_PSD2_SEL1) |           \
                                     PIN_MODE_OUTPUT(GPIOC_PSD2_SEL0) |        \
                                     PIN_MODE_OUTPUT(GPIOC_CS_PSD1) |       \
                                     PIN_MODE_OUTPUT(GPIOC_CS_PSD2) |       \
                                     PIN_MODE_OUTPUT(GPIOC_SDR_TX) |           \
                                     PIN_MODE_INPUT( GPIOC_SDR_RX ) |       \
                                     PIN_MODE_OUTPUT(GPIOC_PWM_HEATER) |           \
                                     PIN_MODE_OUTPUT(GPIOC_EX_SPI_EN) |           \
                                     PIN_MODE_ALTERNATE(GPIOC_SCLK_3) |       \
                                     PIN_MODE_ALTERNATE(GPIOC_MISO_3) |          \
                                     PIN_MODE_ALTERNATE(GPIOC_MOSI_3) |       \
                                     PIN_MODE_OUTPUT(GPIOC_UHF_RESET) |          \
                                     PIN_MODE_OUTPUT(GPIOC_RADFET_OWB) |          \
                                     PIN_MODE_OUTPUT(GPIOC_RAD_RESET))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_PSD1_SEL1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_PSD1_SEL0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PSD2_SEL1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PSD2_SEL0) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CS_PSD1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CS_PSD2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDR_TX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDR_RX ) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PWM_HEATER) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_EX_SPI_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SCLK_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_MISO_3) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_MOSI_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_UHF_RESET) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RADFET_OWB) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RAD_RESET ))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIOC_PSD1_SEL1) |\
                                     PIN_OSPEED_HIGH(GPIOC_PSD1_SEL0) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PSD2_SEL1) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PSD2_SEL0) |       \
                                     PIN_OSPEED_HIGH(GPIOC_CS_PSD1) |          \
                                     PIN_OSPEED_HIGH(GPIOC_CS_PSD2) |          \
                                     PIN_OSPEED_HIGH(GPIOC_SDR_TX) |          \
                                     PIN_OSPEED_HIGH(GPIOC_SDR_RX ) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PWM_HEATER) |          \
                                     PIN_OSPEED_HIGH(GPIOC_EX_SPI_EN) |          \
                                     PIN_OSPEED_HIGH(GPIOC_SCLK_3) |          \
                                     PIN_OSPEED_HIGH(GPIOC_MISO_3) |         \
                                     PIN_OSPEED_HIGH(GPIOC_MOSI_3) |          \
                                     PIN_OSPEED_HIGH(GPIOC_UHF_RESET) |         \
                                     PIN_OSPEED_HIGH(GPIOC_RADFET_OWB) |         \
                                     PIN_OSPEED_HIGH(GPIOC_RAD_RESET))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(GPIOC_PSD1_SEL1) |\
                                     PIN_PUPDR_PULLUP(GPIOC_PSD1_SEL0) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_PSD2_SEL1) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_PSD2_SEL0) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_CS_PSD1) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_CS_PSD2) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_SDR_TX) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_SDR_RX ) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PWM_HEATER) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_EX_SPI_EN) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_SCLK_3) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_MISO_3) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_MOSI_3) |       \
                                     PIN_PUPDR_PULLUP(GPIOC_UHF_RESET) |        \
                                     PIN_PUPDR_PULLUP(GPIOC_RADFET_OWB) |        \
                                     PIN_PUPDR_PULLUP(GPIOC_RAD_RESET))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_PSD1_SEL1) |  \
                                     PIN_ODR_HIGH(GPIOC_PSD1_SEL0) |             \
                                     PIN_ODR_HIGH(GPIOC_PSD2_SEL1) |             \
                                     PIN_ODR_HIGH(GPIOC_PSD2_SEL0) |          \
                                     PIN_ODR_HIGH(GPIOC_CS_PSD1) |          \
                                     PIN_ODR_HIGH(GPIOC_CS_PSD2) |          \
                                     PIN_ODR_HIGH(GPIOC_SDR_TX) |             \
                                     PIN_ODR_HIGH(GPIOC_SDR_RX ) |             \
                                     PIN_ODR_HIGH(GPIOC_PWM_HEATER) |             \
                                     PIN_ODR_HIGH(GPIOC_EX_SPI_EN) |             \
                                     PIN_ODR_HIGH(GPIOC_SCLK_3) |             \
                                     PIN_ODR_HIGH(GPIOC_MISO_3) |            \
                                     PIN_ODR_HIGH(GPIOC_MOSI_3) |             \
                                     PIN_ODR_LOW(GPIOC_UHF_RESET) |            \
                                     PIN_ODR_LOW(GPIOC_RADFET_OWB) |            \
                                     PIN_ODR_LOW(GPIOC_RAD_RESET))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_PSD1_SEL1, 0U) |\
                                     PIN_AFIO_AF(GPIOC_PSD1_SEL0, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PSD2_SEL1, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PSD2_SEL0, 0U) |       \
                                     PIN_AFIO_AF(GPIOC_CS_PSD1, 0U) |       \
                                     PIN_AFIO_AF(GPIOC_CS_PSD2, 0U) |       \
                                     PIN_AFIO_AF(GPIOC_SDR_TX, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_SDR_RX , 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_PWM_HEATER, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_EX_SPI_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_SCLK_3, 6U) |          \
                                     PIN_AFIO_AF(GPIOC_MISO_3, 6U) |         \
                                     PIN_AFIO_AF(GPIOC_MOSI_3, 6U) |          \
                                     PIN_AFIO_AF(GPIOC_UHF_RESET, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_RADFET_OWB, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_RAD_RESET, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input pullup).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PSD2_SEL0                      (input pullup).
 * PD3  - PIN3                      (input pullup).
 * PD4  - RESET                     (output pushpull maximum).
 * PD5  - OVER_CURRENT              (input floating).
 * PD6  - PIN6                      (input pullup).
 * PD7  - PIN7                      (input pullup).
 * PD8  - CONSOLE TX                (alternate 7).
 * PD9  - CONSOLE RX                (alternate 7).
 * PD10 - CS EEPROM                 (output pushpull maximum)
 * PD11 - CS FRAM                   (output pushpull maximum)
 * PD12 - LED4                      (output pushpull maximum).
 * PD13 - LED3                      (output pushpull maximum).
 * PD14 - LED5                      (output pushpull maximum).
 * PD15 - LED6                      (output pushpull maximum).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |           \
                                     PIN_MODE_OUTPUT(GPIOD_RESET) |         \
                                     PIN_MODE_INPUT(GPIOD_OVER_CURRENT) |   \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |           \
                                     PIN_MODE_ALTERNATE(GPIOD_CONSOLE_TX)|  \
                                     PIN_MODE_ALTERNATE(GPIOD_CONSOLE_RX) | \
                                     PIN_MODE_OUTPUT(GPIOD_CS_EEPROM) |     \
                                     PIN_MODE_OUTPUT(GPIOD_CS_FRAM) |       \
                                     PIN_MODE_OUTPUT(GPIOD_LED_BLUE) |      \
                                     PIN_MODE_OUTPUT(GPIOD_LED3) |          \
                                     PIN_MODE_OUTPUT(GPIOD_CS_MPU1) |       \
                                     PIN_MODE_OUTPUT(GPIOD_LED6))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_RESET) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_OVER_CURRENT)|\
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CONSOLE_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CONSOLE_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CS_EEPROM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CS_FRAM) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_LED_BLUE) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOD_LED3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CS_MPU1) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_LED6))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOD_RESET) |         \
                                     PIN_OSPEED_HIGH(GPIOD_OVER_CURRENT) |  \
                                     PIN_OSPEED_HIGH(GPIOD_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN7) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_CONSOLE_TX) | \
                                     PIN_OSPEED_VERYLOW(GPIOD_CONSOLE_RX) | \
                                     PIN_OSPEED_HIGH(GPIOD_CS_EEPROM) |     \
                                     PIN_OSPEED_HIGH(GPIOD_CS_FRAM) |       \
                                     PIN_OSPEED_HIGH(GPIOD_LED_BLUE) |      \
                                     PIN_OSPEED_HIGH(GPIOD_LED3) |          \
                                     PIN_OSPEED_HIGH(GPIOD_CS_MPU1) |       \
                                     PIN_OSPEED_HIGH(GPIOD_LED6))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_RESET) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_OVER_CURRENT) |\
                                     PIN_PUPDR_PULLUP(GPIOD_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_CONSOLE_TX) | \
                                     PIN_PUPDR_FLOATING(GPIOD_CONSOLE_RX) | \
                                     PIN_PUPDR_PULLUP(GPIOD_CS_EEPROM) |  \
                                     PIN_PUPDR_PULLUP(GPIOD_CS_FRAM) |    \
                                     PIN_PUPDR_FLOATING(GPIOD_LED_BLUE) |   \
                                     PIN_PUPDR_FLOATING(GPIOD_LED3) |       \
                                     PIN_PUPDR_PULLUP(GPIOD_CS_MPU1) |    \
                                     PIN_PUPDR_FLOATING(GPIOD_LED6))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOD_RESET) |            \
                                     PIN_ODR_HIGH(GPIOD_OVER_CURRENT) |     \
                                     PIN_ODR_HIGH(GPIOD_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOD_CONSOLE_TX) |       \
                                     PIN_ODR_HIGH(GPIOD_CONSOLE_RX) |       \
                                     PIN_ODR_HIGH(GPIOD_CS_EEPROM) |        \
                                     PIN_ODR_HIGH(GPIOD_CS_FRAM) |          \
                                     PIN_ODR_LOW(GPIOD_LED_BLUE) |          \
                                     PIN_ODR_LOW(GPIOD_LED3) |              \
                                     PIN_ODR_HIGH(GPIOD_CS_MPU1) |           \
                                     PIN_ODR_LOW(GPIOD_LED6))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_RESET, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_OVER_CURRENT, 0U) |  \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_CONSOLE_TX, 7U) |    \
                                     PIN_AFIO_AF(GPIOD_CONSOLE_RX, 7U) |    \
                                     PIN_AFIO_AF(GPIOD_CS_EEPROM, 0U) |     \
                                     PIN_AFIO_AF(GPIOD_CS_FRAM, 0U) |       \
                                     PIN_AFIO_AF(GPIOD_LED_BLUE, 0U) |      \
                                     PIN_AFIO_AF(GPIOD_LED3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_CS_MPU1, 0U) |       \
                                     PIN_AFIO_AF(GPIOD_LED6, 0U))
/*
 * GPIOE setup:
 *
 * PE0  - ANA_PWR_ON                (output pushpull maximum).
 * PE1  - RAD_PWR_ON                (output pushpull maximum).
 * PE2  - GPS_PWR_ON                (output pushpull maximum).
 * PE3  - SBD_PWR_ON                (output pushpull maximum).
 * PE4  - CS_NAND                   (output pushpull maximum).
 * PE5  - CS_LORA                   (output pushpull maximum).
 * PE6  - RSBY_ON                   (output pushpull maximum).
 * PE7  - DIR_X_COIL                (output pushpull maximum).
 * PE8  - DIR_Y_COIL                (output pushpull maximum).
 * PE9  - DIR_Z_COIL                (output pushpull maximum).
 * PE10 - CS_IMU2                   (output pushpull maximum).
 * PE11 - CS_ADC1                   (output pushpull maximum).
 * PE12 - CS_ADC3                   (output pushpull maximum).
 * PE13 - CS_ADC2                   (output pushpull maximum).
 * PE14 - SBD_SER_RI                   (input floating).
 * PE15 - SBD_SER_NET                  (input floating).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_OUTPUT(GPIOE_ANA_PWR_ON) |           \
                                     PIN_MODE_OUTPUT(GPIOE_RAD_PWR_ON) |           \
                                     PIN_MODE_OUTPUT(GPIOE_GPS_PWR_ON) |           \
                                     PIN_MODE_OUTPUT(GPIOE_SBD_PWR_ON) |        \
                                     PIN_MODE_OUTPUT(GPIOE_CS_NAND) |           \
                                     PIN_MODE_OUTPUT(GPIOE_CS_LORA) |           \
                                     PIN_MODE_OUTPUT(GPIOE_RSBY_ON) |           \
                                     PIN_MODE_OUTPUT(GPIOE_DIR_X_COIL) |           \
                                     PIN_MODE_OUTPUT(GPIOE_DIR_Y_COIL) |           \
                                     PIN_MODE_OUTPUT(GPIOE_DIR_Z_COIL) |           \
                                     PIN_MODE_OUTPUT(GPIOE_CS_IMU2 ) |       \
                                     PIN_MODE_OUTPUT(GPIOE_CS_ADC1) |          \
                                     PIN_MODE_OUTPUT(GPIOE_CS_ADC3) |          \
                                     PIN_MODE_OUTPUT(GPIOE_CS_ADC2) |          \
                                     PIN_MODE_INPUT(GPIOE_SBD_SER_RI) |          \
                                     PIN_MODE_INPUT(GPIOE_SBD_SER_NET))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_ANA_PWR_ON) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_RAD_PWR_ON) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_GPS_PWR_ON) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_SBD_PWR_ON) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_NAND) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_LORA) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_RSBY_ON) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_DIR_X_COIL) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_DIR_Y_COIL) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_DIR_Z_COIL) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_IMU2 ) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_ADC1) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_ADC3) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_ADC2) |      \
                                     PIN_OTYPE_OPENDRAIN(GPIOE_SBD_SER_RI) |      \
                                     PIN_OTYPE_OPENDRAIN(GPIOE_SBD_SER_NET))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_ANA_PWR_ON) |          \
                                     PIN_OSPEED_HIGH(GPIOE_RAD_PWR_ON) |          \
                                     PIN_OSPEED_HIGH(GPIOE_GPS_PWR_ON) |          \
                                     PIN_OSPEED_HIGH(GPIOE_SBD_PWR_ON) |        \
                                     PIN_OSPEED_HIGH(GPIOE_CS_NAND) |          \
                                     PIN_OSPEED_HIGH(GPIOE_CS_LORA) |          \
                                     PIN_OSPEED_HIGH(GPIOE_RSBY_ON) |          \
                                     PIN_OSPEED_HIGH(GPIOE_DIR_X_COIL) |          \
                                     PIN_OSPEED_HIGH(GPIOE_DIR_Y_COIL) |          \
                                     PIN_OSPEED_HIGH(GPIOE_DIR_Z_COIL) |          \
                                     PIN_OSPEED_HIGH(GPIOE_CS_IMU2 ) |      \
                                     PIN_OSPEED_HIGH(GPIOE_CS_ADC1) |         \
                                     PIN_OSPEED_HIGH(GPIOE_CS_ADC3) |         \
                                     PIN_OSPEED_HIGH(GPIOE_CS_ADC2) |         \
                                     PIN_OSPEED_HIGH(GPIOE_SBD_SER_RI) |         \
                                     PIN_OSPEED_HIGH(GPIOE_SBD_SER_NET))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOE_ANA_PWR_ON) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOE_RAD_PWR_ON) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOE_GPS_PWR_ON) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOE_SBD_PWR_ON)|     \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_NAND) |       \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_LORA) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOE_RSBY_ON) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_DIR_X_COIL) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_DIR_Y_COIL) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_DIR_Z_COIL) |       \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_IMU2) |   \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_ADC1)|      \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_ADC3)|      \
                                     PIN_PUPDR_PULLUP(GPIOE_CS_ADC2)|      \
                                     PIN_PUPDR_FLOATING(GPIOE_SBD_SER_RI) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_SBD_SER_NET))
#define VAL_GPIOE_ODR               (PIN_ODR_LOW(GPIOE_ANA_PWR_ON) |             \
                                     PIN_ODR_LOW(GPIOE_RAD_PWR_ON) |             \
                                     PIN_ODR_LOW(GPIOE_GPS_PWR_ON) |             \
                                     PIN_ODR_LOW(GPIOE_SBD_PWR_ON) |           \
                                     PIN_ODR_HIGH(GPIOE_CS_NAND) |             \
                                     PIN_ODR_HIGH(GPIOE_CS_LORA) |             \
                                     PIN_ODR_LOW(GPIOE_RSBY_ON) |             \
                                     PIN_ODR_HIGH(GPIOE_DIR_X_COIL) |             \
                                     PIN_ODR_HIGH(GPIOE_DIR_Y_COIL) |             \
                                     PIN_ODR_HIGH(GPIOE_DIR_Z_COIL) |             \
                                     PIN_ODR_HIGH(GPIOE_CS_IMU2 ) |         \
                                     PIN_ODR_HIGH(GPIOE_CS_ADC1) |            \
                                     PIN_ODR_HIGH(GPIOE_CS_ADC3) |            \
                                     PIN_ODR_HIGH(GPIOE_CS_ADC2) |            \
                                     PIN_ODR_HIGH(GPIOE_SBD_SER_RI) |            \
                                     PIN_ODR_HIGH(GPIOE_SBD_SER_NET))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_ANA_PWR_ON, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_RAD_PWR_ON, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_GPS_PWR_ON, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_SBD_PWR_ON, 0U) |        \
                                     PIN_AFIO_AF(GPIOE_CS_NAND, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_CS_LORA, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_RSBY_ON, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_DIR_X_COIL, 0U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_DIR_Y_COIL, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_DIR_Z_COIL, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_CS_IMU2 , 0U) |      \
                                     PIN_AFIO_AF(GPIOE_CS_ADC1, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_CS_ADC3, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_CS_ADC2, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_SBD_SER_RI, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_SBD_SER_NET, 0U))

/*
 * GPIOF setup:
 *
 * PF0  - PIN0                      (input floating).
 * PF1  - PIN1                      (input floating).
 * PF2  - PIN2                      (input floating).
 * PF3  - PIN3                      (input floating).
 * PF4  - PIN4                      (input floating).
 * PF5  - PIN5                      (input floating).
 * PF6  - PIN6                      (input floating).
 * PF7  - PIN7                      (input floating).
 * PF8  - PIN8                      (input floating).
 * PF9  - PIN9                      (input floating).
 * PF10 - PIN10                     (input floating).
 * PF11 - PIN11                     (input floating).
 * PF12 - PIN12                     (input floating).
 * PF13 - PIN13                     (input floating).
 * PF14 - PIN14                     (input floating).
 * PF15 - PIN15                     (input floating).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0U))

/*
 * GPIOG setup:
 *
 * PG0  - PIN0                      (input floating).
 * PG1  - PIN1                      (input floating).
 * PG2  - PIN2                      (input floating).
 * PG3  - PIN3                      (input floating).
 * PG4  - PIN4                      (input floating).
 * PG5  - PIN5                      (input floating).
 * PG6  - PIN6                      (input floating).
 * PG7  - PIN7                      (input floating).
 * PG8  - PIN8                      (input floating).
 * PG9  - PIN9                      (input floating).
 * PG10 - PIN10                     (input floating).
 * PG11 - PIN11                     (input floating).
 * PG12 - PIN12                     (input floating).
 * PG13 - PIN13                     (input floating).
 * PG14 - PIN14                     (input floating).
 * PG15 - PIN15                     (input floating).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_INPUT(GPIOG_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_HIGH(GPIOG_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIOG_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN15))
#define VAL_GPIOG_ODR               (PIN_ODR_HIGH(GPIOG_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN7, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN15, 0U))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 * PH2  - PIN2                      (input floating).
 * PH3  - PIN3                      (input floating).
 * PH4  - PIN4                      (input floating).
 * PH5  - PIN5                      (input floating).
 * PH6  - PIN6                      (input floating).
 * PH7  - PIN7                      (input floating).
 * PH8  - PIN8                      (input floating).
 * PH9  - PIN9                      (input floating).
 * PH10 - PIN10                     (input floating).
 * PH11 - PIN11                     (input floating).
 * PH12 - PIN12                     (input floating).
 * PH13 - PIN13                     (input floating).
 * PH14 - PIN14                     (input floating).
 * PH15 - PIN15                     (input floating).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOH_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN15))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOH_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN15, 0U))

/*
 * GPIOI setup:
 *
 * PI0  - PIN0                      (input floating).
 * PI1  - PIN1                      (input floating).
 * PI2  - PIN2                      (input floating).
 * PI3  - PIN3                      (input floating).
 * PI4  - PIN4                      (input floating).
 * PI5  - PIN5                      (input floating).
 * PI6  - PIN6                      (input floating).
 * PI7  - PIN7                      (input floating).
 * PI8  - PIN8                      (input floating).
 * PI9  - PIN9                      (input floating).
 * PI10 - PIN10                     (input floating).
 * PI11 - PIN11                     (input floating).
 * PI12 - PIN12                     (input floating).
 * PI13 - PIN13                     (input floating).
 * PI14 - PIN14                     (input floating).
 * PI15 - PIN15                     (input floating).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_INPUT(GPIOI_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_HIGH(GPIOI_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_FLOATING(GPIOI_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(GPIOI_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN7, 0U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
