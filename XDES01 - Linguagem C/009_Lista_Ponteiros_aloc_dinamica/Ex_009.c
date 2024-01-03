/*9) Faça um programa usando ponteiros para ordenar 5 números armazenados em um vetor e mostrá-los
ordenados na tela.
*/
#include <stdio.h>

int main() {
    int vetor[5];
    int *ptr = vetor;

    // Leitura dos valores e armazenamento no vetor
    printf("Digite %d números:\n", 5);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    // Ordenação dos números usando o algoritmo Bubble Sort com ponteiros
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    // Exibição dos números ordenados
    printf("Números ordenados: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}