#include <stdio.h>
#include <stdlib.h>
#include "linSolveShayan.h"
#define MAXROW   4
#define MAXCOL   4
#define FALSE   0
#define TRUE   1

//defining functions
void rmExtra(float* matrix[][], int* r0, int* r1, int* r2, int* r3, int* c0, int* c1, int* c2, int* c3)
{
  int m = 0;
  int n = 0;
  *r0 = TRUE; *r1 = TRUE; *r2 = TRUE; *r3 = TRUE;
  *c0 = TRUE; *c1 = TRUE; *c2 = TRUE; *c3 = TRUE;
  for (int i = 0; i < MAXROW; i++)
  {
    if ((matrix[i][n] == 0) & (matrix[i][n + 1] == 0) & (matrix[i][n + 2] == 0) & (matrix[i][n + 3] == 0))
    {
      if (i == 0)
      {
        *r0 = FALSE;
      }
      if (i == 1)
      {
        *r1 = FALSE;
      }
      if (i == 2)
      {
        *r2 = FALSE;
      }
      if (i == 3)
      {
        *r3 = FALSE;
      }
    }
  }
  for (int i = 0; i < MAXCOL; i++)
  {
    if ((matrix[m][i] == 0) & (matrix[m + 1][i] == 0) & (matrix[m + 2][i] == 0) & (matrix[m + 3][i] == 0))
    {
      if (i == 0)
      {
        *c0 = FALSE;
      }
      if (i == 1)
      {
        *c1 = FALSE;
      }
      if (i == 2)
      {
        *c2 = FALSE;
      }
      if (i == 3)
      {
	      *c3 = FALSE;
      }
    }
  }
}

void scaleMatrix(float* inputMatrix[][], float* outputMatrix, float scalar, int max)
{
  for (int m = 0; m < max; m++)
  {
    for (int n = 0; n < max; n++)
    {
      *outputMatrix[m][n] = *inputMatrix[m][n] * scalar;
    }
  }
}

