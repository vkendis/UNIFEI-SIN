
// Passo 1: Ler tamanho de M e N ✅
// Passo 2: Definir vetores M e N ✅
// Passo 3: Ler os elementos dos dois vetores ✅
// Passo 4: a) a união de seus elementos ✅
// Passo 5: b)a interseção ✅
// Passo 6: c) a diferença do primeiro vetor para o segundo. ✅
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int m, n;
    int i, j;
    
    // Passo 1: Ler M e N
    scanf("%d %d", &m, &n);

    // Passo 2: Alocacao dinamica para vetor a e b
    double *veta = (double *)malloc(m * sizeof(double));
    double *vetb = (double *)malloc(n * sizeof(double));

    // Passo 3: Leitura dos vetores a e b
    printf("Digite os elementos do vetor A:\n");
    for (i = 0; i < m; i++) {
        scanf("%lf", &veta[i]);
    }

    printf("Digite os elementos do vetor B:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &vetb[i]);
    }

    // Passo 4: União (Todos os elementos)
    printf("União:\n");
    for (i = 0; i < m; i++) {
        printf("%.2lf ", veta[i]);
    }
    for (i = 0; i < n; i++) 
    {
        int duplicado = 0;
        for (j = 0; j < m; j++)  
        {     
            if (vetb[i] == veta[j])    //Verificamos se existe duplicados 
            {
                duplicado = 1;          //Caso exista, break na iteracao
                break;
            }
        }
        if (!duplicado)                 //Se nao for duplicado, printa.
        {
            printf("%.2lf ", vetb[i]);
        }
   
    // Passo 5: Interseção (Elementos comuns aos dois vetores)
    printf("Interseção:\n"); 
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (veta[i] == vetb[j]) 
            {
                printf("%.2lf ", veta[i]);
                break;
            }
        }
    }
    printf("\n");

    // Passo 6: Diferença do primeiro vetor para o segundo 
    printf("Diferença (A - B):\n");
    //Mesmo metodo do passo 5, porem precisamos ignorar todos os elementos comuns (encontrados = 1) e printar a negacao (encontrado = 0)
    for (i = 0; i < m; i++) {
        int encontrado = 0;
        for (j = 0; j < n; j++) {
            if (veta[i] == vetb[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("%.2lf ", veta[i]);
        }
    }
    printf("\n");

    free(veta);
    free(vetb);

    return 0;
}
}