// 16) Fazer um programa que receba três números e mostre como resposta a soma dos quadrados desses números.
#include <stdio.h>
#include <math.h>
int main(void) {
int num1, num2, num3, soma;
  
  printf("Digite os 3 numeros: \n");
  scanf("%d %d %d", &num1, &num2, &num3);

  soma= pow(num1,2)+pow(num2,2)+pow(num3,2);
  printf("A soma dos quadrados dos numeros e igual a: %d", soma);
  return 0;
}