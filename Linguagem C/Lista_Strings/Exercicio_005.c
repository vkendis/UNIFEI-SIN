//) Faça um programa que leia uma frase e a copie para outro vetor, removendo os espaços em branco.
//Imprima o segundo vetor.

#include <stdio.h>
#include <string.h>

int main() {
    char frase[50];
    char refrase[50];
    int tamanho, i;

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    

    printf("Frase invertida: ");
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%c", frase[i]);
    }

    return 0;
}