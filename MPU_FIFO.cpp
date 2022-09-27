// This file include all the function definitions of functions that relate to using the FIFO on the MPU6050

#include "MPU_FIFO.h"

char FIFO_Reset()
{
  return writeToReg(0x6A, 0x04);
}

char FIFO_Enable()
{
  return writeToReg(0x6A, 0x40);
}

char FIFO_Disable()
{
  return writeToReg(0x6A, 0x00);
}

char readFIFO_count(int* count)
{
  char c[2];
  char tmp = readFromReg(0x72, c, 2);
  *count = ((c[0]<<8) | c[1]);
  return tmp;
}

char readFIFO(char* value)
{
  return readFromReg(0x74, value, 1);
}

char FIFO_OVF_IE()
{
  char current;
  char tmp = readFromReg(0x38, &current,1);
  current |= (1<<4);
  return (tmp && writeToReg(0x38, current));
}

char gyroFIFO_En()
{
  char current;
  char tmp = readFromReg(0x23, &current, 1);
  current |= ((1<<4) | (1<<5) | (1<<6));
  return (tmp && writeToReg(0x23, current));
}

char accFIFIO_En()
{
  char current;
  char tmp = readFromReg(0x23, &current, 1);
  current |= (1<<3);
  return (tmp && writeToReg(0x23, current));
}

char tempFIFO_EN()
{
  char current;
  char tmp = readFromReg(0x23, &current, 1);
  current |= (1<<7);
  return (tmp && writeToReg(0x23, current));
}
