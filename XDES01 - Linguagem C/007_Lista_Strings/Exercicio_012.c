//12) Faça um programa que leia uma frase (string) contendo 4 valores numéricos reais de precisão dupla
//(double), separados por espaços. A seguir, seu programa deve separar cada número dos demais, convertê-lo
//para o formato numérico e exibir a soma dos números.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
    char numeros[100];
    double soma = 0.0;
    double num[4];
    int i,j=0;
    int tamanho;
    scanf("%[^\n]", numeros);

    tamanho = strlen(numeros);
    for(i=0;i<tamanho;i++)
      {
        if(numeros[i] != ' ') 
          {
            num[j] = atof(&numeros[i]);
            soma += num[j];
            j++;

            while (numeros[i] != ' ' && numeros[i] != '\0') 
            {
              i++;
            }  
          }
      }
   
    printf("A soma dos números é: %.6lf\n", soma);
    return 0;
}