
#include "MPU_Basic.h" /* For readings data from the IMU */
#include "MPU_SelfTest.h"

int main(void)
{
	/* Testing the 3 gyroscopes */
	
	int gyroReadingsRaw[3] = {0, 0, 0}; 		// Readings with self-test disabled.
	int gyroReadingsSelfTest[3] = {0, 0, 0};	// Readings with self-test enabled.
	int gyroFactoryTrim[3] = {0, 0, 0};			// Factory trim for each gyro.
	
	I2CInit(); // Initialize I2C peripheral.
	
	setAD0(0);
	deviceReset(); 								// To erase any previous configurations.
	// It's advised to create some delay between reseting the IMU and waking it back up.
	
	wakeUp(); 									// Wake up from sleep mode.
	setGyroFS_Range(0); // +-250dps				// Required gyro FS range for testing.
	setAccFS_Range(2); //  +-8g					// Required accelerometer FS range for testing.
	
	getFactoryTrimGyro(gyroFactoryTrim); 		// Retrieve the factory trim data for the gyros.
	getGyroReadings(gyroReadingsRaw, 0, 0);		// Get raw readings before enabling the self-test.
	
	gyroSelfTestEn();							// Enable the self-test feature for the gyros.
	getGyroReadings(gyroReadingsSelfTest,0,0);  // Get readings with self-test enabled.
	
	int gyroSelfTestResponse[3];
	for(unsigned char i = 0; i < 3; i++)		// Calculate the self-test response.
	{
		gyroSelfTestResponse[i] = gyroReadingsSelfTest[i] - gyroReadingsRaw[i];
	}
	
	float changeFromFactoryTrim[3];
	for(unsigned char i = 0; i < 3; i++)		// The % change should be in between +-2% for a functional IMU.
	{
		changeFromFactoryTrim[i] = ((float) gyroSelfTestResponse[i] - gyroFactoryTrim[i]) / gyroFactoryTrim[i];
		changeFromFactoryTrim[i] = 100 * changeFromFactoryTrim[i]; // Convert to percentage.
	}
	
	/* It's advised to take many samples while self-test is enabled and while it's disabled and to use
	 * the mean of these values to calculate the change from the factory trim to have more reliable results.
	 */
}
	