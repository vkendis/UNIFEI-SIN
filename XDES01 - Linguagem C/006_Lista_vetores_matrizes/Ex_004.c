//Faça um programa que leia um vetor de inteiros de 12 posições. 
//A seguir, mostre quantos números pares e quantos números ímpares estão presentes no vetor. 
//Imprima as respostas em uma única linha, separadas entre si por um único espaço.
#include <stdio.h>
int main ()
{   
    int vet[12];
    int i;
    int contapar=0;
    int contaimpar=0;

    for(i=0; i<12; i++)
    {
        scanf("%d", &vet[i]);
    }

    for(i=0; i<12; i++)
    {
       if(vet[i] % 2 == 0)
       {
        contapar++;        
       }
        else
        {
            contaimpar++;
        }
    }
        printf("%d %d", contapar, contaimpar);

return 0;    
}