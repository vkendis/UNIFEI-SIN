//15) Faça um programa que receba uma frase e mostre a quantidade de palavras digitadas na frase.
#include <stdio.h>
int main ()
{
    char frase[200];
    int contaespace = 0;
    int i = 1; // Inicializa com 1 para considerar o caso de frase vazia

    scanf(" %[^\n]", frase);

    while (frase[i] != '\0') {
        if (frase[i] == ' ') {
            contaespace++;
        }
        i++;
    }

    printf("%d\n", contaespace + 1);

    return 0;
}