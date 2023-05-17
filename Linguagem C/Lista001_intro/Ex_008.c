//8) Fazer um algoritmo para resolver uma equação do segundo grau. Seu algoritmo deve verificar se a equação é
//realmente de segundo grau e tratar o valor do discriminante delta adequadamente.
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float delta, x1, x2;

    printf("Digite o coeficiente 'a': ");
    scanf("%f", &a);

    printf("Digite o coeficiente 'b': ");
    scanf("%f", &b);

    printf("Digite o coeficiente 'c': ");
    scanf("%f", &c);

    delta = b * b - 4 * a * c;

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raizes da equacao sao: x1 = %.2f e x2 = %.2f\n", x1, x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("A equacao possui uma raiz real: x = %.2f\n", x1);
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-delta) / (2 * a);
        printf("A equacao possui raizes complexas: x1 = %.2f + %.2fi e x2 = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}