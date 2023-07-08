/*4) Declare um vetor de inteiros com 10 posições, leia e armazene valores em cada posição. A seguir,
utilizando um ponteiro de int, mostre o endereço e o conteúdo de cada posição do vetor.*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num[10], *ptrnum[10];
    int i, j=1;

    for(i=0; i<10; i++)
    {
    ptrnum[i] = &num[i];
    }

    for(i=0; i<10; i++)
    {   
        printf("Digite um numero inteiro para ser armazenado na posicao %d do vetor: ", j);
        scanf("%d", &num[i]);    
        j++;
    }

    for(i=0; i<10; i++)
    {
        printf("endereco da posicao %d: %p Conteudo: %d \n\n",i+1, ptrnum[i], *ptrnum[i]);    
    }
return 0;    
}