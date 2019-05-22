#include <stdio.h>

int main()
{
  int a = 0;

  // if statement to test is a is equal to 0
  if (a == 0)
  {
    printf("a is 0\n");
  }
  else
  {
    printf("a is not 0\n");
  }

  int b = 0;
  if (a != b)
  {
    printf("a is not equal to b\n");
  }
  else
  {
    printf("a is equal to b\n");
  }

  int c = 1;
  if (a > c)
  {
    printf("a is greater than c\n");
  }
  else
  {
    printf("a is not greater than c\n");
  }

  int d = 1;
  if (c <= d)
  {
    printf("c is less than or equal to d\n");
  }
  else
  {
    printf("c is not less than or equal to d\n");
  }

  if (c == d && a == b)
  {
    printf("c is equal to d and a is equal to b\n");
  }
  else
  {
    printf("both c equal to d and a equal to b are not met\n");
  }

  if (c == d || a == b)
  {
    printf("c is equal to d or a is equal to b\n");
  }
  else
  {
    printf("both c equal to d or a equal to b are not met\n");
  }

if (!(d == 1))
  {
    printf("Not d == 1\n");
  }
  else
  {
    printf("Not not d == 1\n");
  }

}

