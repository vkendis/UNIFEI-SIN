//10) Faça um programa que leia uma matriz 4x4. A seguir, mostre como resposta quantos valores maiores
//que 10 estão presentes na matriz.
#include <stdio.h>
int main ()
{   
    int mat[4][4];
    int i,j;
    int maior=0;

    for(i=0;i < 4; i++)
    {
        for(j=0;j < 4; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for(i=0;i < 4; i++)
    {
        for(j=0;j < 4; j++)
        {
            if(mat[i][j]> 10)
            {
                printf("%d ", mat[i][j]);
                
            }
          
        }
    }

return 0;    
}