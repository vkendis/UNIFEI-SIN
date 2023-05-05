//1) Faça um programa que leia um inteiro N e implemente um contador regressivo, para imprimir na tela os
//numeros de N até 1. Imprima os números em uma única linha, separados entre si por um único espaço.
#include <stdio.h>
int main (){
int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while (num >= 1) {
    printf("%d ", num);
    num--;
}
return 0;
}







