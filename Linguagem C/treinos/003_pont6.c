//Aritmetica de ponteiros com menor diferenca entre elementos e media.
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int n;
    int i;
    double media = 0;
    double soma = 0;
    double prox;
    int indice =0;
    int *pindice = NULL; //Declarado o ponteiro que foi pedido para guardar o end de memoria do indice.
    scanf("%d", &n);
    //Alocacao dinamica - Aritmetica de ponteiros
    double *vetor = (double*)malloc(n*sizeof(double));

    for(i = 0; i < n; i++)
    {
        scanf("%lf", &vetor[i]);
        soma+=vetor[i];
        media = soma/n;

    }
    printf("media : %lf\n", media);
    printf("soma : %lf\n", soma);

    //Para verificar a menor diferenca entre os indices e a media precisamos incializar a "diff"
    double diff = vetor[0] - media;
    
    if(diff < 0)
    {
        diff = -1 * diff; //Se a diferenca for negativa, multiplicamos por -1 para ter a distancia em modulo.
    }
    prox = vetor[0];
    //Para verificar o resto do vetor precisamos incializar em 1
    for(i = 1; i < n; i++)
    {
        double diffatual = vetor[i] - media;
        if(diffatual< 0)
        diffatual = -1 * diffatual; //Se a diferenca for negativa, multiplicamos por -1 para ter a distancia em modulo.

        if(diffatual<diff)
        {
            diff = diffatual;
            prox = vetor[i];
            indice = i;
            pindice = &indice;
        }
    }
    printf("O elemento mais proximo da media e: %0.2lf, tem uma diferenca de  %0.2lf e contem indice: %d\n ", prox,diff,*pindice);
    free(vetor);
}