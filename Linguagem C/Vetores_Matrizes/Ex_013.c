//13) Faça um programa que leia uma matriz MxN, onde o usuário informa os valores de M e N. Mostre como
//resposta o valor do segundo maior elemento presente na matriz, a linha e a coluna em que ele se encontra.
#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    int maior = 0;
    int segundomaior = 0;
    int linha = 0;
    int coluna = 0;
    int linhaseg = 0;
    int colunaseg = 0;

    scanf("%d %d", &m, &n);

    int mat[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (maior < mat[i][j]) {
                segundomaior = maior;
                maior = mat[i][j];
                linha = i;
                coluna = j;
                linhaseg = linha;
                colunaseg = coluna;
            } else if (mat[i][j] > segundomaior && mat[i][j] < maior) {
                segundomaior = mat[i][j];
                linhaseg = i;
                colunaseg = j;
            }
        }
    }

    printf("%d %d %d", segundomaior, linhaseg, colunaseg);

    return 0;
}