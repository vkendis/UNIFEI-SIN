// 14) Fazer um programa que leia o valor de um produto e imprima o valor final com desconto, sabendo que o 
desconto foi de 12%.

#include <stdio.h>

int main(void) {
float valor, desconto;
  printf("Digite o valor a ser descontado: \n");
  scanf("%f", &valor);

  desconto=valor*0.88;
  printf("O valor sera igual a:%0.2f ", desconto);
  return 0;
}