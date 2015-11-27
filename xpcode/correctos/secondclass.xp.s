.data
string_7_1:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -4
#Este es el código generado por la linea 12 de la instrucción x := suma(2, 3)
#Este es el código generado por la linea 12 de la llamada a la función: suma
li $a2 3
addi $sp $sp -4
sw $a2 4($sp)
li $a3 2
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t0 suma
jal $t0
lw $t0 0($sp)
addi $sp $sp 8
move $t1 $t0
#Este es el código generado por la linea 13 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_1
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función suma: linea 4
suma:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 4 de la instrucción return
li $t2 0
add $t2 $t2 $fp
lw $t2 4($t2)
li $t3 4
add $t3 $t3 $fp
lw $t3 4($t3)
add $t4 $t2 $t3
sw $t4 0($fp)
addi $t5 $zero 0
add $t5 $t5 $fp
sw $t2 4($t5)
addi $t5 $zero 4
add $t5 $t5 $fp
sw $t3 4($t5)
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
