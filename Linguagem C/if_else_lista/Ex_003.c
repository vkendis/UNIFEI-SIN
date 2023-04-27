//3) Faça um programa que leia um valor inteiro e, caso este valor seja positivo, calcule e mostre a sua raiz quadrada. Caso ele seja negativo, calcule e mostre o seu quadrado.
#include <stdio.h>
#include <math.h>
int main ()
{
  int num1, root, resultado;

  printf("Digite um valor para num1\n");
  scanf("%d", &num1);
  root=sqrt(num1);
    if (num1 >= 0) 
    {
    printf("A raiz quadrada de num 1 e igual a: %d", root);
    } 
    else{
        resultado=pow(num1,2);
        printf("O resultado sera: %0d", resultado);
    }   
return 0;
  
}