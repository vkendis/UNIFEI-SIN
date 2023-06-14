//11) Faça um programa que leia 4 números inteiros no formato de string, compute a soma dos números lidos
//e mostre o resultado obtido.
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char num[4][10];
    int soma = 0;
    int n[4];
    int i;

    for (i = 0; i < 4; i++) 
    {
        scanf("%s", num[i]);
        n[i] = atoi(num[i]);
        soma += n[i];
    }

    printf("%d\n", soma);

    return 0;
}