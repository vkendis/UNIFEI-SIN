#include <string.h>
#include <stdio.h>

int main ()
{
    char frase[500];
    int indice=0;
    char caractere;
    int tamanho;
    

    scanf(" %[^\n]", frase);
    scanf(" %c", &caractere);
    scanf("%d", &indice);

    tamanho = strlen(frase);
    if(indice>=0 && indice<tamanho)
    {
        int i;
        for(i=indice;i<tamanho;i++)
        {
            if(frase[i]== caractere)
            {
                printf("%d\n", i);
                
            }
            else
            {
                printf("-1\n");
                break;
            }
        }
    }
 


return 0;    
}