/** @file MPU_FIFO.h
 * For using the internal FIFO on the MPU6050.
 * This file includes all the needed function prototypes macros to be able to use
 * the internal FIFO for storing and readings the sensors' output values.
 * @attention The size of the FIFO is 1024 bytes.
 */

#ifndef FIFO_H
#define FIFO_H

#include "MPU_Shared.h"

/**
 * This function resets the FIFO which will clear the FIFO buffer.
 * @attention The register automatically clears the bit to 0 after execution 
 * therefore there is no need to clear it manually.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */ 
char FIFO_Reset();

/**
 * This function enables the FIFO, this needs to be called before enabling the FIFO for specific sensors (gyro, acc, temp).
 * @return Will return 1 upon successful completion or 0 otherwise.
 */ 
char FIFO_Enable();

/**
 * This function disables the FIFO.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */ 
char FIFO_Disable();

/**
 * This function retreives the no of samples currently in the FIFO buffer (in bytes) that are available to be read.
 * This should be checked before reading from the FIFO buffer to insure that it's not empty.
 * @param count A pointer to an unsigned int that will store the current FIFO count.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char readFIFO_count(unsigned int* count);

/**
 * This function reads the first byte that was written to the buffer.
 * @attention The sensor values are written to the buffer in order from the lowest register address (59: AccX High)
 * first to the highest register address (72: GyroZ Low). 
 * @param value A pointer to a signed char that will store the value read from the buffer.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char readFIFO(char* value);

/**
 * This function enables the FIFO overflow interrupt.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char FIFO_OVF_IE();

/**
 * This function enables the FIFO for the gyroscope outputs such that their values will be copied into the FIFO.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char gyroFIFO_En();

/**
 * This function enables the FIFO for the accelerometer outputs such that their values will be copied into the FIFO.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char accFIFO_En();

/**
 * This function enables the FIFO for the temperature sensor output such that its value will be copied into the FIFO.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char tempFIFO_EN();

#endif