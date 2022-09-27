/** @file MPU_Basic.h
 * @brief For basic operation of the MPU6050.
 * This file includes all the prototypes for the basic functions of the MPU6050.
 */

#ifndef BASIC_H
#define BASIC_H

#include "MPU_Shared.h"

/**
 * This function writes to MPU6050's power management register in order to get the device out of
 * its default state at startup which is sleep mode.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char wakeUp();

/**
 * This function will reset all the MPU6050's registers to their default values.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char deviceReset();

/**
 * This function sets full scale range for the 3 accelerometers. Obviously as the range goes up, the sensor's resolution
 * becomes worse.
 * @param FS_SELECT This parameter chooses the FS range and should be chosen as follows:
 * - 1 : +- 4g
 * - 2 : +- 8g
 * - 3 : +- 16g
 * - all other values : +- 2g
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char setAccFS_Range(char FS_SELECT);

/**
 * This function sets full scale range for the 3 gyroscopes. Obviously as the range goes up, the sensor's resolution
 * becomes worse.
 * @param FS_SELECT This parameter chooses the FS range and should be chosen as follows:
 * - 1 : +- 500dps (83.33rpm)
 * - 2 : +- 1000dps (166.66rpm)
 * - 3 : +- 2000dps (333.33 rpm)
 * - all other values : +- 250dps (41.66rpm)
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char setGyroFS_Range(char FS_SELECT);

/**
 * This function retrieves the raw accelerometer readings from the MPU6050.
 * @param data A pointer to the start of a signed int array that will hold the values read from the IMU.
 * @param skipFromBeginning This parameter can be used to retrieve only specific accelerometer readings and not all 3.
 * @param skipFromEnd This parameter can be used to retrieve only specific accelerometer readings and not all 3.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char getAccReadings(int* data, char skipFromBeginning, char skipFromEnd);
 
/**
 * This function retrieves the raw gyroscope readings from the MPU6050.
 * @param data A pointer to the start of a signed int array that will hold the values read from the IMU.
 * @param skipFromBeginning This parameter can be used to retrieve only specific gyroscope readings and not all 3.
 * @param skipFromEnd This parameter can be used to retrieve only specific gyroscope readings and not all 3.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char getGyroReadings(int* data, char skipFromBeginning, char skipFromEnd);

/**
 * This function retrieves the raw temperature sensor reading from the MPU6050.
 * @param data A pointer to a signed int that will hold the value read from the IMU.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char getTempReadings(int* data);

/** @example MPU_BasicExamples.cpp
 * This is an example on how to use the functions, from the MPU_Basic.h file, for retrieving the on-board sensor readings.
 * You will find examples on reading from all 3 sensors (X,Y,Z) or only specific ones as well as retrieving the 
 * temperature sensor readings.
 */
 
#endif