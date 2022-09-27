/** @file MPU_Shared.h
 * @brief Shared functions and macros. 
 * This file includes all the function prototypes, macros, and needed header files for the MPU_Shared.c
 * which has the definitions of functions used by all the other source files of the MPU6050 library.
 * It does not need to be included as all other files include it.
 */
 

#ifndef SHARED_H
#define SHARED_H

#include "I2C_1.h" /* Driver for the atmega32 I2C peripheral. */
#define MPU6050_ADDRESS 0x34 /**< The 6 bit I2C address of the MPU6050 which excludes AD0. */

/**
 * This function sets the value used for the AD0 bit in the MPU6050's I2C 7 bit address and
 * its value should match that of the pin i.e. 1 (High) or  0 (Low).
 * @param pinValue The value of the AD0 pin on the MPU6050 IC. Note: all values other than 0 will be taken as 1.
 */
void setAD0(char pinValue);

/**
 * This function initiates an I2C write request on the I2C bus to the MPU6050's address.
 * @return Will return 1 if the request was made successfully or 0 otherwise.
 * @warning This function is used only internally by other functions and should never be used
 * outside its file.
 */
static char initiateTransmissionWrite();

/**
 * This function initiates an I2C read request on the I2C bus from the MPU6050's address.
 * @return Will return 1 if the request was made successfully or 0 otherwise.
 * @warning This function is used only internally by other functions and should never be used
 * outside its file.
 */
static char initiateTransmissionRead();

/**
 * This function writes a byte into a register on the MPU6050.
 * @param regAddr The address of the register in the MPU6050's register map.
 * @param data The value that will be written to that register.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char writeToReg(char regAddr, char data);

/**
 * This function will read from a register/s on the MPU6050.
 * @param regAddr The address of the first register to read from in the MPU6050's register map.
 * @param data A pointer to the start of an array of bytes that the read data will be written to.
 * @param n The number of registers to read from.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char readFromReg(char regAddr, char* data, char n);

/** 
 * This function reads the status of all 3 possible interrupt sources (FIFO OVF, I2C Master INT, Data RDY INT)
 * on the MPU6050 to determine the source which triggered the interrupt.
 * @param value pointer to char that will hold the read value.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char readInterruptStatus(char* value);

/** 
 * This function disables the all interrupts on the MPU6050.
 * @return Will return 1 upon successful completion or 0 otherwise.
 */
char disableInterrupts();

#endif