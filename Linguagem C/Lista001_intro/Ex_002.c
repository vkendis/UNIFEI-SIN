//2) Fazer um algoritmo para calcular a área de um círculo. Sabe-se que a área do círculo é dada pelo produto do
//raio ao quadrado pela constante π = 3.14. Nos fluxograma e pseudocódigo, represente π como ‘pi’.
#include <stdio.h>
int main ()
{   
    float raio, area;
    scanf("%f",&raio);

    area = acos(-1)* raio*raio;
    printf("%0.2f", area);

return 0;

}
