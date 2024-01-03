//5) Fazer um algoritmo para calcular a média aritmética entre duas notas de um aluno e apresentar a sua situação
//(aprovado / reprovado), considerando que o mínimo para a aprovação seja 6.0 pontos.
#include <stdio.h>
int main ()
{
    float n1, n2;
    float media;

    scanf("%f %f", &n1, &n2);

    media=(n1+n2)/2;

    if(media >= 6)
    {   
        printf("%0.2f\n", media);
        printf("Aprovado");
    }
        else 
        {   
            printf("%0.2f\n", media);
            printf("Nao aprovado");
        }
return 0;    
}
