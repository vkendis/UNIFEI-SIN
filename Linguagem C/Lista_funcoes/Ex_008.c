/*8) Faça uma função que receba um número N e retorne a quantidade de números primos menores que N
existentes. No Moodle, insira apenas a sua função, que deve ter a seguinte assinatura:
int qtdprimos(int n)
*/
#include <stdio.h>

int qtdprimos(int n);

int main()
{
    int n;
    scanf("%d", &n);
    
    int res = qtdprimos(n);
    printf("%d", res);

    return 0;    
}

int qtdprimos(int n)
{
    int contaprimo = 0;

    for (int i = 2; i < n; i++)
    {
        int primo = 1;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                primo = 0;
                break;
            }
        }

        if (primo)
        {
            contaprimo++;
        }
    }

    return contaprimo;
}