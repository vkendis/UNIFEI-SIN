//14) Faça um programa que leia um número N e mostre a soma dos N primeiros termos da seguinte
//expressão, com precisão de duas casas decimais: S = 0/1 + 2/2 + 4/4 + 6/8 + 8/16 + 10/32 + 12/64 + 14/128 + ...
#include <stdio.h>
#include <math.h>

int main() {
    int n, i = 0;
    float termo, soma = 0;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    while (i < n) {
        termo = 2.0 * i / pow(2, i);
        soma += termo;
        i++;
    }

    printf("Soma dos %d primeiros termos: %.2f\n", n, soma);

    return 0;
}