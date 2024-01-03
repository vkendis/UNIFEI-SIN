//9) Faça um programa que determine se um determinado ano lido é bissexto. Um ano é bissexto se for
//divisível por 400, ou se for divisível por 4 e não for divisível por 100. Seu programa deve imprimir apenas
//as respostas “sim” ou “nao”.
#include <stdio.h>
int main ()
{
  int ano;

  printf("Digite o ano:\n");
  scanf("%d", &ano);

  if( ano % 400 == 0 || (ano % 4 == 0 && ano % 100!= 0))   
  {
    printf("sim");
  }
  else 
    printf("nao");
     
return 0;
  
}