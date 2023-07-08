/*11) Escreva um programa que declare dois vetores de int de tamanho M e N (informados pelo usuário), leia
seus elementos e, usando apenas aritmética de ponteiros, compute e mostre: a) a união de seus elementos. b)
a interseção. c) a diferença do primeiro vetor para o segundo.*/

// Passo 1: Ler tamanho de M e N
// Passo 2: Definir vetores M e N
// Passo 3: Ler os elementos dos dois vetores
// Passo 4: a) a união de seus elementos
// Passo 5: b)a interseção
// Passo 6: c) a diferença do primeiro vetor para o segundo.

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int m, n;
    int i,j;
    //Ler M e N
    printf("Digite os valores para M e N: ");
    scanf("%d %d", &m ,&n);

    //Alocacao dinamica para vetor a e vetor b
    int* vetora = (int*)malloc(m*sizeof(int)); 
    int* vetorb = (int*)malloc(m*sizeof(int)); 

    //Ler vetores M e N
    for(i=0; i<m; i++)
    {
        scanf("%d", &vetora[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d", &vetorb[i]);
    }

    //Varredura para achar semelhantes
    int* uniao = (int*)malloc((m+n) * sizeof(int));
    int tamanho_uniao = 0;

    // Verificar e copiar elementos do vetor B para a união (ignorando repetidos)
for (i = 0; i < n; i++) {
    int isRepeated = 0;
    for (j = 0; j < tamanho_uniao; j++) {
        if (vetorb[i] == uniao[j]) {
            isRepeated = 1;
            break;
        }
    }
    if (!isRepeated) {
        uniao[tamanho_uniao++] = vetorb[i];
    }
}
     // Mostrar a união dos elementos
    printf("União dos elementos:\n");
    for (i = 0; i < tamanho_uniao; i++) {
        printf("%d ", uniao[i]);
    }
    printf("\n");
     // Interseção dos elementos
    int *intersecao = (int *)malloc((m < n ? m : n) * sizeof(int));
    int tamanho_intersecao = 0;

    // Encontrar elementos comuns em ambos vetores
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (vetora[i] == vetorb[j]) {
                intersecao[tamanho_intersecao++] = vetora[i];
                break;
            }
        }
    }

    // Mostrar a interseção dos elementos
    printf("Interseção dos elementos:\n");
    for (i = 0; i < tamanho_intersecao; i++) {
        printf("%d ", intersecao[i]);
    }
    printf("\n");

    // Diferença do primeiro vetor para o segundo
    int *diferenca = (int *)malloc(m * sizeof(int));
    int tamanho_diferenca = 0;

    // Encontrar elementos exclusivos do vetor A
    for (i = 0; i < m; i++) {
        int isPresent = 0;
        for (j = 0; j < n; j++) {
            if (vetora[i] == vetorb[j]) {
                isPresent = 1;
                break;
            }
        }
        if (!isPresent) {
            diferenca[tamanho_diferenca++] = vetora[i];
        }
    }

    // Mostrar a diferença do primeiro vetor para o segundo
    printf("Diferença do primeiro vetor para o segundo:\n");
    for (i = 0; i < tamanho_diferenca; i++) {
        printf("%d ", diferenca[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(vetora);
    free(vetorb);
    free(uniao);
    free(intersecao);
    free(diferenca);

    return 0;
}
