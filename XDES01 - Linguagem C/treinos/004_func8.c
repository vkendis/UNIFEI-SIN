#include <stdio.h>
int somafat (int n);
int main ()
{
    long int n;
    int res = 0;

    printf("Digite um numero para o valor de n: ");
    scanf("%d", &n);

    res = (somafat(n));
    printf("A soma dos algarismos do fatorial sera igual a: %ld", res);


    return 0;    
}
int somafat (int n)
{
    long long int fat = 1;
    int i;
    int somatorio = 0;

    for(i = 1; i <= n; i++)
    {
        fat *= i;
    }

    while(fat!=0)
    {
        somatorio += fat % 10;
        fat /= 10;

    }
    return somatorio;
}