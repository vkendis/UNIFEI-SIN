#include <stdio.h>

int main()
{
	int i; 
	int j; 
	int k;
	int l;
	int L1, C1, L2, C2;

	scanf("%d %d", &L1, &C1);

	int mat[L1][C1];

    for(i = 0; i < L1; i++)
    {
        for(j = 0; j < C1; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

	scanf("%d %d", &L2, &C2);

    int mat2[L2][C2];
	int soma[L2][C2];

	for(k = 0; k < L2; k++)
		{
			for(l = 0; l < C2; l++)
			{
				scanf("%d", &mat2[k][l]);
			}
		}

	if(L1 == L2 && C1 == C2)
	{
		for(i = 0; i < L1; i++)
		{
			for(j = 0; j < C1; j++)
			{
				soma[i][j] = mat[i][j] + mat2[i][j];
				printf("%d ", soma[i][j]);
			}
			printf("\n");
		}
	}

	else
	{
		printf("impossivel \n");
	}

return 0;
}