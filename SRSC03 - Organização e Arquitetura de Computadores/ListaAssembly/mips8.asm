.data

space: .asciiz " "
.text
	li $v0, 5
	syscall
	add $t0,$v0, $zero
	
	li $t1,0
	li $t2,1
	li $s0,0
	
loop: 
	beq $s0, $t0, end
	
	li $v0, 1
	add $a0, $t1, $zero
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	add $t3, $t1, $t2
	move $t1,$t2
	move $t2 , $t3
	
	addi $s0,$s0,1
	
	j loop

end: 

	li $v0, 10
	syscall