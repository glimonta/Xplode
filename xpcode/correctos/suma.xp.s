.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -8
#Este es el código generado por la linea 10 de la instrucción f := 6
li $a2 6
move $a3 $a2
#Este es el código generado por la linea 11 de la instrucción g := 9
li $t0 9
move $t1 $t0
#Este es el código generado por la linea 12 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_1
li $v0 4
syscall
#Este es el código generado por la linea 13 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_2
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función suma: linea 3
suma:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 3 de la instrucción return
#Este es el código generado por la linea 3 de la llamada a la función: suma
li $t2 4
add $t2 $t2 $fp
lw $t2 4($t2)
addi $sp $sp -4
sw $t2 4($sp)
li $t3 0
add $t3 $t3 $fp
lw $t3 4($t3)
addi $sp $sp -4
sw $t3 4($sp)
addi $sp $sp -4
la $t4 suma
jal $t4
lw $t4 0($sp)
addi $sp $sp 8
sw $t4 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t5 0
sw $t5 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
