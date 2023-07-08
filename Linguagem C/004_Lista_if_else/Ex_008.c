//8) Faça um programa que leia um valor inteiro e informe se o valor lido é ou não é um múltiplo de 11. Seu
//programa deve imprimir apenas as respostas “sim” ou “nao”.
#include <stdio.h>
int main ()
{
  int num;

  printf("Digite o numero:\n");
  scanf("%d", &num);

  if( num % 11 == 0 )   
  {
    printf("sim");
  }
  else 
    printf("nao");
     
return 0;
  
}