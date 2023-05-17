//7) Fazer um algoritmo para resolver uma equação do primeiro grau
#include <stdio.h>
int main ()
{
    int a, b, x;
    
    scanf("%d %d", &a, &b);
    
    if (a == 0) {
        if (b == 0) {
            printf("A equacao possui infinitas solucoes.\n");
        } else {
            printf("A equacao nao possui solucao.\n");
        }
    } else {
        x = -b / a;
        printf("A solucao da equacao e: x = %.2f\n", x);
    }

    return 0;
}