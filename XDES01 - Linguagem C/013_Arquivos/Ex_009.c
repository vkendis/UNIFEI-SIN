/*9) Crie um programa que leia o arquivo binário criado no Exercício 8 e armazene cada livro cadastrado em
vetor de estrutura. Ao final, mostre todo o conteúdo do vetor.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[100];
    char autor[100];
    int numPaginas;
    int anoPublicacao;
} Livro;

int main()
{
    Livro livros[100]; // Vetor de estrutura para armazenar os livros
    int numLivros = 0; // Contador para o número de livros cadastrados

    // Abrir o arquivo binário para leitura
    FILE *arquivo = fopen("livros.bin", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler os dados dos livros do arquivo
    while (fread(&livros[numLivros], sizeof(Livro), 1, arquivo) == 1)
    {
        numLivros++;
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Exibir todo o conteúdo do vetor de livros
    for (int i = 0; i < numLivros; i++)
    {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Número de páginas: %d\n", livros[i].numPaginas);
        printf("Ano de publicação: %d\n", livros[i].anoPublicacao);
        printf("\n");
    }

    return 0;
}
