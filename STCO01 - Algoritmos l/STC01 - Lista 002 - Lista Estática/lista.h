#ifndef LISTA_H
#define LISTA_h

#define MAX_TAMANHO 100

//Passo 1: Criar a struct 
struct Produto {
    int codigo;
    char nome[30];
    float preco;
    int qtd;
};
//Renomear struct para Produto
typedef struct Produto Produto;

typedef struct ListaEstatica {
    Produto elementos[MAX_TAMANHO];
    int tamanho;
}ListaEstatica;

ListaEstatica* criar_lista();
int inserir_elemento(ListaEstatica* lista, Produto produto);
Produto* buscar_menor_preco(ListaEstatica* lista);
int remover_n_elementos(ListaEstatica* lista, int n);
int trocar_elementos(ListaEstatica* lista, int posicao1, int posicao2);
void imprimir_lista_recursivamente(ListaEstatica* lista, int index);




#endif