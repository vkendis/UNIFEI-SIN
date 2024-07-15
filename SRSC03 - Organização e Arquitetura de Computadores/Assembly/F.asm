.data
    space: .asciiz " "  # Espa�o para separar os n�meros

.text
    main:
        # L� o inteiro N
        li $v0, 5
        syscall
        add $t0, $v0, $zero  # Armazena o valor lido para $t0 (N)

        li $t1, 1      # Inicializa o contador de n�meros �mpares com 1
        li $t2, 0      # Inicializa o contador de n�meros impressos

    loop:
        # Verifica se j� imprimiu N n�meros
        bge $t2, $t0, end_program  # Se $t2 >= $t0, encerra o programa

        # Imprime o n�mero �mpar atual
        li $v0, 1
        add $a0, $t1, $zero  # Configura $a0 com o valor de $t1
        syscall

        # Imprime um espa�o
        li $v0, 4
        la $a0, space
        syscall

        # Incrementa o contador de n�meros �mpares em 2 (para pegar o pr�ximo n�mero �mpar)
        addi $t1, $t1, 2

        # Incrementa o contador de n�meros impressos
        addi $t2, $t2, 1

        # Volta para o in�cio do loop
        j loop

    end_program:
        # Encerra o programa
        li $v0, 10
        syscall

