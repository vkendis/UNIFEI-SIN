#include <stdio.h>>
int main ()
{   
    int mat[3][3];
    int i,j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) 
    {
            if (mat[i][0] == 1 && mat[i][1] == 1 && mat[i][2] == 1)
            {
                printf("sim");
                break;
            }
            else  if (mat[0][j] == 1 && mat[1][j] == 1 && mat[2][j] == 1)
            {
                printf("sim");
                break;
            }
            else if ((mat[0][0] == 1 && mat[1][1] == 1 && mat[2][2] == 1) ||
            (mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1))
            {
                printf("sim");
                break;
            }
            else{
              printf("nao");
              break;
            }
    }

return 0;    
}
