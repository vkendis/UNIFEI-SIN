//Escreva, em linguagem C pura, um programa que leia valores inteiros indefinidamente e armazene, em um vetor de 5 posições, apenas os números primos digitados. Seu programa deve
//parar de ler números quando o vetor estiver totalmente preenchido. Imprima, como resposta, os elementos do vetor, em uma única linha, separados entre si por um único espaço. 
//Um número primo é aquele que possui apenas dois divisores naturais: 1 e ele mesmo.

// 1 2 3 4 5 6 7 8 9 10 11 >>> 2 3 5 7 11

#include <stdio.h>

// Funcao principal
int main()
{
		int vet[5];
		int contadiv=0;
		int contavetor=0;
		int i=1;
//Leitura do vetor;     ****Erro usar mesmo contador para 2 coisas diferentes****
		for(i=1;i<=5;i++)
		{
			scanf("%d", &vet[i]);	
		}
		for(i=1;i<=5;i++)
		{
			if(vet[i] % i == 0)       
			{
				contadiv++;           //Contador de dividores precisa ser 2
			
				if(contadiv == 2)
				{
					printf("%d", vet[i]);
				}
			}
		}
return 0;
}

