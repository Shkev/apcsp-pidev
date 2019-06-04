#include <stdio.h>
#include <stdlib.h>
#include "linSolveShayan.h"
#define MAXROW   4
#define MAXCOL   4
#define FALSE   0
#define TRUE   1

//defining functions
void rmExtra(int* matrix[MAXROW][MAXCOL], int* r1, int* r2, int* r3, int* r4, int* c1, int* c2, int* c3, int* c4)
{
  int m = 0;
  int n = 0;
  &r1 = TRUE; &r2 = TRUE; &r3 = TRUE; &r4 = TRUE;
  &c1 = TRUE; &c2 = TRUE; &c3 = TRUE; &c4 = TRUE;
  for (int i = 0; i < MAXROW; i++)
  {
    if ((matrix[i][n] == 0) & (matrix[i][n + 1] == 0) & (matrix[i][n + 2] == 0) & (matrix[i][n + 3] == 0)
    {
      if (i == 0)
      {
        &r1 = FALSE;
      }
      if (i == 1)
      {
        &r2 = FALSE;
      }
      if (i == 2)
      {
        &r3 = FALSE;
      }
      if (i == 3)
      {
        &r4 = FALSE;
      }
    }
  for (int i = 0; i < MAXCOL; i++)
  {
    if ((matrix[m][i] == 0) & (matrix[m + 1][i] == 0) & (matrix[m + 2][i] == 0) & (matrix[m + 3][i] == 0)
    {
      if (i == 0)
      {
        &c1 = FALSE;
      }
      if (i == 1)
      {
        &c2 = FALSE;
      }
      if (i == 2)
      {
        &c3 = FALSE;
      }
      if (i == 3)
      {
        &c4 = FALSE;
      }
    }
  }
}

void invMatrix(int* matrix[MAXROW][MAXCOL],int* r1, int* r2, int* r3, int* r4, int* c1, int* c2, int* c3, int* c4 )
{
  float deter;
  int adj[MAXROW][MAXCOL];
  if ((&c4 == FALSE) & (&c3 == FALSE) & (&r4 == FALSE) & (&r3 == FALSE))
  {
    deter = ((matrix[1][1])(matrix[2][2])) - ((matrix[1][2])(matrix[2][1]));
    adj[1][1] = matrix [2][2];
    adj[1][2] = (matrix[1][2]) * -1;
  }
}
    
