.data
#Subtração de dois números: Crie um programa em MIPS que leia dois números inteiros, 
#subtraia o segundo do primeiro e mostre o resultado.

.text

	li $v0, 5
	syscall
	add $t1, $v0, $zero
	
	li $v0, 5
	syscall
	add $t2, $v0, $zero
	
	sub $t3, $t1, $t2
	
	li $v0, 1
	add $a0, $t3,$zero
	syscall