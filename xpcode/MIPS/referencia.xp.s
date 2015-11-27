.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"
string_7_3:    .asciiz "\n"
string_7_4:    .asciiz "\n"
string_7_5:    .asciiz "\n"
string_7_6:    .asciiz "\n"
string_7_7:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -4
#Este es el código generado por la linea 32 de la instrucción i := 3
li $a2 3
move $a3 $a2
#Este es el código generado por la linea 33 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $t0 string_7_1
move $a0 $t0
li $v0 4
syscall
#Este es el código generado por la linea 35 de la llamada a la función: prueba
addi $t1 $zero 0
add $t1 $t1 $sp
sw $a3 4($t1)
addi $t1 $zero 4
add $t1 $t1 $sp
sw $t1 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t1 prueba
jal $t1
lw $t1 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 37 de la instrucción write
li $t2 0
add $t2 $t2 $sp
lw $t2 4($t2)
move $a0 $t2
li $v0 1
syscall
la $t3 string_7_2
move $a0 $t3
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función prueba2: linea 3
prueba2:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 5 de la instrucción write
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
lw $t4 0($t4)
move $a0 $t4
li $v0 1
syscall
la $t5 string_7_3
move $a0 $t5
li $v0 4
syscall
#Este es el código generado por la linea 7 de la instrucción a := 7
li $t6 7
move $t4 $t6
#Este es el código generado por la linea 9 de la instrucción write
move $a0 $t4
li $v0 1
syscall
la $t7 string_7_4
move $a0 $t7
li $v0 4
syscall
addi $s0 $zero 0
add $s0 $s0 $fp
lw $s0 4($s0)
sw $t4 0($s0)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función prueba: linea 15
prueba:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 17 de la instrucción write
li $s0 0
add $s0 $s0 $fp
lw $s0 4($s0)
lw $s0 0($s0)
move $a0 $s0
li $v0 1
syscall
la $s1 string_7_5
move $a0 $s1
li $v0 4
syscall
#Este es el código generado por la linea 19 de la instrucción b := 5
li $s2 5
move $s0 $s2
#Este es el código generado por la linea 21 de la instrucción write
move $a0 $s0
li $v0 1
syscall
la $s3 string_7_6
move $a0 $s3
li $v0 4
syscall
#Este es el código generado por la linea 23 de la llamada a la función: prueba2
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
sw $s0 0($s4)
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
sw $s4 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s4 prueba2
jal $s4
lw $s4 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 24 de la instrucción write
li $s5 0
add $s5 $s5 $fp
lw $s5 4($s5)
lw $s5 0($s5)
move $a0 $s5
li $v0 1
syscall
la $s6 string_7_7
move $a0 $s6
li $v0 4
syscall
addi $s7 $zero 0
add $s7 $s7 $fp
lw $s7 4($s7)
sw $s5 0($s7)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
