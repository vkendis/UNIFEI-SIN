#include <stdio.h>

int main() 
{
    int vet[10];
    int *pvet[10];
    int i;
    //Leitura do vetor
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }
    //Fazer com que o ponteiro aponte para a memoria a cada iteracao e printe os enderecos com valores.
    printf("*****Imprimir o endereco e conteudo de cada espaco: *****\n");
    for(i = 0; i < 10; i++)
    {
        pvet[i] = &vet[i];

        printf("O endereco de numero %d e igual a: %p e contem: %d \n", i+1, pvet[i], *pvet[i]);
    }
    
    return 0;
}
