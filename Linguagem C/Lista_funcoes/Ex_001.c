/*1) Faça uma função que receba uma data e exiba-a na tela no formato textual por extenso. Exemplo: para
01/01/2000, imprimir: 1 de janeiro de 2000. Seu scanf deve ler a data no formato dd/mm/aaaa. No Moodle,
insira seu programa completo (main + funções).
*/
#include <stdio.h>
void imprime_data(int a, int b, int c);
int main ()
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    imprime_data(dia, mes, ano);

return 0;
}
void imprime_data(int dia, int mes, int ano)
{
if(mes == 1)
{
   printf("%d de janeiro de %d",dia, ano );
}
else if(mes == 2)
{
   printf("%d de fevereiro de %d",dia, ano );
}
else if(mes == 3)
{
   printf("%d de marco de %d",dia, ano );
}
else if(mes == 4)
{
   printf("%d de abril de %d",dia, ano );
}  
if(mes == 5)
{
   printf("%d de maio de %d",dia, ano );
}
else if(mes == 6)
{
   printf("%d de junho de %d",dia, ano );
}
else if(mes == 7)
{
   printf("%d de julho de %d",dia, ano );
}
else if(mes ==   8)
{
   printf("%d de agosto de %d",dia, ano );
}    
if(mes ==  9)
{
   printf("%d de setembro de %d",dia, ano );
}
else if(mes == 10 )
{
   printf("%d de outubro de %d",dia, ano );
}
else if(mes == 11)
{
   printf("%d de novembro de %d",dia, ano );
}
else if(mes == 12)
{
   printf("%d de dezembro de %d",dia, ano );
}  
}