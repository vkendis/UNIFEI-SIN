/*2) Dado um arquivo contendo um conjunto de nome e data de nascimento (DD/MM/AAAA, isto é, 3
inteiros em sequência), faça um programa que leia o nome do arquivo e a data de hoje e construa outro
arquivo contendo o nome e a idade de cada pessoa do primeiro arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int dia, mes, ano;
} Pessoa;

int calcularIdade(int diaAtual, int mesAtual, int anoAtual, int diaNascimento, int mesNascimento, int anoNascimento)
{
    int idade = anoAtual - anoNascimento;

    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento))
    {
        idade--;
    }

    return idade;
}

int main()
{
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];
    char dataAtual[11];
    int diaAtual, mesAtual, anoAtual;

    // Ler nome do arquivo de entrada
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    // Ler data atual
    printf("Digite a data atual (DD/MM/AAAA): ");
    scanf("%s", dataAtual);
    sscanf(dataAtual, "%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);

    // Abrir arquivo de entrada
    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoEntrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Ler pessoas do arquivo de entrada
    Pessoa pessoas[100];
    int numPessoas = 0;
    while (fscanf(arquivoEntrada, "%s %d/%d/%d", pessoas[numPessoas].nome, &pessoas[numPessoas].dia, &pessoas[numPessoas].mes, &pessoas[numPessoas].ano) == 4)
    {
        numPessoas++;
    }

    // Fechar arquivo de entrada
    fclose(arquivoEntrada);

    // Criar arquivo de saída
    strcpy(nomeArquivoSaida, "idades.txt");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");
    if (arquivoSaida == NULL)
    {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    // Escrever nomes e idades no arquivo de saída
    for (int i = 0; i < numPessoas; i++)
    {
        int idade = calcularIdade(diaAtual, mesAtual, anoAtual, pessoas[i].dia, pessoas[i].mes, pessoas[i].ano);
        fprintf(arquivoSaida, "Nome: %s | Idade: %d\n", pessoas[i].nome, idade);
    }

    // Fechar arquivo de saída
    fclose(arquivoSaida);

    printf("Arquivo de saída criado com sucesso.\n");

    return 0;
}
