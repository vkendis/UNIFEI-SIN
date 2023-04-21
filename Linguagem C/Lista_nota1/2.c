//2) Faça um programa para calcular o valor de desconto de um produto pago à vista. O programa deve ler o valor do produto e a porcentagem de desconto à vista (valor inteiro). Imprima, como resposta, uma única linha contendo o valor final do produto e o valor do desconto, separados entre si por um único espaço.

#include <stdio.h>

int main(void) {
float valor, valorf, descontof;
int desconto;

printf("Digite o valor do produto: \n");
scanf("%f", &valor);

printf("Digite o valor do desconto: \n");
scanf("%d", &desconto);

valorf = valor - (valor * desconto/100);
descontof = valor * desconto/100;
printf("O valor do produto sera de: $%0.2f reais e o valor do desconto sera: $%0.2f reais\n", valorf, descontof);
}