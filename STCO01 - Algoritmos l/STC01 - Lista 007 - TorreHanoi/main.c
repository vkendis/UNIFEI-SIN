#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"


int menu();
int main(void)
{   
    Pilha *tubo1;
    Pilha *tubo2;
    Pilha *tubo3;
    int ok, i, opcao, opcao2;
    char vet[5] = {'U', 'O', 'I', 'E', 'A'};
    char aux, T1, T2, T3;

    tubo1 = cria_pilha();
    tubo2 = cria_pilha();
    tubo3 = cria_pilha();

    for(i = 0; i < 5; i++)
        ok = empilhar(tubo1, vet[i]);

    do{
        consultar(tubo1, tubo2, tubo3);
        printf("\nEm que tubo você quer colocar a primeira vogal?");
        printf("\n\n");
        printf("1 - P2\n");
        printf("2 - P3\n");
        scanf("%d", &opcao);
        system("clear");
    }while(opcao != 1 && opcao != 2);

    if(opcao == 1){
      aux = desempilhar(tubo1);
      empilhar(tubo2, aux);
      system("clear");
    }
    if(opcao == 2){
      aux = desempilhar(tubo1);
      empilhar(tubo3, aux);
      system("clear");
    }

    do{
      do{
        consultar(tubo1, tubo2, tubo3);
        opcao = menu();
        system("clear");
      }while (opcao != 1 && opcao != 2 && opcao != 3);


    // opcaoção 1
      if(opcao == 1){
        T1 = SelecionaCubo(tubo1);
        if(T1 == 'z'){
          printf("\nOperação não é permitida, pois o tubo está vazio.\n\n");
          consultar(tubo1, tubo2, tubo3);
        }
        else{
          do{
            consultar(tubo1, tubo2, tubo3);
            printf("\nOnde deseja colocar a vogal retirada?\n\n");
            printf("1 - P2\n");
            printf("2 - P3\n");
            scanf("%d", &opcao2);
            system("clear");
          }while(opcao2 != 1 && opcao2 != 2);
          if(opcao2 == 1){
            T2 = SelecionaCubo(tubo2);
          if(T2 == 'z'){
            aux = desempilhar(tubo1);
            empilhar(tubo2, aux);
            system("clear");
          }
          else{
            if(T1 < T2){
              aux = desempilhar(tubo1);
              empilhar(tubo2, aux);
              system("clear");
            }
            else
              printf("\nNão foi possível realizar a operação, pois %c > %c\n\n",T1, T2);
            }
          }

          if(opcao2 == 2){
            T3 = SelecionaCubo(tubo3);
            if(T3 == 'z'){
              aux = desempilhar(tubo1);
              empilhar(tubo3, aux);
              system("clear");
          }
          else{
          if(T1 < T3){
            aux = desempilhar(tubo1);
            empilhar(tubo3, aux);
            system("clear");
          }
          else
            printf("\nNão foi possível realizar a operação, pois %c > %c\n\n",T1, T3);
          }
        }
      }
    }

        // opcaoção 2
        if(opcao == 2){
          T2 = SelecionaCubo(tubo2);
          if(T2 == 'z'){
            printf("\nOperação não permitida, pois o tubo está vazio.\n\n");
        }
        else{
          do{
            consultar(tubo1, tubo2, tubo3);
            printf("\nOnde deseja colocar a vogal retirada?\n\n");
            printf("1 - P1\n");
            printf("2 - P3\n");
            scanf("%d", &opcao2);
            system("clear");
        }while(opcao2 != 1 && opcao2 != 2);

        if(opcao2 == 1){
          T1 = SelecionaCubo(tubo1);
          if(T1 == 'z'){
            aux = desempilhar(tubo2);
            empilhar(tubo1, aux);
            system("clear");
          }
          else{
          if(T2 < T1){
            aux = desempilhar(tubo2);
            empilhar(tubo1, aux);
            system("clear");
          }
          else
            printf("Não foi possível realizar a operação, pois %c > %c\n\n",T2, T1);
          }
        }
        else if(opcao == 2){
          T3 = SelecionaCubo(tubo3);
          if(T3 == 'z'){
            aux = desempilhar(tubo2);
            empilhar(tubo3, aux);
            system("clear");
          }
          else{
          if(T2 < T3){
            aux = desempilhar(tubo2);
            empilhar(tubo3, aux);
            system("clear");
          }
          else
            printf("Não foi possível realizar a operação, pois %c > %c\n\n",T2, T3);
              }
            }
          }
        }

        // opcaoção 3
        if(opcao == 3){
          T3 = SelecionaCubo(tubo3);
          if(T3 == 'z')
            printf("Operação não é permitida, pois o tubo está vazio.\n");
            else{
              do{
                consultar(tubo1, tubo2, tubo3);
                printf("Onde deseja colocar a vogal retirada?\n");
                printf("1 - P1\n");
                printf("2 - P2\n");
                scanf("%d", &opcao2);
                system("clear");
              }while(opcao2 != 1 && opcao2 != 2);

            if(opcao2 == 1){
              T1 = SelecionaCubo(tubo1);
              if(T1 == 'z'){
                aux = desempilhar(tubo3);
                empilhar(tubo1, aux);
                system("clear");
              }
              else{
              if(T3 < T1){
                aux = desempilhar(tubo3);
                empilhar(tubo1, aux);
                system("clear");
              }
              else
                printf("Não foi possível realizar a operação, pois %c > %c\n\n",T3, T1);
                }
              }
              else if(opcao2 == 2){
                T2 = SelecionaCubo(tubo2);
              if(T2 == 'z'){
                aux = desempilhar(tubo3);
                empilhar(tubo2, aux);
                system("clear");
              }
              else{
              if(T3 < T2){
                aux = desempilhar(tubo3);
                empilhar(tubo2, aux);
                system("clear");
              }
              else
                printf("Não foi possível realizar a operação, pois %c > %c\n\n",T3, T2);
              }
            }
          }
        }

      ok = verificar(tubo3);
  }while(ok != 1);

  liberar(tubo1);
  liberar(tubo2);
  liberar(tubo3);

  printf("\n\n");
  printf("PARABÉNS! VOCÊ CONSEGUIU!");
  printf("\n\n");

  return 0;
}

int menu(){
  int opcao;

  printf("\nDe qual tubo você deseja retirar a vogal?");
  printf("\n\n");
  printf("1 - P1\n");
  printf("2 - P2\n");
  printf("3 - P3\n");
  scanf("%d", &opcao);
  return opcao;
}