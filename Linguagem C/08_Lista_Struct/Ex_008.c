/*8) Declare uma estrutura para representar números complexos, formados por parte real e parte imaginária. 
A seguir, leia dois números complexos (parte real seguida de parte imaginária de cada um). Apresente como
resposta a soma, a subtração e o prod dos números complexos, sendo um valor por linha.*/
#include <stdio.h>

typedef struct {
    float real;
    float imaginaria;
} complexo;

int main() {
    complexo n1, n2, soma, sub, prod;

    scanf("%f", &n1.real);
    scanf("%f", &n1.imaginaria);
    scanf("%f", &n2.real);
    scanf("%f", &n2.imaginaria);

    soma.real = n1.real + n2.real;
    soma.imaginaria = n1.imaginaria + n2.imaginaria;

    sub.real = n1.real - n2.real;
    sub.imaginaria = n1.imaginaria - n2.imaginaria;

    prod.real = n1.real * n2.real - n1.imaginaria * n2.imaginaria;
    prod.imaginaria = n1.real * n2.imaginaria + n1.imaginaria * n2.real;

    printf("Soma: %.2f + %.2fi\n", soma.real, soma.imaginaria);
    printf("Subtracao: %.2f + %.2fi\n", sub.real, sub.imaginaria);
    printf("Produto: %.2f + %.2fi\n", prod.real, prod.imaginaria);

    return 0;
}






