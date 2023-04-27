#include <stdio.h>

int main() {
    float h, ideal;
    char g;

    printf("Digite sua altura : ");
    scanf("%f", &h);
    printf("Digite seu sexo: ");
    scanf(" %c", &g);

    if ( g == 'm'){
        ideal = (72.7 * h) - 58;
        printf("%0.2f\n", ideal);
    } else if (g == 'f') {
        ideal = (62.1 * h) - 44.7;
         printf("%0.2f\n", ideal);
    }

    return 0;
}





