#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#define MAXROW      4
#define MAXCOL      4

/* not currently necessary
void printMatrix(int m[][MAXCOL],int row,int col)
{
  int a,b;
  for(a = 0; a < row; a++)
  {
    for(b = 0; b < col; b++)
    {
      printf("%d\t",m[a][b]);
    }
      printf("\n");
    }
}*/

int multMat(float* x[][], float* y[][], float* result[][], int m1, int n1, int m2, int n2)
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
        total = total + (x[a][b] * y[b][a]);
        result[a][b] = total;
      }
    }
  }
  else
  {
    printf("\nMultiplication can not be done.");
  }
  exit(EXIT_SUCCESS);
}
