//4) Um grupo de amigos pretende alugar um carro por um certo número de dias. Consultadas duas agências, a 
primeira cobra R$ 62,00 pela diária e mais R$ 1,40 por km rodado. A segunda agência cobra diária de R$ 
80,00 e mais R$ 1,20 por km rodado. Escreva um programa que leia a quantidade de km a serem percorridos 
e a quantidade de dias de aluguel do carro. A seguir, mostre, como resposta, uma única linha contendo o 
valor cobrado pela primeira agência separado do valor cobrado pela segunda agência por um único espaço.

#include <stdio.h>

int main(void) {
float ag1, ag2, km, dias;

printf("Digite quantos dias e quantos km deseja percorrer: \n");
scanf("%f %f", &dias, &km);

ag1 = (62*dias + 1.4*km);
ag2 = (80*dias + 1.2*km);  
  
printf("O preco da sua viagem na agencia 1 sera de: $%0.2f reais e o preco na agencia 2 sera de: $%0.2f reais\n", ag1,ag2);
  
  
  return 0;
}