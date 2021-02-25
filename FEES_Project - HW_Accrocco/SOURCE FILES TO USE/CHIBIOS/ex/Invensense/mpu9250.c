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
 * @file    mpu9250.c
 * @brief   MPU9250 MEMS interface module code.
 *
 * @addtogroup MPU9250
 * @ingroup EX_INVENSENSE
 * @{
 */

#include "hal.h"

#include "mpu9250.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
#if (MPU9250_USE_SPI) || defined(__DOXYGEN__)
/**
 * @brief   Reads a generic register value using SPI.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * @param[in] spip      pointer to the SPI interface
 * @param[in] reg       starting register address
 * @param[in] n         number of consecutive registers to read
 * @param[in] b         pointer to an output buffer.
 */
static void mpu9250SPIReadRegister(SPIDriver *spip, uint8_t reg, size_t n,
                                   uint8_t *b)
{
    uint8_t cmd;
    cmd = reg | MPU9250_RW; /*Setting the first bit to read*/

    spiSelect(spip); /*Lowers the chip select pin*/
    spiSend(spip, 1, &cmd);
    spiReceive(spip, n, b);
    spiUnselect(spip);
}

/**
 * @brief   Writes a value into a generic register using SPI.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * @param[in] spip      pointer to the SPI interface
 * @param[in] reg       starting register address
 * @param[in] n         number of adjacent registers to write
 * @param[in] b         pointer to a buffer of values.
 */
static void mpu9250SPIWriteRegister(SPIDriver *spip, uint8_t reg, size_t n,
                                    uint8_t *b)
{
    uint8_t cmd;
    cmd = reg & (~MPU9250_RW); /*The first bit has to be zero in the address*/
    spiSelect(spip);
    spiSend(spip, 1, &cmd);
    spiSend(spip, n, b);
    spiUnselect(spip);
}
#endif /* MPU9250_USE_SPI */

#if (MPU9250_USE_I2C) || defined(__DOXYGEN__)
/**
 * @brief   Reads registers value using I2C.
 * @pre     The I2C interface must be initialized and the driver started.
 * @note    IF_ADD_INC bit must be 1 in CTRL_REG8
 *
 * @param[in]  i2cp      pointer to the I2C interface
 * @param[in]  sad       slave address without R bit
 * @param[in]  reg       first sub-register address
 * @param[out] rxbuf     pointer to an output buffer
 * @param[in]  n         number of consecutive register to read
 * @return               the operation status.
 * @notapi
 */
msg_t mpu9250I2CReadRegister(I2CDriver *i2cp, mpu9250_sad_t sad, uint8_t reg,
                             uint8_t *rxbuf, size_t n)
{

    return i2cMasterTransmitTimeout(i2cp, sad, &reg, 1, rxbuf, n,
                                    TIME_INFINITE);
}

/**
 * @brief   Writes a value into a register using I2C.
 * @pre     The I2C interface must be initialized and the driver started.
 *
 * @param[in] i2cp       pointer to the I2C interface
 * @param[in] sad        slave address without R bit
 * @param[in] txbuf      buffer containing sub-address value in first position
 *                       and values to write
 * @param[in] n          size of txbuf less one (not considering the first
 *                       element)
 * @return               the operation status.
 * @notapi
 */
#define mpu9250I2CWriteRegister(i2cp, sad, txbuf, n) \
    i2cMasterTransmitTimeout(i2cp, sad, txbuf, n + 1, NULL, 0, TIME_INFINITE)
#endif /* MPU9250_USE_I2C */

/**
 * @brief   Return the number of axes of the BaseAccelerometer.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 *
 * @return              the number of axes.
 */
static size_t acc_get_axes_number(void *ip)
{
    (void)ip;

    return MPU9250_ACC_NUMBER_OF_AXES;
}

/**
 * @brief   Retrieves raw data from the BaseAccelerometer.
 * @note    This data is retrieved from MEMS register without any algebraical
 *          manipulation.
 * @note    The axes array must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 * @param[out] axes     a buffer which would be filled with raw data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more BUS errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 */
static msg_t acc_read_raw(void *ip, int32_t axes[])
{
    MPU9250Driver *devp;
    uint8_t buff[MPU9250_ACC_NUMBER_OF_AXES * 2];
    uint8_t i = 0;
    int16_t tmp;
    msg_t msg=MSG_OK;

    osalDbgCheck((ip != NULL) && (axes != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_read_raw(), invalid state");
#if MPU9250_USE_I2C
    osalDbgAssert((devp->config->i2cp->state == I2C_READY),
                  "acc_read_raw(), channel not ready");

#if MPU9250_SHARED_I2C
    i2cAcquireBus(devp->config->i2cp);
    i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

    msg = mpu9250I2CReadRegister(devp->config->i2cp, devp->config->slaveaddress,
                                 MPU_REG_ACCEL_XOUT_H, buff,
                                 MPU9250_ACC_NUMBER_OF_AXES * 2);

#if MPU9250_SHARED_I2C
    i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
#endif /* MPU9250_USE_I2C */



#if MPU9250_SHARED_SPI
    spiAcquireBus(devp->config->spip);
    spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */
#if MPU9250_USE_SPI
    osalDbgAssert((devp->config->spip->state == SPI_READY),
                  "gyro_read_raw(), channel not ready");

    mpu9250SPIReadRegister(devp->config->spip, MPU_REG_ACCEL_XOUT_H,
                           MPU9250_ACC_NUMBER_OF_AXES * 2, buff);

#if MPU9250_SHARED_SPI
    spiReleaseBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
#endif /* MPU9250_USE_SPI */

    if (msg == MSG_OK)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            tmp = (buff[i * 2] << 8) | buff[i * 2 + 1];
            /* tmp = buff[2 * i] + (buff[2 * i + 1] << 8);*/
            axes[i] = (int32_t)tmp;
        }
    return msg;
}

/**
 * @brief   Retrieves cooked data from the BaseAccelerometer.
 * @note    This data is manipulated according to the formula
 *          cooked = (raw * sensitivity) - bias.
 * @note    Final data is expressed as milli-G.
 * @note    The axes array must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 * @param[out] axes     a buffer which would be filled with cooked data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 */
static msg_t acc_read_cooked(void *ip, float axes[])
{
    MPU9250Driver *devp;
    uint32_t i;
    int32_t raw[MPU9250_ACC_NUMBER_OF_AXES];
    msg_t msg;

    osalDbgCheck((ip != NULL) && (axes != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_read_cooked(), invalid state");

    msg = acc_read_raw(ip, raw);
    for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
    {
        axes[i] = (raw[i] * devp->accsensitivity[i]) - devp->accbias[i];
    }
    return msg;
}

/**
 * @brief   Set bias values for the BaseAccelerometer.
 * @note    Bias must be expressed as milli-G.
 * @note    The bias buffer must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 * @param[in] bp        a buffer which contains biases.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t acc_set_bias(void *ip, float *bp)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck((ip != NULL) && (bp != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_set_bias(), invalid state");

    for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
    {
        devp->accbias[i] = bp[i];
    }
    return msg;
}

/**
 * @brief   Reset bias values for the BaseAccelerometer.
 * @note    Default biases value are obtained from device datasheet when
 *          available otherwise they are considered zero.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t acc_reset_bias(void *ip)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck(ip != NULL);

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_reset_bias(), invalid state");

    for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        devp->accbias[i] = MPU9250_ACC_BIAS;
    return msg;
}

/**
 * @brief   Set sensitivity values for the BaseAccelerometer.
 * @note    Sensitivity must be expressed as milli-G/LSB.
 * @note    The sensitivity buffer must be at least the same size of the
 *          BaseAccelerometer axes number.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 * @param[in] sp        a buffer which contains sensitivities.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t acc_set_sensivity(void *ip, float *sp)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgCheck((ip != NULL) && (sp != NULL));

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_set_sensivity(), invalid state");

    for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
    {
        devp->accsensitivity[i] = sp[i];
    }
    return msg;
}

/**
 * @brief   Reset sensitivity values for the BaseAccelerometer.
 * @note    Default sensitivities value are obtained from device datasheet.
 *
 * @param[in] ip        pointer to @p BaseAccelerometer interface.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 */
static msg_t acc_reset_sensivity(void *ip)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck(ip != NULL);

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseAccelerometer *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_reset_sensivity(), invalid state");

    if (devp->config->accfullscale == MPU9250_ACC_FS_2G)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accsensitivity[i] = MPU9250_ACC_SENS_2G;
    else if (devp->config->accfullscale == MPU9250_ACC_FS_4G)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accsensitivity[i] = MPU9250_ACC_SENS_4G;
    else if (devp->config->accfullscale == MPU9250_ACC_FS_8G)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accsensitivity[i] = MPU9250_ACC_SENS_8G;
    else if (devp->config->accfullscale == MPU9250_ACC_FS_16G)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accsensitivity[i] = MPU9250_ACC_SENS_16G;
    else
    {
        osalDbgAssert(FALSE,
                      "reset_sensivity(), accelerometer full scale issue");
        msg = MSG_RESET;
    }
    return msg;
}

/**
 * @brief   Changes the MPU9250Driver accelerometer fullscale value.
 * @note    This function also rescale sensitivities and biases based on
 *          previous and next fullscale value.
 * @note    A recalibration is highly suggested after calling this function.
 *
 * @param[in] ip        pointer to @p MPU9250Driver interface.
 * @param[in] fs        new fullscale value.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 */
static msg_t acc_set_full_scale(MPU9250Driver *devp, mpu9250_acc_fs_t fs)
{
    float newfs, scale;
    uint8_t i, buff[2];
    msg_t msg;

    /* Computing new float fullscale value.*/
    if (fs == MPU9250_ACC_FS_2G)
    {
        newfs = MPU9250_ACC_2G;
    }
    else if (fs == MPU9250_ACC_FS_4G)
    {
        newfs = MPU9250_ACC_4G;
    }
    else if (fs == MPU9250_ACC_FS_8G)
    {
        newfs = MPU9250_ACC_8G;
    }
    else if (fs == MPU9250_ACC_FS_16G)
    {
        newfs = MPU9250_ACC_16G;
    }
    else
    {
        msg = MSG_RESET;
        return msg;
    }

    osalDbgCheck(devp != NULL);
    osalDbgAssert((devp->state == MPU9250_READY),
                  "acc_set_full_scale(), invalid state");
#if MPU9250_USE_SPI
    osalDbgAssert((devp->config->spip->state == SPI_READY),
                  "acc_set_full_scale(), channel not ready");
#endif
#if MPU9250_USE_I2C
    osalDbgAssert((devp->config->i2cp->state == I2C_READY),
                  "acc_set_full_scale(), channel not ready");

#endif /*MPU9250_USE_I2C*/

    if (newfs != devp->accfullscale)
    {
        /* Computing scale value.*/
        scale              = newfs / devp->accfullscale;
        devp->accfullscale = newfs;

#if MPU9250_USE_I2C
#if MPU9250_SHARED_I2C
        i2cAcquireBus(devp->config->i2cp);
        i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

        /* Updating register.*/
        msg = mpu9250I2CReadRegister(devp->config->i2cp,
                                     devp->config->slaveaddress,
                                     MPU_REG_ACCEL_CONFIG, &buff[1], 1);

#if MPU9250_SHARED_I2C
        i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
        if (msg != MSG_OK)
            return msg;

#endif /*MPU9250_USE_I2C*/

#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
        spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

        mpu9250SPIReadRegister(devp->config->spip, MPU_REG_ACCEL_CONFIG, 1,
                               buff); /*read and save in buff*/
#endif /* MPU9250_USE_SPI*/

        buff[0] = fs | buff[0]; /*keep the setup, change just the fs*/

#if MPU9250_USE_I2C
#if MPU9250_SHARED_I2C
        i2cAcquireBus(devp->config->i2cp);
        i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

        msg = mpu9250I2CWriteRegister(devp->config->i2cp,
                                      devp->config->slaveaddress, buff, 1);

#if MPU9250_SHARED_I2C
        i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
        if (msg != MSG_OK)
            return msg;

#endif /*MPU9250_USE_I2C*/
#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
        spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

        mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_ACCEL_CONFIG, 1,
                                buff);
#endif /* MPU9250_USE_SPI*/

        /* Scaling sensitivity and bias. Re-calibration is suggested anyway.*/
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            devp->accsensitivity[i] *= scale;
            devp->accbias[i] *= scale;
        }
    }
    return msg;
}

/**
 * @brief   Return the number of axes of the BaseGyroscope.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 *
 * @return              the number of axes.
 */
static size_t gyro_get_axes_number(void *ip)
{
    (void)ip;

    return MPU9250_GYRO_NUMBER_OF_AXES;
}

/**
 * @brief   Retrieves raw data from the BaseGyroscope.
 * @note    This data is retrieved from MEMS register without any algebraical
 *          manipulation.
 * @note    The axes array must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 * @param[out] axes     a buffer which would be filled with raw data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 */
static msg_t gyro_read_raw(void *ip, int32_t axes[MPU9250_GYRO_NUMBER_OF_AXES])
{
    MPU9250Driver *devp;
    int16_t tmp;
    uint8_t i, buff[2 * MPU9250_GYRO_NUMBER_OF_AXES];
    msg_t msg = MSG_OK;

    osalDbgCheck((ip != NULL) && (axes != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_read_raw(), invalid state");
#if MPU9250_USE_I2C
    osalDbgAssert((devp->config->i2cp->state == I2C_READY),
                  "gyro_read_raw(), channel not ready");

#if MPU9250_SHARED_I2C
    i2cAcquireBus(devp->config->i2cp);
    i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

    msg = mpu9250I2CReadRegister(devp->config->i2cp, devp->config->slaveaddress,
                                 MPU_REG_GYRO_XOUT_H, buff,
                                 MPU9250_GYRO_NUMBER_OF_AXES * 2);

#if MPU9250_SHARED_I2C
    i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
#endif /* MPU9250_USE_I2C */

#if MPU9250_USE_SPI
    osalDbgAssert((devp->config->spip->state == SPI_READY),
                  "gyro_read_raw(), channel not ready");

#if MPU9250_SHARED_SPI
    spiAcquireBus(devp->config->spip);
    spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

    mpu9250SPIReadRegister(devp->config->spip, MPU_REG_GYRO_XOUT_H,
                           MPU9250_GYRO_NUMBER_OF_AXES * 2, buff);

#if MPU9250_SHARED_SPI
    spiReleaseBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
#endif /* MPU9250_USE_SPI */

    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
    {
        tmp     = (buff[i * 2] << 8) | buff[i * 2 + 1];
        axes[i] = (int32_t)tmp;
    }
    return msg;
}

/**
 * @brief   Retrieves cooked data from the BaseGyroscope.
 * @note    This data is manipulated according to the formula
 *          cooked = (raw * sensitivity) - bias.
 * @note    Final data is expressed as DPS.
 * @note    The axes array must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 * @param[out] axes     a buffer which would be filled with cooked data.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.
 */
static msg_t gyro_read_cooked(void *ip, float axes[])
{
    MPU9250Driver *devp;
    uint32_t i;
    int32_t raw[MPU9250_GYRO_NUMBER_OF_AXES];
    msg_t msg;

    osalDbgCheck((ip != NULL) && (axes != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_read_cooked(), invalid state");

    msg = gyro_read_raw(ip, raw);
    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
    {
        axes[i] = (raw[i] * devp->gyrosensitivity[i]) - devp->gyrobias[i];
    }
    return msg;
}

/**
 * @brief   Samples bias values for the BaseGyroscope.
 * @note    The MPU9250 shall not be moved during the whole procedure.
 * @note    After this function internal bias is automatically updated.
 * @note    The behavior of this function depends on @P MPU9250_BIAS_ACQ_TIMES
 *          and @p MPU9250_BIAS_SETTLING_US.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t gyro_sample_bias(void *ip)
{
    MPU9250Driver *devp;
    uint32_t i, j;
    int32_t raw[MPU9250_GYRO_NUMBER_OF_AXES];
    int32_t buff[MPU9250_GYRO_NUMBER_OF_AXES] = {0, 0, 0};
    msg_t msg;

    osalDbgCheck(ip != NULL);

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_sample_bias(), invalid state");
#if MPU9250_USE_I2C
    osalDbgAssert((devp->config->i2cp->state == I2C_READY),
                  "gyro_sample_bias(), channel not ready");
#endif

#if MPU9250_USE_SPI
    osalDbgAssert((devp->config->spip->state == SPI_READY),
                  "gyro_sample_bias(), channel not ready");
#endif
    for (i = 0; i < MPU9250_GYRO_BIAS_ACQ_TIMES; i++)
    {
        msg = gyro_read_raw(ip, raw);
        if (msg != MSG_OK)
            return msg;
        for (j = 0; j < MPU9250_GYRO_NUMBER_OF_AXES; j++)
        {
            buff[j] += raw[j];
        }
        osalThreadSleepMicroseconds(MPU9250_GYRO_BIAS_SETTLING_US);
    }

    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
    {
        devp->gyrobias[i] = (buff[i] / MPU9250_GYRO_BIAS_ACQ_TIMES);
        devp->gyrobias[i] *= devp->gyrosensitivity[i];
    }
    return msg;
}

/**
 * @brief   Set bias values for the BaseGyroscope.
 * @note    Bias must be expressed as DPS.
 * @note    The bias buffer must be at least the same size of the BaseGyroscope
 *          axes number.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 * @param[in] bp        a buffer which contains biases.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t gyro_set_bias(void *ip, float *bp)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck((ip != NULL) && (bp != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_set_bias(), invalid state");

    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
    {
        devp->gyrobias[i] = bp[i];
    }
    return msg;
}

/**
 * @brief   Reset bias values for the BaseGyroscope.
 * @note    Default biases value are obtained from device datasheet when
 *          available otherwise they are considered zero.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t gyro_reset_bias(void *ip)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck(ip != NULL);

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_reset_bias(), invalid state");

    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        devp->gyrobias[i] = MPU9250_GYRO_BIAS;
    return msg;
}

/**
 * @brief   Set sensitivity values for the BaseGyroscope.
 * @note    Sensitivity must be expressed as DPS/LSB.
 * @note    The sensitivity buffer must be at least the same size of the
 *          BaseGyroscope axes number.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 * @param[in] sp        a buffer which contains sensitivities.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 */
static msg_t gyro_set_sensivity(void *ip, float *sp)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck((ip != NULL) && (sp != NULL));

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_set_sensivity(), invalid state");

    for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
    {
        devp->gyrosensitivity[i] = sp[i];
    }
    return msg;
}

/**
 * @brief   Reset sensitivity values for the BaseGyroscope.
 * @note    Default sensitivities value are obtained from device datasheet.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 */
static msg_t gyro_reset_sensivity(void *ip)
{
    MPU9250Driver *devp;
    uint32_t i;
    msg_t msg = MSG_OK;

    osalDbgCheck(ip != NULL);

    /* Getting parent instance pointer.*/
    devp = objGetInstance(MPU9250Driver *, (BaseGyroscope *)ip);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_reset_sensivity(), invalid state");

    if (devp->config->gyrofullscale == MPU9250_GYRO_FS_250DPS)
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
            devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_250DPS;
    else if (devp->config->gyrofullscale == MPU9250_GYRO_FS_500DPS)
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
            devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_500DPS;
    else if (devp->config->gyrofullscale == MPU9250_GYRO_FS_2000DPS)
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
            devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_2000DPS;
    else
    {
        osalDbgAssert(FALSE, "gyro_reset_sensivity(), full scale issue");
        return MSG_RESET;
    }
    return msg;
}

/**
 * @brief   Changes the MPU9250Driver gyroscope fullscale value.
 * @note    This function also rescale sensitivities and biases based on
 *          previous and next fullscale value.
 * @note    A recalibration is highly suggested after calling this function.
 *
 * @param[in] ip        pointer to @p BaseGyroscope interface.
 * @param[in] fs        new fullscale value.
 *
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    otherwise.
 */
static msg_t gyro_set_full_scale(MPU9250Driver *devp, mpu9250_gyro_fs_t fs)
{
    float newfs, scale;
    uint8_t i, buff[2];
    msg_t msg = MSG_OK;

    osalDbgCheck(devp != NULL);

    osalDbgAssert((devp->state == MPU9250_READY),
                  "gyro_set_full_scale(), invalid state");
#if MPU9250_USE_I2C
    osalDbgAssert((devp->config->i2cp->state == I2C_READY),
                  "gyro_set_full_scale(), channel not ready");
#endif
#if MPU9250_USE_SPI
    osalDbgAssert((devp->config->spip->state == SPI_READY),
                  "gyro_set_full_scale(), channel not ready");
#endif
    if (fs == MPU9250_GYRO_FS_250DPS)
    {
        newfs = MPU9250_GYRO_250DPS;
    }
    else if (fs == MPU9250_GYRO_FS_500DPS)
    {
        newfs = MPU9250_GYRO_500DPS;
    }
    else if (fs == MPU9250_GYRO_FS_2000DPS)
    {
        newfs = MPU9250_GYRO_2000DPS;
    }
    else
    {
        return MSG_RESET;
    }

    if (newfs != devp->gyrofullscale)
    {
        scale               = newfs / devp->gyrofullscale;
        devp->gyrofullscale = newfs;

#if MPU9250_USE_I2C
#if MPU9250_SHARED_I2C
        i2cAcquireBus(devp->config->i2cp);
        i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

        /* Updating register.*/
        msg = mpu9250I2CReadRegister(devp->config->i2cp,
                                     devp->config->slaveaddress,
                                     MPU_REG_GYRO_CONFIG, &buff[1], 1);

#if MPU9250_SHARED_I2C
        i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
#endif /* MPU9250_USE_I2C */
#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
        spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

        mpu9250SPIReadRegister(devp->config->spip, MPU_REG_GYRO_CONFIG, 1,
                               buff);
#endif /* MPU9250_USE_SPI*/

        buff[0] = fs | buff[0]; /*keep the setup, change just the fs*/

#if MPU9250_USE_I2C
#if MPU9250_SHARED_I2C
        i2cAcquireBus(devp->config->i2cp);
        i2cStart(devp->config->i2cp, devp->config->i2ccfg);
#endif /* MPU9250_SHARED_I2C */

        mpu9250I2CWriteRegister(devp->config->i2cp, devp->config->slaveaddress,
                                buff, 1);

#if MPU9250_SHARED_I2C
        i2cReleaseBus(devp->config->i2cp);
#endif /* MPU9250_SHARED_I2C */
#endif /* MPU9250_USE_I2C */

#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
        spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

        mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_GYRO_CONFIG, 1,
                                buff);
#endif /* MPU9250_USE_SPI*/

        /* Scaling sensitivity and bias. Re-calibration is suggested anyway. */
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        {
            devp->gyrosensitivity[i] *= scale;
            devp->gyrobias[i] *= scale;
        }
    }
    return msg;
}

static const struct MPU9250VMT vmt_device = {(size_t)0, acc_set_full_scale,
                                             gyro_set_full_scale};

static const struct BaseAccelerometerVMT vmt_accelerometer = {
    sizeof(struct MPU9250VMT *),
    acc_get_axes_number,
    acc_read_raw,
    acc_read_cooked,
    acc_set_bias,
    acc_reset_bias,
    acc_set_sensivity,
    acc_reset_sensivity};

static const struct BaseGyroscopeVMT vmt_gyroscope = {
    sizeof(struct MPU9250VMT *) + sizeof(BaseAccelerometer),
    gyro_get_axes_number,
    gyro_read_raw,
    gyro_read_cooked,
    gyro_sample_bias,
    gyro_set_bias,
    gyro_reset_bias,
    gyro_set_sensivity,
    gyro_reset_sensivity};

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initializes an instance.
 *
 * @param[out] devp     pointer to the @p MPU9250Driver object
 *
 * @init
 */
void mpu9250ObjectInit(MPU9250Driver *devp)
{
    devp->vmt         = &vmt_device;
    devp->acc_if.vmt  = &vmt_accelerometer;
    devp->gyro_if.vmt = &vmt_gyroscope;

    devp->config = NULL;

    devp->accaxes  = MPU9250_ACC_NUMBER_OF_AXES;
    devp->gyroaxes = MPU9250_GYRO_NUMBER_OF_AXES;

    devp->state = MPU9250_STOP;
}

/**
 * @brief   Configures and activates MPU9250 Complex Driver peripheral.
 *
 * @param[in] devp      pointer to the @p MPU9250Driver object
 * @param[in] config    pointer to the @p MPU9250Config object
 *
 * @api
 */
void mpu9250Start(MPU9250Driver *devp, const MPU9250Config *config)
{
    uint32_t i;
    uint8_t cr[6];
    osalDbgCheck((devp != NULL) && (config != NULL));

    osalDbgAssert(
        (devp->state == MPU9250_STOP) || (devp->state == MPU9250_READY),
        "mpu9250Start(), invalid state");

    devp->config = config;

    /* Configuring common registers.*/
    /* The order is:
     * - USER CONTROL
     * - PWR MAN 1
     * - PWR MAN 2 (right after man1)
     * ---- start cr from 0
     * - CONFIG
     * - GYRO_CONFIG
     * - ACCEL_CONFIG
     * - ACCEL_CONFIG_2 (these are close together)
     */
    /* Control register 8 configuration block.*/

    cr[0] = 0x10; /*@TODO:create constant,disables I2C, from user control */
    cr[1] = 0x01; /*@TODO:create constant, enable auto clock select*/
    cr[2] = 0x00; /*@TODO:create constant, enable all sensors*/
/*Send the first chunck of configurations*/
#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
    spiAcquireBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
    spiStart(devp->config->spip, devp->config->spicfg);

    mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_USER_CTRL, 3, cr);
#if MPU9250_SHARED_SPI
    spiReleaseBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
#endif /* MPU9250_USE_SPI */

    cr[0] = 0x00;                        /*@TODO: no fifo, no sync,no filter */
    cr[1] = devp->config->gyrofullscale; /*@TODO Or with low pass filter*/
    cr[3] = devp->config->accfullscale;  /*@TODO: or with fchoice*/
    cr[4] = 0x00, /*@TODO: FCHOICE = 0, A_DLPF_CFG = 000*/
/*Send the second chunck of configurations*/
#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
    spiStart(devp->config->spip, devp->config->spicfg);

    mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_CONFIG, 4, cr);

    /*@TODO TEST - OFFSET ERASE FOR ACTUAL VALUES*/
    /*TO BE FIXED*/
    cr[0] = 0;
    cr[1] = 0;
    cr[2] = 0;
    cr[3] = 0;
    cr[4] = 0;
    cr[5] = 0;
    mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_XA_OFFSET_H, 6, cr);
    mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_XG_OFFSET_H, 6, cr);
