.data
    space: .asciiz " "  # Espaço para separar os números

.text
    main:
        # Lê o inteiro N
        li $v0, 5
        syscall
        add $t0, $v0, $zero  # Armazena o valor lido para $t0 (N)

        li $t1, 1      # Inicializa o contador de números ímpares com 1
        li $t2, 0      # Inicializa o contador de números impressos

    loop:
        # Verifica se já imprimiu N números
        bge $t2, $t0, end_program  # Se $t2 >= $t0, encerra o programa

        # Imprime o número ímpar atual
        li $v0, 1
        add $a0, $t1, $zero  # Configura $a0 com o valor de $t1
        syscall

        # Imprime um espaço
        li $v0, 4
        la $a0, space
        syscall

        # Incrementa o contador de números ímpares em 2 (para pegar o próximo número ímpar)
        addi $t1, $t1, 2

        # Incrementa o contador de números impressos
        addi $t2, $t2, 1

        # Volta para o início do loop
        j loop

    end_program:
        # Encerra o programa
        li $v0, 10
        syscall

