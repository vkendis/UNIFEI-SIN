//Na matemática, uma combinação simples pode ser definida como sendo um agrupamento dos elementos de um conjunto em subconjuntos.
// Na combinação, a ordem dos elementos não é considerada na formação dos subconjuntos, ou seja, os subconjuntos {A, B} e {B, A} são iguais, 
//sendo considerados uma única vez na contagem da quantidade de combinações. 
//A fórmula geral para encontrar as quantidades de combinações simples de um conjunto é representada, na matemática, por: C(N, P) = N! / [P! * (N – P)!], onde N é a quantidade total de elementos do conjunto inicial e P é a quantidade de elementos de cada subconjunto. Escreva, em linguagem C pura, um programa que leia os valores de N e P 
//informados pelo usuário e imprima como resposta o valor da combinação simples. Não deixe o usuário inserir valores inválidos para N e P, ou seja, zero ou negativos.
//-2 3 7 3 >>> 35

#include <stdio.h>
int main()
{
	int n, p;
	int comb;
	int nfat=1;
	int pfat=1;
	int i;
	int difnp;
	int difnpfat=1;
//Definindo valores somente positivos e diferentes de 0       .
	do{
		scanf("%d" "%d", &n, &p);
	}while(n<0 || p<0);
	
	
// algoritmo para fatorial	                           
	
	difnp=(n-p);
	while(n>0) 
	{
		nfat*=n;
		n--;
	}

	while(p>0) 
	{
		pfat*=p;
		p--;
	}
	
	while(difnp>0)
	{
        difnpfat*=difnp;
        difnp--;
	}
	
	comb = (nfat)/(pfat*(difnpfat));
	printf("%d\n", comb);

return 0;
}