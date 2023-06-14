//17) Faça um programa que receba uma frase e mostre a quantidade de letras minúsculas e de letras
//maiúsculas digitadas. Imprima os dois valores em uma linha, separados por um único espaço.
#include <stdio.h>
#include <ctype.h>

int main() {
    char frase[100]; 
    int contamin = 0;
    int contamax = 0;
    int i = 0;

    scanf("%[^\n]%*c", frase); // Lê a frase até encontrar um caractere de nova linha (\n)

    while (frase[i] != '\0') {
        if (islower(frase[i])) {
           contamin++;
        } else if (isupper(frase[i])) {
            contamax++;
        }
        i++;
    }

    printf("%d %d", contamin, contamax);
    
    return 0;
}