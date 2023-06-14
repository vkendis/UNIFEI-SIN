//18) Faça um programa que receba duas palavras e as concatene em uma única frase, onde as duas palavras
//são separadas por espaço.
#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[50]; 
    char palavra2[50]; 
    char frase[100]; 

    scanf("%s", palavra1);

    scanf("%s", palavra2);

    strcpy(frase, palavra1);
    strcat(frase, " "); 
    strcat(frase, palavra2);

    printf("%s\n", frase);

    return 0;
}