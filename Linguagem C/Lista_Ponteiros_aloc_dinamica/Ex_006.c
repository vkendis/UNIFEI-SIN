/*6) Usando apenas ponteiros, escreva um programa que leia uma frase de até 80 caracteres e a imprima em
ordem reversa convertendo todos os caracteres minúsculos para maiúsculos.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char sentence[80];

    printf("Digite uma frase (até %d caracteres): ", 80);
    fgets(sentence, sizeof(sentence), stdin);

    // Encontra o final da string e pula caracteres não imprimíveis
    char* end = sentence + strlen(sentence) ;
    while (end >= sentence && !isprint(*end)) {
        end--;
    }

   // Converte caracteres minúsculos para maiúsculos e inverte a string
    char* start = sentence;
    while (start < end) {
        if (islower(*start)) {
            *start = toupper(*start);
        }
        if (islower(*end)) {
            *end = toupper(*end);
        }
        // Troca os caracteres usando uma variável temporária
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
        
        // Pula caracteres não imprimíveis no início da frase invertida
        while (start < end && !isprint(*start)) {
            start++;
        }

        // Pula caracteres não imprimíveis no final da frase invertida
        while (end > start && !isprint(*end)) {
            end--;
        }
    }

    // O último caractere não foi processado no loop, então devemos verificar e converter se for minúsculo
    if (islower(*start)) {
        *start = toupper(*start);
    }

    // Imprime a frase invertida em maiúsculas
    printf("Frase em ordem reversa e em maiúsculas: %s\n", sentence);

    return 0;
}
