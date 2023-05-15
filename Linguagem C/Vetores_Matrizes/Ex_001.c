//1) Faça um programa que leia um vetor de char com 8 posições e, a seguir, mostre os valores lidos em
//ordem inversa.
#include <stdio.h>

int main() {
    char vetor[8];
    int i;

    for (i = 0; i < 8; i++) {
        scanf(" %c", &vetor[i]);
    }
    for (i = 7; i >= 0; i--) {
        printf("%c ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}