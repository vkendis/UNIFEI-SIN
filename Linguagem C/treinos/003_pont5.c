#include <stdio.h>
int main ()
{
    int vet[5];
    int *pvet[5];
    int i;
    int bubble = 0;
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &vet[i]);
        pvet[i] = &vet[i];
    }
    
    for(i = 0; i < 5; i++)
    {
        bubble = *pvet[i+1];
        *pvet[i+1] = *pvet[i];
        *pvet[i] = bubble;
        break; // Como precisamo alterar somente uma vez dentro da iteracao, usamos break.
    }
    for(i = 0; i < 5; i++)
    {
       printf("%d", *pvet[i]);
    }


return 0;    
}