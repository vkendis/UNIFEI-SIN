#include <stdio.h>

int main(){
    int linguas;
    char gen, grau;
    
    scanf("%d", &linguas);
    
    scanf(" %c", &gen);
    
    scanf(" %c", &grau);
    
    if ((gen == 'M' && grau == 'M' && linguas >= 2) ||
        (gen == 'F' && grau == 'M' && linguas >= 3) ||
        (gen == 'M' && grau == 'S' && linguas >= 1) ||
        (gen == 'F' && grau == 'S' && linguas >= 2)) {
        printf("sim\n");
    } 
    else{
        printf("nao\n");
    }
    
    return 0;
}