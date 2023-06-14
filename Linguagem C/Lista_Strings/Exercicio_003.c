//3) Faça um programa que leia uma frase e conte quantos espaços existem na frase.
#include <stdio.h>
#include <string.h>
int main ()
{
char palavra[100];
int i;
int contaspace=0;
int tam;

scanf(" %[^\n]", palavra);
tam=strlen(palavra);
for(i=0;i<tam;i++)
    {
        if(palavra[i] == ' ')
        {
            contaspace++;
        }
    }
printf("%d", contaspace);

return 0;    
}