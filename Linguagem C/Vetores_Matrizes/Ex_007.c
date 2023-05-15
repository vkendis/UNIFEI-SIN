//7) Um jogo de loteria é composto por números entre 1 a 25, sendo que o apostador escolhe 15 valores. Faça
//um programa que leia e armazene em um vetor os 15 valores representando o palpite do apostador e leia em
//um segundo vetor quais foram os 15 números sorteados. A seguir, mostre o total de acertos do apostador.
#include <stdio.h>
int main ()
{
    int tentativa[15];
    int res[15];
    int i;
    int j;
    int acertos = 0;

    for(i=0; i<15; i++)
    {
    scanf("%d", &tentativa[i]);
    }
    
    for(i=0; i<15; i++)
    {
    scanf("%d", &res[i]);
    }

    for(i=0; i<15; i++)
      {
        for(j=0; j < 15; j++ )
          {
            if(tentativa[i] == res[j] )
            {
              acertos++;
            }
          }
      }
      printf("%d ", acertos);
return 0;    
}