//12) Fazer um algoritmo que receba um número representando a temperatura da água e mostre em qual estado
//físico (sólido, líquido ou gasoso) ela se encontra.
#include <stdio.h>
int main ()
{
    int temp; 

    scanf("%d", &temp);

    if(temp <= 0)
    {
        printf("Solido");
    }

    if(temp > 0 && temp < 100)
    {
        printf("Liquido");
    }

    if(temp > 100)
    {
        printf("Gasoso");
    }

    
return 0;    
}