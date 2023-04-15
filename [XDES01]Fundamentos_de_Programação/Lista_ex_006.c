// 6) Fazer um programa para calcular a área de um triângulo.

#include <stdio.h>

int main(void) {
int x,h,area;
  printf("Digite os valores da base e da altura:\n");
  scanf("%d %d", &x, &h);
  area= ((x*h)/2);  
  printf("A area do triangulo sera igual a: %d", area);
  
  return 0;
}