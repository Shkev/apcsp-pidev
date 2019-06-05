#include <stdio.h>
#include <stdlib.h>
//#include "linSolveWooch.h"
//#include "linSolveShayan.h"
#define MAXROW 4
#define MAXCOL 4

/* Start of main code */
int main(int argc, char* argv[])
{
  printf("%d", argc);
  float inputMatrix[MAXROW][MAXCOL];
  float equalsMatrix[MAXROW][1];
  int n = 0;
  int m = 0;
<<<<<<< HEAD
  for (int i = 0; i < sizeof(*argv); i++)
=======
  int r0, r1, r2, r3, c0, c1, c2, c3;
  for (int i = 1; i < argc; i++)
>>>>>>> 10854c17912340f28cfbf209667865dd9e8d3527
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
      if ((i % 4) == 0)
      {
        i++;
        equalsMatrix[m][1] = atof(argv[i]);
      }
    }
    n++;
  }
<<<<<<< HEAD
  //  printf("%f\n", inputMatrix[1][1]);
=======
>>>>>>> 10854c17912340f28cfbf209667865dd9e8d3527
  exit(EXIT_SUCCESS);
}
