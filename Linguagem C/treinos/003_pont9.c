#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro
{
    char nome;
    long int matricula;
    int dia, mes, ano;


}cadastro;

int main()
{
    int n;
    int i;
    scanf("%d", &n);

    struct cadastro *aluno = (struct cadastro*)malloc(n*sizeof(struct cadastro));
    for(i = 0; i < n; i++)
    {
        printf("Aluno: %d\n", i+1);
        printf("Digite a matricula: %ld\n");
        scanf("%ld\n", aluno[i].matricula);

        printf("Digite o nome do aluno: %ld\n");
        scanf(" %[^\n]", aluno[i].nome);

        printf("Digite a data de nascimento do aluno: %ld\n");
        scanf(" %d/%d/%d", aluno[i].dia,aluno[i].mes,aluno[i].ano); 
    }

    //Encontrar aluno mais velho e mais novo usando ponteiros
    //O primeiro aluno inicializado como mais novo e mais velho ao mesmo tempo

    struct cadastro *maisvelho = &aluno[0];
    struct cadastro *maisnovo = &aluno[0];

    for(i=1; i < n; i++)
    {
        if(aluno[i].ano<maisvelho->ano || 
        aluno[i].ano == maisvelho->ano && aluno[i].mes < maisvelho->mes||
        aluno[i].mes == maisvelho->mes && aluno[i].dia < maisvelho->dia)
        {
            maisvelho = &aluno[i];
        }
    }
    for(i=1; i < n; i++)
    {
        if(aluno[i].ano>maisvelho->ano || 
        aluno[i].ano == maisvelho->ano && aluno[i].mes > maisvelho->mes||
        aluno[i].mes == maisvelho->mes && aluno[i].dia > maisvelho->dia)
        {
            maisnovo = &aluno[i];
        }
    }
    printf("\nAluno mais velho:\n");
    printf("Nome: %s\n", maisvelho->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", maisvelho->dia, maisvelho->mes, maisvelho->ano);

    printf("\nAluno mais novo:\n");
    printf("Nome: %s\n", maisnovo->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", maisnovo->dia, maisnovo->mes, maisnovo->ano);

    // Liberar a memória alocada para o vetor dinâmico
    free(aluno);

    return 0;
}