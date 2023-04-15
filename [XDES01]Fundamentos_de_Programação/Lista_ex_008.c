// 8) Fazer um programa para calcular a área de um círculo.
#include <stdio.h>
#include <math.h>
int main(void) {
  int raio, area;
  printf("Digite o valor do raio: \n");
  scanf("%d",&raio);

  area=3.14 * pow(raio, 2);
  printf("A area do circulo sera igual a: %d", area);
  return 0;
}