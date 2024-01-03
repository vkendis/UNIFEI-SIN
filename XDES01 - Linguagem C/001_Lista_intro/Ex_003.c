//3) Fazer um algoritmo para converter uma temperatura de graus Celsius para graus Fahrenheit. A fórmula de
//conversão é: F = C * (9 / 5) + 32
#include <stdio.h>
int main ()
{   
    float Celsius, Faren;
    scanf("%f",&Celsius);

    Faren = 1.8*Celsius +32;
    printf("%0.2f", Faren);

return 0;

}
