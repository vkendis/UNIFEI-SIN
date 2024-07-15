.data
#Maior de dois números: Escreva um programa em MIPS que leia dois números inteiros e exiba o maior deles.

.text

	li $v0, 5
	syscall
	add $t1, $v0, $zero
	
	li $v0, 5
	syscall
	add $t2, $v0, $zero
	
main:
	slt $t3, $t1, $t2
	beq $t3, 1, print_t2
	


print_t1:
	li $v0, 1
	add $a0, $t1, $zero
	syscall
	
	j end

print_t2:
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	
	j end

end:

	li $v0, 10
	syscall

