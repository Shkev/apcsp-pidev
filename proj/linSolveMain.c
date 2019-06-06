#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#include "linSolveShayan.h"
#define TRUE      1
#define FALSE     0
#define MAXROW      4
#define MAXCOL      4

/* Start of main code */
int main(int argc, char* argv[])
{
  printf("%d", argc);
  float inputMatrix[MAXROW][MAXCOL];
  float inverseMatrix[MAXROW][MAXCOL];
  float equalsMatrix[MAXROW][1];
  float outputMatrix[MAXROW][MAXCOL];
  int n = 0;
  int m = 0;
  for (int i = 0; i < sizeof(*argv); i++)
  {
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
        if ((i % 4) == 0)
        {
          i++;
          equalsMatrix[m][1] = atof(argv[i]);
        }
      }
      n++;
    }
  }
  rmExtra(inputMatrix, r0, r1, r2, r3, c0, c1, c2, c3);
  invMatrix(inputMatrix, inverseMatrix, r0, r1, r2, r3, c0, c1, c2, c3);
  //Multiplying equalsMatrix by inverseMatrix to get outputMatrix of solutions (inverseMatrix must be entered as first arg).
  int m1, n1, m2, n2;
  m2 = MAXROW;
  n1 = 1;
  if ((r2 == FALSE) & (r3 == FALSE))
  {
    m1 = 2;
    if ((c2 == FALSE) & (c3 == FALSE))
    {
      n1 = 2;
    }
  }
  else
  {
    if (r3 == FALSE)
    {
      m1 = 3;
      if (c3 == FALSE)
      {
        n1 = 3;
      }
    }
  }
  else
  {
    m1 = MAXROW;
    n1 = MAXCOL;
  }
  multMat(inverseMatrix, equalsMatrix, outputMatrix, m1, n1, m2, n2); //outputMatrix is m1 by n2 array
  printSolutions(outputMatrix, m1, n2);
  exit(EXIT_SUCCESS);
}
