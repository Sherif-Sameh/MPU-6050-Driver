
#include "MPU_Basic.h"

int main(void)
{
	/* Read all 3 accelerometers raw values */
	int accReadings[3];
	char status = getAccReadings(accReadings, 0, 0);
	if(status)
	{
		/* Operation was successful and accReadings now contains all 3 raw readings ordered from AccX at index 0 to AccZ at index 2. */
	}
	else
	{
		/* Operation failed and appropriate action should be taken. */
	}

	
	/* Read raw reading for the X-axis accelerometer only */
	int accX;
	status = getAccReadings(&accX, 0, 2);
	if(status)
	{
		/* Operation was successful and the value of the X-axis accelerometer has been loaded into the accX variable */
	}
	else
	{
		/* Operation failed and appropriate action should be taken. */
	}
	
	
	/* Read raw reading for the Y-axis gyroscope only */
	int gyroY;
	status = getGyroReadings(&gyroY, 1, 1);
	if(status)
	{
		/* Operation was successful and the value of the Y-axis gyroscope has been loaded into the gyroY variable */
	}
	else
	{
		/* Operation failed and appropriate action should be taken. */
	}
	
	
	/* Read raw reading for the temperature sensor */
	int temp;
	status = getTempReadings(&temp);
	if(status)
	{
		/* Operation was successful and the value of the temperature sensor has been loaded into the temp variable */
	}
	else
	{
		/* Operation failed and appropriate action should be taken. */
	}
	
	/* Note: The status checks are advised but obviously not mandatory at every step. */