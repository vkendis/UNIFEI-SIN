/*7) Em um vetor de estrutura, armazene as seguintes informações sobre 8 livros: título, autor e ano. A seguir,
leia o nome de um autor e mostre os títulos e anos dos livros escritos por ele. Repita o processo até que o
usuário digite “sair”.*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

int main() {
    Livro livros[8];
    int i;
    char autor[50];

    for (i = 0; i < 8; i++) 
    {
        scanf(" %[^\n]", livros[i].titulo);
        scanf(" %[^\n]", livros[i].autor);
        scanf("%d", &livros[i].ano);
    }
    scanf(" %[^\n]", autor);
    while (strcmp(autor, "sair") != 0) 
    {
        printf("Livros de %s:\n", autor);
        for (i = 0; i < 8; i++) 
        {
            if (strcmp(livros[i].autor, autor) == 0) 
            {
                printf("%s (%d)\n", livros[i].titulo, livros[i].ano);
            }
        }
        printf("\n");

        scanf(" %[^\n]", autor);
    }

    return 0;
}