//8) Faça um programa que leia uma frase F e dois inteiros I e J. A seguir, imprima os caracteres das posições
//que vão de I até J, inclusive.
#include <stdio.h>
#include <string.h>

int main() 
{
    char frase[50];
    int i, j;
    int tamanho;
    int v;
  
    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    printf("Digite dois números inteiros (i e j): ");
    scanf("%d %d", &i, &j);

    tamanho = strlen(frase);

    if (i >= 0 && j < tamanho && i <= j) {
        for (v = i; v <= j; v++) {
            printf("%c", frase[v]);
        }
        printf("\n");
    } else {
        return 0;
    }

    return 0;
}



    

