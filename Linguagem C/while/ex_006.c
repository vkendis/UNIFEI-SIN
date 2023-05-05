//6) Faça um programa que leia dois inteiros A e B, calcule e mostre: a soma dos números pares no intervalo
//[A, B] e o produto dos números ímpares no intervalo [A, B]. Imprima as duas respostas em uma única linha,
//separadas entre si por um único espaço.
#include <stdio.h>
int main (){
    int A, B, i=0,spar=0,prod=1;
    printf("Digite um numero: ");
    scanf("%d", &A);

    printf("Digite outro numero: ");
    scanf("%d", &B);
    
    if (A > B) {
        int troca_valor = A;
        A = B;
        B = troca_valor;
    }
    i = A;

    while(i <= B){
        if(i % 2 == 0){
            spar+=i;
        } else {
            prod*=i;
        }
        i++;
    }

    printf("%d %d\n", spar, prod);
    return 0;
}
