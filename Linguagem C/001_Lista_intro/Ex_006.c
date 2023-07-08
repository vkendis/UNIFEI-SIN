//6) Fazer um algoritmo para calcular o novo salário de um funcionário. Sabe-se que os funcionários que ganham
//até R$ 1000,00 terão aumento de 20%, e os demais terão aumento de 10%.
#include <stdio.h>
int main ()
{
    float salario;

    scanf("%f", &salario);

    if(salario <= 1000)
    {
        salario = 1.2*salario;
    }
        else 
        {
            salario = 1.1*salario;
        }

    printf("%0.2f", salario);

return 0;    
}