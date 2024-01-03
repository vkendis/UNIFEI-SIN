#include <stdio.h>
long long int fatorial(int x);
double serie(int n);
int main()
{
    int n;
    double somatorio = 0;

    printf("Digite um valor para N: \n");
    scanf("%d", &n);

    somatorio = serie(n);
    printf("somatorio da sequencia:  %lf\n ", somatorio);

    return 0;
}
long long int fatorial(int x)
{
    int i;
    long int fat = 1;
    for (i = 1; i <= x; i++)
    {
        fat *= i;
    }
    return fat;
}
double serie(int n)
{
    double soma = 0;
    int i;

    for (i = 1; i <= n; i++)
    {
        soma += (double)i / fatorial(2 * i);
    }
    return soma;
}