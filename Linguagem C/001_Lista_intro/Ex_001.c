//1) Fazer um algoritmo para calcular a área de um triângulo. Sabe-se que a área do triângulo é dada pelo produto
//da base pela altura, dividido por 2.
#include <stdio.h>
int main ()
{
    int area;
    int b,h;

    scanf("%d %d", &b, &h);
    area = (b*h)/2;
    printf("%d", area);

return 0;    
}