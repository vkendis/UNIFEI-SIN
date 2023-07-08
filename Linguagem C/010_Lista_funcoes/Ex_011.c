/*11) Faça uma função que receba um vetor de inteiros e o seu tamanho, e devolva a média dos seus
elementos. No Moodle, insira apenas a sua função, que deve ter a seguinte assinatura:
double avgvet(int *vet, int n)
*/
#include <stdio.h>
double avgvet(int *vet, int n);
int main ()
{
    int n;
    int i;
    scanf("%d", &n);

    int vet[n];
    double media = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d", &vet[i]);
    }
    media = avgvet(vet, n);
    printf("%lf", media);
return 0;    
}
double avgvet(int *vet, int n)
{
    int i;
    int soma = 0;
    double media = 0;

    for(i=0;i<n;i++)
    {
        soma += vet[i];
    }
        media = (double)soma/i;

        return media; 
}



