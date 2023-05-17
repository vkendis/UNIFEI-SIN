//9) Fazer um algoritmo que receba o ano de nascimento de uma pessoa e o ano atual (dois valores de entrada). A
//seguir, calcular e mostrar: 
//a) a idade da pessoa em anos. 
//b) a idade da pessoa em meses. 
//c) a idade da pessoa em dias.
#include <stdio.h>
int main ()
{
    int nasceu, anoatual;
    int anos, meses, dias;

    scanf("%d %d", &nasceu, &anoatual);

    anos = anoatual-nasceu;
    meses = anos*12;
    dias = anos*365;

    printf("%d\n", anos);
    printf("%d\n", meses);
    printf("%d\b", dias);

return 0;    
}