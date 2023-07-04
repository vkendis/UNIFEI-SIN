/*16) Crie um programa que leia o número de linhas, colunas e os valores de uma matriz, fazendo alocação
dinâmica. A seguir, mostre o menor e maior valor digitados, bem como a linha e coluna em que se
encontram.*/
#include <stdio.h>
int main ()
{
    int m,n;
    int i, j;
    
    // Letirura das dimensoes.

    printf("Digite o numero de linhas da sua matriz: \n");
    scanf("%d", &m);

    printf("Digite o numero de colunas da sua matriz: \n");
    scanf("%d", &n);

    //Alocacao dinamica da mtriz

    int **matriz = (int**)malloc(m*sizeof(int*));
    for(i=0; i < m; i++)
    {
        matriz[i] = (int*)malloc(n*sizeof(int));
    }

    // Leitura dos valores

    printf("Digite os valores da matriz: \n");
    for(i = 0; i < m; i++)
    {
        for(j=0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Encontrar o menor e o maior valor na matriz
    int maiorvalor = matriz[0][0];
    int menorvalor = matriz[0][0];
    int posimaior = 0;
    int posjmaior = 0;
    int posimenor = 0;
    int posjmenor = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] > maiorvalor) {
                maiorvalor = matriz[i][j];
                posimaior = i;
                posjmaior = j;
            }
            if (matriz[i][j] < menorvalor) {
                menorvalor = matriz[i][j];
                posimenor = i;
                posjmenor = j;
            }
        }
    }

    printf("Maior valor: %d, Posição: [%d][%d]\n", maiorvalor, posimaior, posjmaior);
    printf("Menor valor: %d, Posição: [%d][%d]\n", menorvalor, posimenor, posjmenor);

    // Liberar a memória alocada para a matriz
    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}