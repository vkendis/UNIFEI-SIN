/*2) Faça uma função booleana (devolve 0 = não, ou 1 = sim) que recebe um valor inteiro N e retorne se esse
número é primo ou não. No Moodle, insira apenas a sua função (sem main, sem includes), que deve ter a
seguinte assinatura:
int primo(int n)
O Moodle irá invocar sua função dentro de um printf para verificar a corretude.*/
#include <stdio.h>

int primo(int n);

int main()
{
    int num;
    scanf("%d", &num);
    
    if (primo(num) == 1)
    {
        printf("1"); 
    }
    else
    {
        printf("0"); 
    }

    return 0;
}

int primo(int n)
{
    int div = 1;
    int contaprimo = 0;

    while (div <= n)
    {
        if (n % div == 0)
        {
            contaprimo++;
        }
        div++;
    }

    if (contaprimo == 2)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}