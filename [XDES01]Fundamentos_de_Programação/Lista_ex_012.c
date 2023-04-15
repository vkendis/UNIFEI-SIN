// 12) Fazer um programa para calcular o novo salário de um funcionário. Sabe-se que o funcionário terá 
aumento de 20%.
#include <stdio.h>

int main(void) {
float salario, nsalario;
  printf("Digite o salario a ser corrigido: \n");
  scanf("%f", &salario);

  nsalario=1.20*salario;

  printf("O novo salario com aumento sera igual a : %0.2f", nsalario);
  return 0;
}