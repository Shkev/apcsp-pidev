#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#define MAXROW      3
#define MAXCOL      3

void printSolutions(int row, int col, float m[row][col])
{
  int i = 1;
  for(int a = 0; a < row; a++)
  {
    for(int b = 0; b < col; b++)
    {
      printf("x%d = %f\t", i, m[a][b]);
    }
    printf("\n");
    i++;
  }
}

void multMat(float* x[MAXROW][MAXCOL], float* y[MAXROW][MAXCOL], float* result[MAXROW][MAXCOL], int m1, int n1, int m2, int n2)
{
  int total;
  if(m1 == n2)
  {
    /*Multiplying two matrices*/
    for(int a = 0; a < m1; a++)
    {
      for(int b = 0; b < n1; b++)
      {
        total = 0;
        float arg1 = *x[a][b];
        float arg2 = *y[b][a];
        total = total + (arg1 * arg2);
        *result[a][b] = total;
      }
    }
  }
  else
  {
    printf("\nMultiplication can not be done.\n");
  }
}
