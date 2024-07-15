.data
.text
    main:
        # Ler N
        li $v0, 5          # syscall para ler um inteiro
        syscall
        add $t0, $v0, $zero  # Armazena N em $t0

        # Inicializa $t1 com o fatorial, começando por 1 (fatorial de 0 é 1)
        li $t1, 1

        # Verifica se N é maior que 0 para calcular o fatorial
        blez $t0, print_result  # Se N <= 0, pula para impressão (fatorial de 0 é 1)

        # Loop para calcular o fatorial de N
        calculate_factorial:
            mul $t1, $t1, $t0  # $t1 = $t1 * $t0
            addi $t0, $t0, -1  # Decrementa N
            bgtz $t0, calculate_factorial  # Continua enquanto N > 0

        # Imprime o fatorial calculado
        print_result:
        li $v0, 1           # syscall para imprimir um inteiro
        add $a0, $t1, $zero  # Prepara o fatorial para impressão
        syscall

        # Encerra o programa
        li $v0, 10
        syscall
