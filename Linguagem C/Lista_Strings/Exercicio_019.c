#include <stdio.h>
#include <string.h>

int main() {
    char string[500];
    int tam;
    int i;
    int contaa=0;
    int contamax=0;
    int harm = 0;
    scanf("%s", string);

    tam = strlen(string);
  
    for (i = 0; i < tam; i++) {
        if (string[i] == 'a') {
            contaa++;
        } else {
            contamax++;
        }
    }
    
    if (contaa > contamax) {
        harm = tam;
    } else {
        
        harm = contaa * 2 - 1;
    }

    printf("%d\n", harm);

    return 0;
}