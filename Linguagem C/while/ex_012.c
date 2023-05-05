//12) Faça um programa que leia um número N e mostre a soma dos N primeiros termos da seguinte
//expressão: S = 1 – 2 + 3 – 4 + 5 – 6 + ... + N.
#include <stdio.h>
int main (){
    int n, soma=0, i=1, sinal=1;
    scanf("%d", &n);

    while(i <= n){
        soma +=i*sinal;
        i++;
        sinal*=-1;
    }
    printf("%d\n", soma);
}