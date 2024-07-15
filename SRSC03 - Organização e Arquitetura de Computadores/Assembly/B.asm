.data
    # Espaço reservado para os quatro valores inteiros
    num1: .word 0
    num2: .word 0
    num3: .word 0
    num4: .word 0
.text
main:
# Leitura e armazenamento de cada um dos quatro valores inteiros
        li $v0, 5
        syscall
        sw $v0, num1

        li $v0, 5
        syscall
        sw $v0, num2

        li $v0, 5
        syscall
        sw $v0, num3

        li $v0, 5
        syscall
        sw $v0, num4

        # Carrega os quatro números dos endereços de memória para os registradores
        lw $t0, num1
        lw $t1, num2
        lw $t2, num3
        lw $t3, num4

        # Compara o primeiro número ($t0) com o segundo ($t1)
        slt $t4, $t0, $t1
        # Se $t0 não é menor que $t1 (ou seja, $t0 é maior ou igual a $t1)
        beq $t4, $zero, check_t2_t0
        # Caso contrário (se $t0 é menor que $t1), $t4 recebe $t1
        add $t4, $t1, $zero  

    check_t2_t0:
        # Se $t0 é maior ou igual a $t1, $t4 recebe $t0
        add $t4, $t0, $zero  

        # Compara $t4 (maior de $t0 e $t1) com o terceiro número ($t2)
        slt $t5, $t4, $t2
        # Se $t4 não é menor que $t2 (ou seja, $t4 é maior ou igual a $t2)
        beq $t5, $zero, check_t3
        # Caso contrário, $t4 recebe $t2
        add $t4, $t2, $zero  

    check_t3:
        # $t4 já é o maior entre $t0, $t1, e $t2

        # Compara $t4 com o quarto número ($t3)
        slt $t5, $t4, $t3
        # Se $t4 não é menor que $t3 (ou seja, $t4 é maior ou igual a $t3)
        beq $t5, $zero, print_t3
        # Caso contrário, $t4 recebe $t3
        add $t4, $t3, $zero  

    print_t3:
        # $t4 é o maior de todos os quatro números

        # Imprime o valor maior
        li $v0, 1
        add $a0, $t4, $zero
        syscall

        # Encerrar o programa
        li $v0, 10
        syscall
