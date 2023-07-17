#include <stdio.h>
int soma (int a, int b);
int main ()
{
    int a, b;
    int res = 0;
    
    printf("Digite os valores para a e b: ");
    scanf("%d %d", &a, &b);

    res = soma(a,b);
    printf("A soma desse intervalo sera igual a: %d ", res);


return 0;    
}
int soma (int a, int b)
{
    int i;
    int soma = 0;

    if(a<b)
    {
        for(i = a; i <= b; i++)
        {
            soma+=i;
        }
        return soma;
    }
    else if (a>b)
        {
            for(i = b; i <= a; i++)
            {
                soma+=i;
            }
        }else   {
                    return 0;
                }



}