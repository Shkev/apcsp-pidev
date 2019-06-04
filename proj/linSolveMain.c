#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#include "linSolveShayan.h"
#define MAXROW 4
#define MAXCOL 4

/* Start of main code */
int main(int argc, int* argv[])
{
  int inputMatrix[MAXROW][MAXCOL];
  for (int i = 0, int n = 0, int m = 0; i < sizeof(argv); i++, n++)
  {
    if ((n % MAXCOL) == 0)
    {
      n = 0
      m++
    }
    inputMatrix[m][n] = argv[i];
  }
}
