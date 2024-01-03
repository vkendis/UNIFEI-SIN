#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

struct elemento{
    char vogal;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};

Pilha* cria_pilha()
{
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}

void liberar(Pilha *pi){
  if(pi != NULL){
    Elemento *atual;


    if(pi->inicio == NULL)
        pi->fim = NULL;
    else{
      while (pi->fim != NULL){
        atual = pi->inicio;
        pi->inicio = atual->prox;
        free(atual);

        if(pi->inicio == NULL)
          pi->fim = NULL;

      }
    }
    free(pi);
  }
}

Elemento* cria_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL)
        return 0;

    return no;
}

int empilhar(Pilha *pi, char vogal){

    if(pi == NULL)
        return -1;

    Elemento *no;
    no = cria_elemento();

    if(pi->fim == NULL){
        no->vogal = vogal;
        no->prox = NULL;

        pi->inicio = no;
        pi->fim = no;
        pi->quant++;
    }
    else{
        Elemento *atual;
        atual = pi->inicio;

        no->vogal = vogal;
        no->prox = atual;

        pi->inicio = no;
        pi->quant++;
    }
    return 1;
}

char desempilhar(Pilha *pi){

    char v = ' ';

    if(pi == NULL){
        return -1;
    }

    if(pi->fim == NULL){
        pi->inicio = NULL;
        pi->quant = 0;

        return v;
    }
    else{
        Elemento *atual = pi->inicio;
        v = atual->vogal;
        pi->inicio = atual->prox;
        pi->quant--;
        free(atual);

        return v;
    }
}

void consultar(Pilha *pi, Pilha *pi2, Pilha *pi3)
{
    Elemento *atual = pi->inicio;
    Elemento *atual2 = pi2->inicio;
    Elemento *atual3 = pi3->inicio;

    printf("|P1| |P2| |P3|");
    printf("\n\n");

    for(int i = 0; i < 5; i++){
        if(i < pi->quant){
            printf("| %c|", atual->vogal);
            atual = atual->prox;
        }
        else
            printf("|  |");

        if(i < pi2->quant){
            printf(" | %c|", atual2->vogal);
            atual2 = atual2->prox;
        }
        else
            printf(" |  |");
        if(i < pi3->quant){
            printf(" | %c|", atual3->vogal);
            atual3 = atual3->prox;
        }else
            printf(" |  |");
        printf("\n");
    }
}

int tamanhoPilha(Pilha *pi)
{
    if(pi == NULL)
        return -1;
    return pi->quant;
}

char SelecionaCubo(Pilha *pi)
{
    if(pi->quant == 0)
        return 'z';
    else
        return pi->inicio->vogal;
}

int verificar(Pilha *pi){

    int vet[5] = {'A','E','I','O','U'};
    int cont = 0;

    Elemento *atual = pi->inicio;
    if(pi->quant == 5){
        for(int i = 0; i < pi->quant; i++){
            if(atual->vogal == vet[i])
                cont++;
            atual = atual->prox;
        }

        if(cont == 5)
            return 1;
        else
            return 0;

    }else
        return 0;

}
