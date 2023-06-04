//Faça um programa que leia uma frase e a imprima de trás para frente.
#include <stdio.h>
#include <string.h>

int main ()
{
    char frase[50];
    int i;
    int tamanho;

    scanf("%[^\n]", frase);

    tamanho = strlen(frase);

    for(i = tamanho - 1 ; i>=0; i--)
        {
            printf("%c", frase[i]);
        }

return 0;    
}