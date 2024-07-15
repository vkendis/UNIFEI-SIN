.data
.text
    main:
        # Loop para garantir que N seja maior que zero
        read_N:
            li $v0, 5         # syscall para ler um inteiro
            syscall
            add $t0, $v0, $zero  # Armazena o valor lido em $t0

            blez $t0, read_N   # Se $t0 <= 0, l� outro n�mero

        # Inicializa o contador e o acumulador de soma
        li $t1, 1            # Contador come�a em 1
        li $t2, 0            # Acumulador da soma come�a em 0

        # Loop para calcular a soma dos n�meros de 1 at� N
        loop:
            add $t2, $t2, $t1  # Adiciona o contador � soma
            addi $t1, $t1, 1  # Incrementa o contador

            ble $t1, $t0, loop # Continua o loop enquanto o contador for <= N

        # Imprime a soma calculada
        li $v0, 1            # syscall para imprimir um inteiro
        add $a0, $t2, $zero  # Prepara o valor da soma para impress�o
        syscall

        # Encerra o programa
        li $v0, 10
        syscall
