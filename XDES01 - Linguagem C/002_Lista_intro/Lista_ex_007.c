// 7) Fazer um programa para calcular a área de um trapézio.
#include <stdio.h>

int main(void) {
int bmaior, bmenor, altura, area;
  printf("Digite o numero da base maior, base menor e a altura: \n");
  scanf("%d %d %d", &bmaior,&bmenor,&altura);

  area= ((bmaior+bmenor)*altura)/2;
  printf("A area do trapezio e igual a: %d", area);
  return 0;
}