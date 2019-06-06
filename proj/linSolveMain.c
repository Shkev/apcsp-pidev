#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#include "linSolveShayan.h"
#define TRUE      1
#define FALSE     0
#define MAXROW      3
#define MAXCOL      3

/* Start of main code */
int main(int argc, char* argv[])
{
  float inputMatrix[MAXROW][MAXCOL];
  float inverseMatrix[MAXROW][MAXCOL];
  float equalsMatrix[MAXROW][1];
  float outputMatrix[MAXROW][MAXCOL];
  int n = 0;
  int m = 0;
  int k = 1;
  int r0, r1, r2, c0, c1, c2;
  r0 = TRUE; r1 = TRUE; r2 = TRUE;
  c0 = TRUE; c1 = TRUE; c2 = TRUE;
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
      if ((k % MAXROW) == 0)
      {
        i++;
        k = 0;
        equalsMatrix[m][0] = atof(argv[i]);
      }
    }
    n++;
    k++;
  }

  rmExtra(inputMatrix, &r0, &r1, &r2, &c0, &c1, &c2);
  invMatrix(inputMatrix, inverseMatrix, &r0, &r1, &r2, &c0, &c1, &c2);
  //Multiplying equalsMatrix by inverseMatrix to get outputMatrix of solutions (inverseMatrix must be entered as first arg).
  int m1, n1, m2, n2;
  m2 = MAXROW;
  n2 = 1;
  if (r2 == FALSE)
  {
    m1 = 2;
  }
  if (c2 == FALSE)
  {
    n1 = 2;
  }
  if ((c2 == TRUE) & (r2 == TRUE))
  {
    m1 = MAXROW;
    n1 = MAXCOL;
  }

  multMat(inverseMatrix, equalsMatrix, outputMatrix, m1, n1, m2, n2); //outputMatrix is m1 by n2 array
  printSolutions(m1, n2, outputMatrix);
  exit(EXIT_SUCCESS);
}
