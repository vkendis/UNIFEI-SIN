/*5) Declare um vetor de inteiros com 10 posições, leia e armazene valores em cada posição. A seguir,
utilizando um ponteiro de int, some uma unidade a cada posição do vetor. Imprima o vetor antes e após a
modificação.*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num[10], *ptrnum[10];
    int i;

    for(i=0;i<10;i++)
    {
        ptrnum[i] = &num[i];
    }

    for(i=0;i<10;i++)
    {
        scanf("%d", &num[i]);
    }

    for(i=0;i<10;i++)
    {
        scanf("%d", &num[i]);
    }

    for(i=0;i<10;i++)
    {
        printf("endereco: %p contem: %d", ptrnum[i], *ptrnum[i]);
    }

return 0;    
}