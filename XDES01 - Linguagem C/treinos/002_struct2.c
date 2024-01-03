#include <stdio.h>

typedef struct 
{
    long int matricula;
    char nome[500];
    float n1;
    float n2;
    float n3;
} cadastro;

int main()
{
    int i;
    cadastro aluno[2];

    for (i = 0; i < 2; i++)
    {
        printf("Digite o nome do aluno: \n");
        scanf(" %[^\n]", aluno[i].nome);
        
        printf("Digite a matricula do aluno: \n");
        scanf("%ld", &aluno[i].matricula);

        printf("Digite as notas do aluno: \n");
        scanf("%f %f %f", &aluno[i].n1, &aluno[i].n2, &aluno[i].n3);
    }

    float maiorn1 = 0;
    int indicemaior = 0;

    for (i = 0; i < 2; i++)
    {
        if (aluno[i].n1 > maiorn1)
        {
            maiorn1 = aluno[i].n1;
            indicemaior = i;
        }
    }

    printf("Aluno com maior nota na primeira prova: %s\n", aluno[indicemaior].nome);
    printf("Maior nota: %.2f\n\n", maiorn1);

    int indicemaiormedia = 0;
    float maiormedia = 0;

    for (i = 0; i < 2; i++)
    {
        float media = (aluno[i].n1 + aluno[i].n2 + aluno[i].n3) / 3;
        if (media > maiormedia)
        {
            maiormedia = media;
            indicemaiormedia = i;
        }
    }

    printf("Aluno com maior média: %s\n", aluno[indicemaiormedia].nome);
    printf("Média: %.2f\n\n", (aluno[indicemaiormedia].n1 + aluno[indicemaiormedia].n2 + aluno[indicemaiormedia].n3) / 3);

    for (i = 0; i < 2; i++)
    {
        float media = (aluno[i].n1 + aluno[i].n2 + aluno[i].n3) / 3;
        if (media >= 6.0)
        {
            printf("O aluno %s foi aprovado com média %.2f!\n", aluno[i].nome, media);
        }
        else
        {
            printf("O aluno %s não foi aprovado e teve média %.2f!\n", aluno[i].nome, media);
        }
    }
    
    return 0;
}
