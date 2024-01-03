#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[100];
    int i;
    int contaa = 0;
    int contae = 0;
    int contai = 0;
    int contao = 0;
    int contau = 0;
    int tam;

    scanf(" %[^\n]", palavra);

    tam = strlen(palavra);

    for (i = 0; i < tam; i++)
    {
        if (palavra[i] == 'a' || palavra[i] ==  'A')
        {
            contaa++;
        }
        if (palavra[i] == 'e' || palavra[i] == 'E')
        {
            contae++;
        }
        if (palavra[i] == 'i' || palavra[i] == 'I')
        {
            contai++;
        }
        if (palavra[i] == 'o' || palavra[i] == 'O')
        {
            contao++;
        }
        if (palavra[i] == 'u' || palavra[i] == 'U')
        {
            contau++;
        }
    }

    printf("A = %d\n", contaa);
    printf("E = %d\n", contae);
    printf("I = %d\n", contai);
    printf("O = %d\n", contao);
    printf("U = %d\n", contau);

    return 0;
}