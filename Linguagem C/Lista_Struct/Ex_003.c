/*3) Crie uma estrutura representando os dados de um aluno: matrícula, nome, nota da primeira prova, nota da
segunda prova e nota da terceira prova. A seguir: a) entre com os dados de 5 alunos. b) encontre o aluno
com maior nota na primeira prova, imprimindo seu nome completo e a nota, com 2 casas decimais. c)
encontre o aluno com maior média geral, imprimindo seu nome completo, seguido da média, com 2 casas
decimais. d) imprima uma listagem de matrícula e nome, dizendo também se cada aluno foi aprovado ou
reprovado, considerando ao menos 60% de média para a aprovação.*/
#include <stdio.h>

typedef struct 
{
  char nome[100];
  long int matricula;
  float nota1;
  float nota2;
  float nota3;
}aluno;
int main()
{
  int i;
  aluno pessoas[5];
  float media, maiormedia=0;
  int indicemedia=0;
  int indicemaiorn1=0;

    for(i=0;i<5;i++)
    {
        scanf("%ld", &pessoas[i].matricula);
        scanf(" %[^\n]", pessoas[i].nome);
        scanf("%f %f %f", &pessoas[i].nota1, &pessoas[i].nota2, &pessoas[i].nota3);
    }
    for(i = 1; i < 5; i++) 
        {
            if(pessoas[i].nota1 > pessoas[indicemaiorn1].nota1) 
                {
                    indicemaiorn1 = i;
                }        
        }

    maiormedia=(pessoas[0].nota1 + pessoas[0].nota2 + pessoas[0].nota3) / 3;
    for(i=0;i<5;i++)
        {
            media= (pessoas[i].nota1 + pessoas[i].nota2 + pessoas[i].nota3) / 3;
            if(media>maiormedia)
            {
                maiormedia = media;
                indicemedia = i;
            }
    }
printf("Maior nota na P1: %.2f\n", pessoas[indicemaiorn1].nota1);
printf("%s\n\n", pessoas[indicemaiorn1].nome);
printf("Maior media: %s\n", pessoas[indicemedia].nome);
printf("Valor: %.2f\n\n", (pessoas[indicemedia].nota1 + pessoas[indicemedia].nota2 + pessoas[indicemedia].nota3) / 3);

for(i = 0; i < 5; i++) {
        media = (pessoas[i].nota1 + pessoas[i].nota2 + pessoas[i].nota3) / 3;
        printf("%ld %s ", pessoas[i].matricula, pessoas[i].nome);
        
        if(media >= 6.0) {
            printf("Aprovado");
        } else {
            printf("Reprovado");
        }
        printf("\n");
    }

    return 0;
}