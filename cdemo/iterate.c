#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand (time(NULL));
  int div = rand();
  printf("div = %d\n", div);
  for (int i = 1; i < 100; i++)
  {
    int mod = div % i;
    if (mod == 0)
    {
      printf("div is divisible by %d\n", i);
    }
  }
}
