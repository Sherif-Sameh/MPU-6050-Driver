
#include "MPU_Advanced.h"

int main(void)
{
	I2CInit();
	
	setAD0(0);
	deviceReset();					// To erase any previous configurations.
									// Insert some delay here.
	
	wakeUp(); 						// Wake up from sleep mode.
	
	/* Configuration 1: DLPF = 2, Sample Rate = 200Hz, Clock Source = Z-axis gyroscope */
	
	setClockSource(gyroZ);			// Set the clock source as Z-axis gyro.
	setDLPF(2);						// Gyro Bandwidth = 98Hz and Accelerometer Bandwidth = 94Hz.
	setSampleRate(200);				// Set the sampling rate to 200Hz.
	
	/* Configuration 2: DLPF = 0, Sample Rate = 500Hz, Clock Source = Internal Oscillator */
	
	setClockSource(intOsc); 		// Set the clock source as the internal oscillator.
	setDLPF(0);						// Gyro Bandwidth = 256Hz and Accelerometer Bandwidth = 260Hz.
	setSampleRate(500);				// Set the sampling rate to 500Hz.
}
	