/*6) Faça uma função que recebe um valor N e retorne o valor da soma dos N primeiros termos da série:
S = 0 + 1/2! + 2/4! + 3/6! + 4/8! + ...
O código deve declarar, também, uma função que calcule o fatorial e seja usada pela função da série.
No Moodle, insira apenas as suas funções, que deve ter as seguintes assinaturas:
long long int fatorial(int x)
double serie(int n)*/
#include <stdio.h>

long long int fatorial(int x);
double serie(int n);

int main()
{
    int n;
    double soma = 0;

    scanf("%d", &n);
    soma = serie(n);
    printf("%lf", soma);

    return 0;
}

long long int fatorial(int x)
{
    long long int resultado = 1;
    for (int i = 1; i <= x; i++)
    {
        resultado *= i;
    }
    return resultado;
}

double serie(int n)
{
    double somatorio = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio += (double)i / fatorial(2 * i);
    }
    return somatorio;
}