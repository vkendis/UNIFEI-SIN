// 9) Fazer um programa para converter uma dada temperatura de graus Celsius para graus Fahrenheit.

#include <stdio.h>

int main(void) {
  float temp, conv;
  printf("Digite a temperatura para ser convertida: \n");
  scanf("%f", &temp);

  conv= (1.8*temp) + 32;
  printf("A temperatura convertida e igual a: %f", conv);
  return 0;
}