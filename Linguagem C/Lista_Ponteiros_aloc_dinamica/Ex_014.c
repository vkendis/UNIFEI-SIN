/*14) Faça um programa que declare uma estrutura para o cadastro de N alunos, onde o usuário informa N.
Armazene as seguintes informações sobre os alunos: matrícula, nome completo e data de nascimento.
Usando aritmética de ponteiros, leia as informações de N alunos e, a seguir, mostre o nome do aluno mais
velho e do aluno mais novo.
*/
#include <stdio.h>
struct Aluno
{
    long int matricula;
    char nome[100];
    int dia, mes, ano;
};
int main()
{
    int n;
    int i;
    
    printf("Digite o numero de alunos que deseja cadastrar: ");
    scanf("%d", &n);
    
    struct Aluno *alunos= (struct Aluno*)malloc(n * sizeof(struct Aluno));

    for(i=0; i<n; i++)
    {
        printf("Aluno %d: ", i+1 );
        printf("Digite a matricula:");
        scanf("%ld", &alunos[i].matricula);

        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]s", alunos[i].nome);

        printf("Digite a data de nascimento: ");
        scanf("%d %d %d", &alunos[i].dia, &alunos[i].mes, &alunos[i].ano );
    }

     // Encontrar o aluno mais velho e o aluno mais novo usando ponteiros
    struct Aluno *mais_velho = alunos;
    struct Aluno *mais_novo = alunos;
    /*Nesta parte, iniciei com i=1 ja que o primeiro aluno seria parametro de comparacao com os demais a seguir. 
    Feito isso e necessario fazer as seguintes condicoes: 
    - Ano ser menor 
    - Ano ser igual mas mes menor 
    - Ano ser igual, mes ser igual mas dia ser menor
    - --> Assim mais velho recebe o proximo da lista */
    
    for (int i = 1; i < n; i++) {
        if (alunos[i].ano < mais_velho->ano || 
            (alunos[i].ano == mais_velho->ano && alunos[i].mes < mais_velho->mes) || 
            (alunos[i].ano == mais_velho->ano && alunos[i].mes == mais_velho->mes && alunos[i].dia < mais_velho->dia)) {
            mais_velho = &alunos[i];
        }

        if (alunos[i].ano > mais_novo->ano || 
            (alunos[i].ano == mais_novo->ano && alunos[i].mes > mais_novo->mes) || 
            (alunos[i].ano == mais_novo->ano && alunos[i].mes == mais_novo->mes && alunos[i].dia > mais_novo->dia)) {
            mais_novo = &alunos[i];
        }
    }

    // Mostrar o nome do aluno mais velho e do aluno mais novo
    printf("\nAluno mais velho:\n");
    printf("Nome: %s\n", mais_velho->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", mais_velho->dia, mais_velho->mes, mais_velho->ano);

    printf("\nAluno mais novo:\n");
    printf("Nome: %s\n", mais_novo->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", mais_novo->dia, mais_novo->mes, mais_novo->ano);

    // Liberar a memória alocada para o vetor dinâmico
    free(alunos);

    return 0;
}


