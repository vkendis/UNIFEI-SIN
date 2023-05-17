//13) Fazer um algoritmo que receba um número representando a temperatura corporal de um paciente. Caso o
//valor seja maior que 39, mostre a mensagem “Febre alta”. Caso o valor esteja entre 38 e 39, mostre a
//mensagem “Febre baixa”. Caso contrário, mostre a mensagem “Temperatura Normal”.
#include <stdio.h>
int main ()
{
    int temp;

    scanf("%d", &temp);

    if(temp > 39)
    {
        printf("Febre Alta");
        return 0;
    }

    if(temp >=38 && temp <=39)
    {
        printf("Febre Baixa");
    } else 
    {
        printf("Temperatura Normal");
    }
    


return 0;    
}