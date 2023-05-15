//3) Faça um programa que declare e leia um vetor com 8 posições. A seguir, leia dois valores X e Y que
//corresponderão a duas posições do vetor. Ao final, mostre a soma dos elementos presentes nas posições X e
//Y. Seu programa não deve permitir que o usuário informe valores inválidos para X e Y.
#include <stdio.h>
int main ()
{
    int vet[8];
    int soma=0;
    int i;
    int x, y;

    for(i=0; i < 8; i++)
    {
        scanf("%d", &vet[i]);
    }
    do {
        scanf("%d", &x);
    } while (x < 0 || x >= 8);

    do {
        scanf("%d", &y);
    } while (y < 0 || y >= 8);

    soma=vet[x] + vet[y];

    printf("%d", soma);

return 0;    
}