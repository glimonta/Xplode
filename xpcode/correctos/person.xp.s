.data
string_7_1:    .asciiz "Person Data is : "
string_7_2:    .asciiz " "
string_7_3:    .asciiz " "
string_7_4:    .asciiz " "
string_7_5:    .asciiz "Person Id is : "
string_7_6:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -16
li $v0 5
syscall
move $a2 $v0
li $a3 4
addi $a3 $a3 0
add $a3 $a3 $sp
sw $a2 4($a3)
li $v0 5
syscall
move $t0 $v0
li $t1 8
addi $t1 $t1 0
add $t1 $t1 $sp
sw $t0 4($t1)
li $v0 5
syscall
move $t2 $v0
li $t3 12
addi $t3 $t3 0
add $t3 $t3 $sp
sw $t2 4($t3)
li $v0 5
syscall
move $t4 $v0
li $t5 0
addi $t5 $t5 0
add $t5 $t5 $sp
sw $t4 4($t5)
#Este es el código generado por la linea 33 de la llamada a la función: print
addi $t6 $zero 4
add $t6 $t6 $sp
sw $t6 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t6 print
jal $t6
lw $t6 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 34 de la llamada a la función: print2
li $t7 4
addi $t7 $t7 0
add $t7 $t7 $sp
lw $s0 4($t7)
addi $sp $sp -4
sw $s0 4($sp)
addi $sp $sp -4
la $s1 print2
jal $s1
lw $s1 0($sp)
addi $sp $sp 4
li $v0 10
syscall
#Definición de Función print: linea 17
print:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 18 de la instrucción write
la $s2 string_7_1
move $a0 $s2
li $v0 4
syscall
#Este es el código generado por la linea 19 de la instrucción write
li $s3 4
addi $s5 $zero 0
add $s5 $s5 $fp
lw $s5 4($s5)
add $s3 $s3 $s5
lw $s4 0($s3)
move $a0 $s4
li $v0 1
syscall
la $s5 string_7_2
move $a0 $s5
li $v0 4
syscall
li $s6 0
addi $t8 $zero 0
add $t8 $t8 $fp
lw $t8 4($t8)
add $s6 $s6 $t8
lw $s7 0($s6)
move $a0 $s7
li $v0 1
syscall
la $t8 string_7_3
move $a0 $t8
li $v0 4
syscall
li $t9 8
addi $a3 $zero 0
add $a3 $a3 $fp
lw $a3 4($a3)
add $t9 $t9 $a3
lw $a2 0($t9)
move $a0 $a2
li $v0 1
syscall
la $a3 string_7_4
move $a0 $a3
li $v0 4
syscall
li $t0 12
addi $t2 $zero 0
add $t2 $t2 $fp
lw $t2 4($t2)
add $t0 $t0 $t2
lw $t1 0($t0)
move $a0 $t1
li $v0 1
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función print2: linea 22
print2:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 23 de la instrucción write
la $t2 string_7_5
move $a0 $t2
li $v0 4
syscall
#Este es el código generado por la linea 24 de la instrucción write
li $t3 0
add $t3 $t3 $fp
lw $t3 4($t3)
move $a0 $t3
li $v0 1
syscall
la $t4 string_7_6
move $a0 $t4
li $v0 4
syscall
addi $t5 $zero 0
add $t5 $t5 $fp
sw $t3 4($t5)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
