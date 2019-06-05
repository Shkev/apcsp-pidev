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
  int n = 0;
  int m = 0;
  for (int i = 0; i < sizeof(*argv); i++)
  {
    if ((n % MAXCOL) == 0)
    {
      n = 0;
      m++;
    }
    inputMatrix[m][n] = atof(argv[i]);
    n++;
  }
  //  printf("%f\n", inputMatrix[1][1]);
  exit(EXIT_SUCCESS);
}
