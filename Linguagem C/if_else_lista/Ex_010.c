//10) Faça um programa que resolva uma equação de segundo grau, na forma: ax2 + bx + c = 0. Caso a
//equação possua duas raízes, imprima-as em uma mesma linha, sendo a raiz de menor valor impressa
//primeiro e separada da maior raiz por um único espaço. Se a equação possuir apenas uma raiz, imprima
//somente este valor. Caso a equação não possua raízes reais, imprima a mensagem “sem raizes reais”.
#include <stdio.h>
#include <math.h>
int main ()
{
  float a, b, c, delta, r1, r2;

  printf("Digite um valor para a\n");
  scanf("%f", &a);

  printf("Digite um valor para b\n");
  scanf("%f", &b);

  printf("Digite um valor para c\n");
  scanf("%f", &c);
  
  delta = pow(b,2) - 4*a*c; 

if (delta > 0) 
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












