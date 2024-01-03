/*9) Faça uma função que receba um número N e retorne a soma dos algarismos do fatorial de N. No Moodle,
insira apenas a sua função, que deve ter a seguinte assinatura:
int somafat(int n)
*/
#include <stdio.h>
int somafat(int n);
int main ()
{
    int n;
    int res;
    scanf("%d",&n);
    res = somafat(n);
    printf("%d",res);
return 0;    
}
int somafat(int n)
{
    int i;
    long long int fat =1;
    int somatorio=0;

    for(i=1;i<=n;i++)
      {
        fat*=i;
      }
    while(fat != 0)
    {
        somatorio += fat % 10;
        fat /= 10;
    }
return somatorio;
}