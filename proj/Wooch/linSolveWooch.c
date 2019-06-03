#include "linSolveWooch.h"

void multMatrix()
{
	int a,b;
	for(a=0;a< row;a++)
    {
        for(b=0;b< col;b++)
        {
            printf("Enter element [%d,%d] : ",a+1,b+1);
            scanf("%d",&m[a][b]);
        }
    }
}

