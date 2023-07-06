/*5) Faça uma função que receba dois valores A e B e retorne a soma dos valores no intervalo [A, B]. No
Moodle, insira apenas a sua função, que deve ter a seguinte assinatura:
int soma(int a, int b)*/
#include <stdio.h>
int soma(int a, int b);
int main ()
{
    int a, b;
    int res;
    scanf("%d %d", &a, &b);
    res = soma(a,b);
    printf("%d", res);

return 0;    
}
int soma(int a, int b)
{
    int i;
    int somatorio = 0;

    for(i=a;i<=b;i++)
    {
        somatorio++;
    }
return somatorio;

}
