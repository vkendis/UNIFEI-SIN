/*3) Crie um programa que receba como entrada o número de alunos de uma disciplina. Aloque
dinamicamente dois vetores para armazenar as informações a respeito desses alunos. O primeiro vetor
contém o nome dos alunos e o segundo contém suas notas finais. Crie um arquivo que armazene, a cada
linha, o nome do aluno e sua nota final. Use nomes com no máximo 40 caracteres.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 41

typedef struct {
    char nome[MAX_NOME];
    float notaFinal;
} Aluno;

int main()
{
    int numAlunos;
    printf("Digite o número de alunos da disciplina: ");
    scanf("%d", &numAlunos);

    // Alocação dinâmica dos vetores de alunos
    Aluno *alunos = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Leitura dos nomes e notas dos alunos
    for (int i = 0; i < numAlunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%40s", alunos[i].nome);

        printf("Digite a nota final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notaFinal);
    }

    // Criação do arquivo
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // Escrita dos nomes e notas no arquivo
    for (int i = 0; i < numAlunos; i++) {
        fprintf(arquivo, "%s %.2f\n", alunos[i].nome, alunos[i].notaFinal);
    }

    // Fechamento do arquivo
    fclose(arquivo);

    // Liberação da memória alocada
    free(alunos);

    printf("Arquivo 'alunos.txt' criado com sucesso.\n");

    return 0;
}
