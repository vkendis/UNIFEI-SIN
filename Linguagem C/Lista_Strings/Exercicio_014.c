//14) Faça um programa que leia um número inteiro longo representando o CPF de uma pessoa e, a seguir,
//mostre o número de vezes que cada dígito aparece no CPF. Siga o formato de saída apresentado no exemplo
//do Moodle.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cpf[20];
    int i;
    int conta1 = 0, conta2 = 0, conta3 = 0, conta4 = 0, conta5 = 0, conta6 = 0, conta7 = 0, conta8 = 0, conta9 = 0, conta0 = 0;
    int tam;

    scanf("%s", cpf);

    tam = strlen(cpf);

    for (i = 0; i < tam; i++) {
        if (cpf[i] == '0') {
            conta0++;
        }
        if (cpf[i] == '1') {
            conta1++;
        }
        if (cpf[i] == '2') {
            conta2++;
        }
        if (cpf[i] == '3') {
            conta3++;
        }
        if (cpf[i] == '4') {
            conta4++;
        }
        if (cpf[i] == '5') {
            conta5++;
        }
        if (cpf[i] == '6') {
            conta6++;
        }
        if (cpf[i] == '7') {
            conta7++;
        }
        if (cpf[i] == '8') {
            conta8++;
        }
        if (cpf[i] == '9') {
            conta9++;
        }
    }

    printf(" 0 = %d\n", conta0);
    printf(" 1 = %d\n", conta1);
    printf(" 2 = %d\n", conta2);
    printf(" 3 = %d\n", conta3);
    printf(" 4 = %d\n", conta4);
    printf(" 5 = %d\n", conta5);
    printf(" 6 = %d\n", conta6);
    printf(" 7 = %d\n", conta7);
    printf(" 8 = %d\n", conta8);
    printf(" 9 = %d\n", conta9);

    return 0;
}