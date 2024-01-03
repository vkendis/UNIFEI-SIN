#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ListaDupla *li =
      criarLista(); // Cria a lista vazia para as letras selecionadas
  char letra = 'A';
  int opcao;
  Lista *listaAlfabeto =
      criarListaAlfabeto(); // Cria a lista com todas as letras do alfabeto

  do {
    printf("\n\n################# MENU DE OPCOES #################");
    printf("\n 0 - Sair");
    printf("\n 1 - Avançar letra");
    printf("\n 2 - Retroceder letra");
    printf("\n 3 - Confirmar inserção (Letra atual: %c)", letra);
    printf("\n 4 - Imprimir nova lista");
    printf("\n 5 - Manipular lista");
    printf("\nOpção: ");

    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      liberarLista(li);
      liberarLista(listaAlfabeto);
      printf("\nFinalizando...\n\n");
      return 0;
    case 1:
      if (letra < 'Z') {
        letra++;
      }
      break;
    case 2:
      if (letra > 'A') {
        letra--;
      }
      break;
    case 3: {
      char letraSelecionada = letra;
      inserirFinalLista(li, letraSelecionada);
      printf("\nLetra %c inserida na nova lista!", letraSelecionada);
      break;
    }
    case 4:
      printf("\nNova lista: ");
      imprimirLista(li);
      break;
    case 5:
      manipularLista(li);
      break;
    default:
      printf("\nOpção inválida!");
      break;
    }

    fflush(stdin); // Limpa o buffer de entrada

  } while (opcao != 0);

  return 0;
}
