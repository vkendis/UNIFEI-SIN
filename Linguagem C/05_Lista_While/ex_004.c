//4) Faça um programa que leia um inteiro positivo N, calcule e mostre a soma dos N primeiros números
//ímpares. Não deixe o usuário inserir um valor negativo. Se um valor negativo for inserido, continue lendo N.
#include <stdio.h>
int main (){
    int num, i=0,impar=1, soma=0;

    do{
        printf("Digite um numero: ");
        scanf("%d", &num);
    }while(num < 0);
    
    while (i < num){
        soma+=impar;
        impar+=2;
        i++;
    }
    printf("%d", soma);
return 0;
}