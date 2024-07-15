.data
.text
.globl main

main:
    li $v0, 5           # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall             # Chama a syscall para ler um inteiro
    add $a0, $v0, $zero # Move o valor lido para $a0

    li $v0, 5           # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall             # Chama a syscall para ler um inteiro
    add $a1, $v0, $zero # Move o valor lido para $a1

    jal sum_range       # Chama a função sum_range

    add $a0, $v0, $zero # Move o resultado (soma) para $a0
    li $v0, 1           # Coloca 1 em $v0 para chamar a impressão de inteiro (syscall 1)
    syscall             # Chama a syscall para imprimir o inteiro
    li $v0, 10          # Coloca 10 em $v0 para encerrar o programa (syscall 10)
    syscall             # Chama a syscall para encerrar o programa

sum_range:
    add $t0, $a0, $zero # Inicializa $t0 com o valor de $a0 (início do intervalo)
    add $t1, $a1, $zero # Inicializa $t1 com o valor de $a1 (fim do intervalo)
    add $v0, $zero, $zero # Inicializa $v0 com 0 (soma acumulada)

loop:
    add $v0, $v0, $t0   # Adiciona $t0 à soma acumulada ($v0)
    addi $t0, $t0, 1    # Incrementa $t0 em 1
    bne $t0, $t1, loop  # Se $t0 não for igual a $t1, volta para loop
    add $v0, $v0, $t1   # Adiciona o valor final de $t1 à soma acumulada
    jr $ra              # Retorna para a função chamadora
