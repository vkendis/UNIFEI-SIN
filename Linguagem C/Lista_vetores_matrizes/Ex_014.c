//Faça um programa que leia uma matriz 3x3. Essa matriz será preenchida apenas com elementos 0 e 1 (não é necessário verificar; os casos de testes não irão "trapacear" a entrada), 
//representando um "jogo da velha". Imprima como resposta apenas um "sim" ou "nao", informando se as marcações de "1" venceram a partida.
#include <stdio.h>

int main() {
    int mat[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[i][0] == 1 && mat[i][1] == 1 && mat[i][2] == 1) {
                printf("sim");
                return 0;
            } else if (mat[0][j] == 1 && mat[1][j] == 1 && mat[2][j] == 1) {
                printf("sim");
                return 0;
            }
        }
    }

    if ((mat[0][0] == 1 && mat[1][1] == 1 && mat[2][2] == 1) ||
        (mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1)) {
        printf("sim");
    } else {
        printf("nao");
    }

    return 0;
}