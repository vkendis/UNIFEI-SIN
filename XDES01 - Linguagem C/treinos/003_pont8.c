//Alocacao dinamica e print de pares e impares dentro do vetor alocado dinamicamente
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    int i;

    printf("Digite o valor para n: ");
    scanf("%d", &n);
    
    int *vet = (int*)malloc(n*sizeof(int));
    
    for(i = 0; i < n; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
        
    }
    printf("Numeros pares: ");
    for(i = 0; i < n; i++)
    {
        
        if(vet[i] % 2 == 0)
        {
            printf("%d ", vet[i]);
        }
    }
    printf("\n");
    printf("Numeros impares: ");
    for(i = 0; i < n; i++)
    {
        if(vet[i] % 2 != 0)
        {
            printf("%d ", vet[i]);
        }
    }
return 0;    
}