.data
    space: .asciiz " "
.text
.globl main
main:    
    # Leitura do valor de N
    li $v0, 5
    syscall
    add $t0, $v0, $zero  # Salvar valor lido em $t0
    
    # Imprimir os números de N até 1
    add $t1, $t0, $zero  # Registrador para controlar o loop
    
print_loop:
    # Imprimir o número atual
    add $a0, $t1, $zero
    li $v0, 1
    syscall
    
    # Imprimir espaço
    li $v0, 4
    la $a0, space
    syscall
    
    # Decrementar o contador
    subi $t1, $t1, 1
    
    # Verificar se chegou a 0
    bgtz $t1, print_loop
