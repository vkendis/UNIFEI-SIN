# Ler um numero inteiro
# Comparar se � menor que 0
# Se 1, imprimir positivo
# Se 0, imprimir negativo


.data

pos:    .asciiz "positivo\n"
neg:    .asciiz "negativo\n"

.text
main:
    # Ler um n�mero inteiro do usu�rio
    li $v0, 5          # C�digo do servi�o para ler inteiro
    syscall            # Chamar o servi�o
    
    # Comparar o n�mero com zero
    slt $t0, $v0, $zero  # $t0 = 1 se $v0 < 0, $t0 = 0 se $v0 >= 0
    bne $t0, $zero, negativo  # Se $t0 != 0 (n�mero � negativo), v� para 'negativo'

    # Se o n�mero for positivo ou zero
    li $v0, 4          # C�digo do servi�o para imprimir string
    la $a0, pos        # Endere�o da string 'pos'
    syscall            # Chamar o servi�o
    j fim              # Pular para o fim

negativo:
    # Se o n�mero for negativo
    li $v0, 4          # C�digo do servi�o para imprimir string
    la $a0, neg        # Endere�o da string 'neg'
    syscall            # Chamar o servi�o

fim:
    # Terminar o programa
    li $v0, 10         # C�digo do servi�o para terminar o programa
    syscall            # Chamar o servi�o

