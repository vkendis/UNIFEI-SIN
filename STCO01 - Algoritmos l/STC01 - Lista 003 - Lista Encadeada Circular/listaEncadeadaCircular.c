#include "listaEncadeadaCircular.h"
#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento* prox;
};

// Implementação das funções

Lista* criar_lista() {
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

int liberar_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou já está vazia
    }
    struct elemento* aux, * no = *li;
    while ((*li) != no->prox) {
        aux = no;
        no = no->prox;
        free(aux);
    }
    free(no);
    free(li);
    return 1;
}

int tamanho_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    int cont = 0;
    struct elemento* no = *li;
    do {
        cont++;
        no = no->prox;
    } while (no != (*li));
    return cont;
}

int lista_vazia(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 1; // Lista não existe ou está vazia
    }
    return 0; // Lista não está vazia
}

int lista_cheia(Lista* li) {
    return 0; // Uma lista encadeada nunca fica cheia em C
}

int inserir_lista_inicio(Lista* li, int dado) {
    if (li == NULL) {
        return 0; // Lista não existe
    }
    struct elemento* novo = (struct elemento*)malloc(sizeof(struct elemento));
    if (novo == NULL) {
        return 0; // Falha na alocação
    }
    novo->dado = dado;
    if (*li == NULL) {
        novo->prox = novo; // Lista vazia, aponta para si mesmo
    } else {
        struct elemento* ultimo = *li;
        while (ultimo->prox != *li) {
            ultimo = ultimo->prox;
        }
        novo->prox = *li;
        ultimo->prox = novo;
    }
    *li = novo; // Novo elemento se torna o início da lista
    return 1;
}

int inserir_lista_final(Lista* li, int dado) {
    if (li == NULL) {
        return 0; // Lista não existe
    }
    struct elemento* novo = (struct elemento*)malloc(sizeof(struct elemento));
    if (novo == NULL) {
        return 0; // Falha na alocação
    }
    novo->dado = dado;
    if (*li == NULL) {
        novo->prox = novo; // Lista vazia, aponta para si mesmo
        *li = novo; // Novo elemento se torna o início da lista
    } else {
        struct elemento* aux = *li;
        while (aux->prox != *li) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = *li;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, int dado) {
    if (li == NULL) {
        return 0; // Lista não existe
    }
    struct elemento* novo = (struct elemento*)malloc(sizeof(struct elemento));
    if (novo == NULL) {
        return 0; // Falha na alocação
    }
    novo->dado = dado;
    if (*li == NULL) {
        novo->prox = novo; // Lista vazia, aponta para si mesmo
        *li = novo; // Novo elemento se torna o início da lista
        return 1;
    } else {
        struct elemento* ant = NULL;
        struct elemento* atual = *li;
        while (atual->dado < dado) {
            ant = atual;
            atual = atual->prox;
            if (atual == *li) break; // Volta ao início da lista
        }
        if (ant == NULL) {
            // Inserir no início da lista
            struct elemento* ultimo = *li;
            while (ultimo->prox != *li) {
                ultimo = ultimo->prox;
            }
            novo->prox = *li;
            ultimo->prox = novo;
            *li = novo; // Novo elemento se torna o início da lista
        } else {
            ant->prox = novo;
            novo->prox = atual;
        }
        return 1;
    }
}

int remover_lista_inicio(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    if (*li == (*li)->prox) {
        free(*li);
        *li = NULL;
        return 1;
    }
    struct elemento* no = *li;
    struct elemento* ultimo = *li;
    while (ultimo->prox != *li) {
        ultimo = ultimo->prox;
    }
    *li = no->prox;
    ultimo->prox = *li;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    if (*li == (*li)->prox) {
        free(*li);
        *li = NULL;
        return 1;
    }
    struct elemento* ant = NULL;
    struct elemento* no = *li;
    while (no->prox != *li) {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remover_lista_meio(Lista* li, int codigo) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    struct elemento* ant = NULL;
    struct elemento* no = *li;
    while (no->dado != codigo) {
        ant = no;
        no = no->prox;
        if (no == *li) {
            return 0; // Elemento não encontrado
        }
    }
    if (ant == NULL) {
        // Remover o primeiro elemento
        struct elemento* ultimo = *li;
        while (ultimo->prox != *li) {
            ultimo = ultimo->prox;
        }
        *li = no->prox;
        ultimo->prox = *li;
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int buscar_lista_posicao(Lista* li, int pos, int* dado) {
    if (li == NULL || *li == NULL || pos <= 0) {
        return 0; // Lista não existe, está vazia ou posição inválida
    }
    struct elemento* no = *li;
    int cont = 1;
    do {
        if (cont == pos) {
            *dado = no->dado;
            return 1; // Elemento encontrado
        }
        cont++;
        no = no->prox;
    } while (no != (*li));
    return 0; // Elemento não encontrado
}

int buscar_lista_dado(Lista* li, int dado, int* pos) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    struct elemento* no = *li;
    int cont = 1;
    do {
        if (no->dado == dado) {
            *pos = cont;
            return 1; // Elemento encontrado
        }
        cont++;
        no = no->prox;
    } while (no != (*li));
    return 0; // Elemento não encontrado
}

int imprimir_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    struct elemento* no = *li;
    do {
        printf("%d ", no->dado);
        no = no->prox;
    } while (no != (*li));
    printf("\n");
    return 1;
}

int concat_listas(Lista* li, Lista* li2) {
    if (li == NULL || *li == NULL || li2 == NULL || *li2 == NULL) {
        return 0; // Alguma das listas não existe ou está vazia
    }
    struct elemento* ultimo1 = *li;
    while (ultimo1->prox != *li) {
        ultimo1 = ultimo1->prox;
    }
    struct elemento* primeiro2 = *li2;
    struct elemento* ultimo2 = *li2;
    while (ultimo2->prox != *li2) {
        ultimo2 = ultimo2->prox;
    }
    ultimo1->prox = primeiro2;
    ultimo2->prox = *li;
    free(li2); // Liberar a lista li2
    *li2 = NULL; // Apontar li2 para NULL
    return 1;
}

int eliminar_numeros_repetidos(Lista *li) {
  if (li == NULL || *li == NULL) {
    return 0; // Lista não existe ou está vazia
  }

  int existeRepetido = 0; // Variável para verificar se existem números repetidos

  struct elemento *atual = *li;
  struct elemento *outro, *anterior;

  do {
    outro = atual->prox;
    anterior = atual;

    while (outro != *li) {
      if (outro->dado == atual->dado) {
        // Número repetido encontrado, remove o 'outro'
        anterior->prox = outro->prox;
        free(outro);
        outro = anterior->prox;

        existeRepetido = 1;
      } else {
        // Não é repetido, avança para o próximo
        anterior = outro;
        outro = outro->prox;
      }
    }

    atual = atual->prox;
  } while (atual != *li);

  if (existeRepetido) {
    return 1; // Números repetidos eliminados
  } else {
    return 0; // Sem números repetidos
  }
}


int inverter_numeros(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    struct elemento* anterior = NULL;
    struct elemento* atual = *li;
    struct elemento* proximo = NULL;
    do {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    } while (atual != (*li));
    (*li)->prox = anterior;
    *li = anterior; // Atualizar o início da lista
    return 1;
}
int ordem_ordenada(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0; // Lista não existe ou está vazia
    }
    
    struct elemento* atual = *li;
    
    while (atual->prox != *li) {
        if (atual->dado > atual->prox->dado) {
            return 0; // Lista não está em ordem ordenada
        }
        atual = atual->prox;
    }
    
    return 1; // Lista está em ordem ordenada
}