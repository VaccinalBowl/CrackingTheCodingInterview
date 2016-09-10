/*
  Flip Bit to Win. You have an integer and you can flip exactly one bit from a 0 to 1. Write code to find the length of the longest sequence of 1s you could create.
  
  Input: 1775 or: 11011101111
  Output 8
  
*/

#include <stdio.h>

int getBit(int number, int bit)
{
  return ((number & (1<<bit)) != 0);
}

int setBit(int number, int bit)
{
  return (number | (1 <<bit));
}

int longestSequence(int input)
{
    int max = 0;
    int lastBit = 0; 
    int count = 0; 
    int i = 0; 
    while(i < 32){
      int bit = getBit(input,i);
      if(bit){
	count++;
      }else if ((!bit)&&lastBit){
	max = (count>max) ? count : max ;
	count = 0; 
      }
      lastBit = bit;  
      i++;
    }
    return max;
}


int main()
{

  int max = 0; 
  int input = 1775;
  int i = 0;
  while(i<32){
    int bit = getBit(input,i);
    if(!bit){
      int oneBitFlipped = setBit(input,i); 
      int longest = longestSequence(oneBitFlipped);
      max = (longest>max) ? longest : max ; 
    }
    i++;
  }

  printf("%d\n",max);
  return 0; 
}
