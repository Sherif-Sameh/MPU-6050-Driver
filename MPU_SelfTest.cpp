// This file includes all the function definitions for functions that are needed for testing the MPU6050

#include "MPU_SelfTest.h"
#inlcude "MPU_Basic.h"

char accSelfTestEn()
{
  char current;
  char tmp = setAccFS_Range(2); //  +-8g
  tmp = tmp && readFromReg(0x1C, &current, 1);
  current |= ((1<<5) | (1<<6) | (1<<7));
  return (tmp && writeToReg(0x1C, current));
}

char gyroSelfTestEn()
{
  char current;
  char tmp = setGyroFS_Range(0); // +-250dps
  tmp = tmp && readFromReg(0x1B, &current, 1);
  current |= ((1<<5) | (1<<6) | (1<<7));
  return (tmp && writeToReg(0x1B, current));
}

char getFactoryTrimGyro(int* data)
{
  unsigned char gyroTest[3];
  char tmp = readFromReg(0x0D, gyroTest, 3);
  for(char i = 0; i<3; i++)
  {
    gyroTest[i] &= 0x1F;
    if(gyroTest[i] == 0)
    {
      data[i] = 0;
    }
    else
    {
      data[i] = 3275*powf(1.046, gyroTest[i]-1); 
    }
  }
  data[1] = -data[1];
  return tmp;
}

char getFactoryTrimAcc(int* data)
{
  unsigned char accTest[4];
  char tmp = readFromReg(0x0D, accTest, 4);
  for(char i = 0; i < 3; i++)
  {
    accTest[i] &= 0xE0;
    unsigned char tmp1 = ((accTest[3]>>2*(2-i)) & 0x03); 
    accTest[i] = ((accTest[i]>>3) | tmp1);
    if(accTest[i] == 0)
    {
      data[i] = 0;
    }
    else
    {
      data[i] = 1392.64*powf(0.92/0.34,(accTest[i]-1)/30.0);   
    }
  }
  return tmp;
}