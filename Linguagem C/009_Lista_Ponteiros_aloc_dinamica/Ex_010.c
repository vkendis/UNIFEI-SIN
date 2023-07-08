/*10) Escreva um programa que declare um vetor de double de tamanho N (informado pelo usuário) e um
ponteiro para um inteiro. Usando apenas aritmética de ponteiros, leia o vetor e mostre a média dos
elementos. A seguir, armazene no ponteiro o índice do elemento que tem o valor mais próximo da média e o
exiba.
*/

//Passo 1: Solicitar o tamanho de n.✅
//Passo 2: Alocar dinamicamente o vetor de double com tamanho N.✅
//Passo 3: Ler os valores dentro do vetor.✅
//Passo 4: Calcular a media dos elementes do vetor.✅
//Passo 5: Encontrar o indice do elemento que tem o valor mais proximo da media. ✅
//Passo 6: Exibir a media e o indice encontrado. ✅
#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n;
  int i;
  double soma=0;
  double media=0;
  printf("Digite o tamanho de n: ");
  scanf("%d", &n);
  
  double* vetor = (double*)malloc(n*sizeof(double));

  for(i = 0; i <  n; i++)
    {
    printf("Digite o numero: ");
    scanf("%lf", &vetor[i]);
    soma += vetor[i];
    }
    media=soma/i;

  int indice = 0;
  double menordiff = abs(vetor[0] - media);

  for(i=1; i<n; i++)
    {
      double novadiff = abs(vetor[i] - media);
      if( novadiff < menordiff) 
      {
      menordiff = novadiff;
      indice = i;
      }
    }

  printf("A media entre os numeros de entrada sera igual a: %0.2lf\n\n", media);
  
  printf("O indice que tem o elemento mais proximo da media e igual a: %d\n", indice);
  
  free(vetor);
return 0;  
}