//Faça um programa que leia uma frase e conte quantas vogais a frase possui no total.


#include <stdio.h>
#include <ctype.h>
int main() 
{
    char frase[30];
    char lower;
    int i;
    int contavogal=0;

    scanf(" %[^\n]", frase);  // Entrada de frase ate encontrar "\n"
    
    for(i=0;i<frase[i];i++)
    {
        lower=tolower(frase[i]);  //Variavel lower vai receber o vetor de letras minusculas 
        if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')            // Varrer o valor para encontrar vogais
            {
                contavogal++;
            }
    }
    //Teste da frase de entrada
    printf("Frase digitada: %s\n", frase);
    printf("%d\n", contavogal);
    return 0;
}