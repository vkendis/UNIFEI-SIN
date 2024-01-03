// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaEncadeada.h"


//criando Elemento
typedef struct elemento{
    char dado[4];
    struct elemento *prox;
} Elemento;

//criando nó descritor
struct descritor{
    Elemento *inicio;
    Elemento *fim;
    int quant;
};


// função para alocar memória do tipo Fila
Fila* criar_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi)
{

  if(fi == NULL){    
    return 0;
  }

  Elemento *atual;

  while(fi->inicio != NULL){    
    atual = fi->inicio;
    fi->inicio = fi->inicio->prox;
    fi->quant--;
    free(atual);
  }

  free(fi);  

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
    return (Elemento*) malloc(sizeof(Elemento));
}


// função para inserir elemento no final da fila 
int enfileirar(Fila *fi, char dado[4])
{
  if(fi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  strcpy(no->dado, dado);
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if(fi->inicio == NULL){    
    fi->inicio = no;  

  // senão insere elemento no final da fila  
  }else{
    (fi->fim)->prox = no;    
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila // 
int desenfileirar(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  // fila vazia, não remove nada
  if(fi->inicio == NULL){
    return 0;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if(fi->inicio == NULL){
    fi->fim = NULL;
  }

  return 1;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, char *dado)
{
  // verifica se a fila foi criada corretamente e se não está vazia
  if(fi == NULL || fi->inicio == NULL){
    return 0;
  }

  // copia o dado do início da fila

  dado[0] = fi->inicio->dado[0];
  dado[1] = fi->inicio->dado[1];

  // printf("Dado: %s", dado);

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi)
{
    if(fi == NULL){
        return -1;
    }
    return fi->quant;
}

int imprimir_fila(Fila *fi){

  if(fi == NULL) return -1;
  if(tamanho_fila(fi) <= 0) return 0;

  Elemento *aux = fi->inicio;
  while(aux != NULL){
    char senha[4];
    printf(" %s ", aux->dado);
    aux = aux->prox;
  }
  printf("\n");

  return 1;
}