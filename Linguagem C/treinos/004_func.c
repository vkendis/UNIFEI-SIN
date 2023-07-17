//Codigo booleano para devolver se o numero e primo ou nao.
#include <stdio.h>
int primo(int n);
int main ()
{
    int n;
    scanf("%d", &n);

    if(primo(n) == 1)
    {
        printf("1\n");
    }else
        {
            printf("0\n");
        }
return 0;
}
int primo(int n)
{
    int i;
    int conta=0;
  
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            conta++;
        }
        
    }
    if(conta == 2)
        {
            return 1;
        }else
            {
                return 0;
            }

}