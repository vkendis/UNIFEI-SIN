/*3) Faça uma função que receba três notas de um aluno e uma letra. Se a letra for ‘A’, a função deve calcular
a média aritmética das notas do aluno; se for ‘P’, deve calcular a média ponderada, com pesos 5, 3 e 2. No
Moodle, insira seu programa completo (main + funções).
*/
#include <stdio.h>
void imprime_media(float a,float b,float c, char letra);
int main ()
{
    float n1, n2, n3;
    char media; 

    scanf("%f %f %f", &n1, &n2, &n3);
    scanf(" %c", &media);

    imprime_media(n1, n2, n3, media);
return 0;    
}
void imprime_media(float n1,float n2,float n3,char media)
{
if(media == 'A')
    {
        printf("%0.2f ", (n1+n2+n3)/3);
    }    
if(media == 'P')
    {
        printf("%0.2f", ((n1*5) + (n2*3) + (n3*2))/10);
    }    



}