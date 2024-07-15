.data
resultado_sim: .asciiz "sim"
resultado_nao: .asciiz "nao"

.text
.globl main

main:
    li $v0, 5                # L� idade
    syscall
    
    add $s0, $v0, $zero      # Salva idade em $s0

    li $v0, 5                # L� tempo de servi�o
    syscall
 
    add $s1, $v0, $zero      # Salva tempo de servi�o em $s1

    # Verifica condi��es de aposentadoria
    li $s2, 0                # Inicializa flag de aposentadoria

    bge $s0, 65, aposentar    # Se idade >= 65, vai para aposentar
    bge $s1, 35, aposentar    # Se tempo de servi�o >= 35, vai para aposentar
    li $t3, 60               # Configura idade m�nima para pr�xima condi��o
    bge $s0, $t3, verifica_servico  # Verifica se idade >= 60

nao_aposentar:
    move $s2, $zero          # Define flag de aposentadoria como 0
    j imprimir_resultado

verifica_servico:
    bge $s1, 30, aposentar   # Se tempo de servi�o >= 30, vai para aposentar

    j nao_aposentar

aposentar:
    li $s2, 1                # Define flag de aposentadoria como 1

imprimir_resultado:
    beq $s2, $zero, imprimir_nao
    li $v0, 4                # Imprime "sim"
    la $a0, resultado_sim
    syscall
    j fim

imprimir_nao:
    li $v0, 4                # Imprime "n�o"
    la $a0, resultado_nao
    syscall

fim:
    li $v0, 10               # Termina a execu��o do programa
    syscall
