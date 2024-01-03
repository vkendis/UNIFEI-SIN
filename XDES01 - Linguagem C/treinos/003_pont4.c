//Fazer ordenacao com bubble "Flutuar valor"
#include  <stdio.h>
int main ()
{
    int vet[10];
    int *pvet[10];
    int i;
    int bubble = 0;
    for(i =0; i < 10; i++)
    {
        scanf("%d", &vet[i]); 
        pvet[i] = &vet[i];
    }
   //Para fazer o bubble precisamos percorrer o vetor ate a penultima casa, ja que o j ajudara a comparar com o elemento a direita. 
   //Ou seja, quando i for 9, j sera 10 (i+1).
    for(i=0; i < 9; i++)
    {
        int j;
        for(j = i + 1; j < 10; j++)
            {
                if(*pvet[j] < *pvet[i]) //Logica para comprar se o numero a direita e menor do que o da esquerda, se sim = "bubble"
                {
                    bubble = *pvet[j];  //bubble sera variavel auxiliar para "flutuar e guardar o valor""Tira do plano pra realocar depois"
                    *pvet[j]=*pvet[i];  //Hora de consertar a variavel que teve o valor flutuado, esse indice recebera o valor a esquerda(maior)
                    *pvet[i]= bubble;   //Logo devemos voltar com o valor que foi retirado na bubble, realocando no indice a esquerda.
                }
            }
    }
    for(i=0; i < 10; i++)
    {
        printf("%d", *pvet[i]);
    }

return 0;    
}