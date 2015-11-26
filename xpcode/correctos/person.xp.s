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
#Este es el código generado por la linea 34 de la llamada a la función: print2
li $t6 4
addi $t6 $t6 0
add $t6 $t6 $sp
lw $t7 4($t6)
addi $sp $sp -4
sw $t7 4($sp)
addi $sp $sp -4
la $s0 print2
jal $s0
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
la $s0 string_7_1
move $a0 $s0
li $v0 4
syscall
#Este es el código generado por la linea 19 de la instrucción write
li $s1 4
addi $s3 $zero 0
add $s3 $s3 $fp
lw $s3 4($s3)
add $s1 $s1 $s3
lw $s2 0($s1)
move $a0 $s2
li $v0 1
syscall
la $s3 string_7_2
move $a0 $s3
li $v0 4
syscall
li $s4 0
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s4 $s4 $s6
lw $s5 0($s4)
move $a0 $s5
li $v0 1
syscall
la $s6 string_7_3
move $a0 $s6
li $v0 4
syscall
li $s7 8
addi $t9 $zero 0
add $t9 $t9 $fp
lw $t9 4($t9)
add $s7 $s7 $t9
lw $t8 0($s7)
move $a0 $t8
li $v0 1
syscall
la $t9 string_7_4
move $a0 $t9
li $v0 4
syscall
li $a3 12
addi $t3 $zero 0
add $t3 $t3 $fp
lw $t3 4($t3)
add $a3 $a3 $t3
lw $t1 0($a3)
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
la $t3 string_7_5
move $a0 $t3
li $v0 4
syscall
#Este es el código generado por la linea 24 de la instrucción write
li $t5 0
add $t5 $t5 $fp
lw $t5 4($t5)
move $a0 $t5
li $v0 1
syscall
la $t6 string_7_6
move $a0 $t6
li $v0 4
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
