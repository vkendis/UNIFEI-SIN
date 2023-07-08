//2) Fazer um programa que leia um número real e o imprima na tela.

#include <stdio.h>

int main(void) {
float num;
  printf("Digite um numero Real: \n");
  scanf("%f", &num);
  printf("O numero real escolhido foi: %f", num);
  return 0;
}