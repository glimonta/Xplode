.data
string_7_1:    .asciiz "Person Data is : "
string_7_2:    .asciiz " "
string_7_3:    .asciiz " "
string_7_4:    .asciiz " "

.align 4

.text
main:
addi $sp $sp -244
#Este es el código generado por la linea 26 de la instrucción for que inicia en begin_for_26_1 y termina en end_for_26_1
#Este es el código generado por la linea 26 de la instrucción i := 0
li $a2 0
move $a3 $a2
j first_for_26_1
begin_for_26_1:
#Este es el código generado por la linea 26 de la instrucción i := 1 + 1
li $t0 1
li $t1 1
add $t2 $t0 $t1
move $a3 $t2
first_for_26_1:
li $t3 10
slt $t4 $a3 $t3
bnez $t4 mid1
j end_for_26_1
mid1:
#Este es el código generado por la linea 27 de la llamada a la función: readPerson
addi $t5 $zero 240
add $t5 $t5 $sp
sw $a3 4($t5)
li $t5 24
mul $t6 $a3 $t5
addi $t7 $zero 4
add $t7 $t7 $sp
sw $t7 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t7 readPerson
jal $t7
lw $t7 0($sp)
addi $sp $sp 4
j begin_for_26_1
end_for_26_1:
#Este es el código generado por la linea 29 de la instrucción for que inicia en begin_for_29_1 y termina en end_for_29_1
#Este es el código generado por la linea 29 de la instrucción i := 0
li $s0 0
move $s1 $s0
j first_for_29_1
begin_for_29_1:
#Este es el código generado por la linea 29 de la instrucción i := 1 + 1
li $s2 1
li $s3 1
add $s4 $s2 $s3
move $s1 $s4
first_for_29_1:
li $s5 10
slt $s6 $s1 $s5
bnez $s6 mid2
j end_for_29_1
mid2:
#Este es el código generado por la linea 30 de la llamada a la función: printPerson
addi $s7 $zero 240
add $s7 $s7 $sp
sw $s1 4($s7)
li $s7 24
mul $t8 $s1 $s7
addi $t9 $zero 4
add $t9 $t9 $sp
sw $t9 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t9 printPerson
jal $t9
lw $t9 0($sp)
addi $sp $sp 4
j begin_for_29_1
end_for_29_1:
#Este es el código generado por la linea 33 de la instrucción i := p[7].id
li $a2 7
li $t0 24
mul $t1 $a2 $t0
li $t2 12
add $t3 $t1 $t2
addi $t3 $t3 0
add $t3 $t3 $sp
lw $t4 4($t3)
move $t5 $t4
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
li $a3 12
addi $s0 $zero 0
add $s0 $s0 $fp
lw $s0 4($s0)
add $a3 $a3 $s0
lw $t6 0($a3)
move $a0 $t6
li $v0 1
syscall
la $a0 string_7_2
li $v0 4
syscall
li $s0 0
addi $s3 $zero 0
add $s3 $s3 $fp
lw $s3 4($s3)
add $s0 $s0 $s3
lw $s2 0($s0)
la $a0 string_7_3
li $v0 4
syscall
li $s3 16
addi $s5 $zero 0
add $s5 $s5 $fp
lw $s5 4($s5)
add $s3 $s3 $s5
lw $s4 0($s3)
mov.s $f12 $f1
li $v0 2
syscall
la $a0 string_7_4
li $v0 4
syscall
li $s5 20
addi $s7 $zero 0
add $s7 $s7 $fp
lw $s7 4($s7)
add $s5 $s5 $s7
lw $s6 0($s5)
mov.s $f12 $f2
li $v0 2
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
move $s7 $v0
li $s1 12
addi $t7 $zero 0
add $t7 $t7 $fp
lw $t7 4($t7)
add $s1 $s1 $t7
sw $s7 0($s1)
li $v0 6
syscall
mov.s $f3 $f0
li $t7 16
addi $a2 $zero 0
add $a2 $a2 $fp
lw $a2 4($a2)
add $t7 $t7 $a2
sw $t8 0($t7)
li $v0 6
syscall
mov.s $f4 $f0
li $a2 20
addi $t1 $zero 0
add $t1 $t1 $fp
lw $t1 4($t1)
add $a2 $a2 $t1
sw $t0 0($a2)
li $t1 0
addi $t3 $zero 0
add $t3 $t3 $fp
lw $t3 4($t3)
add $t1 $t1 $t3
sw $t2 0($t1)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