void invMatrix(float matrix[][],int* r1, int* r2, int* r3, int* r4, int* c1, int* c2, int* c3, int* c4 )
{
  float deter;
  if ((*c3 == FALSE) & (*c2 == FALSE) & (*r3 == FALSE) & (*r2 == FALSE))
  {
    //if matrix[][] is a 2 by 2 matrix (array)
    float adj[2][2];
    float invMat[2][2];
    float a = matrix[1][1];
    float b = matrix[1][2];
    float c = matrix[2][1];
    float d = matrix[2][2];
    deter = (a * d) -  (b * c);
    if (deter == 0)
    {
      printf("Infinite Solutions or No Solutions\n");
    }
    else
    {
      adj[1][1] = d;
      adj[1][2] = b * (-1);
      adj[2][1] = c * (-1);
      adj[2][2] = a;
      scaleMatrix(adj, invMat, (1 / deter), 2);
      /*for (int m = 0; m < 2; m++)
      {
        for (int n = 0; n < 2; n++)
        {
          invMat[m][n] = adj[m][n] * (1 / deter);
        }
      }*/
    }
  }
  else
  {
    if ((*c3 == FALSE) & (*r3 == FALSE))
    {
      //if matrix[][] is a 3 by 3 matrix (array)
      float adj[3][3];
      float invMat[3][3];
      float matMinor[3][3];
      float a, b, c, d, e, f, g, h, i;
      a = matrix[0][0]; b = matrix[0][1]; c = matrix[0][2];
      d = matrix[1][0]; e = matrix[1][1]; f = matrix[1][2];
      g = matrix[2][0]; h = matrix[2][1]; i = matrix[2][2];
      //creating matrix of minors
      matMinor[0][0] = (e * i) - (f * g);
      matMinor[0][1] = (d * i) - (h * f);
      matMinor[0][2] = (d * g) - (h * e);
      matMinor[1][0] = (b * i) - (g * c);
      matMinor[1][1] = (a * i) - (h * c);
      matMinor[1][2] = (a * g) - (b * h);
      matMinor[2][0] = (b * f) - (e * c);
      matMinor[2][1] = (a * f) - (d * c);
      matMinor[2][2] = (a * e) - (b * d);
      float matCoFact[3][3];
      int m, n;
      for (int i = 0; i < 9; i++)
      {
        if ((i % 2) == 0)
        {
          matCoFact[m][n] = matMinor[m][n];
        }
        else
        {
          matCoFact[m][n] = matMinor[m][n] * (-1);
        }
        m++;
        n++;
      }
      //code to transpose matrix of cofactors to adjugate
      adj[0][0] = matCoFact[0][0];
      adj[0][1] = matCoFact[1][0];
      adj[0][2] = matCoFact[2][0];
      adj[1][0] = matCoFact[0][1];
      adj[1][1] = matCoFact[1][1];
      adj[1][2] = matCoFact[2][1];
      adj[2][0] = matCoFact[0][2];
      adj[2][1] = matCoFact[1][2];
      adj[2][2] = matCoFact[2][2];
      deter = (matCoFact[0][0] * a) + (matCoFact[0][1] * b) + (matCoFact[0][2] * c);
      if (deter == 0)
      {
        printf("Infinite Solutions or No Solutions\n");
      }
      else
      {
        scaleMatrix(adj, invMat, (1 / deter), 3);
        /*for (int m = 0; m < 3; m++)
        {
          for (int n = 0; n < 3; n++)
          {
            invMat[m][n] = adj[m][n] * (1 / deter);
          }
        }*/
      }
    }
    /*else
    {
      code for 4 by 4 matrix, not working, update later
      float adj[4][4];
      float invMat[4][4];
      float minor1[3][3], minor2[3][3], minor3[3][3], minor4[3][3];
      float coFact1[3][3], coFact2[3][3], coFact3[3][3], coFact4[3][3];
      float a, b, c, d, e, f, g, h, i, j, k, l, m1, n1, o, p;
      a = matrix[0][0]; b = matrix[0][1]; c = matrix[0][2]; d = matrix[0][3];
      e = matrix[1][0]; f = matrix[1][1]; g = matrix[1][2]; h = matrix[1][3];
      i = matrix[2][0]; j = matrix[2][1]; k = matrix[2][2]; l = matrix[2][3];
      m1 = matrix[3][0]; n1 = matrix[3][1]; o = matrix[3][2]; p = matrix[3][3];
      //creating matrix of minors at M_i,j = M_0,0
      minor1[0][0] = f; minor1[0][1] = g; minor1[0][2] = h;
      minor1[1][0] = j; minor1[1][1] = k; minor1[1][2] = l;
      minor1[2][0] = n1; minor1[2][1] = o; minor1[2][2] = p;
      scaleMatrix(minor1, coFact1, 1, 4);
      //creating matrix of minors at M_i,j = M_0,1
      minor2[0][0] = e; minor2[0][1] = g; minor2[0][2] = h;
      minor2[1][0] = i; minor2[1][1] = k; minor2[1][2] = l;
      minor2[2][0] = m1; minor2[2][1] = o; minor2[2][2] = p;
      scaleMatrix(minor2, coFact2, -1, 4);
      //creating matrix of minors at M_i,j = M_0,2
      minor3[0][0] = e; minor3[0][1] = f; minor3[0][2] = h;
      minor3[1][0] = i; minor3[1][1] = j; minor3[1][2] = l;
      minor3[2][0] = m1; minor3[2][1] = n1; minor3[2][2] = p;
      scaleMatrix(minor3, coFact3, 1, 4);
      //creating matrix of minors at M_i,j = M_0,3
      minor4[0][0] = e; minor4[0][1] = f; minor4[0][2] = g;
      minor4[1][0] = i; minor4[1][1] = j; minor4[1][2] = k;
      minor4[2][0] = m1; minor4[2][1] = n1; minor4[2][2] = o;
      scaleMatrix(minor4, coFact4, -1, 4);
    }*/
  }
}
