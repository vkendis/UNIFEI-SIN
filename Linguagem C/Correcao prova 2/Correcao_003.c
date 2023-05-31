#include <stdio.h>

int main() {
    float vet[8];
    int i;
    float menor;
    float segundomenor;
    float terceiromenor;
    int posi1, posi2, posi3;
    
    for (i = 0; i < 8; i++) {
        scanf("%f", &vet[i]);
    }
    
    menor = vet[0];
    posi1 = 0;
    segundomenor = vet[1];
    posi2 = 1;
    terceiromenor = vet[2];
    posi3 = 2;
  
    for (i = 0; i < 8; i++) {
        if (vet[i] < menor) {
            terceiromenor = segundomenor;
            segundomenor = menor;
            menor = vet[i];
            posi3 = posi2;
            posi2 = posi1;
            posi1 = i;
        } else if (vet[i] < segundomenor && vet[i] != menor) {
            terceiromenor = segundomenor;
            segundomenor = vet[i];
            posi3 = posi2;
            posi2 = i;
        } else if (vet[i] < terceiromenor && vet[i] != menor && vet[i] != segundomenor) {
            terceiromenor = vet[i];
            posi3 = i;
        }
    }
    
    printf("%.2f %d \n", menor, posi1);
    printf("%.2f %d\n", segundomenor, posi2);
    printf("%.2f %d\n", terceiromenor, posi3);
    
    return 0;
}