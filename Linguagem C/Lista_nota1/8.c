//8) O volume de um cilindro é dado pela seguinte fórmula: V = πr2h, onde r é o valor raio, h é a sua altura e π é umaconstantematemática.Faça um programa que leia os valores de r e h ecalcule o volume do cilindro correspondente, com duas casas decimais. Represente π com todas as suas casas decimais.

#include <stdio.h>
#include <math.h>
int main(void) {
float Vol,raio,h, pi=3.14159265358979323846;
  
printf("Digite os valores para r e h:\n");
scanf("%f %f", &raio, &h);

Vol = pi*pow(raio,2)*h;
printf("O volume do cilindo sera de: %0.2f cm³", Vol);
  return 0;
}