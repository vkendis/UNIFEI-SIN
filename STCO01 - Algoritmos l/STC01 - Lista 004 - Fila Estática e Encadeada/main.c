//Vinícius Kendi Sasaki
//2023013498

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bibliotecas do projeto
#include "filaSenhas.h"

// função para limpar a tela
void clearScreen(){
  system("clear");
}

// funcao principal
int main(void) {

  srand(time(NULL));
// Organizacao para gerar senhas aleatorias
  Fila *SE = NULL;
  Fila *XP = NULL;
  Fila *XC = NULL;
  Fila *NP = NULL;
  Fila *NC = NULL;

  int qnt_senhas = 0; 

  clearScreen();

  do {
    printf("\nInsira o limite diário de atendimentos: ");
    scanf("%d", &qnt_senhas);
    if (!qnt_senhas) printf("\nPor favor, insira um valor maior que 0.\n");
  }while(!qnt_senhas);

  SE = criar_senhas(qnt_senhas);
  if(SE == NULL){
    printf("\nNão foi possível criar as senhas");
    return 0;
  }

  int opcao = 0, ok = 0, atendimentos_realizados = 0, atendimento = 0, perfil = 0;
  char servico, prioridade, senha[4], cont_pref_caixa = 0, cont_pref_negocial = 0;

  // menu de opções para execuções de operações sobre a fila
  do {

    printf("\n\nMenu de opções");
    printf("\n1 - Retirar senha");
    printf("\n2 - Chamar senha");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    clearScreen();

    // opção 1 - retirar senha
    if(opcao == 1){
      clearScreen();

      printf("\n\nQual tipo de atendimento você deseja?");
      printf("\n1 - Caixa");
      printf("\n2 - Negocial");
      printf("\nInsira aqui: ");
      scanf("%d", &atendimento);

      printf("\n\nQual o seu perfil?");
      printf("\n1 - Preferencial");
      printf("\n2 - Convencional"); 
      printf("\nInsira aqui: ");
      scanf("%d", &perfil);

      Fila **fi = NULL;

      fi = atendimento == 1 ? (perfil == 1 ? &XP : &XC) : (perfil == 1 ? &NP : &NC);
      servico = atendimento == 1 ? 'X' : 'N';
      prioridade = perfil == 1 ? 'P' : 'C';

      //Limpeza de tala apos a opcao 1  
      clearScreen();

      char num_senha[4];

      if(!retirar_senha(SE, num_senha)) return 0;

      if(inserir_senha_fila(fi, num_senha, servico, prioridade)){
        printf("\n Senha cadastrada com sucesso!");
      }else{
        printf("\n Fila não criada!");
      }

    // opção 2 - chamar senha
    } else if(opcao == 2) {   



      if(fila_vazia(XP) && fila_vazia(XC) && fila_vazia(NP) && fila_vazia(NC)){

        printf("\n TODAS VAZIAS");


        // Todas filas vazias

      }else{


        Fila **fila = NULL;
        int vazia = 0;


        Fila **fila_sorteada = NULL;
        char fila_sorteada_txt[2] = {' ', ' '};
        do {

          int num = rand() % 2;

          printf("num: %d\n", num);

          fila_sorteada = num == 1 ? (cont_pref_caixa >= 2 ? &XC : &XP) : (cont_pref_negocial >= 2 ? &NC : &NP);
          fila_sorteada_txt[0] = num == 1 ? 'X' : 'N';
          fila_sorteada_txt[1] = (cont_pref_caixa >= 2 || cont_pref_negocial >= 2) ? 'C' : 'P';
        
          vazia = fila_vazia(*fila_sorteada);
        } while(vazia);

        if(fila_sorteada_txt[0] == 'X'){
          cont_pref_caixa = fila_sorteada_txt[1] == 'P' ? cont_pref_caixa + 1 : 0;
        } else {
          cont_pref_negocial = fila_sorteada_txt[1] == 'P' ? cont_pref_negocial + 1 : 0;
        }

        char senha[4];

        ok = retirar_senha_fila(fila_sorteada, senha);

        if(ok == 1){
          printf("\n Senha: %s", senha);
        }else{
          printf("\n Erro!");
        } 
      }

    } else{
      printf("\nOpção inválida!");
    } 

  }while(!atendimentos_realizados);

  return 0;
}