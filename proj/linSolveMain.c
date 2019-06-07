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
  for (int i = 1; i < (argc - 1); i++)
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
	if ((m == 1) & (n == 3))
	{
	  k = 0;
	}
        equalsMatrix[m][0] = atof(argv[i]);
      }
    }
    n++;
    k++;
  }
  printf("\nInput\n");
  printf("%f %f %f %f\n", inputMatrix[0][0], inputMatrix[0][1], inputMatrix[0][2], equalsMatrix[0][0]);
  printf("%f %f %f %f\n", inputMatrix[1][0], inputMatrix[1][1], inputMatrix[1][2], equalsMatrix[1][0]);
  printf("%f %f %f %f\n", inputMatrix[2][0], inputMatrix[2][1], inputMatrix[2][2], equalsMatrix[2][0]);
  rmExtra(inputMatrix, &r0, &r1, &r2, &c0, &c1, &c2);
  int cont = TRUE;
  invMatrix(inputMatrix, inverseMatrix, &r0, &r1, &r2, &c0, &c1, &c2, &cont);
  if (cont == TRUE)
  {
    /* Debugging code
    printf("\n%f %f %f\n", inverseMatrix[0][0], inverseMatrix[0][1], inverseMatrix[0][2]);
    printf("%f %f %f\n", inverseMatrix[1][0], inverseMatrix[1][1], inverseMatrix[1][2]);
    printf("%f %f %f\n", inverseMatrix[2][0], inverseMatrix[2][1], inverseMatrix[2][2]);
    printf("%d%d%d%d%d%d\n", r0, r1, r2, c0, c1, c2); */
    //MultiplequalsMatrixing equalsMatrix bequalsMatrix inverseMatrix to get outputMatrix of solutions (inverseMatrix must be entered as first arg).
    int m1, n1, m2, n2;
    if (equalsMatrix[2][0] != 0)
    {
      m2 = MAXROW;
    }
    if ((equalsMatrix[2][0] == 0) & (equalsMatrix[1][0] != 0))
    {
      m2 = 2;
    }
    n2 = 1;
    if (r2 == FALSE)
    {
      m1 = 2;
    }
    if (c2 == FALSE)
    {
      n1 = 2;
    }
    if (c2 == TRUE)
    {
      n1 = MAXCOL;
    }
    if (r2 == TRUE)
    {
      m1 = MAXROW;
    }
    printf("\nequal matrix\n");
    printf("%f\n", equalsMatrix[0][0]);
    printf("%f\n", equalsMatrix[1][0]);
    //printf("%f\n", equalsMatrix[2][0]); 
    multMat(m1, n1, m2, n2, inverseMatrix, equalsMatrix, outputMatrix); //outputMatrix is m1 by equalsMatrix n2 arraequalsMatrix
    printSolutions(m1, n2, outputMatrix);
    exit(EXIT_SUCCESS);
  }
}
