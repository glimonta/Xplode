.data
string_7_1:    .asciiz " "
string_7_2:    .asciiz " "
string_7_3:    .asciiz " "
string_7_4:    .asciiz " "

.align 4

.text
main:
addi $sp $sp -52
#Este es el código generado por la linea 31 de la instrucción if que termina en next_if_31_1
li $a2 2
li $a3 2
seq $t0 $a2 $a3
beqz $t0 false_if_31_1
#Este es el código generado por la linea 35 de la instrucción if que termina en next_if_35_1
#Este es el código generado por la linea 40 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
next_if_35_1:
#Este es el código generado por la linea 44 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
j next_if_31_1
false_if_31_1:
#Este es el código generado por la linea 50 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
next_if_31_1:
#Este es el código generado por la linea 54 de la instrucción if que termina en next_if_54_1
li $t1 8
li $t2 8
seq $t3 $t1 $t2
beqz $t3 next_if_54_1
#Este es el código generado por la linea 59 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
next_if_54_1:
li $v0 10
syscall
#Definición de Función fib: linea 3
fib:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -16
#Este es el código generado por la linea 8 de la instrucción if que termina en next_if_8_1
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
lw $t4 0($t4)
li $t5 2
slt $t6 $t4 $t5
beqz $t6 next_if_8_1
#Este es el código generado por la linea 10 de la instrucción return
li $t7 1
sw $t7 0($fp)
addi $s0 $zero 0
add $s0 $s0 $fp
lw $s0 4($s0)
sw $t4 0($s0)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_8_1:
#Este es el código generado por la linea 14 de la instrucción j := fib(num, 8, k)
#Este es el código generado por la linea 14 de la llamada a la función: fib
addi $s0 $zero 12
add $s0 $s0 $sp
sw $s0 0($sp)
addi $sp $sp -4
li $s0 8
addi $sp $sp -4
sw $s0 4($sp)
addi $s1 $zero 0
add $s1 $s1 $fp
lw $s1 4($s1)
sw $s1 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s1 fib
jal $s1
lw $s1 0($sp)
addi $sp $sp 12
move $s2 $s1
#Este es el código generado por la linea 15 de la instrucción k := fib(num, 8, k)
#Este es el código generado por la linea 15 de la llamada a la función: fib
addi $s3 $zero 4
add $s3 $s3 $sp
sw $s2 4($s3)
addi $s3 $zero 12
add $s3 $s3 $sp
sw $s3 0($sp)
addi $sp $sp -4
li $s3 8
addi $sp $sp -4
sw $s3 4($sp)
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
sw $s4 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s4 fib
jal $s4
lw $s4 0($sp)
addi $sp $sp 12
move $s5 $s4
#Este es el código generado por la linea 16 de la instrucción return
li $s6 4
add $s6 $s6 $sp
lw $s6 4($s6)
add $s7 $s5 $s6
sw $s7 0($fp)
addi $t8 $zero 4
add $t8 $t8 $sp
sw $s6 4($t8)
addi $t8 $zero 8
add $t8 $t8 $sp
sw $s5 4($t8)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t8 0
sw $t8 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
