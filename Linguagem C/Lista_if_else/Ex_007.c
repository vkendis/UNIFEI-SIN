//7) Cada estado da região sudeste possui uma taxa de imposto distinta sobre o valor dos produtos nele
//comercializados. Faça um programa que leia o preço de um produto e o estado (use 1 = MG; 2 = SP; 3 = RJ;
//e 4 = ES), e mostre o preço final acrescido do imposto, de acordo com as seguintes taxas: MG = 12%; SP = 7%; RJ = 15%; ES = 8%.
#include <stdio.h>
int main ()
{
  float preco, imposto;

  printf("Digite o preco do produto:\n");
  scanf("%f", &preco);

  printf("Digite o numero equivalente ao Estado da compra:\n");
  scanf("%f", &imposto);

  if( imposto == 1)   
  {
    printf("O valor do produto e igual a: %0.2f\n", 1.12*preco);
  }
  else 
      if( imposto == 2)
      {  
      printf("O valor do produto e igual a: %0.2f\n", 1.07*preco);
      }
      else
            if( imposto == 3)
            { 
            printf("O valor do produto e igual a: %0.2f\n", 1.15*preco);
            }
            else
                if( imposto == 4)
                { 
                printf("O valor do produto e igual a: %0.2f\n", 1.08*preco);
                }
return 0;
  
}