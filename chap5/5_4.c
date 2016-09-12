#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bit.h"

int main(int argc, char** argv)
{

  if(argc != 2){
    printf("./exec INT\n");
    return 1; 
  }

  char str[200];
  strcpy(str,argv[1]);
  int input = atoi(str);
  int target = countBits(input,1); 

  /*Brute force first*/
  int next = input + 1; 
  while(next<=0b11111111111111111111111111111111){
    int nCount = countBits(next,1);
    if(target==nCount){
      break;
    }
    next++;
  }
  printf("Next is: %d\n",next);
  int prev = input - 1; 
  while(prev>0){
    int pCount = countBits(prev,1);
    if(target==pCount){
      break;
    }
    prev--;
  }
  printf("Previous is: %d\n",prev);


  /* Rational non brute force approach */
  /* Calculate next */
  int i = 0;
  int firstOneFound = 0; 
  while(i<32){
    int bit = getBit(input,i);
    if(bit==1){
      firstOneFound=1; 
    }
    if((bit==0)&&firstOneFound){
      break;
    }
    i++;
  }
  
  int withBitSet = setBit(input,i);
  withBitSet = clearBitLSBI(withBitSet,i-1);
  int currentBits = countBits(withBitSet,1);
  int onesToAdd = target - currentBits;
  int newMask = (1 << onesToAdd) -1;
  int nex = newMask|withBitSet;
  printf("Next is: %d\n",nex);

  /* Calculate prev */ 
  i = 0;
  int onesAtStart = 0;
  int countOnesAtStart = 0;
  int foundSomeZeros = 0;
  //printf("Inputy %d\n",input);
  while(i<32){
    int currentBit = getBit(input,i);
    if(i == 0 && currentBit){
      countOnesAtStart=1; 
    }

    if(countOnesAtStart && currentBit && !foundSomeZeros){
      //printf("yes yes\n");
      onesAtStart++;
    }
   
    if(!currentBit){
      foundSomeZeros = 1;
    }

    if(currentBit==1 && foundSomeZeros){
      break; 
    }
    i++;
  }
  
  int inputBitCleared = clearBit(input,i);
  //printf("Input Bit Cleared: %d\n",inputBitCleared);
  int previousBitSet = setBit(inputBitCleared, i-1);
  //printf("Previous Bit Set: %d\n",previousBitSet);
  //printf("Ones at start: %d\n",onesAtStart); 
  if(onesAtStart>0)
  {
    //printf("In here man\n");
    int j = 0;
    int number = i-2; 
    while(j<onesAtStart){
      previousBitSet = setBit(previousBitSet,number);
      //printf("Again %d\n",previousBitSet);
      previousBitSet = clearBit(previousBitSet,j);

      
      j++;
      number--;
      }
  }
  printf("Previous is: %d\n",previousBitSet);
  return 0; 
}
