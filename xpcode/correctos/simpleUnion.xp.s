.data

.align 4

.text
main:
addi $sp $sp -4
#Este es el código generado por la linea 11 de la instrucción ci.c := 'a'
li $a2 0
addi $a2 $a2 0
add $a2 $a2 $sp
sw $a3 4($a2)
#Este es el código generado por la linea 12 de la instrucción ci.i := 3
li $t0 0
li $t1 3
addi $t0 $t0 0
add $t0 $t0 $sp
sw $t1 4($t0)
li $v0 5
syscall
move $t2 $v0
li $t3 0
addi $t3 $t3 0
add $t3 $t3 $sp
sw $t2 4($t3)
#Este es el código generado por la linea 15 de la instrucción write
li $t4 0
addi $t4 $t4 0
add $t4 $t4 $sp
lw $t5 4($t4)
move $a0 $t5
li $v0 1
syscall
li $v0 5
syscall
move $t6 $v0
li $t7 0
addi $t7 $t7 0
add $t7 $t7 $sp
sw $t6 4($t7)
#Este es el código generado por la linea 18 de la instrucción write
li $s0 0
addi $s0 $s0 0
add $s0 $s0 $sp
lw $s1 4($s0)
move $a0 $s1
li $v0 11
syscall
li $v0 10
syscall
