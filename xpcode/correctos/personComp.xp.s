.data
string_7_1:    .asciiz "Person Data is : "
string_7_2:    .asciiz " "
string_7_3:    .asciiz " "
string_7_4:    .asciiz " "

.align 4

.text
main:
addi $sp $sp -48
#Este es el código generado por la linea 37 de la llamada a la función: readPerson
addi $a2 $zero 4
add $a2 $a2 $sp
sw $a2 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $a2 readPerson
jal $a2
lw $a2 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 38 de la llamada a la función: readPerson
addi $a3 $zero 20
add $a3 $a3 $sp
sw $a3 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $a3 readPerson
jal $a3
lw $a3 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 39 de la llamada a la función: readPerson
addi $t0 $zero 36
add $t0 $t0 $sp
sw $t0 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t0 readPerson
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 40 de la instrucción if que termina en next_if_40_1
#Este es el código generado por la linea 40 de la llamada a la función: anotherComp
addi $t1 $zero 20
add $t1 $t1 $sp
sw $t1 0($sp)
addi $sp $sp -4
addi $t1 $zero 4
add $t1 $t1 $sp
sw $t1 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t1 anotherComp
jal $t1
lw $t1 0($sp)
addi $sp $sp 8
beqz $t1 false_if_40_1
#Este es el código generado por la linea 41 de la instrucción if que termina en next_if_41_1
#Este es el código generado por la linea 41 de la llamada a la función: anotherComp
addi $t2 $zero 36
add $t2 $t2 $sp
sw $t2 0($sp)
addi $sp $sp -4
addi $t2 $zero 4
add $t2 $t2 $sp
sw $t2 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t2 anotherComp
jal $t2
lw $t2 0($sp)
addi $sp $sp 8
beqz $t2 false_if_41_1
#Este es el código generado por la linea 42 de la llamada a la función: printPerson
addi $t3 $zero 4
add $t3 $t3 $sp
sw $t3 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t3 printPerson
jal $t3
lw $t3 0($sp)
addi $sp $sp 4
j next_if_41_1
false_if_41_1:
#Este es el código generado por la linea 44 de la llamada a la función: printPerson
addi $t4 $zero 36
add $t4 $t4 $sp
sw $t4 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t4 printPerson
jal $t4
lw $t4 0($sp)
addi $sp $sp 4
next_if_41_1:
j next_if_40_1
false_if_40_1:
#Este es el código generado por la linea 47 de la instrucción if que termina en next_if_47_1
#Este es el código generado por la linea 47 de la llamada a la función: anotherComp
addi $t5 $zero 36
add $t5 $t5 $sp
sw $t5 0($sp)
addi $sp $sp -4
addi $t5 $zero 20
add $t5 $t5 $sp
sw $t5 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t5 anotherComp
jal $t5
lw $t5 0($sp)
addi $sp $sp 8
beqz $t5 false_if_47_1
#Este es el código generado por la linea 48 de la llamada a la función: printPerson
addi $t6 $zero 20
add $t6 $t6 $sp
sw $t6 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t6 printPerson
jal $t6
lw $t6 0($sp)
addi $sp $sp 4
j next_if_47_1
false_if_47_1:
#Este es el código generado por la linea 50 de la llamada a la función: printPerson
addi $t7 $zero 36
add $t7 $t7 $sp
sw $t7 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t7 printPerson
jal $t7
lw $t7 0($sp)
addi $sp $sp 4
next_if_47_1:
next_if_40_1:
li $v0 10
syscall
#Definición de Función printPerson: linea 10
printPerson:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 11 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
#Este es el código generado por la linea 12 de la instrucción write
li $s0 4
addi $s2 $zero 0
add $s2 $s2 $fp
lw $s2 4($s2)
add $s0 $s0 $s2
lw $s1 0($s0)
move $a0 $s1
li $v0 1
syscall
la $a0 string_7_2
li $v0 4
syscall
li $s2 0
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
add $s2 $s2 $s4
lw $s3 0($s2)
move $a0 $s3
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
li $s4 8
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s4 $s4 $s6
lw $s5 0($s4)
move $a0 $s5
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
li $s6 12
addi $t8 $zero 0
add $t8 $t8 $fp
lw $t8 4($t8)
add $s6 $s6 $t8
lw $s7 0($s6)
move $a0 $s7
li $v0 1
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función readPerson: linea 15
readPerson:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
li $v0 5
syscall
move $t8 $v0
li $t9 4
addi $a2 $zero 0
add $a2 $a2 $fp
lw $a2 4($a2)
add $t9 $t9 $a2
sw $t8 0($t9)
li $v0 5
syscall
move $a2 $v0
li $a3 8
addi $t0 $zero 0
add $t0 $t0 $fp
lw $t0 4($t0)
add $a3 $a3 $t0
sw $a2 0($a3)
li $v0 5
syscall
move $t0 $v0
li $t1 12
addi $t2 $zero 0
add $t2 $t2 $fp
lw $t2 4($t2)
add $t1 $t1 $t2
sw $t0 0($t1)
li $v0 5
syscall
move $t2 $v0
li $t3 0
addi $t4 $zero 0
add $t4 $t4 $fp
lw $t4 4($t4)
add $t3 $t3 $t4
sw $t2 0($t3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función personComp: linea 22
personComp:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 23 de la instrucción return
li $t4 4
addi $t6 $zero 0
add $t6 $t6 $fp
lw $t6 4($t6)
add $t4 $t4 $t6
lw $t5 0($t4)
li $t6 4
addi $s0 $zero 16
add $s0 $s0 $fp
lw $s0 4($s0)
add $t6 $t6 $s0
lw $t7 0($t6)
slt $s0 $t5 $t7
sw $s0 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $s1 0
sw $s1 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función anotherComp: linea 28
anotherComp:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 29 de la instrucción return
#Este es el código generado por la linea 29 de la llamada a la función: personComp
addi $s2 $zero 16
add $s2 $s2 $fp
lw $s2 4($s2)
sw $s2 0($sp)
addi $sp $sp -4
addi $s2 $zero 0
add $s2 $s2 $fp
lw $s2 4($s2)
sw $s2 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s2 personComp
jal $s2
lw $s2 0($sp)
addi $sp $sp 8
sw $s2 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $s3 0
sw $s3 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
