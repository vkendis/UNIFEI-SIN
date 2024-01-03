//10) Fazer um algoritmo que receba dois números como entrada e mostre qual o maior deles.
#include <stdio.h>
int main ()
{
    int n1, n2;

    scanf("%d %d", &n1, &n2);
    if(n1 > n2)
    {
        printf("%d", n1);
    } else
    {
       printf("%d", n2); 
    }

return 0;    
}