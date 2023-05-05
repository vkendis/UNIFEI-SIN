//15) Faça um programa que leia um número N e mostre a soma dos N primeiros termos da seguinte
//expressão, com precisão de duas casas decimais: S = + 1/1 + 3/2 – 5/3 – 7/4 + 9/5 + 11/6 – 13/7 – 15/8 + ...
#include <stdio.h>

int main() {
    int n, i = 1;
    float termo, soma = 0;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    while (i <= n) {
        termo =(2.0 * i - 1) / i;
        soma += termo;
        i++;
    }

    printf("Soma dos %d primeiros termos: %.2f\n", n, soma);

    return 0;
}