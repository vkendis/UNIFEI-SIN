/*6) Faça um programa que leia um vetor de estrutura com os dados de 8 carros: marca, preço e ano. A seguir,
leia um valor P e mostre as informações de todos os carros com preço menor que P. Repita esse processo até
que seja lido um valor P ≤ 0.
*/
#include <stdio.h>

typedef struct {
    char marca[50];
    float preco;
    int ano;
} Carro;

int main() {
    Carro carros[8];
    int i;
    float P;

    for (i = 0; i < 8; i++) {
        scanf(" %[^\n]", carros[i].marca);
        scanf("%f", &carros[i].preco);
        scanf("%d", &carros[i].ano);
    }

    scanf("%f", &P);
    while (P > 0) 
    {
        printf("Carros mais baratos que %.2f:\n", P);
        for (i = 0; i < 8; i++) {
            if (carros[i].preco < P) 
            {
                printf("%s ", carros[i].marca);
                printf("%.2f ", carros[i].preco);
                printf("%d\n", carros[i].ano);  
            }
        }
        printf("\n");
        scanf("%f", &P);
    }

    return 0;
}