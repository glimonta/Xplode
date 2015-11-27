.data
string_7_1:    .asciiz "Escriba el numero de platos iniciales, que se moveran del plato 1 al 2\n"
string_7_2:    .asciiz "Mover plato de "
string_7_3:    .asciiz " a "
string_7_4:    .asciiz "\n"
string_7_5:    .asciiz "Mover plato de "
string_7_6:    .asciiz " a "
string_7_7:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -8
#Este es el código generado por la linea 27 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 30 de la llamada a la función: hanoi
addi $t0 $zero 4
add $t0 $t0 $sp
sw $a3 4($t0)
li $t0 3
addi $sp $sp -4
sw $t0 4($sp)
li $t1 2
addi $sp $sp -4
sw $t1 4($sp)
li $t2 1
addi $sp $sp -4
sw $t2 4($sp)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t3 hanoi
jal $t3
lw $t3 0($sp)
addi $sp $sp 16
li $v0 10
syscall
#Definición de Función hanoi: linea 3
hanoi:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
li $t5 1
seq $t6 $t4 $t5
beqz $t6 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
li $t7 4
add $t7 $t7 $fp
lw $t7 4($t7)
move $a0 $t7
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
li $s0 8
add $s0 $s0 $fp
lw $s0 4($s0)
move $a0 $s0
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
#Este es el código generado por la linea 8 de la instrucción return
addi $s1 $zero 8
add $s1 $s1 $fp
sw $s0 4($s1)
addi $s1 $zero 4
add $s1 $s1 $fp
sw $t7 4($s1)
addi $s1 $zero 0
add $s1 $s1 $fp
sw $t4 4($s1)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 12 de la llamada a la función: hanoi
li $s1 8
add $s1 $s1 $fp
lw $s1 4($s1)
addi $sp $sp -4
sw $s1 4($sp)
li $s2 12
add $s2 $s2 $fp
lw $s2 4($s2)
addi $sp $sp -4
sw $s2 4($sp)
li $s3 4
add $s3 $s3 $fp
lw $s3 4($s3)
addi $sp $sp -4
sw $s3 4($sp)
li $s4 0
add $s4 $s4 $fp
lw $s4 4($s4)
li $s5 1
sub $s6 $s4 $s5
addi $sp $sp -4
sw $s6 4($sp)
addi $sp $sp -4
la $s7 hanoi
jal $s7
lw $s7 0($sp)
addi $sp $sp 16
#Este es el código generado por la linea 13 de la instrucción write
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 14 de la instrucción write
li $t8 4
add $t8 $t8 $fp
lw $t8 4($t8)
move $a0 $t8
li $v0 1
syscall
#Este es el código generado por la linea 15 de la instrucción write
la $a0 string_7_6
li $v0 4
syscall
#Este es el código generado por la linea 16 de la instrucción write
li $t9 8
add $t9 $t9 $fp
lw $t9 4($t9)
move $a0 $t9
li $v0 1
syscall
#Este es el código generado por la linea 17 de la instrucción write
la $a0 string_7_7
li $v0 4
syscall
#Este es el código generado por la linea 18 de la llamada a la función: hanoi
addi $a2 $zero 8
add $a2 $a2 $fp
sw $t9 4($a2)
addi $a2 $zero 4
add $a2 $a2 $fp
sw $t8 4($a2)
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
sw $t9 4($sp)
li $a2 12
add $a2 $a2 $fp
lw $a2 4($a2)
addi $sp $sp -4
sw $a2 4($sp)
li $t0 0
add $t0 $t0 $fp
lw $t0 4($t0)
li $t1 1
sub $t2 $t0 $t1
addi $sp $sp -4
sw $t2 4($sp)
addi $sp $sp -4
la $a3 hanoi
jal $a3
lw $a3 0($sp)
addi $sp $sp 16
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
