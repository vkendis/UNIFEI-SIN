/*7) Crie um programa que leia o arquivo binário criado no Exercício 6, calcule e exiba o nome do atleta mais
velho e o nome do atleta mais alto.*/

#include <stdio.h>

typedef struct {
    char nome[100];
    char esporte[100];
    int idade;
    float altura;
} Atleta;

int main()
{
    Atleta atletas[5];

    // Abrir o arquivo binário para leitura
    FILE *arquivo = fopen("atletas.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler os dados dos atletas do arquivo binário
    fread(atletas, sizeof(Atleta), 5, arquivo);

    // Fechar o arquivo
    fclose(arquivo);

    // Inicializar variáveis para o atleta mais velho e mais alto
    int idadeMaisVelho = atletas[0].idade;
    float alturaMaisAlta = atletas[0].altura;
    char nomeMaisVelho[100];
    char nomeMaisAlto[100];

    // Encontrar o atleta mais velho e mais alto
    for (int i = 1; i < 5; i++) {
        if (atletas[i].idade > idadeMaisVelho) {
            idadeMaisVelho = atletas[i].idade;
            strcpy(nomeMaisVelho, atletas[i].nome);
        }

        if (atletas[i].altura > alturaMaisAlta) {
            alturaMaisAlta = atletas[i].altura;
            strcpy(nomeMaisAlto, atletas[i].nome);
        }
    }

    // Exibir o nome do atleta mais velho e mais alto
    printf("Atleta mais velho: %s\n", nomeMaisVelho);
    printf("Atleta mais alto: %s\n", nomeMaisAlto);

    return 0;
}
