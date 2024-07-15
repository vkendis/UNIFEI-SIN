.data
#Número primo: Implemente um programa em MIPS que leia um número inteiro e 
#determine se ele é primo ou não, exibindo uma mensagem correspondente.
sim: .asciiz"eh primo"
nao: .asciiz"nao eh primo"

.text

	li $v0, 5
	syscall
	add $t1, $v0, $zero
	
	li $t0 , 2
	li $s0 , 0 #conta div
	
	
loop: 	
	beq $t0, $t1, end
	
	div $t1, $t0
	mfhi $t3
	
	beq $t3, 0 , incrementa
	
	addi $t0, $t0, 1
	
	j loop
	
	
incrementa:
	
	addi $s0, $s0, 1
	addi $t0, $t0, 1
	
	j loop
	
end: 
	beq $s0, 0, print_primo
	
print_nprimo:
	li $v0, 4
	la $a0, nao
	syscall
	j exit

print_primo:
	li $v0, 4
	la $a0, sim
	syscall
	
exit: 	li $v0, 10
	syscall


