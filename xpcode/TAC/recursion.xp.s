.data
string_7_1:    .asciiz "Permutaciones totales: "
string_7_2:    .asciiz "No intentes explotar aunque programes en Xplode!"

.align 4

.text
main:
addi $sp $sp -8
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 24 de la instrucción res := factorial(n)
#Este es el código generado por la linea 24 de la llamada a la función: factorial
addi $t0 $zero 0
add $t0 $t0 $sp
sw $a3 4($t0)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t0 factorial
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
move $t1 $t0
#Este es el código generado por la linea 25 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
move $a0 $t1
li $v0 1
syscall
li $v0 10
syscall
#Definición de Función factorial: linea 3
factorial:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 5 de la instrucción if que termina en next_if_5_1
li $t2 0
add $t2 $t2 $fp
lw $t2 4($t2)
li $t3 1
seq $t4 $t2 $t3
beqz $t4 next_if_5_1
#Este es el código generado por la linea 5 de la instrucción return
li $t5 1
sw $t5 0($fp)
addi $t6 $zero 0
add $t6 $t6 $fp
sw $t2 4($t6)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_5_1:
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $t6 0
add $t6 $t6 $fp
lw $t6 4($t6)
li $t7 1
slt $s0 $t6 $t7
beqz $s0 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 8 de la instrucción return
li $s1 1
neg $s2 $s1
sw $s2 0($fp)
addi $s3 $zero 0
add $s3 $s3 $fp
sw $t6 4($s3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 11 de la instrucción return
#Este es el código generado por la linea 11 de la llamada a la función: factorial
li $s3 0
add $s3 $s3 $fp
lw $s3 4($s3)
li $s4 1
sub $s5 $s3 $s4
addi $sp $sp -4
sw $s5 4($sp)
addi $sp $sp -4
la $s6 factorial
jal $s6
lw $s6 0($sp)
addi $sp $sp 4
li $s7 0
add $s7 $s7 $fp
lw $s7 4($s7)
mul $t8 $s6 $s7
sw $t8 0($fp)
addi $t9 $zero 0
add $t9 $t9 $fp
sw $s7 4($t9)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t9 0
sw $t9 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
