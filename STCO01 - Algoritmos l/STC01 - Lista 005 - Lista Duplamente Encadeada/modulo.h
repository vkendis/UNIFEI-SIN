#ifndef _MODULO
#define _MODULO

typedef struct celula Celula;

typedef struct lista {
    Celula *inicio;
    Celula *fim;
    Celula *cursor;
} ListaDupla;

typedef ListaDupla *Lista;

ListaDupla *criarLista();
Lista *criarListaAlfabeto();
int liberarLista(ListaDupla *li);
int inserirFinalLista(ListaDupla *li, char letra);
int imprimirLista(ListaDupla *li);
void manipularLista(ListaDupla *li);
void consultarLista(ListaDupla *li, int opcao);

#endif
