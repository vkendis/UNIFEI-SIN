#ifndef TUBOS_FILA_H
#define TUBOS_FILA_H

typedef struct descritor Pilha;

Pilha* cria_pilha();

void liberar(Pilha *pi);

int empilhar(Pilha *pi, char vogal);

char desempilhar(Pilha *pi);

void consultar(Pilha *pi, Pilha *pi2, Pilha *pi3);

int tamanhoPilha(Pilha *pi);

char SelecionaCubo(Pilha *pi);

int verificar(Pilha *pi);

#endif