.data
#Ordenação de três números: Crie um programa em MIPS que leia três números inteiros e os exiba em ordem crescente.

space: .asciiz" "
.text

	li $v0, 5
	syscall
	add $t1, $v0, $zero
	
	li $v0, 5
	syscall
	add $t2, $v0, $zero
	
	li $v0, 5
	syscall
	add $t3, $v0, $zero
	
pass1: 
	
	slt $s0, $t1, $t2
	beq $s0, 1, compara1
	
	move $t4 , $t1
	move $t1 ,$t2
	move $t2 ,$t4
	
compara1:

	slt $s0, $t2, $t3
	beq $s0, 1, pass2
	
	move $t4, $t2
	move $t2 ,$t3
	move $t3 ,$t4

pass2:
	slt $s0, $t1, $t2
	beq $s0, 1, compara2
	
	move $t4 , $t1
	move $t1 ,$t2
	move $t2 ,$t4
		
			
compara2:	

	slt $s0, $t2, $t3
	beq $s0, 1, end
	
	move $t4, $t2
	move $t2 ,$t3
	move $t3 ,$t4
				
end: 
	li $v0, 1
	add $a0, $t1, $zero
	syscall
	
	li $v0, 4
	la $a0,space
	syscall
	
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	
	li $v0, 4
	la $a0,space
	syscall
	
	li $v0, 1
	add $a0, $t3, $zero
	syscall
	

	
	
	
	
	
	
	

	
