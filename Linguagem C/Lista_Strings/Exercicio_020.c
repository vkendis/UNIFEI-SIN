/*
Alice criou uma string S apenas com letras minúsculas do alfabeto. A partir de S, ela
definiu uma string S’ removendo todas as letras “a” de S, e mantendo as demais letras na ordem em que
aparecem. Então, Alice formou uma nova string T concatenando as strings S e S’, isto é: T = S + S’. Por
exemplo:
S = “abacaxi”
S’ = “bcxi”
T = “abacaxibcxi”
Dada como entrada a string T, sua tarefa é encontrar a string S que Alice usou para produzir T. Considere
que não haverão espaços na string de entrada. Além disso, a string de entrada pode conter entre 1 até 105
caracteres. Caso não exista uma resposta para a entrada fornecida, imprima –1.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
   char T[100000]; 
   char S[100000];
   char Slin[100000];
   int  contaa = 0;
   int tamt, tams, tamsl;
   int i = 0, j = 0, c = 0;

   scanf("%s", T);

   tamt = strlen(T);

   
   while(T[i] != '\0')
   {
      if(T[i] == 'a')
      {
         contaa++;
      }
      else
      {
         Slin[j] = T[i];
         j++;
      }
      i++;
   }

   tams = ((tamt - contaa) / 2) + contaa;
   tamsl = (tamt - contaa) / 2;

   if(tamsl % 2 == 1)
   {
      c++;
   }

   for(i = 0 ; i < tams ; i++)
   {
      S[i] = T[i];
   }

   S[tams] = '\0';
   Slin[j] = '\0';

   for(i = 0 ; i < tamsl ; i++)
   {
      if(Slin[i] != Slin[i+tamsl])
      {
         c++;
      }
   }

   if(c != 0)
   {
      printf("-1");
   }
   else if (c ==0)
   {
      printf("%s\n", S);   
   }

   return 0;
}