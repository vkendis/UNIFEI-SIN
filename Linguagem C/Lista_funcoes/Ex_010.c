/*10) Faça uma função que receba um vetor de inteiros e o seu tamanho, e devolva o valor do maior elemento
presente no vetor. No Moodle, insira apenas a sua função, que deve ter a seguinte assinatura:
int maxvet(int *vet, int n)*/
#include <stdio.h>
int maxvet(int *vet, int n);
int main ()
{
    int n;
    int i;
    scanf("%d", &n);

    int *vet[n];    
    for(i=0;i<n;i++)
    {
        scanf("%d", &vet[i]);
    }

return 0;    
}
int maxvet(int *vet, int n) {
    int maxvetor = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i] > maxvetor) {
            maxvetor = vet[i]; 
        }
    }

    return maxvetor;
}