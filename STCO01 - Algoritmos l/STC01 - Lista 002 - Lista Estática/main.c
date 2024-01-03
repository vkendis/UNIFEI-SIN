/*
Criar uma struct em TAD com as seguintes funcoes:
1 - Buscar e retornar o produto de menor preco
2 - Remover, se possivel, os n ultimos elementos da lista
3 - Receber a posicao de 2 elementos da lista e trocar de lugar
4 - Imprimir Lista
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main () {
    ListaEstatica*lista = criar_lista();

    int opcao;
    int inserido;
    //Menu para operacoes da lista encadeada
    do {
        printf("\nMenu de Opções:\n");
        printf("1. Inserir Produto\n");
        printf("2. Buscar Produto de Menor Preço\n");
        printf("3. Remover N últimos Elementos\n");
        printf("4. Trocar Posição de Dois Elementos\n");
        printf("5. Imprimir Lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Produto produto;
                printf("Digite o código do produto: ");
                scanf("%d", &produto.codigo);
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", produto.nome);
                printf("Digite o preço do produto: ");
                scanf("%f", &produto.preco);
                printf("Digite a quantidade do produto: ");
                scanf("%d", &produto.qtd);

                inserido = inserir_elemento(lista, produto);
                if (inserido) {
                    printf("Produto inserido com sucesso.\n");
                } else {
                    printf("Não foi possível inserir o produto. Lista cheia.\n");
                }
                break;
            }
            case 2: {
                Produto* menor_preco = buscar_menor_preco(lista);
                if (menor_preco != NULL) {
                    printf("Produto de menor preço:\n");
                    printf("Código: %d, Nome: %s, Preço: %.2f, Quantidade: %d\n",
                           menor_preco->codigo, menor_preco->nome,
                           menor_preco->preco, menor_preco->qtd);
                } else {
                    printf("Lista vazia, nenhum produto para buscar.\n");
                }
                break;
            }
            case 3: {
                int n;
                printf("Digite a quantidade de elementos a serem removidos: ");
                scanf("%d", &n);

                int removidos = remover_n_elementos(lista, n);
                if (removidos) {
                    printf("%d últimos elementos removidos com sucesso.\n", n);
                } else {
                    printf("Não foi possível remover os elementos. Lista insuficiente.\n");
                }
                break;
            }
            // Efetuar Bubble para troca de elementos
            case 4: {
                int posicao1, posicao2;
                printf("Digite a posição do primeiro elemento: ");
                scanf("%d", &posicao1);
                printf("Digite a posição do segundo elemento: ");
                scanf("%d", &posicao2);

                int troca = trocar_elementos(lista, posicao1, posicao2);
                if (troca) {
                    printf("Elementos nas posições %d e %d trocados de lugar.\n", posicao1, posicao2);
                } else {
                    printf("Não foi possível trocar os elementos. Posições inválidas.\n");
                }
                break;
            }
            case 5: {
                printf("Produtos na lista:\n");
                imprimir_lista_recursivamente(lista, 0);
                break;
            }
            case 0: {
                printf("Encerrando o programa.\n");
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    free(lista);

    return 0;
}

    