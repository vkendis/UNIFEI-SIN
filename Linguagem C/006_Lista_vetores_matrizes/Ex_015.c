#include <stdio.h>
int main ()
{   int n;
    int i,j;
    int soma=0;
    int somaref=0;
    
    scanf("%d",&n);
    
    int mat[n][n];

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        {
            somaref += mat[i][0];
        }
                
    for (i = 0; i < n; i++) {
        soma=0; // zerar soma para iniciar for
        for (j = 0; j < n; j++) {
            soma+= mat[i][j];
        }
            if(soma != somaref)
            {
                printf("nao");
                return 0;
            }
    }       

    for (j = 0; j < n; j++) {
        soma=0; // zerar soma para iniciar for
        for (i = 0; i < n; i++) {
            soma+= mat[i][j];
        }
            if(soma != somaref)
            {
                printf("nao");
                return 0;
            }
    }       

    soma=0; // zerar soma para iniciar for
        for (i = 0; i < n; i++) {
            soma+= mat[i][i]; // Diagonal principal
        }
            if(soma != somaref)
            {
                printf("nao");
                return 0;
            }
    
    soma=0; // zerar soma para iniciar for
        for (i = 0; i < n; i++) {
            soma+= mat[i][n-1-i];
        }
            if(soma != somaref)
            {
                printf("nao");
                return 0;
            }

            printf("sim");
return 0;
}