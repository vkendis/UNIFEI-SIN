/*4) Faça uma função que recebe um valor N e retorne o somatório dos quadrados dos números de 1 a N. No
Moodle, insira apenas a sua função, que deve ter a seguinte assinatura:
int quadrados(int n)
*/
#include <stdio.h>

int quadrados(int n);
int main ()
{
    int n;
    int res;
    scanf("%d", &n);
  
    res = quadrados(n);
    printf("%d", res);

    return 0;
}

int quadrados(int n)
{
    int somatorio = 0;
    int i = 1;
    while (i <= n)
    {
        somatorio += i * i;
        i++;
    }
    return somatorio;
}