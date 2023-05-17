//1) Faça um programa que leia um valor dado em reais (R$) e a cotação do dólar (US$). A seguir, mostre o valor em reais convertido para dólares.

#include <stdio.h>

int main(void) {
  float real, dolar, conv;
 
  printf("Digite o valor em real para converter: \n");
  scanf("%f", &real);
  printf("Digite o valor da cotacao atual do dolar: \n");
  scanf("%f", &dolar);
  
  conv=real/dolar;
  printf("A conversao em dolares sera igual a: $%0.2f dolares\n", conv);
  return 0;
}