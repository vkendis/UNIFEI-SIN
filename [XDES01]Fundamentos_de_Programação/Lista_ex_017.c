//17) Fazer um programa que receba três números e mostre como resposta o quadrado da soma desses números.

#include <stdio.h>
#include <math.h>
int main(void) {
int num1, num2, num3, soma, exp;
  printf("Digite os 3 numeros: \n");
  scanf("%d %d %d", &num1, &num2, &num3);

  soma=num1+num2+num3;
  exp= pow(soma,2);
  printf("O quadrado da soma dos numeros e igual a: %d", exp);
  return 0;
}