#include <stdio.h>
#include <stdlib.h>
//#include "linSolveWooch.h"
//#include "linSolveShayan.h"
#define MAXROW 4
#define MAXCOL 4

/* Start of main code */
int main(int argc, char* argv[])
{
  float inputMatrix[MAXROW][MAXCOL];
  int n = 0;
  int m = 0;
  int r0, r1, r2, r3, c0, c1, c2, c3;
  for (int i = 1; i < argc; i++)
  {
    if (n == 0)
    {
      inputMatrix[m][n] = atof(argv[i]);
    }
    else
    {
      if ((n % MAXCOL) == 0)
      {
        n = 0;
        m++;
      }
      inputMatrix[m][n] = atof(argv[i]);
    }
    n++;
  }
  exit(EXIT_SUCCESS);
}
