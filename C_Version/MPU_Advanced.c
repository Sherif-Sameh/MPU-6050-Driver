// This file includes all the function definitions of the functions that would be needed by a more advanced user for the MPU6050

#include "MPU_Advanced.h"

char setClockSource(enum clockSource CS)
{
  char data;
  switch(CS)
  {
    case 1: data = 0x01; break;
    case 2: data = 0x02; break;
    case 3: data = 0x03; break;
    default: data = 0x00;
  }
  return writeToReg(0x6B, data);
}

char resetAccSignalPath()
{
  return writeToReg(0x68, 0x02);
}

char resetGyroSignalPath()
{
  return writeToReg(0x68, 0x04);
}

char resetTempSignalPath()
{
	return writeToReg(0x68, 0x01);
}

char dataRDY_IE()
{
  char current;
  char tmp = readFromReg(0x38, &current,1);
  current |= (1<<0);
  return (tmp && writeToReg(0x38, current));
}

char setDLPF(char DLPF_CFG)
{
  if( (DLPF_CFG>6) || (DLPF_CFG<0))
  {
    DLPF_CFG = 0;
  }
  return writeToReg(0x1A, DLPF_CFG);
}

char setSampleRate(int sampleRate)
{
  char DLPF;
  char tmp = readFromReg(0x1A, &DLPF, 1);
  if(DLPF == 0)
  {
    sampleRate = (8000/sampleRate) - 1;
  }
  else
  {
    sampleRate = (1000/sampleRate) - 1;
  }
  if(sampleRate<0)
  {
    return 0;
  }
  return (tmp && writeToReg(0x19, (char)sampleRate));
}
