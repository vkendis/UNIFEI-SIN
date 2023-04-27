//9) Um aluno deseja saber qual a porcentagem de faltas que ele tem em uma disciplina. Faça um programa que leia a carga horária total da disciplina e a quantidade de horas de faltas acumuladas, e mostre a porcentagem de faltas do aluno (entre 0 a 100).


#include <stdio.h>

int main(void) {
float horas, faltas, porcentagem;

  printf("Digite as horas totais e as faltas na disciplina: \n");
  scanf(" %f %f ", &horas, &faltas);

porcentagem = (faltas/horas)*100;
  printf("A porcentagem de horas de faltas na disciplina e igual a % 0.2f %% \n", porcentagem);
  return 0;
}