//5) Faça um programa que leia um vetor de inteiros de 10 posições. A seguir, mostre quais são o maior e o
//menor elementos presentes no vetor. Na linha seguinte, imprima suas respectivas posições dentro do vetor.
//Separe os valores da resposta por um único espaço.
#include <stdio.h>
int main ()
{
    int vet[10];
    int i;
    int maior;
    int menor;
    int posimaior = 0;
    int posimenor = 0;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }

    maior = vet[0];
    menor = vet[0];
    for(i = 1; i < 10; i++)
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
            posimaior = i;
        }
        if(vet[i] < menor)
        {
            menor = vet[i];
            posimenor = i;
        }
    }
    printf("%d %d \n", maior, menor);
    printf("%d %d ", posimaior, posimenor);
    


return 0;    
}