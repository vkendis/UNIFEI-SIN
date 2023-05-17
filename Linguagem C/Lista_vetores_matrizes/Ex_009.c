//9) Faça um programa que leia um vetor de inteiros de 8 posições. A seguir, imprima, em uma única linha, os
//números primos que estão presentes no vetor. Separe os números da resposta por um único espaço.
#include <stdio.h>

int main() {
    int vetor[8];
    int i;
    int j;
    int cont;
  
    // Preencher o vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < 8; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Números primos no vetor:");

    for(i=0; i<8; i++){
      cont=0;
      for(j=1;j<=vetor[i];j++){
        if(vetor[i] % j == 0){
          cont++;
        }
      }
      if(cont == 2){
        printf("%d ", vetor[i]);
      }
    }
return 0;
}