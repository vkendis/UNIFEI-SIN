/*1) Faça um programa que leia o nome de um arquivo de entrada e outro de saída. O arquivo de entrada
contém em cada linha o nome de uma cidade (ocupando 40 caracteres) e o seu número de habitantes. O
programa deverá ler o arquivo de entrada e gerar um arquivo de saída onde aparece o nome da cidade mais
populosa seguida pelo seu número de habitantes.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 41

typedef struct {
    char nome[MAX_NOME];
    int habitantes;
} Cidade;

void lerCidades(FILE *arquivo, Cidade cidades[], int *numCidades);
void escreverCidadeMaisPopulosa(FILE *arquivo, Cidade cidades[], int numCidades);

int main()
{
    char nomeArquivoEntrada[MAX_NOME];
    char nomeArquivoSaida[MAX_NOME];
    FILE *arquivoEntrada;
    FILE *arquivoSaida;
    Cidade cidades[100];
    int numCidades = 0;

    // Ler nomes dos arquivos de entrada e saída
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%40s", nomeArquivoEntrada);
    printf("Digite o nome do arquivo de saída: ");
    scanf("%40s", nomeArquivoSaida);

    // Abrir arquivo de entrada
    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Ler cidades do arquivo de entrada
    lerCidades(arquivoEntrada, cidades, &numCidades);

    // Fechar arquivo de entrada
    fclose(arquivoEntrada);

    // Abrir arquivo de saída
    arquivoSaida = fopen(nomeArquivoSaida, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Escrever cidade mais populosa no arquivo de saída
    escreverCidadeMaisPopulosa(arquivoSaida, cidades, numCidades);

    // Fechar arquivo de saída
    fclose(arquivoSaida);

    printf("Processamento concluído. Verifique o arquivo de saída.\n");

    return 0;
}

void lerCidades(FILE *arquivo, Cidade cidades[], int *numCidades)
{
    char linha[MAX_NOME + 10];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%40s %d", cidades[*numCidades].nome, &cidades[*numCidades].habitantes) == 2) {
            (*numCidades)++;
        }
    }
}

void escreverCidadeMaisPopulosa(FILE *arquivo, Cidade cidades[], int numCidades)
{
    int i;
    int indiceMaisPopulosa = 0;
    for (i = 1; i < numCidades; i++) {
        if (cidades[i].habitantes > cidades[indiceMaisPopulosa].habitantes) {
            indiceMaisPopulosa = i;
        }
    }
    fprintf(arquivo, "Cidade mais populosa: %s\n", cidades[indiceMaisPopulosa].nome);
    fprintf(arquivo, "Número de habitantes: %d\n", cidades[indiceMaisPopulosa].habitantes);
}
