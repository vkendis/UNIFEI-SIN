// 5) Fazer um programa que receba um número real e imprima a quinta parte desse número.
#include <stdio.h>

int main(void) {
float num, x;
  printf("Digite um numero real: \n");
  scanf("%f", &num);
  x=(num/5);
  printf("A quinta parte do numero escolhido e: %f", x);
  return 0;
}