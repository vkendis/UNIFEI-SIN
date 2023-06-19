/*4) Crie uma estrutura para representar pontos em coordenadas polares: raio r e argumento a (em graus). Crie
uma estrutura para representar pontos em coordenadas cartesianas: x e y. Leia 6 pontos em coordenadas
polares e armazene em um vetor. A seguir, converta esses pontos para coordenadas cartesianas e armazene o
resultado em outro vetor. A conversão é dada por: x = r * cos(a) e y = r * sen(a). Por fim, mostre o resultado
de cada ponto em coordenadas cartesianas (x, y), com 1 casa decimal. Lembre-se que o valor do argumento
deve estar em radianos para usar as funções cos e sin.*/
#include <stdio.h>
#include <math.h>

typedef struct {
    float raio;
    float grau;
} Polar;

typedef struct {
    float x;
    float y;
} Cartesian;

int main() {
    Polar polares[6];
    Cartesian cartesianas[6];
    int i;
   
    for (i = 0; i < 6; i++) {
        scanf("%f", &polares[i].raio);
        scanf("%f", &polares[i].grau);
        polares[i].grau = polares[i].grau * acos(-1) / 180.0;
    }

    for (i = 0; i < 6; i++) {
        cartesianas[i].x = polares[i].raio * cos(polares[i].grau);
        cartesianas[i].y = polares[i].raio * sin(polares[i].grau);
    }

    for (i = 0; i < 6; i++) {
        printf("(%.2f, %.2f)\n", cartesianas[i].x, cartesianas[i].y);
    }

    return 0;
}
