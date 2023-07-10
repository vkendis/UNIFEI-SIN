#include <stdio.h>
#include <stdlib.h>
//Criar a struct com typedef
//Adicionar tipagem das variaveis dentro da struct 
//Declarar variavel struct 
//Ler as infos
//Printar as infos 
typedef struct
{
    char nome[100];
    int numero;
    int idade;
    char end[100];

}cadastro;

int main ()
{
    cadastro pessoa;
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", pessoa.nome);

    printf("Digite o endereco da pessoa: ");
    scanf(" %[^\n]", pessoa.end);

    printf("Digite o numero da pessoa: ");
    scanf("%d", &pessoa.numero);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);
    
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereco: %s, numero: %d\n", pessoa.end, pessoa.numero);

return 0;    
}