//3) A bula de um remédio pediátrico recomenda a seguinte dosagem: 5 gotas para cada 2kg de peso da criança. Faça um programa que leia o peso da criança e mostre a quantidade de gotas a ser ministrada.
#include <stdio.h>

int main(void) {
int kg, gotas, bula;
  printf("Digite o peso da crianca:\n");
  scanf("%d", &kg);

  gotas=kg/0.4;
  printf("A crianca deve tomar %d gotas de remedio.\n", gotas);
  return 0;
}