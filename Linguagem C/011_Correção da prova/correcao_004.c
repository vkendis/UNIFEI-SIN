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
	
	
// Leia os numeros dentro da matriz e dentro do vetor

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
// Leia os numeros dentro do vetor
	scanf("%d", &p);

	int vet[p];

	for(i=0; i < p; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	
	int imparmat[m*n];
	int imparvet[p];
  int contaimpmat = 0;
  int contaimpvet = 0;
	
	// Verificar impares
	
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			if( mat[i][j] % 2 != 0)
			{
			imparmat[contaimpmat] = mat[i][j];
      contaimpmat++;
			}
		}
	}

	for(i=0; i < p; i++)
	{ 
		if(vet[i] % 2 != 0)
		{
			imparvet[contaimpvet] = vet[i];
      contaimpvet++;
		}
	}

// Mostre em uma unica linha contendo elementos impares da matriz que tambem estao presentes no vetor
	
	for(i = 0; i < contaimpmat; i++) 
    {
		  for(j = 0; j < contaimpvet; j++) 
        {
			      if(imparmat[i] == imparvet[j]) 
                {
				            printf("%d ", imparmat[i]);
	              }
	
        }
    } 
return 0;  
}

    