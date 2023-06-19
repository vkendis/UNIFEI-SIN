/*1) Faça um programa que leia o nome, a idade e o endereço (rua e número) de uma pessoa e armazene os
dados em uma estrutura. Mostre na tela as informações armazenadas.*/
#include <stdio.h>

typedef struct
{
    char nome[100];
    int idade;
    char endereco[100];
    int numero;
}paciente;

int main ()
{
    paciente pessoa;
  
    scanf("%[^\n]", pessoa.nome );

    scanf("%d\n", &pessoa.idade);

    scanf("%[^\n]", pessoa.endereco);

    scanf("%d", &pessoa.numero);

    printf("Nome: %s\n", pessoa.nome );

    printf("Idade: %d\n", pessoa.idade);

    printf("Endereco: %s, %d\n", pessoa.endereco, pessoa.numero);

return 0;    
}
