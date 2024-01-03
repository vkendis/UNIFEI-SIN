#include <stdio.h>
int quadrados(int n);
int main ()
{
    int n;
    int res = 0;

    printf("Digite o numero para n: \n");
    scanf("%d", &n);

    res = quadrados(n);
    printf("%d", res);
return 0;
}
int quadrados(int n)
{
    int i;
    int somatorio=0;

    for(i=0; i <= n; i++)
    {
        somatorio+=i*i;
    }
    return somatorio;
}