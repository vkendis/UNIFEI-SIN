.data
A:  .space 16           # Aloca 16 bytes para o array A
B:  .space 24           # Aloca 24 bytes para o array B

.text
.globl main

main:
    li $t0, 0            # Inicializa $t0 com 0
ler_a:
    bge $t0, 16, ler_b   # Se $t0 >= 16, vá para ler_b
    li $v0, 5            # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall              # Chama a syscall para ler um inteiro
    sw $v0, A($t0)       # Armazena o valor lido na posição A[$t0]
    addi $t0, $t0, 4     # Incrementa $t0 em 4
    j ler_a              # Volta para ler_a

ler_b:
    li $t1, 0            # Inicializa $t1 com 0
ler_b_loop:
    bge $t1, 24, encontrar_comum   # Se $t1 >= 24, vá para encontrar_comum
    li $v0, 5                      # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall                        # Chama a syscall para ler um inteiro
    sw $v0, B($t1)                 # Armazena o valor lido na posição B[$t1]
    addi $t1, $t1, 4               # Incrementa $t1 em 4
    j ler_b_loop                   # Volta para ler_b_loop

encontrar_comum:
    jal contar_elementos_comuns    # Chama a função contar_elementos_comuns

    move $a0, $s0         # Move o resultado (número de elementos comuns) para $a0
    li $v0, 1             # Coloca 1 em $v0 para chamar a impressão de inteiro (syscall 1)
    syscall               # Chama a syscall para imprimir o inteiro

    li $v0, 10            # Coloca 10 em $v0 para encerrar o programa (syscall 10)
    syscall               # Chama a syscall para encerrar o programa

contar_elementos_comuns:
    li $s0, 0             # Inicializa $s0 com 0 (contador de elementos comuns)
    li $t3, 0             # Inicializa $t3 com 0 (índice para array A)
loop_a:
    bge $t3, 16, fim_contagem  # Se $t3 >= 16, vá para fim_contagem
    lw $t4, A($t3)             # Carrega o valor de A[$t3] em $t4
    li $t5, 0                  # Inicializa $t5 com 0 (índice para array B)
loop_b:
    bge $t5, 24, proximo_a     # Se $t5 >= 24, vá para proximo_a
    lw $t6, B($t5)             # Carrega o valor de B[$t5] em $t6
    beq $t4, $t6, incrementar  # Se $t4 == $t6, vá para incrementar
    addi $t5, $t5, 4           # Incrementa $t5 em 4
    j loop_b                   # Volta para loop_b
incrementar:
    addi $s0, $s0, 1           # Incrementa o contador $s0
proximo_a:
    addi $t3, $t3, 4           # Incrementa $t3 em 4
    j loop_a                   # Volta para loop_a
fim_contagem:
    jr $ra                     # Retorna para a função chamadora

