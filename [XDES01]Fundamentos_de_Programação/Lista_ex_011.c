// 11) Fazer um programa para converter um ângulo de graus para radianos.
#include <stdio.h>
#include <math.h>
int main(void) {
float graus, rad;
  printf("Digite os graus: \n");
  scanf("%f", &graus);

  rad = graus * M_PI/180.0;
  printf("A conversao de graus em radianos e igual a: %f ", rad);

  return 0;
}