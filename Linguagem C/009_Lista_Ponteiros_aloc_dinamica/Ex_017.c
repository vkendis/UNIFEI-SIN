/*17) Crie um programa que aloque e leia uma matriz X. A seguir, aloque uma segunda matriz Y, tal que Y
seja a transposta de X. Mostre as duas matrizes na tela.*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,j;

    int **mata = (int**)malloc(3*sizeof(int*));
    for(i=0; i<3; i++)
    {
        mata[i] = (int*)malloc(3*sizeof(int));
    }
    printf("Digite os numeros de sua matriz: ");
    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            scanf("%d", &mata[i][j]);
        }
    }

    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            printf("  %d  ", mata[i][j]);
        }
        printf("\n");
    }   

    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            printf("  %d  ", mata[j][i]);
        }
        printf("\n");
    }   



return 0;    
}