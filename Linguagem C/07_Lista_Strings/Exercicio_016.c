//16) Faça um programa que receba uma frase e converta a primeira letra de cada palavra para maiúscula.
#include <stdio.h>
#include <ctype.h>

int main() {
    char frase[100];

    scanf("%[^\n]%*c", frase);

    frase[0] = toupper(frase[0]);

    for (int i = 1; frase[i] != '\0'; i++) 
    {
       if (frase[i] == ' ') 
        {
            frase[i + 1] = toupper(frase[i + 1]);
        }
    }

    printf("%s\n", frase);

    return 0;
}