//6) Faça um programa que leia um vetor de inteiros de 10 posições. A seguir, leia um valor X e mostre na tela
//os elementos presentes no vetor que são múltiplos de X. Imprima os números em uma única linha, separados
//entre si por um único espaço.
#include <stdio.h>
int main ()
{
    int vet[10];
    int x;
    int i;

    for(i = 0; i<10; i++)
    {
        scanf("%d", &vet[i]);
    }

    scanf("%d", &x);
  
    for(i = 0; i<10; i++)
    {
        if(vet[i] % x == 0)
        {
            printf("%d ", vet[i]);
        }
    }
 


return 0;    
}
