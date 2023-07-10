/*2) Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis, compare seus endereços
e exiba o conteúdo do maior endereço.*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n1, n2;
    int *pn1, *pn2;

    scanf("%d %d", &n1, &n2);
    pn1 = &n1;
    pn2 = &n2;

    printf("O endereco: %p contem: %d\n\n", pn1, *pn1);
    printf("O endereco: %p contem: %d\n\n", pn2, *pn2);

    if(pn1>pn2)
    {
        printf("O endereco: %p contem: %d", pn1, *pn1);
    }else if (pn2>pn1)
    {
        printf("O endereco: %p contem: %d", pn2, *pn2);
    }   
    else
        {
            printf("Os dois sao iguais");
        }


return 0;    
}