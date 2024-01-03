#include <stdio.h>

int maxvet(int *vet, int n);

int main()
{
    int n;
    int i;
    
    printf("Digite um numero para n: ");
    scanf("%d", &n);
    
    int vet[n];
    int maiorelemento;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    maiorelemento = maxvet(vet, n);
    printf("%d\n", maiorelemento);

    return 0;    
}

int maxvet(int *vet, int n)
{
    int i;
    int maior = vet[0];

    for(i = 0; i < n; i++)
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
        }
    }

    return maior;
}
