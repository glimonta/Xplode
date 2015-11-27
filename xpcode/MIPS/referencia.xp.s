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
la $a0 string_7_1
li $v0 4
syscall
#Este es el código generado por la linea 35 de la llamada a la función: prueba
addi $t0 $zero 0
add $t0 $t0 $sp
sw $a3 4($t0)
addi $t0 $zero 4
add $t0 $t0 $sp
sw $t0 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t0 prueba
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 37 de la instrucción write
li $t1 0
add $t1 $t1 $sp
lw $t1 4($t1)
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_2
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
li $t2 0
add $t2 $t2 $fp
lw $t2 4($t2)
lw $t2 0($t2)
move $a0 $t2
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 7 de la instrucción a := 7
li $t3 7
move $t2 $t3
#Este es el código generado por la linea 9 de la instrucción write
move $a0 $t2
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
addi $t4 $zero 0
add $t4 $t4 $fp
lw $t4 4($t4)
sw $t2 0($t4)
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
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
lw $t4 0($t4)
move $a0 $t4
li $v0 1
syscall
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 19 de la instrucción b := 5
li $t5 5
move $t4 $t5
#Este es el código generado por la linea 21 de la instrucción write
move $a0 $t4
li $v0 1
syscall
la $a0 string_7_6
li $v0 4
syscall
#Este es el código generado por la linea 23 de la llamada a la función: prueba2
addi $t6 $zero 0
add $t6 $t6 $fp
lw $t6 4($t6)
sw $t4 0($t6)
addi $t6 $zero 0
add $t6 $t6 $fp
lw $t6 4($t6)
sw $t6 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $t6 prueba2
jal $t6
lw $t6 0($sp)
addi $sp $sp 4
#Este es el código generado por la linea 24 de la instrucción write
li $t7 0
add $t7 $t7 $fp
lw $t7 4($t7)
lw $t7 0($t7)
move $a0 $t7
li $v0 1
syscall
la $a0 string_7_7
li $v0 4
syscall
addi $s0 $zero 0
add $s0 $s0 $fp
lw $s0 4($s0)
sw $t7 0($s0)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
