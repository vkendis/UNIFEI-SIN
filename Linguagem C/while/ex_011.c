//11) Faça um programa que leia um inteiro X e mostre a diferença entre o quadrado da soma pela soma dos quadrados dos X primeiros números naturais.
//Exemplo: seja X = 10:
//Quadrado da soma: (1 + 2 + ... + 10)2 = (55)2 = 3025
//Soma dos quadrados: (12 + 22 + ... + 102
//) = 385
//Diferença: 3025 – 385 = 2640
#include <stdio.h>
int main (){
    int n, i = 1, soma=0, quadrado, somadosq=0, dif;

    scanf("%d", &n);

    while (i <= n) {
    soma+=i;
    i++;
}
    quadrado = soma*soma;
    i=1;
    while (i <= n) {  
    somadosq += i*i;
    i++;
}

    dif=quadrado-somadosq;
    printf("%d", dif);
    return 0;
}
