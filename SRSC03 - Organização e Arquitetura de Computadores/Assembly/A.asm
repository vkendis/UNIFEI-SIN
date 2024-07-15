# Ler um numero inteiro
# Comparar se é menor que 0
# Se 1, imprimir positivo
# Se 0, imprimir negativo


.data

pos:    .asciiz "positivo\n"
neg:    .asciiz "negativo\n"

.text
main:
    # Ler um número inteiro do usuário
    li $v0, 5          # Código do serviço para ler inteiro
    syscall            # Chamar o serviço
    
    # Comparar o número com zero
    slt $t0, $v0, $zero  # $t0 = 1 se $v0 < 0, $t0 = 0 se $v0 >= 0
    bne $t0, $zero, negativo  # Se $t0 != 0 (número é negativo), vá para 'negativo'

    # Se o número for positivo ou zero
    li $v0, 4          # Código do serviço para imprimir string
    la $a0, pos        # Endereço da string 'pos'
    syscall            # Chamar o serviço
    j fim              # Pular para o fim

negativo:
    # Se o número for negativo
    li $v0, 4          # Código do serviço para imprimir string
    la $a0, neg        # Endereço da string 'neg'
    syscall            # Chamar o serviço

fim:
    # Terminar o programa
    li $v0, 10         # Código do serviço para terminar o programa
    syscall            # Chamar o serviço

