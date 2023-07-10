#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

struct Jogador {
    int forca;
    int vida;
    int ouro;
    int numEspadasSimples;
    int numEspadasLendarias;
};

void esperarSegundos(float segundos) {
#ifdef _WIN32
    Sleep((int)(segundos * 1000));
#else
    usleep((int)(segundos * 1000000));
#endif
}

int main() {
    struct Jogador jogador;
    int vidaInimigo = 100;
    int estagio = 1;
    char opcao;
    
    jogador.forca = 10;
    jogador.vida = 50;
    jogador.ouro = 0;
    jogador.numEspadasSimples = 0;
    jogador.numEspadasLendarias = 0;
    
    printf("Bem-vindo ao jogo de dungeon!\n");
    printf("Digite '1' para jogar: ");
    scanf(" %c", &opcao);
    
    if (opcao == '1') {
        srand(time(0));  // Inicializa a semente para geração de números aleatórios
        
        while (opcao != 'N' && opcao != 'n') {
            printf("\n----- Estágio %d -----\n", estagio);
            printf("Você está no estágio %d da dungeon!\n", estagio);
            
            vidaInimigo = 100;
            
            while (vidaInimigo > 0) {
                float ataque = jogador.forca * (rand() / (float)RAND_MAX * 0.5 + 0.5);
                
                printf("Você ataca o inimigo e causa %.2f de dano!\n", ataque);
                vidaInimigo -= (int)ataque;
                
                if (vidaInimigo < 0) {
                    vidaInimigo = 0;
                }
                
                printf("Vida do inimigo: %d\n", vidaInimigo);
                
                esperarSegundos(1.5);  // Aguarda 1,5 segundos antes do próximo ataque
            }
            
            printf("Você matou o inimigo!\n");
            
            // Chance de obter loot após matar o monstro
            int chanceLoot = rand() % 100 + 1;  // Gera um número aleatório entre 1 e 100
            
            if (chanceLoot <= 60) {
                printf("Você encontrou uma \033[1;33m espada lendária\033[0m ! Ela adiciona +30 de dano à sua força!\n");
                
                if (jogador.forca < 30) {
                    jogador.forca += 30;
                } else if (jogador.forca == 20) {
                    jogador.forca = 20;
                }
                
                jogador.numEspadasLendarias++;
            } else {
                printf("Você encontrou uma espada simples! Ela adiciona +5 de dano à sua força!\n");
                
                if (jogador.forca == 10) {
                    jogador.forca += 5;
                } else if (jogador.forca == 20) {
                    jogador.forca = 20;
                }
                
                jogador.numEspadasSimples++;
            }
            
            printf("A força do jogador agora é: %d\n", jogador.forca);
            
            printf("Deseja continuar na dungeon? (S/N): ");
            scanf(" %c", &opcao);
            
            estagio++;
        }
        
        printf("\n----- Fim do jogo -----\n");
        printf("Você finalizou o jogo na dungeon do estágio %d!\n", estagio - 1);
        
        if (jogador.numEspadasSimples > 0 || jogador.numEspadasLendarias > 0) {
            printf("Você encontrou loots para vender:\n");
            
            int valorEspadaSimples = 500;
            int valorEspadaLendaria = 5000;
            int totalOuro = jogador.ouro;
            
            if (jogador.numEspadasSimples > 0) {
                printf("%d espada(s) simples\n", jogador.numEspadasSimples);
                totalOuro += jogador.numEspadasSimples * valorEspadaSimples;
            }
            
            if (jogador.numEspadasLendarias > 0) {
                printf("%d espada(s) lendária(s)\n", jogador.numEspadasLendarias);
                totalOuro += jogador.numEspadasLendarias * valorEspadaLendaria;
            }
            
            printf("Você ganhou %dG com os loots!\n", totalOuro);
        }
    }
    
    return 0;
}
