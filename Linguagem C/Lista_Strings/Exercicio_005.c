//5) Faça um programa que leia uma frase e a copie para outro vetor, removendo os espaços em branco.
//Imprima o segundo vetor.
#include <stdio.h>
#include <string.h>

int main() 
{
    char frase[50];
    char refrase[50];
    int tamanho, i, j = 0;

    scanf("%[^\n]s", frase);

    tamanho = strlen(frase);

    for (i = 0; i < tamanho; i++) 
    {
        if (frase[i] != ' ') 
        {
            refrase[j] = frase[i];
            j++;
        }
    }

    refrase[j] = '\0';

    printf("%s\n", refrase);

    return 0;
}