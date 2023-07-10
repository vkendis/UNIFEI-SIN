#include <stdio.h>
#include <string.h>

int main() {
    char a[50];
    char b[50];
    int ocor = 0;
    int tama;
    int tamb;
  
    scanf(" %[^\n]", a);
    scanf(" %[^\n]", b);

    tama = strlen(a);
    tamb = strlen(b);

    int i;
    for (i = 0; i <= tamb; i++) {
        if (strncmp(a, b+i, tama) == 0) {
            ocor++;
        }
    }

    printf("%d\n", ocor);

    return 0;
}
