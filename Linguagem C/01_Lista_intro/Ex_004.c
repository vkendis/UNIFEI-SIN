//4) Fazer um algoritmo para converter um ângulo de graus para radianos. A fórmula de conversão é: rad = graus
//* π / 180, onde π = 3.14.
#include <stdio.h>
int main ()
{   
    float graus, rad;
    scanf("%f",&graus);

    rad = graus* (acos(-1))/180.0;
    printf("%0.2f", rad);

return 0;

}
