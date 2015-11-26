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
la $t2 string_7_1
move $a0 $t2
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
li $t3 0
add $t3 $t3 $fp
lw $t3 4($t3)
li $t4 1
seq $t5 $t3 $t4
beqz $t5 next_if_5_1
#Este es el código generado por la linea 5 de la instrucción return
li $t6 1
sw $t6 0($fp)
addi $t7 $zero 0
add $t7 $t7 $fp
sw $t3 4($t7)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_5_1:
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $t7 0
add $t7 $t7 $fp
lw $t7 4($t7)
li $s0 1
slt $s1 $t7 $s0
beqz $s1 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción write
la $s2 string_7_2
move $a0 $s2
li $v0 4
syscall
#Este es el código generado por la linea 8 de la instrucción return
li $s3 1
neg $s4 $s3
sw $s4 0($fp)
addi $s5 $zero 0
add $s5 $s5 $fp
sw $t7 4($s5)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 11 de la instrucción return
#Este es el código generado por la linea 11 de la llamada a la función: factorial
li $s5 0
add $s5 $s5 $fp
lw $s5 4($s5)
li $s6 1
sub $s7 $s5 $s6
addi $sp $sp -4
sw $s7 4($sp)
addi $sp $sp -4
la $t8 factorial
jal $t8
lw $t8 0($sp)
addi $sp $sp 4
li $t9 0
add $t9 $t9 $fp
lw $t9 4($t9)
mul $a2 $t8 $t9
sw $a2 0($fp)
addi $a3 $zero 0
add $a3 $a3 $fp
sw $t9 4($a3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $a3 0
sw $a3 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
