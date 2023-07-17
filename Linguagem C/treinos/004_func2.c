#include <stdio.h>
double imprimenota(double n1, double n2, double n3);
int main ()
{
    double n1, n2, n3;
    double res=0;

    printf("Digite as notas dos alunos : n1, n2 n3\n");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    res = imprimenota(n1,n2,n3);
    printf(" %f ", res);
return 0;    
}
double imprimenota(double n1, double n2, double n3)
{
    char tipo;

    float media=0;

    printf("Qual o tipo de media voce quer consultar: ");
    scanf(" %c", &tipo);

    if(tipo == 'A')
    {
        media = (n1+n2+n3)/3;
        return media;
    }
    if(tipo == 'P')
    {
        media = ((n1*0.5)+(n2*0.3)+(n3*0.2)/10);
        return media;
    }
}