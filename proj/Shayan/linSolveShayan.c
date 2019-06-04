#include <stdio.h>
0;256;0c#include <stdlib.h>
#include "linSolveShayan.h"
#define MAXROW   4
#define MAXCOL   4
#define FALSE   0
#define TRUE   1

//defining functions
void rmExtra(int* matrix[MAXROW][MAXCOL])
{
  int m = 0;
  int n = 0;
  int r1 = TRUE, r2 = TRUE, r3 = TRUE,r4 = TRUE;
  int c1 = TRUE, c2 = TRUE, c3 = TRUE, c4 = TRUE;
  for (int i = 0; i < MAXROW; i++)
  if ((matrix[i][n] == 0) & (matrix[i][n + 1] == 0) & (matrix[i][n + 2] == 0) & (matrix[i][n + 3] == 0)
  {
    if (i == 0)
    {
      r1 = FALSE;
    }
    if (i == 1)
    {
      r2 = FALSE;
    }
    if (i == 2)
    {
      r3 = FALSE;
    }
    if (i == 3)
    {
      r4 = FALSE;
    }
  for (int i = 0; i < MAXCOL; i++)
  {
    if ((matrix[m][i] == 0) & (matrix[m + 1][i] == 0) & (matrix[m + 2][i] == 0) & (matrix[m + 3][i] == 0)
    {
      if (i == 0)
      {
        c1 = FALSE;
      }
      if (i == 1)
      {
        c2 = FALSE;
      }
      if (i == 2)
      {
        c3 = FALSE;
      }
      if (i == 3)
      {
        c4 = FALSE;
      }
    }
  }
}

void invMatrix(int* matrix[MAXROW][MAXCOL])
{

}
