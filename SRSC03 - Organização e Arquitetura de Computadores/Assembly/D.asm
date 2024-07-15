.data
    # Mensagens para cada tipo de tri�ngulo
    equilatero: .asciiz "equilatero"
    isosceles: .asciiz "isosceles"
    escaleno: .asciiz "escaleno"

.text
    main:
        # Leitura do primeiro lado
        li $v0, 5
        syscall
        add $t0, $v0, $zero  # Armazena o lado a em $t0

        # Leitura do segundo lado
        li $v0, 5
        syscall
        add $t1, $v0, $zero  # Armazena o lado b em $t1

        # Leitura do terceiro lado
        li $v0, 5
        syscall
        add $t2, $v0, $zero  # Armazena o lado c em $t2

        # Checa se todos os lados s�o iguais (equil�tero)
        bne $t0, $t1, check_isosceles  # Se a != b, n�o � equil�tero
        bne $t0, $t2, check_isosceles  # Se a != c, n�o � equil�tero
        la $a0, equilatero
        li $v0, 4
        syscall
        j end_program

    check_isosceles:
        # Checa se dois lados s�o iguais (is�sceles)
        beq $t0, $t1, print_isosceles  # Se a == b, � is�sceles
        beq $t0, $t2, print_isosceles  # Se a == c, � is�sceles
        beq $t1, $t2, print_isosceles  # Se b == c, � is�sceles
        la $a0, escaleno
        li $v0, 4
        syscall
        j end_program

    print_isosceles:
        la $a0, isosceles
        li $v0, 4
        syscall

    end_program:
        # Encerra o programa
        li $v0, 10
        syscall

