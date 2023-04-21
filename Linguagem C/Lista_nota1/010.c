//10) Uma máquina demora 17 segundos para produzir uma peça. Faça um programa que leia a quantidade de peças que devem ser produzidas e mostre o tempo em horas, minutos e segundos necessários para produzir ssa quantidade de peças. Por exemplo, se um operador deseja produzir 4 peças, a máquina gastaria 68 segundos. Nesse caso, o programa daria como resposta: 0 horas, 1 minuto e 8 segundos. Em sua resposta, indique somente os números, separados por um único espaço entre eles. Por exemplo: 0 1 8

#include <stdio.h>

int main(void) {
int npeca,hor,min,seg,tpeca;

  printf("Digite quantas pecas voce quer produzir:  \n");
  scanf("%d", &npeca);
  tpeca=npeca*17;
  
  hor=tpeca/3600;
  min = tpeca % 3600/60;
  seg = tpeca % 60;
  
  printf("%d %d %d", hor, min, seg);
  return 0;
}