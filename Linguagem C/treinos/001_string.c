#include <stdio.h>
#include <string.h>
//Codigo para printar o que foi lido.
//Codigo para printar a frase invertida
//Encontrar vogais
//Remover os espacos em branco
//Verificar Palindromo
int main ()
{
    
    int n;
    int tam;
    int i,j=0, z=0;
    char frase[500];
    char inverte[500];
    char espaco[500];
    int contavogal=0;
    int palindromo=0;

    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    tam = strlen(frase);

    //Codigo para printar o que foi lido.
    printf("Frase lida: %s\n", frase);

    //Codigo para printar a frase invertida

    for(i=tam-1;i>=0;i--)
        {
            inverte[j] = frase[i];
            j++;
        }
    inverte[j] = '\0';

    printf("Frase invertida: %s\n", inverte);
    // Encontrar vogais
    
    for(i=0;i<tam;i++)
        {
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
        contavogal++;
        }
    printf("Quantidade de vogais: %d\n", contavogal);

    // Remover os espacos em branco
    for(i=0;i<tam;i++)
        {
            if(frase[i] != ' ')
            {
                espaco[z] = frase[i];
                z++;
            }
        }
        espaco[z] = '\0';
    
    printf("Frase sem espacos: %s\n", espaco);
   
    // Verificar Palindromo
    if(strcmp(frase,inverte) == 0)
    {
        palindromo = 1;
    }
    if(palindromo)
    {
        printf("Palindromo\n");
    }else 
    {
         printf("Nao Palindromo\n");
    }

    //Verificar o tamanho de uma string A ou B

    char palavra1[500];
    char palavra2[500];
    int tamp1=0;
    int tamp2=0;
    int diftam=0;

    printf("Digite uma frase 1: ");
    scanf(" %[^\n]", palavra1);
    
    printf("Digite uma frase 2: ");
    scanf(" %[^\n]", palavra2);

    tamp1 = strlen(palavra1);
    tamp2 = strlen(palavra2);

    diftam = tamp1-tamp2;

    printf("A frase 1 possui %d a mais/menos que a frase 2\n", diftam);


    return 0;
}