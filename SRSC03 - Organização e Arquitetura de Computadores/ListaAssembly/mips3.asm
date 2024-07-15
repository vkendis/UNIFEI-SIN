.data
#Fatorial: Implemente um programa em MIPS que calcule o fatorial de um número inteiro positivo lido da entrada.
op : .asciiz "*"
space : .asciiz " "
equal: .asciiz " = "
linha: .asciiz "\n"

.text
	
	li $v0, 5
	syscall
	add $t1, $v0, $zero
	
	li $t2, 1
	
loop:
	beq $t1, 1, end_loop
	
	li $v0, 1
	add $a0, $t1, $zero
	syscall
	
	li $v0, 4
	la $a0, op
	syscall
	
	li $v0, 4
	la $a0, linha
	syscall
	
	mul $t2, $t2, $t1
	sub $t1, $t1, 1
	
	
	
	j loop
end_loop:

	li $v0, 1
	li $a0, 1
	syscall
	
	li $v0, 4
	la $a0, equal
	syscall
	
	
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	
	li $v0, 10
	syscall