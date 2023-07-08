/*12) Faça um programa que leia do usuário um número N e faça a alocação dinâmica de um vetor de N
posições. Usando aritmética de ponteiros, leia o vetor e mostre quantos dos números armazenados são pares
e quantos são ímpares.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;
    int contaimpar = 0;
    int contapar = 0;

    printf("Digite o tamanho do vetor n: ");
    scanf("%d", &n);

    int* vetora = (int*)malloc(n * sizeof(int));

    if (vetora == NULL) {
        printf("Erro na alocação de memória. Não há memória suficiente disponível.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &vetora[i]);
    }

    for (i = 0; i < n; i++) {
        if (vetora[i] % 2 == 0) {
            printf("Par = %d\n", vetora[i]);
            contapar++;
        }
    }
    printf("Esse código possui %d pares\n", contapar);

    for (i = 0; i < n; i++) {
        if (vetora[i] % 2 != 0) {
            contaimpar++;
            printf("Impar = %d\n", vetora[i]);
        }
    }
    printf("Esse código possui %d ímpares\n", contaimpar);

    free(vetora);
    return 0;
}
