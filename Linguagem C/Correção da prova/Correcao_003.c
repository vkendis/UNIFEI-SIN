//Escreva, em linguagem C pura, um programa que leia valores inteiros indefinidamente e armazene, em um vetor de 5 posições, apenas os números primos digitados. Seu programa deve
//parar de ler números quando o vetor estiver totalmente preenchido. Imprima, como resposta, os elementos do vetor, em uma única linha, separados entre si por um único espaço. 
//Um número primo é aquele que possui apenas dois divisores naturais: 1 e ele mesmo.

// 1 2 3 4 5 6 7 8 9 10 11 >>> 2 3 5 7 11

#include <stdio.h>

// Funcao principal
int main()
{
    int vet[5];
    int i = 0;
    int n;
    int div;
    int j;

    // Leitura do vetor
    while (i < 5)
    {
        scanf("%d", &n);
        div = 0;
        
        for (j = 1; j <= n; j++)
        {
            if (n % j == 0)
            {
                div++;
            }
        }

        if (div == 2)
        {
            vet[i] = n;
            i++;
        }
    }

    // Impressão dos elementos do vetor
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}