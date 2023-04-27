//11) Faça um programa que leia a idade e o tempo de serviço de um trabalhador e escreva se ele pode ou não
//se aposentar. As condições para aposentadoria são:
//• Ter pelo menos 65 anos,
//• Ou ter trabalhado pelo menos 30 anos,
//• Ou ter pelo menos 60 anos e trabalhado pelo menos 25 anos.
//Seu programa deve imprimir apenas as respostas “sim” ou “nao”.
#include <stdio.h>
int main ()
{
  int idade, tempo;

  printf("Digite sua idade:\n");
  scanf("%d", &idade);

  printf("Digite o tempo que trabalhou: \n");
  scanf("%d", &tempo);

if (idade > 0) 
    {
        r1 = (-b - sqrt(delta)) / (2*a);
        r2 = (-b + sqrt(delta)) / (2*a);
        if (r1 < r2) 
        {
            printf("%.2f %.2f\n", r1, r2);
        } else 
        {
            printf("%.2f %.2f\n", r2, r1);
        }
    }       else if (delta == 0) 
                    {
                    r1 = -b / (2*a);
                    printf("%.2f\n", r1);
                    } else  
                        {
                        printf("sem raizes reais\n");
                        }

    return 0;
}








