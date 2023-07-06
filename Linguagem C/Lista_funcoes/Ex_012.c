/*12) Faça uma função booleana que receba duas strings A e B e verifique se a string A está contida no final
da string B. A função deve retornar 0 (para não) ou 1 (para sim). No Moodle, insira apenas a sua função, que
deve ter a seguinte assinatura:
int afimb(char *a, char *b)*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int afimb(char *a, char *b);

int main() {
    char a[100];
    char b[100];

    printf("Digite a string A: ");
    scanf("%s", a);

    printf("Digite a string B: ");
    scanf("%s", b);

    int result = afimb(a, b);

    if (result == 1) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}
int afimb(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    if (lenA > lenB) {
        return 0; // A não pode estar contida no final de B se A for maior que B
    }

    int i = lenA - 1;
    int j = lenB - 1;

    while (i >= 0) {
        if (a[i] != b[j]) {
            return 0; // Encontrou um caractere diferente, então A não está no final de B
        }
        i--;
        j--;
    }

    return 1;
}