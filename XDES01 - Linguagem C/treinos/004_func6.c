#include <stdio.h>
int algarismos(int n);
int main()
{
    int n;
    int res = 0;

    printf("Digite um valor para N: ");
    scanf("%d", &n);

    res = algarismos(n);
    printf("%d", res);
    return 0;
}

int algarismos(int n)
{
    int soma = 0;
    
    while(n != 0)
    {
        soma += n % 10;  // Pega o resto da divisao e adiciona a soma. Ex: 255por 10 = 250 e sobra 5
        n /= 10;  //Remove ultimo digito
    }
    return soma;
}