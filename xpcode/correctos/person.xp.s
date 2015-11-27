.data
string_7_1:    .asciiz "Person Data is : "
string_7_2:    .asciiz " "
string_7_3:    .asciiz " "
string_7_4:    .asciiz "Person Id is : "
string_7_5:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -12
li $v0 5
syscall
move $a2 $v0
li $a3 0
addi $a3 $a3 0
add $a3 $a3 $sp
sw $a2 4($a3)
li $v0 6
syscall
mov.s $f1 $f0
li $t0 4
addi $t0 $t0 0
add $t0 $t0 $sp
sw $t1 4($t0)
li $v0 6
syscall
mov.s $f2 $f0
li $t2 8
addi $t2 $t2 0
add $t2 $t2 $sp
sw $t3 4($t2)
#Este es el código generado por la linea 25 de la llamada a la función: print
addi $t4 $zero 4
add $t4 $t4 $sp
sw $t4 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t4 print
jal $t4
lw $t4 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 26 de la llamada a la función: print2
li $t5 0
addi $t5 $t5 0
add $t5 $t5 $sp
lw $t6 4($t5)
addi $sp $sp -4
sw $t6 4($sp)
addi $sp $sp -4
la $t7 print2
jal $t7
lw $t7 0($sp)
addi $sp $sp 4
li $v0 10
syscall
#Definición de Función print: linea 10
print:
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
li $s0 0
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
li $s2 4
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
add $s2 $s2 $s4
lw $s3 0($s2)
mov.s $f12 $f3
li $v0 2
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
mov.s $f12 $f4
li $v0 2
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función print2: linea 15
print2:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 16 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
#Este es el código generado por la linea 17 de la instrucción write
li $s6 0
add $s6 $s6 $fp
lw $s6 4($s6)
move $a0 $s6
li $v0 1
syscall
la $a0 string_7_5
li $v0 4
syscall
addi $s7 $zero 0
add $s7 $s7 $fp
sw $s6 4($s7)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
