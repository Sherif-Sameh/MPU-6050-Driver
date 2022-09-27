// This file inlcudes all the needed function definitions for the MPU_Basic.h header file

#include "MPU_Basic.h"

char wakeUp()
{
  return writeToReg(0x6B, 0x00);
}

char deviceReset()
{ 
  return writeToReg(0x6B, 0x80);
}

char setAccFS_Range(char FS_SELECT)
{
  char current;
  char tmp = readFromReg(0x1C, &current, 1);
  current &= ~((1<<3) | (1<<4));
  switch(FS_SELECT)
  {
    case 1: current |= (1<<3); break;
    case 2: current |= (1<<4); break;
    case 3: current |= ((1<<3) | (1<<4)); break;
  }
  return (tmp && writeToReg(0x1C, current));
}

char setGyroFS_Range(char FS_SELECT)
{
  char current;
  char tmp = readFromReg(0x1B, &current, 1);
  current &= ~((1<<3) | (1<<4));
  switch(FS_SELECT)
  {
    case 1: current |= (1<<3); break;
    case 2: current |= (1<<4); break;
    case 3: current |= ((1<<3) | (1<<4)); break;
  }
  return (tmp && writeToReg(0x1B, current));
}

char getAccReadings(int* data, char skipFromBeginning, char skipFromEnd)
{
  char c[6-2*(skipFromBeginning+skipFromEnd)];
  char tmp = readFromReg((0x3B + 2*skipFromBeginning), c, 6-2*(skipFromBeginning+skipFromEnd));
  for( char i = 0; i < (6-2*(skipFromBeginning + skipFromEnd)); i+=2)
  {
    data[i/2] = ((c[i]<<8) | ((unsigned char)c[i+1]));
  }
  return tmp;
}

char getGyroReadings(int* data, char skipFromBeginning, char skipFromEnd)
{
  char c[6-2*(skipFromBeginning+skipFromEnd)];
  char tmp = readFromReg((0x43 + 2*skipFromBeginning), c, 6-2*(skipFromBeginning+skipFromEnd));
  for( char i = 0; i < (6-2*(skipFromBeginning + skipFromEnd)); i+=2)
  {
    data[i/2] = ((c[i]<<8) | ((unsigned char)c[i+1]));
  }
  return tmp;
}

char getTempReadings(int* data)
{
	char c[2];
	char tmp = readFromReg(0x41, c, 2);
	*data = ((c[0]<<8) | ((unsigned char)c[1]));
	return tmp;
}