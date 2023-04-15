// 15) Fazer um programa que leia a distância (km) percorrida por um veículo e o tempo gasto (h), mostrando como resposta a sua velocidade média: Vm = s / t
#include <stdio.h>

int main(void) {
float km, hora, vel;
  printf("Digite a distancia em km e o tempo em horas: \n");
  scanf("%f %f", &km, &hora);

  vel=km/hora;
  printf("A velocidade media e igual a: %0.2f", vel);
  return 0;
}