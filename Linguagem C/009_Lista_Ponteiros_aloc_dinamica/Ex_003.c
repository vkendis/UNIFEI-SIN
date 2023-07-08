/*3) Escreva um programa que declare um inteiro, um real e um char, e ponteiros para essas variáveis. Associe
as variáveis aos ponteiros. Modifique os valores de cada variável usando os ponteiros. Imprima os valores
das variáveis antes e após a modificação.
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n1, *ptrn1 = NULL;
    float real, *ptrreal = NULL;
    char ext, *ptrext = NULL;

    //Leitura dos valores 
    scanf("%d %f %c", &n1, &real, &ext);

    ptrn1 = &n1;   
    ptrreal = &real;
    ptrext = &ext;

    //Print dos valores antes de modificacao
    printf("Valores antes da modificacao: \n");
    printf("Inteiro: %d\n", n1);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", ext);

    //Alterando os resultados
    printf("******Aplicar modificacao nos enderecos******\n");

    *ptrn1 = 30;   
    *ptrreal = 56.2;
    *ptrext = 'b';

    //print dos valores alterados
    printf("Valores apos a modificacao: \n");
    printf("Inteiro: %d\n", n1);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", ext);

return 0;    
}