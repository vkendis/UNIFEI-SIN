//8) Faça um programa que leia dois inteiros N e X e mostre a soma dos múltiplos de X menores que N. Não
//deixe o usuário inserir valores negativos.
#include <stdio.h>
int main (){
int N, X, soma=0, i=1;
    do{
    printf("Digite um numero: ");
    scanf("%d", &N);
    } while (N < 0);

    do{
    printf("Digite um numero: ");
    scanf("%d", &X);
    } while (X < 0);
    
    while (i < N){
        if( i % X == 0){
        soma+=i;
        }
        i++;
    }
    printf("%d ", soma);
}