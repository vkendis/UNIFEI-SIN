//5) Faça um programa que leia duas notas de um aluno e verifique se estas notas são válidas. Uma nota é válida se ela está no intervalo de 0 a 10. 
//Caso as notas sejam válidas, mostre a média entre elas. Caso nãosejam válidas, mostre a mensagem “notas incorretas”.
#include <stdio.h>
int main ()
{
  int nota1, nota2, media=0;

  printf("Digite um valor para a nota 1\n");
  scanf("%d", &nota1);

  printf("Digite um valor para a nota 2\n");
  scanf("%d", &nota2);

  media=(nota1+nota2)/2;

  if( nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10)   
  {
    media=(nota1+nota2)/2;
    printf("A media entre as notas do aluno e igual a: %d\n", media);
  }
  else
    printf("Notas incorretas\n");
  
  return 0;
  
}