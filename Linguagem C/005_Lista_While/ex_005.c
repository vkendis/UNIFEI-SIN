//5) Faça um programa que leia dois inteiros N e X. A seguir, mostre quais são os N primeiros números
//naturais que são múltiplos de X. Imprima os números em uma única linha, separados entre si por um único
//espaço.
#include <stdio.h>
int main (){
    int n, x, i=0,mult=1;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Digite outro numero: ");
    scanf("%d", &x);
    while (i < n){
        if(mult % x == 0){
            printf("%d ", mult);
            i++;
        }
        mult++;
    }
return 0;    
}