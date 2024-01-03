//13) Faça um programa que leia a idade de um nadador e mostre em qual categoria ele é classificado, de acordo com a tabela a seguir.
#include <stdio.h>
int main ()
{
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if( idade > 3 && idade < 6 )
    {
        printf("Fraldinha");    
    }
        else
            if( idade > 5 && idade < 13 )
            {
                printf("Infantil");    
            }
                else
                    if( idade > 12 && idade < 19 )
                    {
                        printf("Juvenil");    
                    }
                        else
                            if( idade > 18 )
                            {
                                printf("Adulto");    
                            }
return 0;
}                                
