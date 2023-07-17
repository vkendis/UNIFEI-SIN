#include <stdio.h>
#include <stdlib.h>

int main ()
{

int i, j;    
int **mata = (int**)malloc(3*sizeof(int*));
for(i=0;i<3;i++)
{
    mata[i] = (int*)malloc(3*sizeof(int));
}

for(i=0;i<3;i++)
{
    scanf("%d", &mata[i][j]);
}


}