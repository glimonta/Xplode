.data
string_7_1:    .asciiz "Escriba el primer argumento:\n"
string_7_2:    .asciiz "Escriba el segundo argumento:\n"
string_7_3:    .asciiz "ack("
string_7_4:    .asciiz " , "
string_7_5:    .asciiz " )="
string_7_6:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -8
#Este es el código generado por la linea 28 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 30 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
li $v0 5
syscall
move $t0 $v0
move $t1 $t0
#Este es el código generado por la linea 33 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 33 de la llamada a la función: ack
addi $t2 $zero 0
add $t2 $t2 $sp
sw $a3 4($t2)
addi $t2 $zero 4
add $t2 $t2 $sp
sw $t1 4($t2)
addi $sp $sp -4
sw $t1 4($sp)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t2 ack
jal $t2
lw $t2 0($sp)
addi $sp $sp 8
move $a0 $t2
li $v0 1
syscall
la $a0 string_7_6
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función ack: linea 3
ack:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -4
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $t3 0
add $t3 $t3 $fp
lw $t3 4($t3)
li $t4 0
seq $t5 $t3 $t4
beqz $t5 next_if_6_1
#Este es el código generado por la linea 8 de la instrucción return
li $t6 4
add $t6 $t6 $fp
lw $t6 4($t6)
li $t7 1
add $s0 $t6 $t7
sw $s0 0($fp)
addi $s1 $zero 0
add $s1 $s1 $fp
sw $t3 4($s1)
addi $s1 $zero 4
add $s1 $s1 $fp
sw $t6 4($s1)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 12 de la instrucción if que termina en next_if_12_1
li $s1 4
add $s1 $s1 $fp
lw $s1 4($s1)
li $s2 0
seq $s3 $s1 $s2
beqz $s3 next_if_12_1
#Este es el código generado por la linea 14 de la instrucción return
#Este es el código generado por la linea 14 de la llamada a la función: ack
addi $s4 $zero 4
add $s4 $s4 $fp
sw $s1 4($s4)
li $s4 1
addi $sp $sp -4
sw $s4 4($sp)
li $s5 0
add $s5 $s5 $fp
lw $s5 4($s5)
li $s6 1
sub $s7 $s5 $s6
addi $sp $sp -4
sw $s7 4($sp)
addi $sp $sp -4
la $t8 ack
jal $t8
lw $t8 0($sp)
addi $sp $sp 8
sw $t8 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_12_1:
#Este es el código generado por la linea 18 de la instrucción r1 := ack(m, n - 1)
#Este es el código generado por la linea 18 de la llamada a la función: ack
li $t9 4
add $t9 $t9 $fp
lw $t9 4($t9)
li $a2 1
sub $t0 $t9 $a2
addi $sp $sp -4
sw $t0 4($sp)
li $a3 0
add $a3 $a3 $fp
lw $a3 4($a3)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t1 ack
jal $t1
lw $t1 0($sp)
addi $sp $sp 8
move $t2 $t1
#Este es el código generado por la linea 20 de la instrucción return
#Este es el código generado por la linea 20 de la llamada a la función: ack
addi $t4 $zero 0
add $t4 $t4 $sp
sw $t2 4($t4)
addi $sp $sp -4
sw $t2 4($sp)
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
li $t5 1
sub $t7 $t4 $t5
addi $sp $sp -4
sw $t7 4($sp)
addi $sp $sp -4
la $s0 ack
jal $s0
lw $s0 0($sp)
addi $sp $sp 8
sw $s0 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t3 0
sw $t3 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
