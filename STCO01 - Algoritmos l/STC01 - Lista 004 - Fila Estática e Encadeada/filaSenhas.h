// TAD para gerenciar filas com senhas de atendimento do banco

#ifndef _FILA
#define _FILA

typedef struct descritor Fila;               

// funções para gerenciar a fila de senhas
Fila* criar_senhas(int quantidade_senhas);
int retirar_senha(Fila *SE, char *senha);

// funções para gerenciar as senhas na fila
int inserir_senha_fila(Fila **fi, char *num_senha, char servico, char prioridade);
int retirar_senha_fila(Fila **fi, char *senha);

// função para verificar se a fila está vazia
int fila_vazia(Fila *fi);

#endif