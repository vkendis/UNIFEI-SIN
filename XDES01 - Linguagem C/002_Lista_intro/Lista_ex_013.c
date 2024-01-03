// 13) Fazer um programa que receba o ano de nascimento de uma pessoa e o ano atual. A seguir, o algoritmo deve calcular e mostrar: a) a idade da pessoa em anos. b) a idade da pessoa em meses. c) a idade da pessoa 
em dias.
#include <stdio.h>

int main(void) {
int birth, year, ayear,month,day,idade;
  
  printf("Digite o ano de seu nascimento e o ano que estamos: \n");
  scanf("%d %d", &birth, &ayear);

  idade=ayear-birth;
  month=idade*12;
  day=idade*365;

  printf("A idade em anos e igual a: %d anos\n", idade);
  printf("A idade em meses e igual a: %d meses\n", month);
  printf("A idade em dias e igual a: %d dias\n", day);
  return 0;
}