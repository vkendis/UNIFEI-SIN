// 10) Fazer um programa para converter uma dada temperatura de graus Fahrenheit para graus Celsius.

#include <stdio.h>

int main(void) {
float temp, conv;
  
  printf("Digite a temperatura a ser convertida: \n");
  scanf("%f", &temp);

  conv= (temp-32)/1.8;
  printf("A temperatura convertida e igual a: %f", conv);
  return 0;
}