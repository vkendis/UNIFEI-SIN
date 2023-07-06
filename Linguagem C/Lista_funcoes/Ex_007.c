/*7) Faça uma função que receba um número inteiro e retorne a soma de seus algarismos. No Moodle, insira
seu programa completo (main + funções).*/
#include <stdio.h>
int soma_algarismo(int a);
int main ()
{
    int a;
    int res=0;

    scanf("%d", &a);
    res = soma_algarismo(a);
    printf("%d", res);
return 0;    
}

int soma_algarismo(int n)
{
    int soma = 0;
    while (n!= 0)
    {
        soma += n % 10; // divide por 10 e obtem o ultimo digito. Ex: 253 por 10 resta 3, logo 3 sera somado.
        n /= 10;        // remove o ultimo digito
    }
    return soma;
}
