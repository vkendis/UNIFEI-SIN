//5) Faça um programa que leia um número inteiro e mostre, como resposta, a soma de sua raiz cúbica com sua raiz quarta. Mostre o resultado usando duas casas decimais.

#include <stdio.h>
#include <math.h>
int main(void) {
float num1,soma=0, root3, root4;
  printf("Digite o numero: \n");
  scanf("%f",&num1);

  root3=pow(num1,3);
  root4=pow(num1,4);
  soma=root3+root4;
  
  printf("A soma das raizes cubicas e quadricas sera de: %0.2f", soma);
  return 0;

  }