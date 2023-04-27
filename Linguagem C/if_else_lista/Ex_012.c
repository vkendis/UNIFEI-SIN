//12) Faça um programa que leia as medidas dos 3 lados de um triângulo e mostre o tipo de triângulo:
//equilátero, isósceles ou escaleno. Imprima apenas o nome do triângulo, em letras minúsculas e sem acentos.
#include <stdio.h>
int main ()
{
  int a, b, c;

  printf("Digite o numero de a:\n");
  scanf("%d", &a);

  printf("Digite o numero de b:\n");
  scanf("%d", &b);

  printf("Digite o numero de c:\n");
  scanf("%d", &c);  
  
  if( a == b && a == c )
  {
    printf("equilatero");
  }   
    else    
        if(a != b && b != c)
        {
            printf("escaleno");
        }
            else    
                if((a == b && a != c) || (b == c && b != c))
                {
                    printf("isosceles");
                }  
return 0;
}
