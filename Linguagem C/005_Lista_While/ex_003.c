//3) Faça um programa que leia um inteiro N e mostre quais são os N primeiros números impares. Imprima os
//numeros em uma única linha, separados entre si por um único espaço. Atenção: se o usuário digita N = 4, a
//resposta e: 1 3 5 7 (que são os 4 primeiros números ímpares!)
#include <stdio.h>
int main (){
    int num, i=0,impar=1;
    printf("Digite um numero: ");
    scanf("%d", &num);

    while (i < num){
        printf("%d ", impar);
        impar += 2;
        i++;
    }
return 0;    
}