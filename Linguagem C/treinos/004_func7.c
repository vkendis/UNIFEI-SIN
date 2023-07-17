#include <stdio.h>
int primo (int n);
int qtdprimos (int n);
int main ()
{
    int n;
    int res = 0;

    printf("Digite um numero para o valor de N: ");
    scanf("%d", &n);

    res = qtdprimos(n);
    printf("%d", res);
return 0;    
}
int primo (int n)
{   
    int i;
    int conta=0;
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            conta++;
        }
        
    }
    if(conta == 2)
        {
            return 1;
        }
    return 0;
}
int qtdprimos (int n)
{
    int i;
    int contaprimo=0;

    for (i=0; i<n; i++)
    {
        if(primo(i) == 1)
        {
            contaprimo++;
        }
    }
    return contaprimo;
}