/*
 * MPU9250_FEES_SPI.h
 *
 *  Created on: 19/ott/2018
 *      Author: Stefano
 */

#ifndef MPU9250_FEES_SPI_H_
#define MPU9250_FEES_SPI_H_

#include "ch.h"
#include "hal.h"
#include "../../../os/hal/boards/LASERNAV_STM32F4-FEES/board.h"

#include "halconf.h"
#include "hal_i2c_lld.h"
#include "hal_pwm.h"
#include "hal_spi.h"

#include "mcuconf.h"

/*====================================================*/
/* 			MPU9250 related. ( SPI1 - 2 )	          */
/*====================================================*/

/* MPU9250 Driver: This object represent an MPU9250 instance */
static MPU9250Driver MPU9250D1;
static MPU9250Driver MPU9250D2;

static int32_t accraw1[MPU9250_ACC_NUMBER_OF_AXES];
static int32_t gyroraw1[MPU9250_GYRO_NUMBER_OF_AXES];

static float acccooked1[MPU9250_ACC_NUMBER_OF_AXES];
static float gyrocooked1[MPU9250_GYRO_NUMBER_OF_AXES];

static float accBias1[MPU9250_ACC_NUMBER_OF_AXES]={2565,2670,70};
static float accBias2[MPU9250_ACC_NUMBER_OF_AXES]={2850,3320,70};

static int32_t accraw2[MPU9250_ACC_NUMBER_OF_AXES];
static int32_t gyroraw2[MPU9250_GYRO_NUMBER_OF_AXES];

static float acccooked2[MPU9250_ACC_NUMBER_OF_AXES];
static float gyrocooked2[MPU9250_GYRO_NUMBER_OF_AXES];

static char axisID[MPU9250_ACC_NUMBER_OF_AXES] = {'X', 'Y', 'Z'};
static uint32_t i;


/* SPI 1-2 CONFIG for IMU 1-2 */
static const SPIConfig spicfg1 = {
    FALSE,
    NULL,
    GPIOD,
    GPIOD_CS_MPU1,
    SPI_CR1_BR_2 | SPI_CR1_BR_1 | !SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
    0};
static const SPIConfig spicfg2 = {
    FALSE,
    NULL,
    GPIOE,
	GPIOE_CS_IMU2,
    SPI_CR1_BR_2 | SPI_CR1_BR_1 | !SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
    0};

static MPU9250Config mpu9250cfg1 = {&SPID1,
                                    &spicfg1,
                                    NULL,
                                    NULL,
                                    MPU9250_ACC_FS_16G,
                                    NULL,
                                    NULL,
                                    MPU9250_GYRO_FS_2000DPS};
static MPU9250Config mpu9250cfg2 = {&SPID2,
                                    &spicfg2,
                                    NULL,
                                    NULL,
                                    MPU9250_ACC_FS_16G,
                                    NULL,
                                    NULL,
                                    MPU9250_GYRO_FS_2000DPS};
/*===========================================================================*/
/* 						END OF MPU9250 related.     		                 */
/*===========================================================================*/



void printImus()
	{

		//// INIZIO IMU ///

	mpu9250AccelerometerReadRaw(&MPU9250D1, accraw1);
	mpu9250AccelerometerReadRaw(&MPU9250D2, accraw2);
	chprintf((BaseSequentialStream*)&SD3,
	         "/n"
	         "|***********************************************************************|"
	         "| MPU9250 Accelerometer raw data...\r\n|\t SENSOR 1 \t\t SENSOR 2  |\n\r");
	for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
	{
		chprintf((BaseSequentialStream*)&SD3, "| %c-axis: \t %d \t\t %d \t |\r\n",
	             axisID[i], accraw1[i], accraw2[i]);
	}
	mpu9250GyroscopeReadRaw(&MPU9250D1, gyroraw1);
	mpu9250GyroscopeReadRaw(&MPU9250D2, gyroraw2);
	chprintf((BaseSequentialStream*)&SD3,
	         "| MPU9250 Gyroscope raw data...\r\n| \t SENSOR 1 \t\t\t SENSOR 2  |\n\r");
	for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
	{
		chprintf((BaseSequentialStream*)&SD3, "|  %c-axis: \t %d \t\t %d \t |\r\n",
				axisID[i], gyroraw1[i], gyroraw2[i]);
	}
	chprintf((BaseSequentialStream*)&SD3,
	         "| \t\t\t\t\t\t | \n\r"
	         "|=============================================================| \n\r \n\r" );

	mpu9250AccelerometerReadCooked(&MPU9250D1, acccooked1);
	mpu9250AccelerometerReadCooked(&MPU9250D2, acccooked2);
	chprintf((BaseSequentialStream*)&SD3,
	         "/n"
	         "|***********************************************************************|"
	    	 "| MPU9250 Accelerometer Cooked data...[milli-g]\r\nSENSOR 1 \t\t\t SENSOR 2\n\r");
	for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
	{
	    chprintf((BaseSequentialStream*)&SD3,
	    		"|  %c-axis: \t %8.2f \t\t %8.2f \t  | \r\n", axisID[i], acccooked1[i], acccooked2[i]);
	}
	mpu9250GyroscopeReadCooked(&MPU9250D1, gyrocooked1);
	mpu9250GyroscopeReadCooked(&MPU9250D2, gyrocooked2);
	chprintf((BaseSequentialStream*)&SD3,
	        "| MPU9250 Gyroscope Cooked data...[DPS]\r\n| \t SENSOR 1 \t\t SENSOR 2 \t |\n\r");
	for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
	{
		chprintf((BaseSequentialStream*)&SD3,
		     "|  %c-axis: \t %8.2f \t\t %8.2f \t  |\r\n", axisID[i], gyrocooked1[i], gyrocooked2[i]);
	}
	chprintf((BaseSequentialStream*)&SD3,
	         "| \t\t\t\t\t\t | \n\r"
             "|=============================================================| \n\r \n\r" );

	        /// /// Fine IMU /// ///
}

#endif /* MPU9250_FEES_SPI_H_ */
