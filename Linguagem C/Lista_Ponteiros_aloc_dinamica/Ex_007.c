/*7) Declare um vetor de inteiros com 10 posições, leia e armazene valores em cada posição. A seguir,
utilizando apenas ponteiros de int, some uma unidade ao conteúdo de cada posição do vetor se o conteúdo
for par; multiplique por 2 se for ímpar.
*/
#include <stdio.h>

int main() {
    int vetor[10];

    printf("Digite 10 valores inteiros:\n");

    // Lê e armazena valores no vetor
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    // Ponteiro de int para percorrer o vetor
    int* ptr = vetor;

    // Percorre o vetor e aplica a operação indicada para cada elemento
    for (int i = 0; i < 10; i++) {
        if (*ptr % 2 == 0) { // Se o valor for par
            (*ptr)++; // Soma uma unidade
        } else {
            (*ptr) *= 2; // Multiplica por 2 se for ímpar
        }
        ptr++; // Avança para o próximo elemento do vetor
    }

    // Imprime o vetor modificado
    printf("Vetor modificado: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
