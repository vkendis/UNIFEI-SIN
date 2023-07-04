/*15) Crie um programa que leia o número de linhas, colunas e os valores de uma matriz, fazendo alocação
dinâmica. A seguir, leia um valor do usuário e verifique se o valor digitado está contido na matriz.*/
#include <stdio.h>
int main ()
{
    int m, n;
    int num;
    int valor;
    int encontrado = 0;
    int i,j;

    printf("Digite o tamanho de sua matriz: ");
    scanf("%d %d", &m, &n);

    int **matriz = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Leitura dos valores da matriz
    
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matriz[i][j]);
        }
    }

        printf("Digite o valor para ser encontrado na matriz: \n");
        scanf("%d", &valor);

    for(i=0; i<m; i++)
    {
        for(j=0; j< n; j++)
        {
            if(matriz[i][j] == valor)
            {
                encontrado = 1;
                break;
            }
        }
    }

     if (encontrado) {
        printf("O valor %d está contido na matriz.\n", valor);
    } else {
        printf("O valor %d não está contido na matriz.\n", valor);
    }

    // Liberar a memória alocada para a matriz
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
