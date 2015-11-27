.data
string_7_1:    .asciiz "n es 42"
string_7_2:    .asciiz "Not magical, try again!\n"
string_7_3:    .asciiz "SUCCESS!"

.align 4

.text
main:
addi $sp $sp -4
#Este es el código generado por la linea 19 de la instrucción n := 0
li $a2 0
move $a3 $a2
#Este es el código generado por la linea 20 de la instrucción while que inicia en begin_while_20_1 y termina en next_while_20_1
begin_while_20_1:
#Este es el código generado por la linea 20 de la llamada a la función: magicNumber
addi $t0 $zero 0
add $t0 $t0 $sp
sw $a3 4($t0)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t0 magicNumber
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
bnez $t0 next_while_20_1
j true_while_20_1
true_while_20_1:
li $v0 5
syscall
move $t1 $v0
move $t2 $t1
#Este es el código generado por la linea 22 de la instrucción if que termina en next_if_22_1
li $t3 42
seq $t4 $t2 $t3
beqz $t4 next_if_22_1
#Este es el código generado por la linea 23 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
#Este es el código generado por la linea 24 de la instrucción continue
j begin_while_20_1
next_if_22_1:
#Este es el código generado por la linea 26 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
j begin_while_20_1
next_while_20_1:
#Este es el código generado por la linea 28 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 30 de la instrucción sleep
#Este es el código generado por la linea 31 de la instrucción sleep
li $v0 10
syscall
#Definición de Función magicNumber: linea 3
magicNumber:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -4
#Este es el código generado por la linea 5 de la instrucción k := 0
li $t5 0
move $t6 $t5
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $t7 0
add $t7 $t7 $fp
lw $t7 4($t7)
li $s0 2
slt $s1 $t7 $s0
beqz $s1 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción return
li $s2 0
sw $s2 0($fp)
addi $s3 $zero 0
add $s3 $s3 $sp
sw $t6 4($s3)
addi $s3 $zero 0
add $s3 $s3 $fp
sw $t7 4($s3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 9 de la instrucción for que inicia en begin_for_9_1 y termina en end_for_9_1
#Este es el código generado por la linea 9 de la instrucción k := 2
li $s3 2
move $s4 $s3
j first_for_9_1
begin_for_9_1:
#Este es el código generado por la linea 9 de la instrucción k := k + 1
li $s5 1
add $s6 $s4 $s5
move $s4 $s6
first_for_9_1:
li $s7 0
add $s7 $s7 $fp
lw $s7 4($s7)
slt $t8 $s4 $s7
bnez $t8 mid1
j end_for_9_1
mid1:
#Este es el código generado por la linea 10 de la instrucción if que termina en next_if_10_1
div $s7 $s4
mflo $t9
li $a2 0
seq $a3 $t9 $a2
beqz $a3 next_if_10_1
#Este es el código generado por la linea 11 de la instrucción return
li $t0 0
sw $t0 0($fp)
addi $t1 $zero 0
add $t1 $t1 $sp
sw $s4 4($t1)
addi $t1 $zero 0
add $t1 $t1 $fp
sw $s7 4($t1)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_10_1:
j begin_for_9_1
end_for_9_1:
#Este es el código generado por la linea 14 de la instrucción return
li $t1 1
sw $t1 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t3 0
sw $t3 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
