#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char copia[100];
    int tamanho, i, j = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    tamanho = strlen(frase);

    for (i = 0; i < tamanho; i++) {
        if (frase[i] != ' ') {
            copia[j] = frase[i];
            j++;
        }
    }

    copia[j] = '\0';

    printf("Frase sem espacos: %s\n", copia);

    return 0;
}