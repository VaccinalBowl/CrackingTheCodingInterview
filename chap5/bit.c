int getBit(int number, int bit)
{
  return ((number & (1<<bit)) != 0);
}

int setBit(int number, int bit)
{
  return (number | (1 <<bit));
}

int countBits(int number, int bit)
{
  int i = 0;
  int count = 0;
  while( i < (sizeof(int)*8)){
    int current_bit = getBit(number,i);  
    count = (current_bit == bit) ? count+1 : count ; 
    i++;
  }
  return count;
}

int clearBit(int number, int bit)
{
  int mask = ~(1<<bit);
  return number & mask; 
}


int clearBitsMSBI(int number,int i)
{
  int mask = (1<<i)-1;
  return mask & number;
}

int clearBitLSBI(int number, int i)
{
  int mask = (-1<<(i+1));
  return mask & number; 
}
