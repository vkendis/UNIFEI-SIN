//7) Faça um programa que leia o valor de ângulo, dado em graus, e mostre, com duas casas decimais, os valores de seno, cosseno e tangente do ângulo lido, em uma única linha, separados por um único espaço.


#include <stdio.h>
#include <math.h>

int main(void) {
float angulo,sen,coss,tg,ang_rad;
printf("Digite o angulo: \n");
scanf("%f", &angulo);

ang_rad = angulo*M_PI/180.0;
  
sen=sin(ang_rad);
coss=cos(ang_rad);
tg=tan(ang_rad);

printf("%0.2f %0.2f %0.2f \n", sen,coss,tg);
  
  return 0;
}