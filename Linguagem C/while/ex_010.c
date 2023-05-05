//10) Faça um programa que leia um inteiro positivo N e mostre a soma de seus divisores. Por exemplo, a
//soma dos divisores de 30 é 1 + 2 + 3 + 5 + 6 + 10 + 15 + 30 = 72. Não deixe o usuário inserir um valor
//negativo.
#include <stdio.h>
int main (){
    int num, i=1, soma=0;;
    do{
        printf("Digite um numero: ");
        scanf("%d", &num);
    }while (num<0);
    
    while (i <= num) {
        if (num % i == 0) {
            soma += i;
        }
        i++;
    }

    printf("%d\n",soma);

    return 0;
}



