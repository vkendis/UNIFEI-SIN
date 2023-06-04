/* Modifique o programa anterior para contar a quantidade de cada vogal. Siga o formato de saída
apresentado no exemplo do Moodle.
**/
#include <stdio.h>
#include <ctype.h>
int main() 
{
    char frase[30];
    char lower;
    int i;
    int contaa=0;
    int contae=0;
    int contai=0;
    int contao=0;
    int contau=0;

    scanf(" %[^\n]", frase);  // Entrada de frase ate encontrar "\n"
    
    for(i=0;i<frase[i];i++)
    {
        lower=tolower(frase[i]);  //Variavel lower vai receber o vetor de letras minusculas 
        if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')            // Varrer o valor para encontrar vogais
            {                                                                                       // Usar if continuos para seguir a analise de todas as vogais
                contaa++;
            }
                if (lower == 'e')
                {
                    contae++;
                }
                        if ( lower == 'i')
                        {
                            contai++;
                        }
                                if ( lower == 'o')
                                {
                                    contao++;
                                }
                                    if ( lower == 'u')
                                    {
                                        contau++;
                                    }   
    }
    
    printf("%d %d %d %d %d\n", contaa, contae, contai, contao, contau);
    return 0;
}