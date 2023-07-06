// 1) Faça um programa que receba dois números e mostre qual deles é o menor.
#include <stdio.h>
int main ()
{
  int num1, num2;

  printf("Digite um valor para num1\n");
  scanf("%d", &num1);

  printf("Digite um valor para num2\n");
  scanf("%d", &num2);

  if( num1 < num2 ) 
  {
    printf("%d Sera o menor numero\n", num1);
  }
  else
    if( num1 > num2 )
    printf("%d Sera o menor numero\n", num2);
  
  return 0;
  
}