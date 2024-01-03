// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "listaEncadeadaCircular.h"

int criar_dado(int *dado);

int main(void) {

  Lista *li = NULL;
  int opcao, dado, ok, pos;
  Lista *li2 = criar_lista();
  inserir_lista_final(li2, 5);
  inserir_lista_final(li2, 6);
  inserir_lista_final(li2, 7); 

  do {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");  
    printf("\n12 - Concatenar Lista 1 e Lista 2");
    printf("\n13 - Eliminar numeros repetidos da lista");
    printf("\n14 - Inverter Lista");
    printf("\n15 - Verificar ordenacao");
    printf("\n16 - Verificar tamanho");
    printf("\n17 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1: 
        li = criar_lista();
        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;

      case 2: 
        ok = liberar_lista(li);
        li = NULL; 
        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:
        ok = criar_dado(&dado);               
        ok = inserir_lista_inicio(li, dado);
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
        break;

      case 4:
        ok = criar_dado(&dado);
        ok = inserir_lista_final(li, dado);
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
        break;

      case 5:
        ok = criar_dado(&dado);
        ok = inserir_lista_ordenada(li, dado);
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
        break;

      case 6:    
        ok = remover_lista_inicio(li);
        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:   
        ok = remover_lista_final(li);
        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:
        printf("\nQual dado deseja remover: ");
        ok = scanf("%d", &dado);
        ok = remover_lista_meio(li, dado);
        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 9:
        printf("\nQual posição deseja buscar: ");
        ok = scanf("%d", &pos);
        ok = buscar_lista_posicao(li, pos, &dado);
        if(ok == 1){
          printf("\n O dado que está na posição %d é %d", pos, dado);
        }else{
          printf("\n Posição não encontrada!");
        }
        break;

      case 10:  
        printf("\nQual dado deseja buscar: ");
        ok = scanf("%d", &dado);
        ok = buscar_lista_dado(li, dado, &pos);
        if(ok == 1){
          printf("\n O dado %d está na posição %d", dado, pos);
        }else{
          printf("\n Dado não encontrado!");
        }
        break;

      case 11:  
        ok = imprimir_lista(li);
        break;

      case 12:
        ok = concat_listas(li, li2);
        if(ok == 1){
          printf("\n Concatenação realizada com sucesso!");
        }else{
          printf("\n Falha na concatenação!");
        }
        break;

      case 13:
        
        // Eliminar numeros repetidos
        if (eliminar_numeros_repetidos(li))
        {
            printf("\n Números repetidos eliminados!");
        }   else {
            printf("\n Sem números repetidos.");
        }
        break;

      case 14:
        ok = inverter_numeros(li);
        if(ok == 1){
          printf("\n Lista invertida com sucesso!");
        }else{
          printf("\n Falha na inversão!");
        }
        break;

      case 15:
        if(ordem_ordenada(li)){
          printf("\n 0");
        }else{
          printf("\n 2");
        }
        break;

      case 16:
        pos = tamanho_lista(li);
        printf("\n Tamanho da lista: %d", pos);
        break;

      case 17:
        printf("\n Programa finalizado!");
        ok = liberar_lista(li);
        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }
  }while(opcao != 17);
  return 0;
}

int criar_dado(int *dado){
  printf("\nInforme o dado: ");
  return scanf("%d", dado);
}