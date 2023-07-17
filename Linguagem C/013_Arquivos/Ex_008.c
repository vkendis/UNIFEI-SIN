/*8) Crie uma estrutura para representar livros. Cada livro possui um título, autor, número de páginas e ano de
publicação. Leia, indefinidamente, os dados de vários livros (até que o usuário digite “sair” como título) e os
armazene em um arquivo binário. A seguir, solicite ao usuário um número N e exiba as informações do nésimo livro 
armazenado no arquivo, até que o usuário digite um valor de N menor ou igual a zero.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int numPaginas;
    int anoPublicacao;
} Livro;

int main()
{
    Livro livro;
    int n;

    // Abrir o arquivo binário para escrita
    FILE *arquivo = fopen("livros.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler os dados dos livros e armazenar no arquivo
    while (1) {
        printf("Digite o título do livro (ou 'sair' para encerrar): ");
        fgets(livro.titulo, sizeof(livro.titulo), stdin);
        livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

        if (strcmp(livro.titulo, "sair") == 0) {
            break;
        }

        printf("Digite o autor do livro: ");
        fgets(livro.autor, sizeof(livro.autor), stdin);
        livro.autor[strcspn(livro.autor, "\n")] = '\0';

        printf("Digite o número de páginas do livro: ");
        scanf("%d", &livro.numPaginas);

        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &livro.anoPublicacao);
        getchar();  // Consumir o caractere '\n' deixado pelo scanf

        fwrite(&livro, sizeof(Livro), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Abrir o arquivo binário para leitura
    arquivo = fopen("livros.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Solicitar o número N e exibir as informações do N-ésimo livro
    while (1) {
        printf("Digite o número N (ou um valor menor ou igual a zero para encerrar): ");
        scanf("%d", &n);

        if (n <= 0) {
            break;
        }

        // Posicionar o cursor no registro desejado
        fseek(arquivo, (n - 1) * sizeof(Livro), SEEK_SET);

        // Ler as informações do N-ésimo livro
        fread(&livro, sizeof(Livro), 1, arquivo);

        // Exibir as informações do N-ésimo livro
        printf("Título: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Número de páginas: %d\n", livro.numPaginas);
        printf("Ano de publicação: %d\n", livro.anoPublicacao);
    }

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}
