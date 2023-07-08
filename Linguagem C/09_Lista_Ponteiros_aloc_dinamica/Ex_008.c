/*8) Declare um vetor de inteiros com 10 posições, leia e armazene valores em cada posição. A seguir,
utilizando apenas ponteiros de int troque o segundo maior elemento de posição com o segundo menor
elemento*/
#include <stdio.h>

int main() {
    int vetor[10];
    int *ptr = vetor;
    
    printf("Digite %d valores inteiros:\n", 10);
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    // Bubble Sort para ordenar o vetor em ordem crescente
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    // Trocando os elementos de posição
    int temp = vetor[1];
    vetor[1] = vetor[10 - 2];
    vetor[10 - 2] = temp;

    printf("Vetor com o segundo maior e segundo menor elementos trocados: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}