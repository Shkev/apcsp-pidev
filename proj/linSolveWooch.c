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

void multMat(float x[][MAXCOL], float y[][MAXCOL], float result[][MAXCOL], int r, int s, int t)
{
  int total;
    /*Multiplying two matrices*/
    for(r=0; r<3; r++)
    {
      for(s=0; s<3; s++)
      {
	total=0;
        for(t=0; t<3; t++)
        {
          total = total + x[r][t] * y[t][s];
        }
        result[r][s] = total;
      }
    }
}
