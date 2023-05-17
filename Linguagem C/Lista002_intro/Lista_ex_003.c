// 3) Fazer um programa que receba três valores, que podem ser inteiros ou reais, e mostre a soma desses valores.

#include <stdio.h>

int main(void) {
float num1,num2,num3,soma=0;
  printf("Digite 3 numeros divididos por espaco: \n");
  scanf("%f %f %f", &num1, &num2, &num3);
  soma=(num1+num2+num3);
  printf("A soma dos 3 numeros e: %f", soma);
  return 0;
}