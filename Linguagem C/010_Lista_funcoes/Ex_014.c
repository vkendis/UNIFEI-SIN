/*14) Faça uma função que receba um valor N e dois vetores de tamanho N. A função deve alocar um terceiro
vetor, formado pela soma dos dois vetores recebidos e devolvê-lo ao main. Por fim, o main imprime o vetor
soma, sendo um elemento separado do outro por um único espaço. Use apenas aritmética de ponteiros, isto
é, faça este programa sem usar colchetes. O main deve ler o valor N, alocar e ler os dois vetores. No
Moodle, insira seu programa completo (main + funções).
*/
#include <stdio.h>
#include <stdlib.h>

int* somaVetores(int n, int* veta, int* vetb);

int main()
{
    int n;
    int i;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    int* veta = (int*)malloc(n * sizeof(int));
    int* vetb = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", veta + i);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", vetb + i);
    }

    int* vetorSoma = somaVetores(n, veta, vetb);

    printf("Vetor soma: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(vetorSoma + i));
    }
    printf("\n");

    free(veta);
    free(vetb);
    free(vetorSoma);

    return 0;
}

int* somaVetores(int n, int* vetor1, int* vetor2)
{
    int* vetorSoma = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
    {
        *(vetorSoma + i) = *(vetor1 + i) + *(vetor2 + i);
    }

    return vetorSoma;
}