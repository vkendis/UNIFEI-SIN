//Faça um programa que leia uma frase e conte quantos espaços existem na frase.

#include <stdio.h>
#include <ctype.h>

int main ()
{
    char frase[30];
    char lower;
    int contaspace=0;
    int i;

    scanf("%[^\n]", frase);

    for(i=0; i<frase[i]; i++)
        {
            lower=tolower(frase[i]);
            if(lower == ' ')
                {
                    contaspace++;
                }
        }
    printf("%d\n", contaspace);
return 0;
}