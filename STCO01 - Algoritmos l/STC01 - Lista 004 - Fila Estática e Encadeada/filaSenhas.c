// TAD para gerenciar filas com senhas de atendimento do banco

#include <stdio.h>
#include <stdlib.h>

#include "filaEncadeada.h"

// funções para gerenciar a fila de senhas
Fila* criar_senhas(int quantidade_senhas){
  Fila *SE = criar_fila();
  for(int i = 0; i <= quantidade_senhas; i++){

    char num[4] = {' '};
    if(i < 10){
      num[0] = '0';
      num[1] = i + '0';
    }else{
      sprintf(num, "%d", i);
    }
    enfileirar(SE, num);
  }

  return SE;
}

int retirar_senha(Fila *SE, char *senha){

  if(SE == NULL) return 0;

  if(!consultar_inicio_fila(SE, senha)) return 0;

  return desenfileirar(SE);
}

// funções para gerenciar as senhas na fila
int inserir_senha_fila(Fila **fi, char *num_senha, char servico, char prioridade){

  if(*fi == NULL){
    *fi = criar_fila();
    if(*fi == NULL) return 0; 
  }

  char senha[4];

  senha[0] = servico;
  senha[1] = prioridade;
  senha[2] = num_senha[0];
  senha[3] = num_senha[1];

  if(!enfileirar(*fi, senha)) return 0;
  if(!imprimir_fila(*fi)) return 0;

  return 1;
}

int retirar_senha_fila(Fila **fi, char *senha){
  if(*fi == NULL) return 0;

  if(!consultar_inicio_fila(*fi, senha)) return 0;

  return desenfileirar(*fi);
}

// função para verificar se a fila está vazia
//Verificar o criterio de parada***
int fila_vazia(Fila *fi){
  return (int)tamanho_fila(fi) <= 0;
}
