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
    int posimaior;
    int posimenor;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < 10; i++)
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
    printf("%d ", posimaior);
    printf("%d", posimenor);


return 0;    
}