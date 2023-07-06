//2) Faça um programa que receba quatro números e mostre qual deles é o menor.
#include <stdio.h>
int main ()
{
  int num1, num2, num3, num4, menor;

  printf("Digite um valor para num1\n");
  scanf("%d", &num1);

  printf("Digite um valor para num2\n");
  scanf("%d", &num2);

  printf("Digite um valor para num3\n");
  scanf("%d", &num3);

  printf("Digite um valor para num4\n");
  scanf("%d", &num4);

    menor=num1;
  if( num2 < menor ) {
    menor=num2;
  }
  if( num3 < menor ) {
    menor=num3;
  }
  if( num4 < menor ) {
    menor=num4;
  }
  printf("O menor numero sera igual a: %d\n", menor);
  
  return 0;
  
}