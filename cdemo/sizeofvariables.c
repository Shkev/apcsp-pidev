#include<stdio.h>

int main()
{
  int a = 999;

  // print value and size of an int variable
  printf("int a value: %d and size: %d bytes\n", a, sizeof(a));

  unsigned int b = 999;
  printf("unsigned b value: %d and size: %d bytes\n", b, sizeof(b));

  short int c = 999;
  printf("short c value: %d and size: %d bytes\n", c, sizeof(c));

  long int d = 999;
  printf("long d value: %d and size: %d bytes\n", d, sizeof(d));


}

