// 4) Fazer um programa que receba um número real e imprima o quadrado e o cubo do valor lido.
#include <stdio.h>
#include <math.h>
int main(void) {
float num, square, cube;
  printf("Digite um numero: \n");
  scanf("%f", &num);
  square=pow(num, 2);
  cube=pow(num, 3);

  printf("O quadrado do numero escolhido e: %f\n", square);
  printf("O cubo do numero escolhido e: %f\n", cube);
  return 0;
}