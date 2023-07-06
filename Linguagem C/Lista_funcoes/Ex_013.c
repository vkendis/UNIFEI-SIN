/*13) Seja a seguinte struct para representar pontos no espaço 2D:
struct Ponto
{
int x, y;
};
Faça uma função booleana (devolve 0 = não, ou 1 = sim) que receba um Ponto P e verifique se ele está
contido no interior de um retângulo. O retângulo é definido por dois pontos: o vértice inferior esquerdo (v1)
e o vértice superior direito (v2). Para todos os pontos, leia as coordenadas X e Y. No Moodle, insira seu
programa completo (main + funções).
*/
#include <stdio.h>

struct Ponto
{
    int x, y;
};

int contemPonto(struct Ponto ponto, struct Ponto verticeInfEsq, struct Ponto verticeSupDir)
{
    if (ponto.x > verticeInfEsq.x && ponto.x < verticeSupDir.x && ponto.y > verticeInfEsq.y && ponto.y < verticeSupDir.y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Ponto ponto;
    struct Ponto verticeInfEsq;
    struct Ponto verticeSupDir;

    scanf("%d %d", &ponto.x, &ponto.y);

    scanf("%d %d", &verticeInfEsq.x, &verticeInfEsq.y);

    scanf("%d %d", &verticeSupDir.x, &verticeSupDir.y);

    if (contemPonto(ponto, verticeInfEsq, verticeSupDir))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }

    return 0;
}
