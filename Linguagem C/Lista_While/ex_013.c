//13) Faça um programa que leia um número N e mostre a soma dos N primeiros termos da seguinte
//expressão, com precisão de duas casas decimais: S = – 1 + 1/2 – 1/3 + 1/4 – 1/5 + ... + 1/N.
#include <stdio.h>

int main() {
    int n, i = 1, sinal = -1;
    float soma = 0;
    
    scanf("%d", &n);

    while (i <= n) {
        soma += sinal * (1.0 / i);
        sinal *= -1;
        i++;
    }

    printf("%.2f\n", soma);

    return 0;
}