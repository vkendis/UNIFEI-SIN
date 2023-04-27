//4) Faça um programa que receba um número inteiro e informe se este número é par ou ímpar. Imprima apenas as palavras “par” ou “impar” em sua resposta.
#include <stdio.h>
int main ()
{
  int num1;

  printf("Digite um valor para num1\n");
  scanf("%d", &num1);

  if( num1 %2==0 ) 
  {
    printf("O numero e par\n");
  }
  else
    printf("O numero e impar\n");
  
  return 0;
  
}