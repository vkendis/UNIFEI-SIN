//9) Faça um programa que leia uma frase F, um caractere C e um inteiro I. Seu programa deve devolver o
//índice da primeira posição da string onde foi encontrado o caractere C, sendo que a procura começa a partir
//da posição I. Caso o caractere buscado não exista, imprima –1.
#include <stdio.h>
#include <string.h>

int main() {
    char frase[50];
    char caractere;
    int indice;
    int tamanho;

    scanf(" %[^\n]", frase);
    scanf(" %c", &caractere);
    scanf(" %d", &indice);

    tamanho = strlen(frase);

    if (indice >= 0 && indice < tamanho) {
        int i;
        for (i = indice; i < tamanho; i++) {
            if (frase[i] == caractere) {
                printf("%d\n", i);
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}