#if MPU9250_SHARED_SPI
    spiReleaseBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
#endif /* MPU9250_USE_SPI */

    if (devp->config->gyrofullscale == MPU9250_GYRO_FS_250DPS)
    {
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        {
            if (devp->config->gyrosensitivity == NULL)
                devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_250DPS;
            else
                devp->gyrosensitivity[i] = devp->config->gyrosensitivity[i];
        }
        devp->gyrofullscale = MPU9250_GYRO_250DPS;
    }
    else if (devp->config->gyrofullscale == MPU9250_GYRO_FS_500DPS)
    {
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        {
            if (devp->config->gyrosensitivity == NULL)
                devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_500DPS;
            else
                devp->gyrosensitivity[i] = devp->config->gyrosensitivity[i];
        }
        devp->gyrofullscale = MPU9250_GYRO_500DPS;
    }
    else if (devp->config->gyrofullscale == MPU9250_GYRO_FS_1000DPS)
    {
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        {
            if (devp->config->gyrosensitivity == NULL)
                devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_1000DPS;
            else
                devp->gyrosensitivity[i] = devp->config->gyrosensitivity[i];
        }
        devp->gyrofullscale = MPU9250_GYRO_1000DPS;
    }
    else if (devp->config->gyrofullscale == MPU9250_GYRO_FS_2000DPS)
    {
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
        {
            if (devp->config->gyrosensitivity == NULL)
                devp->gyrosensitivity[i] = MPU9250_GYRO_SENS_2000DPS;
            else
                devp->gyrosensitivity[i] = devp->config->gyrosensitivity[i];
        }
        devp->gyrofullscale = MPU9250_GYRO_2000DPS;
    }
    else
        osalDbgAssert(FALSE, "mpu9250Start(), wrong gyroscope full scale");

    /* Storing bias information */
    if (devp->config->gyrobias != NULL)
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
            devp->gyrobias[i] = devp->config->gyrobias[i];
    else
        for (i = 0; i < MPU9250_GYRO_NUMBER_OF_AXES; i++)
            devp->gyrobias[i] = MPU9250_GYRO_BIAS;

    /* Storing sensitivity according to user settings */
    if (devp->config->accfullscale == MPU9250_ACC_FS_2G)
    {
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            if (devp->config->accsensitivity == NULL)
                devp->accsensitivity[i] = MPU9250_ACC_SENS_2G;
            else
                devp->accsensitivity[i] = devp->config->accsensitivity[i];
        }
        devp->accfullscale = MPU9250_ACC_2G;
    }
    else if (devp->config->accfullscale == MPU9250_ACC_FS_4G)
    {
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            if (devp->config->accsensitivity == NULL)
                devp->accsensitivity[i] = MPU9250_ACC_SENS_4G;
            else
                devp->accsensitivity[i] = devp->config->accsensitivity[i];
        }
        devp->accfullscale = MPU9250_ACC_4G;
    }
    else if (devp->config->accfullscale == MPU9250_ACC_FS_8G)
    {
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            if (devp->config->accsensitivity == NULL)
                devp->accsensitivity[i] = MPU9250_ACC_SENS_8G;
            else
                devp->accsensitivity[i] = devp->config->accsensitivity[i];
        }
        devp->accfullscale = MPU9250_ACC_8G;
    }
    else if (devp->config->accfullscale == MPU9250_ACC_FS_16G)
    {
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
        {
            if (devp->config->accsensitivity == NULL)
                devp->accsensitivity[i] = MPU9250_ACC_SENS_16G;
            else
                devp->accsensitivity[i] = devp->config->accsensitivity[i];
        }
        devp->accfullscale = MPU9250_ACC_16G;
    }
    else
        osalDbgAssert(FALSE, "mpu9250Start(), wrong accelerometer full scale ");

    /* Storing bias information */
    if (devp->config->accbias != NULL)
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accbias[i] = devp->config->accbias[i];
    else
        for (i = 0; i < MPU9250_ACC_NUMBER_OF_AXES; i++)
            devp->accbias[i] = MPU9250_ACC_BIAS;

    /* This is the MEMS transient recovery time */
    osalThreadSleepMilliseconds(35);
    devp->state = MPU9250_READY;
}

