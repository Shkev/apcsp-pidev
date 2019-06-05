#include <stdio.h>
#include <stdlib.h>
#include "linSolveWooch.h"

#define MAXROW      4
#define MAXCOL      4

void multMatrix(int matrix[][MAXCOL], int matri[][MAXROW], int row,int col)
{
	int a,b;
	for(a=0;a< row;a++)
    {
        for(b=0;b< col;b++)
        {
            printf("Please enter the element [%d,%d] : ",a+1,b+1);
            scanf("%d",&matrix[a][b]);
        }
    }
}

void printMatrix(int m[][MAXCOL],int row,int col)
{
    int a,b;
    for(a=0;a< row;a++)
    {
        for(b=0;b< col;b++)
        {
            printf("%d\t",m[a][b]);
        }
        printf("\n");
    }
}
int main()
{
    int x[MAXROW][MAXCOL],y[MAXROW][MAXCOL],result[MAXROW][MAXCOL];
    int a,b,m1,n1,m2,n2;
    int total,t;


    printf("Please enter number of Rows of matrix a: ");
    scanf("%d",&m1);
    printf("Please enter the number of Columns of matrix x: ");
    scanf("%d",&n1);

    printf("\nPlease enter the elements of matrix x: \n");
    readMatrix(a,m1,n1);

    printf("Please enter the number of Rows of matrix y: ");
    scanf("%d",&m2);
    printf("Please enter the number of Columns of matrix y: ");
    scanf("%d",&n2);

    printf("\nPlease enter the elements of matrix y: \n");
    readMatrix(b,m2,n2);

    if(m1==n2)
    {
        /*Multiplying two matrices*/
        for(a=0;a< m1;a++)
        {
            for(b=0;b< n1;b++)
            {
                total=0;
                for(t=0;t< m1;t++)
                {
                    total = total  + (x[a][t]*y[t][b]);
                }
                result[a][b]= total;
            }
        }

        /*This will print the final matrix*/
        printf("\nThe result matrix after multiplying:\n");
        printMatrix(result,m1,n1);


    }
    else
    {
        printf("\nMultiplication can not be done.");
    }


    return 0;
}
