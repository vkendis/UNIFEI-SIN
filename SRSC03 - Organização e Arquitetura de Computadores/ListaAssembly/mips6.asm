.data



.text
#M�dia de N n�meros: Escreva um programa em MIPS que leia N n�meros inteiros 
#(onde N � fornecido pelo usu�rio), calcule e exiba a m�dia desses n�meros.

	li $v0, 5               
    	syscall
    	add $t0, $v0 ,$zero
    	
    	li $t1, 0
    	li $t2, 0
    	
loop:


	beq $t0, $t2, calc_media
	
	li $v0, 5              
    	syscall
    	add $t1, $t1, $v0  
    	
    	addi $t2, $t2, 1
    	
    	j loop
    	
calc_media: 

	div $t1, $t0
	mflo $t3
	
	li $v0, 1
	add $a0, $t3, $zero
	syscall

	
	