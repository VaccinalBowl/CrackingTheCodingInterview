#include <stdio.h>
#include "bit.h"

//Write a function to determine the number of bits you need to flip to convert integer x into integer y.

int main()
{
  int x = 29;
  int y = 15;
  
  printf("Number of bits to flip %d\n",countBits(x^y,1));
}
