//1) Faça um programa que leia uma frase e conte quantas vogais a frase possui no total.
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[20];
    int i;
    int contavogal = 0;
    int tam;

    scanf(" %[^\n]", palavra);

    tam = strlen(palavra);

    for (i = 0; i < tam; i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
        {
            contavogal++;
        }
    }

    printf("%d\n", contavogal);

    return 0;
}