/**
 * @brief   Deactivates the MPU9250 Complex Driver peripheral.
 *
 * @param[in] devp       pointer to the @p MPU9250Driver object
 *
 * @api
 */
void mpu9250Stop(MPU9250Driver *devp)
{
    uint8_t cr[2];

    osalDbgCheck(devp != NULL);

    osalDbgAssert(
        (devp->state == MPU9250_STOP) || (devp->state == MPU9250_READY),
        "mpu9250Stop(), invalid state");

    cr[0] = 0x3F; /*@TODO add const:turning off the sensors in power management 2*/
    if (devp->state == MPU9250_READY)
    {
#if MPU9250_USE_SPI
#if MPU9250_SHARED_SPI
        spiAcquireBus(devp->config->spip);
        spiStart(devp->config->spip, devp->config->spicfg);
#endif /* MPU9250_SHARED_SPI */

        mpu9250SPIWriteRegister(devp->config->spip, MPU_REG_PWR_MGMT_2, 1, cr); /* FIXME qui era &cr , ora ho messo cr - se non funziona questa è una possibile causa  */
        spiStop(devp->config->spip);

#if MPU9250_SHARED_SPI
        spiReleaseBus(devp->config->spip);
#endif /* MPU9250_SHARED_SPI */
#endif /* MPU9250_USE_SPI */
    }
    devp->state = MPU9250_STOP;
}
/** @} */
