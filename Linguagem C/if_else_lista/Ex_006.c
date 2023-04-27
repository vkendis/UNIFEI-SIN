//6) Faça um programa que leia o salário de um trabalhador e o valor da prestação de um empréstimo. Se a
//prestação for maior que 20% de seu salário, mostre a mensagem: “emprestimo nao concedido”. Caso
//contrário, mostre a mensagem: “emprestimo concedido”.
#include <stdio.h>
int main ()
{
  float salario, prestacao;

  printf("Digite o valor do seu salario:\n");
  scanf("%f", &salario);

  printf("Digite o valor do seu prestacao:\n");
  scanf("%f", &prestacao);

  if( prestacao > 0.2* salario)   
  {
    printf("emprestimo nao concedido\n");
  }
  else
    printf("emprestimo concedido\n");
  
  return 0;
  
}