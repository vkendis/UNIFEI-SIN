/*15) Faça uma função que receba um vet de inteiros, seu tam (n) e duas variáveis inteiras. Armazene
nessas variáveis o valor mínimo e máximo do vet. O main deve ler n, ler o vetor, chamar a função e
imprimir o menor valor separado do maior por um único espaço. Use apenas aritmética de ponteiros, isto é,
faça este programa sem usar colchetes. no Moodle, insira seu programa completo (main + funções).*/
#include <stdio.h>

void minmax(int* vet, int tam, int* min, int* max)
{
    int i;
    *min = *max = *vet; // Inicializa min e max com o primeiro elemento do vet

    for (i = 1; i < tam; i++)
    {
        if (*(vet + i) < *min) // Compara o elemento atual com o valor mínimo atual
        {
            *min = *(vet + i); // Atualiza o valor mínimo
        }

        if (*(vet + i) > *max) // Compara o elemento atual com o valor máximo atual
        {
            *max = *(vet + i); // Atualiza o valor máximo
        }
    }
}

int main()
{
    int n;
   
    scanf("%d", &n);

    int vetor[n];
    int i;

    
    for (i = 0; i < n; i++)
    {
        scanf("%d", vetor + i); // Lê os elementos do vetor
    }

    int min, max;
    minmax(vetor, n, &min, &max); // Chama a função para encontrar o mínimo e máximo

    printf("Mínimo e máximo: %d %d\n", min, max);

    return 0;
}