/*2) Crie uma estrutura para armazenar os dados de um aluno: nome, número de matrícula e curso. Leia as
informações de 5 alunos e armazene em um vetor dessa estrutura. A seguir, imprima os dados de todos os
alunos na tela. Siga o formato de saída mostrado no Moodle.*/
#include <stdio.h>

typedef struct 
{
  char nome[100];
  long int matricula;
  char curso[50];
}aluno;
int main()
{
  int i;
  aluno pessoas[5];

  for(i=0;i<5;i++)
    {
      scanf(" %[^\n]", pessoas[i].nome);
      scanf("%ld", &pessoas[i].matricula);
      scanf(" %[^\n]", pessoas[i].curso);
      
    }
for(i=0;i<5;i++)
  {
    printf("Aluno %d:\n", i+1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Matricula: %ld\n", pessoas[i].matricula);
    printf("Curso: %s\n\n", pessoas[i].curso);
  }
    return 0;
}