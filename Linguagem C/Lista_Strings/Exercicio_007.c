//7) Leia duas frases e mostre a diferença de tamanho entre elas. Sua saída deve estar no padrão: “A frase 1
//possui X caracteres a mais/menos que a frase 2.”.
#include <stdio.h>
#include <string.h>

int main() {
    char frase1[50];
    char frase2[50];
    int tamanho1 = 0;
    int tamanho2 = 0;
    int dif;
    
    scanf(" %[^\n]", frase1);
    scanf(" %[^\n]", frase2);

    tamanho1 = strlen(frase1);

    tamanho2 = strlen(frase2);

    dif = tamanho1 - tamanho2;

    if (dif > 0) {
        printf("A frase 1 possui %d caracteres a mais que a frase 2.\n", dif);
    } else if (dif == 0) {
        printf("As frases possuem o mesmo tamanho.\n");
    } else {
        printf("A frase 1 possui %d caracteres a menos que a frase 2.\n", -dif);
    }

    return 0;
}