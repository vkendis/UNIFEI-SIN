#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula
struct celula {
    struct celula *ant;
    char letra;
    struct celula *prox;
};

// Função auxiliar para alocar uma célula
Celula *alocarCelula() {
    Celula *no = (Celula *)malloc(sizeof(Celula));
    return no;
}

// Função auxiliar para criar uma lista vazia
ListaDupla *criarLista() {
    ListaDupla *li = (ListaDupla *)malloc(sizeof(ListaDupla));
    if (li != NULL) {
        li->inicio = NULL;
        li->fim = NULL;
        li->cursor = NULL;
    }
    return li;
}

// Função auxiliar para criar uma lista com todas as letras do alfabeto
Lista *criarListaAlfabeto() {
    Lista *li = criarLista();
    if (li != NULL) {
        for (char letra = 'A'; letra <= 'Z'; letra++) {
            inserirFinalLista(li, letra);
        }
    }
    return li;
}

// Função para liberar uma lista
int liberarLista(ListaDupla *li) {
    if (li == NULL)
        return 0;

    Celula *no;
    while (li->inicio != NULL) {
        no = li->inicio;
        li->inicio = li->inicio->prox;
        free(no);
    }

    free(li);

    return 1;
}

// Função para inserir um caractere no final da lista
int inserirFinalLista(ListaDupla *li, char letra) {
    if (li == NULL)
        return 0;

    Celula *no = alocarCelula();
    if (no == NULL)
        return 0;

    no->letra = letra;
    no->ant = NULL;
    no->prox = NULL;

    if (li->inicio == NULL) {
        li->inicio = no;
        li->fim = no;
        li->cursor = no; // Atualize o cursor para o novo elemento
    } else {
        no->ant = li->fim;
        li->fim->prox = no;
        li->fim = no;
    }

    return 1;
}

// Função para imprimir a lista
int imprimirLista(ListaDupla *li) {
    if (li == NULL || li->inicio == NULL) {
        printf("\nLista vazia!\n");
        return 0;
    }

    printf("\nLISTA: ");
    Celula *aux = li->inicio;

    while (aux != NULL) {
        printf("%c", aux->letra);
        aux = aux->prox;
    }
    printf("\n");

    return 1;
}

// Função para manipular a lista
void manipularLista(ListaDupla *li) {
    int opcao;

    do {
        printf("\n\n################# MENU DE MANIPULAÇÃO #################");
        printf("\n 1 - Mostrar cursor atual");
        printf("\n 2 - Avançar uma posição");
        printf("\n 3 - Retroceder uma posição");
        printf("\n 4 - Sair (liberar lista)");
        printf("\nOpção: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (li->cursor != NULL) {
                    printf("\nCursor atual: %c", li->cursor->letra);
                } else {
                    printf("\nCursor não definido!");
                }
                break;
            case 2:
                consultarLista(li, 1); // Avança uma posição na lista
                if (li->cursor != NULL) {
                    printf("\nAvançou uma posição. Novo cursor: %c", li->cursor->letra);
                }
                break;
            case 3:
                consultarLista(li, -1); // Retrocede uma posição na lista
                if (li->cursor != NULL) {
                    printf("\nRetrocedeu uma posição. Novo cursor: %c", li->cursor->letra);
                }
                break;
            case 4:
                liberarLista(li);
                printf("\nLiberando a lista...\n");
                return;
            default:
                printf("\nOpção inválida!");
                break;
        }

    } while (opcao != 4);
}

// Função para consultar elementos da lista
void consultarLista(ListaDupla *li, int opcao) {
    if (li == NULL || li->cursor == NULL) {
        printf("\nLista vazia ou cursor não definido!\n");
        return;
    }

    if (opcao == 1) {
        if (li->cursor->prox != NULL) {
            li->cursor = li->cursor->prox;
        } else {
            printf("\nVocê já está no final da lista!\n");
        }
    } else if (opcao == -1) {
        if (li->cursor->ant != NULL) {
            li->cursor = li->cursor->ant;
        } else {
            printf("\nVocê já está no início da lista!\n");
        }
    } else {
        printf("\nOpção inválida!\n");
    }
}
