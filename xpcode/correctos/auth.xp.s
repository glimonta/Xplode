.data
string_7_1:    .asciiz "You're in.\n"
string_7_2:    .asciiz "You thief! \n"

.align 4

.text
main:
addi $sp $sp -4
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 12 de la instrucción if que termina en next_if_12_1
#Este es el código generado por la linea 12 de la llamada a la función: authenticate
addi $t0 $zero 0
add $t0 $t0 $sp
sw $a3 4($t0)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t0 authenticate
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
beqz $t0 false_if_12_1
#Este es el código generado por la linea 13 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
j next_if_12_1
false_if_12_1:
#Este es el código generado por la linea 15 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
next_if_12_1:
li $v0 10
syscall
#Definición de Función authenticate: linea 3
authenticate:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 4 de la instrucción return
li $t1 0
add $t1 $t1 $fp
lw $t1 4($t1)
sub $t2 $t1 $t1
add $t3 $t2 $t1
seq $t4 $t1 $t3
sw $t4 0($fp)
addi $t5 $zero 0
add $t5 $t5 $fp
sw $t1 4($t5)
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
