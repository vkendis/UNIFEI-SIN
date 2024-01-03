/*4) Faça um programa que gere, aleatoriamente, 100 números entre 1 e 1000. Esse programa deverá
armazenar esses números em um arquivo binário.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NUMEROS 100

int main()
{
    int numeros[NUM_NUMEROS];

    // Gerar números aleatórios
    srand(time(NULL));
    for (int i = 0; i < NUM_NUMEROS; i++) {
        numeros[i] = rand() % 1000 + 1;
    }

    // Abrir arquivo binário para escrita
    FILE *arquivo = fopen("numeros.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrever os números no arquivo binário
    fwrite(numeros, sizeof(int), NUM_NUMEROS, arquivo);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Arquivo 'numeros.bin' gerado com sucesso.\n");

    return 0;
}
