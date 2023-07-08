//13) Faça um programa que leia 4 números inteiros no formato de string, compute a soma dos números lidos,
//converta o resultado para outra string e mostre a string que contém o resultado.
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char num[4][10];
    int soma = 0;
    int n[4];
    int i;
    char restring[100];

    for (i = 0; i < 4; i++) 
    {
        scanf("%s", num[i]);
        n[i] = atoi(num[i]);
        soma += n[i];
    }

    sprintf(restring, "%d", soma);
    printf("%s", restring);

    return 0;
}