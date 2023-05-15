//11) Faça um programa que leia uma matriz 4x4. A seguir, mostre como resposta quantos valores pares e
//quantos valores ímpares estão presentes na matriz. Imprima os valores da resposta em uma única linha,
//separados por um único espaço.
#include <stdio.h>
int main ()
{   
    int mat[4][4];
    int i,j;
    int contapar=0;
    int contaimpar=0;

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
            if(mat[i][j] % 2 == 0)
            {
                contapar++;
                
            } 
                else 
                {
                     contaimpar++;
                }
               
        }
          
        }

        
            printf("%d %d", contapar, contaimpar);
        
        return 0;   
    }

 
