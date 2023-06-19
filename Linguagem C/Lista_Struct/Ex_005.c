/*5) Utilizando um vetor de estrutura, faça um programa que leia o nome e o telefone de 5 pessoas e os
imprima em ordem alfabética pelo nome. Dica: pesquise os detalhes de uso da função strcmp().*/
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[100];
    char telefone[100];
} Pessoa;

int main() {
    int i, j;
    Pessoa pessoas[5];

    for (i = 0; i < 5; i++) 
    {
       
        scanf(" %[^\n]", pessoas[i].nome);
        scanf(" %[^\n]", pessoas[i].telefone);
    }

    for (i = 0; i < 4; i++) 
    {
        for (j = i + 1; j < 5; j++) 
        {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) 
            {
                Pessoa temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
    for (i = 0; i < 5; i++) 
    {
        printf("%s %s\n", pessoas[i].nome, pessoas[i].telefone);
    }

    return 0;
}