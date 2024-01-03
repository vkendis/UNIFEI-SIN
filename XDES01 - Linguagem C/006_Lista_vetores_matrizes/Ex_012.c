//12) Faça um programa que leia uma matriz MxN, onde o usuário informa os valores de M e N. Mostre como
//resposta o valor do maior elemento presente na matriz, a linha e a coluna em que ele se encontra.
#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    int maior = 0;
    int linha = 0;
    int coluna = 0;

    scanf("%d %d", &m, &n);

    int mat[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    printf("%d %d %d", maior, linha, coluna);

    return 0;
}