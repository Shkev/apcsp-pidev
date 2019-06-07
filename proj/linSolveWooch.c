#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"
#define MAXROW      3
#define MAXCOL      3

void printSolutions(int row, int col, float m[row][col])
{
  int i = 1;
  printf("\n");
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

void multMat(int m1, int n1, int m2, int n2, float x[][MAXCOL], float y[][MAXCOL], float result[n1][m2])
{
  float total;
  /*Multiplying two matrices*/
  for(int r = 0; r < n2; r++)
  {
    for(int s = 0; s < m1; s++)
    {
      total = 0;
      for(int t = 0; t < n1; t++)
      {
        total = total + x[s][t] * y[t][r];
        printf("%f", total);
      }
      result[r][s] = total;
    }
  }
}
