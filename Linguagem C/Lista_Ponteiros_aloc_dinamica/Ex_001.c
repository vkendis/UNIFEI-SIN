/*1) Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior
deles.
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n1, n2;
    int *pn1, *pn2;

    scanf("%d %d", &n1, &n2);
    pn1 = &n1;
    pn2 = &n2;

    if(pn1>pn2)
    {
        printf("%p", pn1);
    }else if (pn2>pn1)
    {
        printf("%p", pn2);
    }   
    else
        {
            printf("Os dois sao iguais");
        }


return 0;    
}