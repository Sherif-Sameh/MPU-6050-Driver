Author: Sherif Sameh

For the latest version of the driver : https://github.com/Sherif-Sameh/MPU-6050-Driver

This document describes the MPU6050 driver.

Current version: 1.0

The driver builds on the I2C/TWI driver for the ATMega32 microcontroller family, found at https://github.com/Sherif-Sameh/ATMega32-I2C-Driver, to communicate
with the MPU6050 through I2C communication. However, the user must only initialize the I2C peripheral using the library then all the communication is handeled
through the MPU6050 library and there is no need to include the I2C driver's header file as the MPU6050 library's header files will include it automatically.

Important: The I2C source and header file must be located in the same directory as the MPU6050 library files. 

The library consists of 5 pairs of C/C++ source and header files namely:
	
	- MPU_Shared.cpp/c & MPU_Shared.h
	- MPU_Basic.cpp/c & MPU_Basic.h
	- MPU_SelfTest.cpp/c & MPU_SelfTest.h
	- MPU_FIFO.cpp/c & MPU_FIFO.h
	- MPU_Advanced.cpp/c & MPU_Advanced.h
	
The C and C++ versions are identical but the C++ variants exist for compatibilty with the Arduino IDE since the .c files were not working with it when testing.

Description of each of the 5 files and its intended usage:

	- MPU_Shared: Only 3 functions (setAD0, readInterruptStatus & disableInterrupts) should be accessed from this file, the rest are used internally by the other
	source files and should not be used by the user. Also, the header file will be included automatically when any of the other source files are included.
	
	- MPU_Basic: This file has only the basic functionalities available to it where the user can only reset the MPU6050, wake it up from sleep mode, set both
	full-scale ranges for the accelerometers and gyroscopes as well as read the lastest raw readings of the 3 accelerometers, 3 gyroscopes and the on-board
	temperature sensor. The intented use case for this file is when a user does not care nor need the more advanced features of the MPU6050 like changing its
	clock source, configuring the digital low pass filter (DLPF), etc... but only wants to get the device up and running and take readings from it.
	
	- MPU_FIFO: This file has all the functions that have to do with the on-board FIFO buffer which can be used to load data into it and read data direclty from the
	FIFO buffer instead of the sensor registers. The user can reset, enable or disable the FIFO buffer, enable the buffer overflow interrupt signal as well as 
	enabling the buffer for specific sensors (gyros, accelerometers, or temperature sensor) such that their data is loaded into the buffer and then he can check the
	number of bytes available to be read and if their is data to be read then he can start reading them byte by byte. The intended use case from the FIFO buffer is
	when taking bursts of readings then going back to sleep mode so that the MCU can read the data from more than one sample through the buffer without waking up the IMU. 
	
	- MPU_Advanced: This file gives the user more control over the configuration of the MPU6050. Through the given API functions the user is able to choose a clock
	source for the MPU6050 out of 4 possible choices, reset the individual signal paths of the sensors, enable the data ready interrupt signal, which is set everytime
	new sensor data is loaded into the sensor registers, configure the digital low pass filter setting, and choose the IMU's sampling rate. The intended use case for this
	file is to be used in conjuction with the MPU_Basic files to yield more desirable and better results from the IMU through configuring it to suit the needed task.
	
	- MPU_SelfTest: This file is used soley to validate the IMU's 6 sensors (3 gyroscopes and 3 accelerometers) to insure that they are still capable of
	delivering accurate readings, this is done through using the MPU6050's self-test feature which will use the on-board electronics to actuate the sensors
	therefore yielding certian results and through recording both the sensor's response with and without self-test enabled as well as comparing it to the 
	manufacturer's results which can be retrieved from the MPU6050's memory we can determine if a sensor is still working properly or is no longer able to 
	deliver accurate results. The intended use case for this file is to be used to test the MPU6050's sensors once only before starting to use the device to insure
	its validity.

Important Note: As of now the following functionalities have not been tested:

	- Enabling and using the internal interrupt sources on the MPU6050.
	- All The functions that have to do with the FIFO as there was no need to use it during any application so far.
	
Planned future updates:

	- To support the MPU6050's digital motion processor (DMP).
	- To add more functions and enums that remove the need of familiarity with the data sheet or register map at all such as:
	returning the scaled values, returning the interrupt status for a specific interrupt, getting the current scale factor, etc... 