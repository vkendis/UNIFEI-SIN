//2) Faça um programa que declare e leia um vetor com 10 números reais. Calcule e armazene em um segundo
//vetor o quadrado de cada número real lido. Mostre os dois vetores na tela. Imprima cada vetor em uma linha,
//com os números separados entre si por um único espaço.
#include <stdio.h>
int main ()
{
    float vet[10];
    float res[10];
    int i;
    
    for(i=0; i < 10; i++)
    {
        scanf("%f", &vet[i]);
    }
    
    for(i=0; i < 10; i++)
    {
        res[i] = vet[i] * vet[i];
    }

    for(i=0; i < 10; i++)
    {
        printf("%.2f ", vet[i]);
    }
    printf("\n");

    for(i=0; i < 10; i++)
    {
        printf("%.2f ", res[i]);
    }

return 0;    
}