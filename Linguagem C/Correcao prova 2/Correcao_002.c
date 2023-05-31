#include <stdio.h>

int main(){
    int n;
    float catalan;
    float termo;
    int sinal = 1;
    int denominador = 3;
    
    do  {
            scanf("%d", &n);
        }while (n<=0);
    
    for (int i = 1; i <= n; i++){
        termo = 1.0 / (denominador * denominador);
        termo *= sinal;
        catalan += termo;

        denominador+=2;
        sinal*=-1;
    }
    
    printf("%.4f\n", catalan);
    
    return 0;
}