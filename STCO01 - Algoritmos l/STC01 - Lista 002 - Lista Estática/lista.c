#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
    

ListaEstatica* criar_lista() {
    ListaEstatica* lista = (ListaEstatica*)malloc(sizeof(ListaEstatica));
    if (lista == NULL) {
        return NULL; // Falha na alocação de memória
    }
    
    lista->tamanho = 0; // Inicializa o tamanho como zero
    return lista; // Retorna o ponteiro para a lista alocada
}


int inserir_elemento(ListaEstatica* lista, Produto produto) {
    if(lista->tamanho >= MAX_TAMANHO) {
        return 0; //Caso de lista cheia 
    }

    lista->elementos[lista->tamanho] = produto;
    lista->tamanho++;
    return 1; // Caso de sucesso para insercao
}

//Funcao para busca o menor preco 
Produto* buscar_menor_preco(ListaEstatica* lista) {
    if(lista->tamanho == 0) {
        return NULL; //Sem itens para busca
    }
// O ponteiro foi inicializado para o indice[0], apos isso, o preco do indice 0 foi comparado com os elementos de indice 1 a "tamanho". O menor preco atribui o conteudo do endereco de memoria 
    Produto* menor_preco = &lista->elementos[0];

    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->elementos[i].preco < menor_preco->preco) {
            menor_preco = &lista->elementos[i];
        }
    }
    return menor_preco;
}

//Funcao para remover n elementos da lista
//Verifica se o tamnho atual da lista e menor do que n
int remover_n_elementos(ListaEstatica* lista, int n) {
    if (lista->tamanho < n){
        return 0;
    }

    lista->tamanho -=n; //
    return 1; //Sucesso na remocao
}

//Funcao para trocar elemento da lista

int trocar_elementos(ListaEstatica* lista, int posicao1, int posicao2) {
    if(posicao1 < 0 || posicao2 < 0 || posicao1 >= lista->tamanho || posicao2 >= lista->tamanho) {
        return 0; //Verificao de posicoes invalidas
    }
    //Bubble para corrigir posicionamento 

    Produto temp = lista->elementos[posicao1];
    lista->elementos[posicao1] = lista->elementos[posicao2];
    lista->elementos[posicao2] = temp;

    return 1; // Troca correta
}

//Funcao para imprimir lista atual
// Imprimir a lista de acordo com o incremento do indice
void imprimir_lista_recursivamente(ListaEstatica* lista, int index) {
    if (index >= lista->tamanho) { //Condicao de parada para recursao 
        return; 
    }

    printf("Código: %d, Nome: %s, Preço: %.2f, Quantidade: %d\n",
           lista->elementos[index].codigo, lista->elementos[index].nome,
           lista->elementos[index].preco, lista->elementos[index].qtd);

    imprimir_lista_recursivamente(lista, index + 1); // Chamada recursiva
}
