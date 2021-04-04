/*
    ChibiOS - Copyright (C) 2018 Matteo Franceschini

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
 *                          				Stefano Ampolo                             		   *
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
 * @file    mpu9250.h
 * @brief   MPU9250 MEMS interface module header.
 *
 * @addtogroup MPU9250
 * @ingroup EX_INVENSENSE
 * @{
 */
#ifndef _MPU9250_H_
#define _MPU9250_H_

#include "hal_accelerometer.h"
#include "hal_gyroscope.h"
/*MAGNETOMETER NOT SUPPORTED YET*/

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Version identification
 * @{
 */
/**
 * @brief   MPU9250 driver version string.
 */
#define EX_MPU9250_VERSION "0.0.0"

/**
 * @brief   MPU9250 driver version major number.
 */
#define EX_MPU9250_MAJOR 0

/**
 * @brief   MPU9250 driver version minor number.
 */
#define EX_MPU9250_MINOR 0

/**
 * @brief   MPU9250 driver version patch number.
 */
#define EX_MPU9250_PATCH 0
/** @} */

/**
 * @brief   MPU9250 accelerometer subsystem characteristics.
 * @note    Sensitivity is expressed as milli-G/LSB whereas
 *          1 milli-G = 0.00980665 m/s^2.
 * @note    Bias is expressed as milli-G.
 *
 * @{
 */
#define MPU9250_ACC_NUMBER_OF_AXES 3U

#define MPU9250_ACC_2G 2000.0f
#define MPU9250_ACC_4G 4000.0f
#define MPU9250_ACC_8G 8000.0f
#define MPU9250_ACC_16G 16000.0f

#define MPU9250_ACC_SENS_2G 2000.0f / 32768.0f
#define MPU9250_ACC_SENS_4G 4000.0f / 32768.0f
#define MPU9250_ACC_SENS_8G 8000.0f / 32768.0f
#define MPU9250_ACC_SENS_16G 16000.0f / 32768.0f

#define MPU9250_ACC_BIAS 0.0f
/** @} */

/**
 * @brief   MPU9250 gyroscope system characteristics.
 * @note    Sensitivity is expressed as DPS/LSB whereas DPS stand for Degree
 *          per second [°/s].
 * @note    Bias is expressed as DPS.
 *
 * @{
 */
#define MPU9250_GYRO_NUMBER_OF_AXES 3U

#define MPU9250_GYRO_250DPS 250.0f
#define MPU9250_GYRO_500DPS 500.0f
#define MPU9250_GYRO_1000DPS 1000.0f
#define MPU9250_GYRO_2000DPS 2000.0f

#define MPU9250_GYRO_SENS_250DPS 250 / 32768.0f
#define MPU9250_GYRO_SENS_500DPS 500 / 32768.0f
#define MPU9250_GYRO_SENS_1000DPS 1000 / 32768.0f
#define MPU9250_GYRO_SENS_2000DPS 2000 / 32768.0f

#define MPU9250_GYRO_BIAS 0.0f
/** @} */

/**
 * @name    MPU9250 communication interfaces related bit masks
 * @{
 */
/*#define MPU9250_DI_MASK 0xFF
#define MPU9250_DI(n) (1 << n)
#define MPU9250_AD_MASK 0x3F
#define MPU9250_AD(n) (1 << n)*/ /*<- NOT USED*/
#define MPU9250_RW (1 << 7) /*First bit of first byte defines R/W operation*/
/** @} */

/**
 * @name   MPU9250 Accelerometer and Gyroscope Registers
 * @{
 */
#define MPU_REG_ELF_TEST_X_GYRO 0x00
#define MPU_REG_ELF_TEST_Y_GYRO 0x01
#define MPU_REG_ELF_TEST_Z_GYRO 0x02

#define MPU_REG_SELF_TEST_X_ACCEL 0x0D
#define MPU_REG_SELF_TEST_Y_ACCEL 0x0E
#define MPU_REG_SELF_TEST_Z_ACCEL 0x0F

#define MPU_REG_XG_OFFSET_H 0x13
#define MPU_REG_XG_OFFSET_L 0x14
#define MPU_REG_YG_OFFSET_H 0x15
#define MPU_REG_YG_OFFSET_L 0x16
#define MPU_REG_ZG_OFFSET_H 0x17
#define MPU_REG_ZG_OFFSET_L 0x18
#define MPU_REG_SMPLRT_DIV 0x19
#define MPU_REG_CONFIG 0x1A
#define MPU_REG_GYRO_CONFIG 0x1B
#define MPU_REG_ACCEL_CONFIG 0x1C
#define MPU_REG_ACCEL_CONFIG_2 0x1D
#define MPU_REG_LP_ACCEL_ODR 0x1E
#define MPU_REG_WOM_THR 0x1F

#define MPU_REG_FIFO_EN 0x23
#define MPU_REG_I2C_MST_CTRL 0x24
#define MPU_REG_I2C_SLV0_ADDR 0x25
#define MPU_REG_I2C_SLV0_REG 0x26
#define MPU_REG_I2C_SLV0_CTRL 0x27
#define MPU_REG_I2C_SLV1_ADDR 0x28
#define MPU_REG_I2C_SLV1_REG 0x29
#define MPU_REG_I2C_SLV1_CTRL 0x2A
#define MPU_REG_I2C_SLV2_ADDR 0x2B
#define MPU_REG_I2C_SLV2_REG 0x2C
#define MPU_REG_I2C_SLV2_CTRL 0x2D
#define MPU_REG_I2C_SLV3_ADDR 0x2E
#define MPU_REG_I2C_SLV3_REG 0x2F
#define MPU_REG_I2C_SLV3_CTRL 0x30
#define MPU_REG_I2C_SLV4_ADDR 0x31
#define MPU_REG_I2C_SLV4_REG 0x32
#define MPU_REG_I2C_SLV4_DO 0x33
#define MPU_REG_I2C_SLV4_CTRL 0x34
#define MPU_REG_I2C_SLV4_DI 0x35
#define MPU_REG_I2C_MST_STATUS 0x36
#define MPU_REG_INT_PIN_CFG 0x37
#define MPU_REG_INT_ENABLE 0x38

#define MPU_REG_INT_STATUS 0x3A
#define MPU_REG_ACCEL_XOUT_H 0x3B
#define MPU_REG_ACCEL_XOUT_L 0x3C
#define MPU_REG_ACCEL_YOUT_H 0x3D
#define MPU_REG_ACCEL_YOUT_L 0x3E
#define MPU_REG_ACCEL_ZOUT_H 0x3F
#define MPU_REG_ACCEL_ZOUT_L 0x40
#define MPU_REG_TEMP_OUT_H 0x41
#define MPU_REG_TEMP_OUT_L 0x42
#define MPU_REG_GYRO_XOUT_H 0x43
#define MPU_REG_GYRO_XOUT_L 0x44
#define MPU_REG_GYRO_YOUT_H 0x45
#define MPU_REG_GYRO_YOUT_L 0x46
#define MPU_REG_GYRO_ZOUT_H 0x47
#define MPU_REG_GYRO_ZOUT_L 0x48
#define MPU_REG_EXT_SENS_DATA_00 0x49
#define MPU_REG_EXT_SENS_DATA_01 0x4A
#define MPU_REG_EXT_SENS_DATA_02 0x4B
#define MPU_REG_EXT_SENS_DATA_03 0x4C
#define MPU_REG_EXT_SENS_DATA_04 0x4D
#define MPU_REG_EXT_SENS_DATA_05 0x4E
#define MPU_REG_EXT_SENS_DATA_06 0x4F
#define MPU_REG_EXT_SENS_DATA_07 0x50
#define MPU_REG_EXT_SENS_DATA_08 0x51
#define MPU_REG_EXT_SENS_DATA_09 0x52
#define MPU_REG_EXT_SENS_DATA_10 0x53
#define MPU_REG_EXT_SENS_DATA_11 0x54
#define MPU_REG_EXT_SENS_DATA_12 0x55
#define MPU_REG_EXT_SENS_DATA_13 0x56
#define MPU_REG_EXT_SENS_DATA_14 0x57
#define MPU_REG_EXT_SENS_DATA_15 0x58
#define MPU_REG_EXT_SENS_DATA_16 0x59
#define MPU_REG_EXT_SENS_DATA_17 0x5A
#define MPU_REG_EXT_SENS_DATA_18 0x5B
#define MPU_REG_EXT_SENS_DATA_19 0x5C
#define MPU_REG_EXT_SENS_DATA_20 0x5D
#define MPU_REG_EXT_SENS_DATA_21 0x5E
#define MPU_REG_EXT_SENS_DATA_22 0x5F
#define MPU_REG_EXT_SENS_DATA_23 0x60

#define MPU_REG_I2C_SLV0_DO 0x63
#define MPU_REG_I2C_SLV1_DO 0x64
#define MPU_REG_I2C_SLV2_DO 0x65
#define MPU_REG_I2C_SLV3_DO 0x66
#define MPU_REG_I2C_MST_DELAY_CTRL 0x67
#define MPU_REG_SIGNAL_PATH_RESET 0x68
#define MPU_REG_MOT_DETECT_CTRL 0x69
#define MPU_REG_USER_CTRL 0x6A
#define MPU_REG_PWR_MGMT_1 0x6B
#define MPU_REG_PWR_MGMT_2 0x6C

#define MPU_REG_FIFO_COUNTH 0x72
#define MPU_REG_FIFO_COUNTL 0x73
#define MPU_REG_FIFO_R_W 0x74
#define MPU_REG_WHO_AM_I 0x75

#define MPU_REG_XA_OFFSET_H 0x77
#define MPU_REG_XA_OFFSET_L 0x78

#define MPU_REG_YA_OFFSET_H 0x7A
#define MPU_REG_YA_OFFSET_L 0x7B

#define MPU_REG_ZA_OFFSET_H 0x7D
#define MPU_REG_ZA_OFFSET_L 0x7E

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   MPU9250 SPI interface switch.
 * @details If set to @p TRUE the support for SPI is included.
 * @note    The default is @p FALSE.
 */
#if !defined(MPU9250_USE_SPI) || defined(__DOXYGEN__)
#define MPU9250_USE_SPI 		TRUE
#endif

/**
 * @brief   MPU9250 shared SPI switch.
 * @details If set to @p TRUE the device acquires SPI bus ownership
 *          on each transaction.
 * @note    The default is @p FALSE. Requires SPI_USE_MUTUAL_EXCLUSION.
 */
#if !defined(MPU9250_SHARED_SPI) || defined(__DOXYGEN__)
#define MPU9250_SHARED_SPI 		TRUE
#endif

/**
 * @brief   MPU9250 I2C interface switch.
 * @details If set to @p TRUE the support for I2C is included.
 * @note    The default is @p TRUE.
 */
#if !defined(MPU9250_USE_I2C) || defined(__DOXYGEN__)
#define MPU9250_USE_I2C FALSE
#endif

/**
 * @brief   MPU9250 shared I2C switch.
 * @details If set to @p TRUE the device acquires I2C bus ownership
 *          on each transaction.
 * @note    The default is @p FALSE. Requires I2C_USE_MUTUAL_EXCLUSION.
 */
#if !defined(MPU9250_SHARED_I2C) || defined(__DOXYGEN__)
#define MPU9250_SHARED_I2C FALSE
#endif

/**
 * @brief   MPU9250 advanced configurations switch.
 * @details If set to @p TRUE more configurations are available.
 * @note    The default is @p FALSE.
 */
#if !defined(MPU9250_USE_ADVANCED) || defined(__DOXYGEN__)
#define MPU9250_USE_ADVANCED FALSE
#endif

/**
 * @brief   MPU9250 accelerometer subsystem advanced configurations
 *          switch.
 * @details If set to @p TRUE more configurations are available.
 * @note    The default is @p FALSE.
 */
#if !defined(MPU9250_ACC_USE_ADVANCED) || defined(__DOXYGEN__)
#define MPU9250_ACC_USE_ADVANCED FALSE
#endif

/**
 * @brief   MPU9250 gyroscope subsystem advanced configurations
 *          switch.
 * @details If set to @p TRUE more configurations are available.
 * @note    The default is @p FALSE.
 */
#if !defined(MPU9250_GYRO_USE_ADVANCED) || defined(__DOXYGEN__)
#define MPU9250_GYRO_USE_ADVANCED FALSE
#endif

/**
 * @brief   Number of acquisitions for gyroscope bias removal.
 * @details This is the number of acquisitions performed to compute the
 *          bias. A repetition is required in order to remove noise.
 */
#if !defined(MPU9250_GYRO_BIAS_ACQ_TIMES) || defined(__DOXYGEN__)
#define MPU9250_GYRO_BIAS_ACQ_TIMES 50
#endif

/**
 * @brief   Settling time for gyroscope bias removal.
 * @details This is the time between each bias acquisition.
 */
#if !defined(MPU9250_GYRO_BIAS_SETTLING_US) || defined(__DOXYGEN__)
#define MPU9250_GYRO_BIAS_SETTLING_US 5000
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !(MPU9250_USE_SPI ^ MPU9250_USE_I2C)
#error "MPU9250_USE_SPI and MPU9250_USE_I2C cannot be both true or both false"
#endif

#if MPU9250_USE_SPI && !HAL_USE_SPI
#error "MPU9250_USE_SPI requires HAL_USE_SPI"
#endif

#if MPU9250_SHARED_SPI && !SPI_USE_MUTUAL_EXCLUSION
#error "MPU9250_SHARED_SPI requires SPI_USE_MUTUAL_EXCLUSION"
#endif

#if MPU9250_USE_I2C && !HAL_USE_I2C
#error "MPU9250_USE_I2C requires HAL_USE_I2C"
#endif

#if MPU9250_SHARED_I2C && !I2C_USE_MUTUAL_EXCLUSION
#error "MPU9250_SHARED_I2C requires I2C_USE_MUTUAL_EXCLUSION"
#endif

/**
 * @todo    Add support for MPU9250 over I2C.
 */
#if MPU9250_USE_I2C
#error "MPU9250 over I2C still not supported"
#endif

/**
 * @todo    Add support for advanced features.
 */
#if MPU9250_GYRO_USE_ADVANCED
#error "MPU9250_GYRO_USE_ADVANCED still not supported"
#endif

/**
 * @todo    Add support for advanced features.
 */
#if MPU9250_ACC_USE_ADVANCED
#error "MPU9250_ACC_USE_ADVANCED still not supported"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief  Accelerometer and Gyroscope Slave Address.
 * The address is defined by the value of the address pin (pin 9).
 */
typedef enum
{
    MPU9250_SAD_GND = 0x68, /**< SAD pin connected to GND.          */
    MPU9250_SAD_VCC = 0x69  /**< SAD pin connected to VCC.          */
} mpu9250_sad_t;

/**
 * @name    MPU9250 data structures and types.
 * @{
 */
/**
 * @brief   Structure representing a MPU9250 driver.
 */
typedef struct MPU9250Driver MPU9250Driver;

/**
 * @brief   MPU9250 accelerometer subsystem full scale.
 * This will set bytes 3 and 4 of Config 1.
 */
typedef enum
{
    MPU9250_ACC_FS_2G  = 0x00, /**< Full scale ±2g.                    */
    MPU9250_ACC_FS_4G  = 0x08, /**< Full scale ±4g.                    */
    MPU9250_ACC_FS_8G  = 0x10, /**< Full scale ±8g.                    */
    MPU9250_ACC_FS_16G = 0x18  /**< Full scale ±16g.                   */
} mpu9250_acc_fs_t;

/**
 * @brief MPU9250 gyroscope subsystem full scale.
 */
typedef enum
{
    MPU9250_GYRO_FS_250DPS  = 0x00, /**< Full scale ±250 degree per second  */
    MPU9250_GYRO_FS_500DPS  = 0x08, /**< Full scale ±500 degree per second  */
    MPU9250_GYRO_FS_1000DPS = 0x10, /**< Full scale ±1000 degree per second */
    MPU9250_GYRO_FS_2000DPS = 0x18  /**< Full scale ±2000 degree per second */
} mpu9250_gyro_fs_t;

/**
 * @brief   Driver state machine possible states.
 */
typedef enum
{
    MPU9250_UNINIT = 0, /**< Not initialized.                   */
    MPU9250_STOP   = 1, /**< Stopped.                           */
    MPU9250_READY  = 2, /**< Ready.                             */
} mpu9250_state_t;

/**
 * @brief MPU9250 configuration structure.
 */
typedef struct
{
#if (MPU9250_USE_SPI) || defined(__DOXYGEN__)
    /**
     * @brief SPI driver associated to this MPU9250.
     */
    SPIDriver *spip;
    /**
     * @brief SPI configuration associated to this MPU9250 accelerometer
     *        subsystem.
     */
    const SPIConfig *spicfg;
#endif /* MPU9250_USE_SPI */
#if (MPU9250_USE_I2C) || defined(__DOXYGEN__)
    /**
     * @brief I2C driver associated to this MPU9250.
     */
    I2CDriver *i2cp;
    /**
     * @brief I2C configuration associated to this MPU9250 accelerometer
     *        subsystem.
     */
    const I2CConfig *i2ccfg;
    /**
     * @brief MPU9250 Slave Address
     */
    mpu9250_sad_t slaveaddress;
#endif /* MPU9250_USE_I2C */
    /**
     * @brief MPU9250 accelerometer subsystem initial sensitivity.
     */
    float *accsensitivity;
    /**
     * @brief MPU9250 accelerometer subsystem initial bias.
     */
    float *accbias;
    /**
     * @brief MPU9250 accelerometer subsystem full scale.
     */
    mpu9250_acc_fs_t accfullscale;

#if MPU9250_ACC_USE_ADVANCED || defined(__DOXYGEN__)
    /**
     * @brief MPU9250 accelerometer subsystem output data rate.
     */
    mpu9250_acc_odr_t accoutdatarate;
    /**
     * @brief MPU9250 accelerometer subsystem decimation mode.
     */
    mpu9250_acc_dec_t accdecmode;
#endif /* MPU9250_ACC_USE_ADVANCED */
    /**
     * @brief MPU9250 gyroscope subsystem initial sensitivity.
     */
    float *gyrosensitivity;
    /**
     * @brief MPU9250 gyroscope subsystem initial bias.
     */
    float *gyrobias;
    /**
     * @brief MPU9250 gyroscope subsystem full scale.
     */
    mpu9250_gyro_fs_t gyrofullscale;

#if MPU9250_GYRO_USE_ADVANCED || defined(__DOXYGEN__)
    /**
     * @brief MPU9250 gyroscope subsystem output data rate.
     */
    mpu9250_gyro_odr_t gyrooutdatarate;
    /**
     * @brief MPU9250 gyroscope subsystem low mode configuration.
     */
    mpu9250_gyro_lp_t gyrolowmodecfg;
    /**
     * @brief MPU9250 gyroscope subsystem output selection.
     */
    mpu9250_gyro_out_sel_t gyrooutsel;
    /**
     * @brief MPU9250 gyroscope subsystem high pass filter.
     */
    mpu9250_gyro_hp_t gyrohpfenable;
    /**
     * @brief MPU9250 gyroscope subsystem high pass filter configuration.
     */
    mpu9250_gyro_hpcf_t gyrohpcfg;
#endif /* MPU9250_GYRO_USE_ADVANCED */
#if (MPU9250_USE_ADVANCED) || defined(__DOXYGEN__)
    /**
     * @brief MPU9250 block data update
     */
    mpu9250_bdu_t blockdataupdate;
    /**
     * @brief MPU9250  endianness
     */
    mpu9250_end_t endianness;
#endif /* MPU9250_USE_ADVANCED */
} MPU9250Config;

/**
 * @brief   @p MPU9250 specific methods.
 */
#define _mpu9250_methods_alone                                              \
    /* Change full scale value of MPU9250 accelerometer subsystem .*/       \
    msg_t (*acc_set_full_scale)(MPU9250Driver * devp, mpu9250_acc_fs_t fs); \
    /* Change full scale value of MPU9250 gyroscope subsystem .*/           \
    msg_t (*gyro_set_full_scale)(MPU9250Driver * devp, mpu9250_gyro_fs_t fs);

/**
 * @brief   @p MPU9250 specific methods with inherited ones.
 */
#define _mpu9250_methods _base_object_methods _mpu9250_methods_alone

/**
 * @extends BaseObjectVMT
 *
 * @brief @p MPU9250 virtual methods table.
 */
struct MPU9250VMT
{
    _mpu9250_methods
};

/**
 * @brief   @p MPU9250Driver specific data.
 */
#define _mpu9250_data                                      \
    _base_sensor_data /* Driver state.*/                   \
        mpu9250_state_t state;                             \
    /* Current configuration data.*/                       \
    const MPU9250Config *config;                           \
    /* Accelerometer subsystem axes number.*/              \
    size_t accaxes;                                        \
    /* Accelerometer subsystem current sensitivity.*/      \
    float accsensitivity[MPU9250_ACC_NUMBER_OF_AXES];      \
    /* Accelerometer subsystem current bias .*/            \
    float accbias[MPU9250_ACC_NUMBER_OF_AXES];             \
    /* Accelerometer subsystem current full scale value.*/ \
    float accfullscale;                                    \
    /* Gyroscope subsystem axes number.*/                  \
    size_t gyroaxes;                                       \
    /* Gyroscope subsystem current sensitivity.*/          \
    float gyrosensitivity[MPU9250_GYRO_NUMBER_OF_AXES];    \
    /* Gyroscope subsystem current Bias.*/                 \
    float gyrobias[MPU9250_GYRO_NUMBER_OF_AXES];           \
    /* Gyroscope subsystem current full scale value.*/     \
    float gyrofullscale;

/**
 * @brief MPU9250 6-axis accelerometer/gyroscope class.
 */
struct MPU9250Driver
{
    /** @brief Virtual Methods Table.*/
    const struct MPU9250VMT *vmt;
    /** @brief Base accelerometer interface.*/
    BaseAccelerometer acc_if;
    /** @brief Base gyroscope interface.*/
    BaseGyroscope gyro_if;
    _mpu9250_data
};
/** @} */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Return the number of axes of the BaseAccelerometer.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              the number of axes.
 *
 * @api
 */
#define mpu9250AccelerometerGetAxesNumber(devp) \
    accelerometerGetAxesNumber(&((devp)->acc_if))

/**
 * @brief   Retrieves raw data from the BaseAccelerometer.
 * @note    This data is retrieved from MEMS register without any algebraical
 *          manipulation.
 * @note    The axes array must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[out] axes     a buffer which would be filled with raw data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 *
 * @api
 */
#define mpu9250AccelerometerReadRaw(devp, axes) \
    accelerometerReadRaw(&((devp)->acc_if), axes)

/**
 * @brief   Retrieves cooked data from the BaseAccelerometer.
 * @note    This data is manipulated according to the formula
 *          cooked = (raw * sensitivity) - bias.
 * @note    Final data is expressed as milli-G.
 * @note    The axes array must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[out] axes     a buffer which would be filled with cooked data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 *
 * @api
 */
#define mpu9250AccelerometerReadCooked(devp, axes) \
    accelerometerReadCooked(&((devp)->acc_if), axes)

/**
 * @brief   Set bias values for the BaseAccelerometer.
 * @note    Bias must be expressed as milli-G.
 * @note    The bias buffer must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] bp        a buffer which contains biases.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250AccelerometerSetBias(devp, bp) \
    accelerometerSetBias(&((devp)->acc_if), bp)

/**
 * @brief   Reset bias values for the BaseAccelerometer.
 * @note    Default biases value are obtained from device datasheet when
 *          available otherwise they are considered zero.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250AccelerometerResetBias(devp) \
    accelerometerResetBias(&((devp)->acc_if))

/**
 * @brief   Set sensitivity values for the BaseAccelerometer.
 * @note    Sensitivity must be expressed as milli-G/LSB.
 * @note    The sensitivity buffer must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] sp        a buffer which contains sensitivities.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250AccelerometerSetSensitivity(devp, sp) \
    accelerometerSetSensitivity(&((devp)->acc_if), sp)

/**
 * @brief   Reset sensitivity values for the BaseAccelerometer.
 * @note    Default sensitivities value are obtained from device datasheet.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 *
 * @api
 */
#define mpu9250AccelerometerResetSensitivity(devp) \
    accelerometerResetSensitivity(&((devp)->acc_if))

/**
 * @brief   Changes the MPU9250Driver accelerometer fullscale value.
 * @note    This function also rescale sensitivities and biases based on
 *          previous and next fullscale value.
 * @note    A recalibration is highly suggested after calling this function.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] fs        new fullscale value.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 *
 * @api
 */
#define mpu9250AccelerometerSetFullScale(devp, fs) \
    (devp)->vmt->acc_set_full_scale(devp, fs)

/**
 * @brief   Return the number of axes of the BaseGyroscope.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              the number of axes.
 *
 * @api
 */
#define mpu9250GyroscopeGetAxesNumber(devp) \
    gyroscopeGetAxesNumber(&((devp)->gyro_if))

/**
 * @brief   Retrieves raw data from the BaseGyroscope.
 * @note    This data is retrieved from MEMS register without any algebraical
 *          manipulation.
 * @note    The axes array must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[out] axes     a buffer which would be filled with raw data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 *
 * @api
 */
#define mpu9250GyroscopeReadRaw(devp, axes) \
    gyroscopeReadRaw(&((devp)->gyro_if), axes)

/**
 * @brief   Retrieves cooked data from the BaseGyroscope.
 * @note    This data is manipulated according to the formula
 *          cooked = (raw * sensitivity) - bias.
 * @note    Final data is expressed as DPS.
 * @note    The axes array must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[out] axes     a buffer which would be filled with cooked data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 *
 * @api
 */
#define mpu9250GyroscopeReadCooked(devp, axes) \
    gyroscopeReadCooked(&((devp)->gyro_if), axes)

/**
 * @brief   Samples bias values for the BaseGyroscope.
 * @note    The MPU9250 shall not be moved during the whole procedure.
 * @note    After this function internal bias is automatically updated.
 * @note    The behavior of this function depends on @P MPU9250_BIAS_ACQ_TIMES
 *          and @p MPU9250_BIAS_SETTLING_US.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 *
 * @api
 */
#define mpu9250GyroscopeSampleBias(devp) gyroscopeSampleBias(&((devp)->gyro_if))

/**
 * @brief   Set bias values for the BaseGyroscope.
 * @note    Bias must be expressed as DPS.
 * @note    The bias buffer must be at least the same size of the BaseGyroscope
 *          axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] bp        a buffer which contains biases.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250GyroscopeSetBias(devp, bp) \
    gyroscopeSetBias(&((devp)->gyro_if), bp)

/**
 * @brief   Reset bias values for the BaseGyroscope.
 * @note    Default biases value are obtained from device datasheet when
 *          available otherwise they are considered zero.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250GyroscopeResetBias(devp) gyroscopeResetBias(&((devp)->gyro_if))

/**
 * @brief   Set sensitivity values for the BaseGyroscope.
 * @note    Sensitivity must be expressed as DPS/LSB.
 * @note    The sensitivity buffer must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] sp        a buffer which contains sensitivities.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 *
 * @api
 */
#define mpu9250GyroscopeSetSensitivity(devp, sp) \
    gyroscopeSetSensitivity(&((devp)->gyro_if), sp)

/**
 * @brief   Reset sensitivity values for the BaseGyroscope.
 * @note    Default sensitivities value are obtained from device datasheet.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 *
 * @api
 */
#define mpu9250GyroscopeResetSensitivity(devp) \
    gyroscopeResetSensitivity(&((devp)->gyro_if))

/**
 * @brief   Changes the MPU9250Driver gyroscope fullscale value.
 * @note    This function also rescale sensitivities and biases based on
 *          previous and next fullscale value.
 * @note    A recalibration is highly suggested after calling this function.
 *
 * @param[in] devp      pointer to @p MPU9250Driver.
 * @param[in] fs        new fullscale value.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 *
 * @api
 */
#define mpu9250GyroscopeSetFullScale(devp, fs) \
    (devp)->vmt->acc_set_full_scale(devp, fs)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif
    void mpu9250ObjectInit(MPU9250Driver *devp);
    void mpu9250Start(MPU9250Driver *devp, const MPU9250Config *config);
    void mpu9250Stop(MPU9250Driver *devp);
#ifdef __cplusplus
}
#endif

#endif /* _MPU9250_H_ */

/** @} */
