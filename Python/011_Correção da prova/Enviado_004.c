//Escreva, em linguagem C pura, um programa que leia uma matriz de inteiros de ordem MxN, onde o usuário informa os valores de M e N. A seguir, leia um vetor de inteiros de P posições, onde o usuário informa o valor de P. 
//Mostre, como resposta, uma única linha contendo os elementos ímpares da matriz que também estão presentes no vetor. 
//Separe os elementos por um único espaço.

// 2 3 1 2 3 4 5 6 7 1 2 3 4 5 6 7 >>> 1 3 5

#include <stdio.h>
int main()
{
	int m,n;
	int p;
	int i;
	int j;
	
	scanf("%d %d", &m, &n);
	

	int mat[m][n];
	
	
// Leia os numeros dentro da matriz e dentro do vetor                   ****correto****

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
// Leia os numeros dentro do vetor                                      ****correto****
	scanf("%d", &p);

	int vet[p];

	for(i=0; i < p; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	
	int imparmat[p];
	int imparvet[p];
	
	// Verificar impares                                                ****erro: dimensao dos vetores que receberao valores impares****
	
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			if( mat[i][j] % 2 != 0)
			{
			imparmat[i] = mat[i][j];
			}
		}
	}

	for(i=0; i < p; i++)
	{ 
		if(vet[i] % 2 != 0)
		{
			imparvet[i] = vet[i];
		}
	}

// Mostre em uma unica linha contendo elementos impares da matriz que tambem estao presentes no vetor     
// ****Faltou for pra i e j com criterio de parada em contaimpmat e contaimpvet****
	
	for(i=0;i < p; i++)
	{
		if( imparmat[i] == imparvet[i])
			printf("%d\n", imparmat[i]);
	}
return 0;	
}
