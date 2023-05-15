//8) Faça um programa que leia dois vetores X e Y de inteiros com 8 elementos cada um. Calcule e mostre os
//vetores resultantes para cada caso a seguir:
//a) Soma entre X e Y: soma de cada elemento de X com o elemento da mesma posição em Y.
//b) Produto entre X e Y: multiplicação de cada elemento de X com o elemento da mesma posição em Y.
//c) Interseção de conjuntos entre X e Y: apenas os elementos que aparecem nos dois vetores.
//d) Diferença de conjuntos entre X e Y: todos os elementos de X que não existem em Y.
//Imprima cada item em uma linha, sendo os valores separados entre si por um único espaço.
#include <stdio.h>
int main ()
{
    int A[8];
    int B[8];
    int i, j;
    int soma[8];
    int produto[8];
    int inter[8];
    int dif[8];
    

    for(i=0; i<8; i++)
    {
        scanf("%d", &A[i]);
    }

    for(i=0; i<8; i++)
    {
        scanf("%d", &B[i]);
    }
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            soma[i]=A[i] + B[i];
            
        }
      printf("%d ", soma[i]);
    }
    printf("\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            produto[i]=A[i] * B[i];
            
        }
      printf("%d ", produto[i]);
    }
    printf("\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(A[i] == B[j])
            {
               inter[i] =A[i];
               printf("%d ", inter[i]);
            }
            
        }
     
    }
    printf("\n");
    
    for (int i = 0; i < 8; i++) {
        dif[i] = 0;
        for (int j = 0; j < 8; j++) {
            if (A[i] == B[j]) {
                dif[i] = 1;
               
            }
        }
        
        if (!dif[i]) {
            dif[i] = A[i];
            printf("%d\n", dif[i]);
        }
    }
    
    return 0;
}