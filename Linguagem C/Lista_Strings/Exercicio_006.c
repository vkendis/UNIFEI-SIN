//6) Faça um programa que leia uma frase e verifique se a frase é um palíndromo, ou seja, igual quando lida
//da esquerda para a direita e da direita para a esquerda. Desconsidere os espaços existentes na frase durante a
//verificação. Seu programa deve imprimir apenas “sim” ou “nao” como resposta.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char frase[100];
    char inversa[100];
    int tamanho, i, j = 0;
    int palindromo = 1; 

    scanf("%[^\n]s", frase);

    tamanho = strlen(frase);

    for (i = 0; i < tamanho; i++) {
        if (frase[i] != ' ') {
            frase[j] = tolower(frase[i]);
            j++;
        }
    }
    frase[j] = '\0';

    tamanho = strlen(frase);

    
    for (i = tamanho - 1, j = 0; i >= 0; i--, j++) {
        inversa[j] = frase[i];
    }
    inversa[j] = '\0';

    
    if (strcmp(frase, inversa) != 0) {
        palindromo = 0; 
    }

    if (palindromo) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}