.data
.text
.globl main

main:
    li $v0, 5              # Coloca 5 em $v0 para chamar a leitura de inteiro (syscall 5)
    syscall                # Chama a syscall para ler um inteiro
    add $a0, $v0, $zero    # Move o valor lido para $a0

    jal eh_quadrado_perfeito  # Chama a função eh_quadrado_perfeito

    add $a0, $v0, $zero    # Move o resultado (1 ou 0) para $a0
    li $v0, 1              # Coloca 1 em $v0 para chamar a impressão de inteiro (syscall 1)
    syscall                # Chama a syscall para imprimir o inteiro
    li $v0, 10             # Coloca 10 em $v0 para encerrar o programa (syscall 10)
    syscall                # Chama a syscall para encerrar o programa

eh_quadrado_perfeito:
    add $t0, $zero, $zero  # Inicializa $t0 com 0 (não utilizado, pode ser removido)
    add $t1, $zero, $zero  # Inicializa $t1 com 0 (contador para tentativa de quadrado perfeito)

loop_perfeito:
    addi $t1, $t1, 1       # Incrementa $t1 em 1
    mul $t2, $t1, $t1      # Calcula o quadrado de $t1 e armazena em $t2
    bgt $t2, $a0, nao_perfeito  # Se $t2 > $a0, vá para nao_perfeito
    beq $t2, $a0, quadrado_perfeito  # Se $t2 == $a0, vá para quadrado_perfeito
    j loop_perfeito        # Volta para loop_perfeito

quadrado_perfeito:
    li $v0, 1              # Coloca 1 em $v0 (indicando que é um quadrado perfeito)
    jr $ra                 # Retorna para a função chamadora

nao_perfeito:
    li $v0, 0              # Coloca 0 em $v0 (indicando que não é um quadrado perfeito)
    jr $ra                 # Retorna para a função chamadora
