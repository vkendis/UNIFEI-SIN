//9) Faça um programa que leia uma quantidade desconhecida de valores inteiros e mostre a sua média, com 1
//casa decimal. O programa deve parar de ler quando um valor negativo for inserido.
#include <stdio.h>

int main() {
    float soma = 0, num, media;
    int i = 0;

    while (num >= 0) {
        printf("Digite um numero positivo: ");
        scanf("%f", &num);
            
    if (num < 0) {
    break; 
    }

    soma += num;
    i++;
    }
        media = soma / i;
        printf("%.1f\n", media);
    return 0;
}