/*5) Faça um programa que leia o arquivo binário gerado no Exercício 4 e, a seguir, mostre na tela a soma dos
100 números armazenados.*/
#include <stdio.h>

#define NUM_NUMEROS 100

int main()
{
    int numeros[NUM_NUMEROS];

    // Abrir o arquivo binário para leitura
    FILE *arquivo = fopen("numeros.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler os números do arquivo binário
    fread(numeros, sizeof(int), NUM_NUMEROS, arquivo);

    // Calcular a soma dos números
    int soma = 0;
    for (int i = 0; i < NUM_NUMEROS; i++) {
        soma += numeros[i];
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Exibir a soma dos números
    printf("A soma dos 100 números é: %d\n", soma);

    return 0;
}
