int getBit(int number, int bit)
{
  return ((number & (1<<bit)) != 0);
}

int setBit(int number, int bit)
{
  return (number | (1 <<bit));
}
