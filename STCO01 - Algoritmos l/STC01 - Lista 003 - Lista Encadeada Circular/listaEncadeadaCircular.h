#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct elemento* Lista;

Lista* criar_lista();
int liberar_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);
int buscar_lista_posicao(Lista *li, int pos, int *dado);
int buscar_lista_dado(Lista *li, int dado, int *pos);
int imprimir_lista(Lista *li);
int concat_listas(Lista *li, Lista *li2);
int eliminar_numeros_repetidos(Lista *li);
int inverter_listas(Lista* li, Lista* li2);

#endif
