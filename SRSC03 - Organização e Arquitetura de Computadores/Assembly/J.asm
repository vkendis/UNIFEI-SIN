.data
    array: .space 24       # Aloca 24 bytes para o array (suficiente para 6 inteiros de 4 bytes cada)
.text
.globl main

main:
    li $t0, 0              # Inicializa $t0 com 0 (índice do array)
    li $t1, 6              # Inicializa $t1 com 6 (número de elementos a serem lidos)

read_loop:
    li $v0, 5              # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall                # Chama a syscall para ler um inteiro
    sw $v0, array($t0)     # Armazena o valor lido na posição array[$t0]
    addi $t0, $t0, 4       # Incrementa $t0 em 4 (próxima posição do array)
    subi $t1, $t1, 1       # Decrementa $t1 em 1
    bnez $t1, read_loop    # Se $t1 não for zero, volta para read_loop

    la $a0, array          # Carrega o endereço base do array em $a0
    jal find_max           # Chama a função find_max

    add $a0, $v0, $zero    # Move o valor máximo encontrado para $a0
    li $v0, 1              # Coloca 1 em $v0 para chamar a impressão de inteiro (syscall 1)
    syscall                # Chama a syscall para imprimir o inteiro
    li $v0, 10             # Coloca 10 em $v0 para encerrar o programa (syscall 10)
    syscall                # Chama a syscall para encerrar o programa

find_max:
    li $t2, -2147483648    # Inicializa $t2 com o menor inteiro possível (valor mínimo)
    li $t3, 0              # Inicializa $t3 com 0 (contador de índice, não usado)
    li $t4, 6              # Inicializa $t4 com 6 (número de elementos a serem verificados)

max_loop:
    lw $t5, 0($a0)         # Carrega o valor atual do array em $t5
    slt $t6, $t2, $t5      # Define $t6 como 1 se $t2 < $t5, caso contrário, 0
    movn $t2, $t5, $t6     # Se $t6 não for zero, move $t5 para $t2
    addi $a0, $a0, 4       # Incrementa $a0 para a próxima posição do array
    subi $t4, $t4, 1       # Decrementa $t4 em 1
    bnez $t4, max_loop     # Se $t4 não for zero, volta para max_loop

    add $v0, $t2, $zero    # Move o valor máximo encontrado para $v0
    jr $ra                 # Retorna para a função chamadora

