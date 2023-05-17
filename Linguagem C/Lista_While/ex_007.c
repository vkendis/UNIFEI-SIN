//7) Faça um programa que leia um inteiro positivo N e mostre quais são os seus divisores. Por exemplo, os
//divisores de 30 são 1, 2, 3, 5, 6, 10, 15 e 30. Não deixe o usuário inserir um valor negativo. Imprima os
//números em uma única linha, separados entre si por um único espaço
#include <stdio.h>
int main (){
int n, i=1;
    do{
        printf("Digite um numero positivo: ");
        scanf("%d", &n);
    } while(n < 0 );

    while(i <= n){
       if(n % i == 0){
        
        printf("%d ", i);
       }
        
    i++;
    }
return 0;
}