/** @file MPU_SelfTest.h
 * For testing the relaibility of the IMU's readings.
 * This file includes all the function prototypes and macros for using the MPU6050's self-test feature which
 * can be used to insure that the device can still deliver relaible readings.
 * @attention According to the manufacturers's datasheet, the FS range for testing the gyros and accelerometers should be
 * +-250 dps and +-8g respectively.
 *
 * The Change from the factory trim is calculated as follows:
 * \f[
	 \textnormal{Change from the factory trim} = \frac{STR - FT}{FT}
   \f]
 * Where STR is the self-test response and equals to:
 * \f$ STR = (\textnormal{Output with self test enabled} - \textnormal{Output with self test disabled}) \f$ \n 
 * The acceptable change is within +- 2%. 
 */
 
#ifndef SELF_TEST_H
#define SELF_TEST_H

#include "MPU_Shared.h"
#include <math.h>

/**
 * This function enables the self-test feature for the accelerometers which uses the on-board electronics to
 * actuate the on-board sensors as well as setting the appropriate full-scale range for testing.
 * @return Will return 1 upon successful completion or 0 otherwise. 
 */
char accSelfTestEn();

/**
 * This function enables the self-test feature for the gyroscopes which uses the on-board electronics to
 * actuate the on-board sensors as well as setting the appropriate full-scale range for testing.
 * @return Will return 1 upon successful completion or 0 otherwise. 
 */
char gyroSelfTestEn();

/**
 * This function will retrieve the factory trim values for the gyroscopes.
 * @param data A pointer to the start of an array of signed int that will store the FTs for each gyroscope.
 * @return Will return 1 upon successful completion or 0 otherwise. 
 */
char getFactoryTrimGyro(int* data);

/**
 * This function will retrieve the factory trim values for the accelerometers.
 * @param data A pointer to the start of an array of signed int that will store the FTs for each accelerometer.
 * @return Will return 1 upon successful completion or 0 otherwise. 
 */
char getFactoryTrimAcc(int* data);

/** @example MPU_SelfTestExample.cpp
 * This examples shows how to use the MPU_SelfTest.h functions to calculate the percent change from the
 * factory trim for the 3 gyroscopes. The exact same procedure would be done for the accelerometers.
 */

#endif