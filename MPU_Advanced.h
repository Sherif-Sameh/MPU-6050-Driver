/** @file MPU_Advanced.h
 * For changing the device's configuration.
 * This file includes all the function prototypes and macros for changing the configuration
 * of the MPU6050 such as clock source, sample rate, enable data ready interrupt, etc....
 */

#ifndef ADVANCED_H
#define ADVANCED_H

#include "MPU_Shared.h"

/** An enum for choosing the clock source.
 *  Chooses between internal oscillator or one of the gyros.
 */
enum clockSource 
{
	intOsc, /**< Internal oscillator */
	gyroX, /**< X-axis gyroscope */
	gyroY, /**< Y-axis gyroscope */
	gyroZ /**< Z-axis gyroscope */
};

/**
 * This function is used to set a clock source, by default the internal oscillator is used.
 * @param CS The enum of type clockSource used to set the clock source of the MPU6050.
 * @attention It is recommended by the manufacturer to use one of the gyros for improved clock stability.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char setClockSource(enum clockSource CS);

/**
 * This function will revert the ADC and DLPF settings for the accelerometers to their default values.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char resetAccSignalPath();

/**
 * This function will revert the ADC and DLPF settings for the gyroscopes to their default values.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char resetGyroSignalPath();

/**
 * This function will revert the ADC and DLPF settings for the temperature sensor to their default values.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char resetTempSignalPath();

/**
 * This function will enable the data ready interrupt which is set everytime new readings are written to the
 * sensor registers after passing by the ADC and the DLPF.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char dataRDY_IE();

/**
 * This function is used to configure the digital low-pass filter (DLPF) for both the gyroscope and
 * accelerometer readings.
 * @param DLPF_CFG This is the value written to the register and ranges from 0 to 6, the exact bandwidth
 * and delay associated with each value can found in page 13 of the MPU6050's register map document.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char setDLPF(char DLPF_CFG);

/**
 * This function sets the sample rate divider of the MPU6050 according to the desired sample rate
 * and the current DLPF settings.
 * @param sampleRate The desired sampling rate.
 * @attention It's advised to recall this function everytime setDLPF(char DLPF_CFG) is called
 * because that could indirectly change the sampling rate.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char setSampleRate(int sampleRate);

/** @example MPU_AdvancedExample.cpp
 * This example shows how to change the MPU6050's configuration using the functions from MPU_Advanced.h.
 */

#endif