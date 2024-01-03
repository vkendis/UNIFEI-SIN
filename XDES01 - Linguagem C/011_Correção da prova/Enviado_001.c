#include <stdio.h>

// Funcao principal
int main()
{
	int vet[3];
	int maior=0;
	int i;
	
	for(i=0;i<3;i++)
	{
		scanf("%d", &vet[i]);
	}

	for(i=0;i<3;i++)
		{
			if(maior < vet[i])
			{
				maior= vet[i];
			}
		}

		if(maior == 90)
		{
			printf("retangulo");
		}else if (maior <90)
			{
				printf("acutangulo");
			}else 
				{
					printf("obtusangulo");
				}	
return 0;
}