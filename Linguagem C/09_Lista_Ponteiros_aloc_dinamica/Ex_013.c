#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeros_apostados[15];
    int numeros_sorteados[15];
    int acertos = 0;

    printf("Digite 15 numeros de 1 a 25 (apostados):\n");
    for (int i = 0; i < 15; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros_apostados[i]);
    }

    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Gerar 15 números sorteados não repetidos entre 1 e 25
    int numeros_gerados[25] = {0}; // Vetor para marcar os números já sorteados

    for (int i = 0; i < 15; i++) {
        int numero_aleatorio;

        do {
            numero_aleatorio = (rand() % 25) + 1;
        } while (numeros_gerados[numero_aleatorio - 1]);

        numeros_sorteados[i] = numero_aleatorio;
        numeros_gerados[numero_aleatorio - 1] = 1; // Marca o número como sorteado
    
    }
 

    // Bubble Sort para ordenar os números sorteados
    for (int i = 0; i < 15 - 1; i++) {
        for (int j = 0; j < 15 - i - 1; j++) {
            if (numeros_sorteados[j] > numeros_sorteados[j + 1]) {
                // Troca os elementos de posição se estiverem fora de ordem
                int temp = numeros_sorteados[j];
                numeros_sorteados[j] = numeros_sorteados[j + 1];
                numeros_sorteados[j + 1] = temp;
            }
        }
    }

    printf("\nNumeros sorteados ordenados:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", numeros_sorteados[i]);
    }
    printf("\n");

    // Verifica quantos números o usuário acertou
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (numeros_apostados[i] == numeros_sorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    printf("\nQuantidade de acertos: %d\n", acertos);

    // Cria um vetor dinamicamente para armazenar os números acertados
    int *numeros_acertados = (int *)malloc(acertos * sizeof(int));

    // Armazena os números acertados no vetor usando aritmética de ponteiros
    int *p = numeros_acertados;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (numeros_apostados[i] == numeros_sorteados[j]) {
                *p = numeros_apostados[i];
                p++;
                break;
            }
        }
    }

    printf("\nNumeros acertados:\n");
    for (int i = 0; i < acertos; i++) {
        printf("Numero de acertos do usuario %d : %d \n", i + 1, numeros_acertados[i]);
    }
    printf("\n");

    // Libera a memória alocada para o vetor dinâmico
    free(numeros_acertados);

    return 0;
}