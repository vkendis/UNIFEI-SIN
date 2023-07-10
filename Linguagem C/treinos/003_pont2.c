#include <stdio.h>
//Criar 3 variaveis e seus respectivos ponteiros.
int main ()
{
    int n1, *pn1 = NULL;        //Ponteiros inicializados
    float n2, *pn2 = NULL;      //Ponteiros inicializados  
    char nome, *pnome = NULL;   //Ponteiros inicializados
//Leitura das variaveis
    printf("Digite um numero inteiro, um numero real e um caractere: \n");
    scanf("%d", &n1);
    scanf("%f", &n2);
    scanf(" %c", &nome);
//Ponteiros apontando para os enderecos de memoria (variaveis)
//Um Ponteiro SEMPRE aponta para um endereco de memoria
    pn1 = &n1;
    pn2 = &n2;
    pnome = &nome;
//Print dos enderecos e variaves apontadas
//Operador '*' sempre sera usado para acessar o VALOR da memoria.
//Ponteiros sem '*' retornam o numero do endereco hexadecimal. 
    
    printf("*****Valores antes da modificacao*****\n\n");
    printf("O endereco %p possui: %d\n", pn1, *pn1);
    printf("O endereco %p possui: %f\n", pn2, *pn2);
    printf("O endereco %p possui: %c\n\n", pnome, *pnome);

//Aplicar modificacao nos ponteiros 
    *pn1 = 50;
    *pn2 = 8.9;
    *pnome = 'c';

    printf("*****Valores depois da modificacao*****\n\n");
    printf("O endereco %p possui: %d\n", pn1, *pn1);
    printf("O endereco %p possui: %f\n", pn2, *pn2);
    printf("O endereco %p possui: %c\n", pnome, *pnome);
    printf("\n\n");

//Caso precise armazenar inteiros dentro de um vetor e printar seus ponteiros
//a linha 52 precisa estar dentro do for para apontar 1 a 1.

    int vet[10];
    int *pvet[10];
    int i;
    //Leitura do vetor
    printf("Digite 10 numeros: \n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }
    //Fazer com que o ponteiro aponte para a memoria a cada iteracao e printe os enderecos com valores.
    printf("*****Imprimir o endereco e conteudo de cada espaco: *****\n");
    for(i = 0; i < 10; i++)
    {
        pvet[i] = &vet[i];    // <<<<<<<<<<<<<<<<

        printf("O endereco de numero %d e igual a: %p e contem: %d \n", i+1, pvet[i], *pvet[i]);
    }
    
    return 0;
}

