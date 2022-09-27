// This file include all the definitions of functions that are shared by all the other MPU6060 specific files

#include "MPU_Shared.h"

char AD0 = 0;

void setAD0(char pinValue)
{
  if(pinValue == 0)
  {
    AD0 = 0;
  }
  else
  {
    AD0 = 1;
  }
}

static char initiateTransmissionWrite()
{
  char addr = ((MPU6050_ADDRESS<<1) | AD0);
  return initiateWrite(addr);
}

static char initiateTransmissionRead()
{
  char addr = ((MPU6050_ADDRESS<<1) | AD0);
  return initiateRead(addr);
}

char writeToReg(char regAddr, char data)
{
  char tmp = initiateTransmissionWrite();
  tmp = (tmp && burstWrite(&regAddr,1));
  tmp = (tmp && burstWrite(&data,1));
  stopTransmission(); 
  return tmp;
}

char readFromReg(char regAddr, char* data, char n)
{
  char tmp = initiateTransmissionWrite();
  tmp = (tmp && burstWrite(&regAddr,1));
  tmp = (tmp && initiateTransmissionRead());
  tmp = (tmp && burstRead(data, n));
  stopTransmission();
  return tmp;
}

char readInterruptStatus(char* value)
{
  return readFromReg(0x3A, value, 1);
}

char disableInterrupts()
{
  return writeToReg(0x38,0x00);
}
