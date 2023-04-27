//15) Faça um programa que verifique se um número lido é divisível por 3 ou por 5, mas não pelos dois ao
//mesmo tempo. Imprima como resposta apenas as frases: “divisivel por 3”, “divisivel por 5”,
//“nao divisivel”, de acordo com a entrada recebida.
#include <stdio.h>
int main () {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    if (num % 3 == 0 && num % 5 == 0 ){
        printf("nao divisivel\n");
    } else if (num % 5 == 0 ){
        printf("divisivel por 5\n");
    } else if (num % 3 == 0 ){
        printf("divisivel por 3\n");
    } else {
        printf("nao divisivel\n");
    }
    return 0;
    
  }    


















