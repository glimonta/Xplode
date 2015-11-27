.data
string_7_1:    .asciiz "Lei un numero"
string_7_2:    .asciiz "Aca saco el promedio con la magia de next, length y la desconocida"

.align 4

.text
main:
addi $sp $sp -24
#Este es el código generado por la linea 18 de la instrucción while que inicia en begin_while_18_1 y termina en next_while_18_1
begin_while_18_1:
j true_while_18_1
true_while_18_1:
li $v0 5
syscall
move $a2 $v0
li $a3 20
add $a3 $a3 $sp
lw $a3 4($a3)
li $t0 4
mul $t1 $a3 $t0
addi $t1 $t1 0
add $t1 $t1 $sp
sw $a2 4($t1)
#Este es el código generado por la linea 22 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
#Este es el código generado por la linea 23 de la instrucción if que termina en next_if_23_1
li $t2 4
mul $t3 $a3 $t2
addi $t3 $t3 0
add $t3 $t3 $sp
lw $t4 4($t3)
li $t5 1
neg $t6 $t5
seq $t7 $t4 $t6
beqz $t7 next_if_23_1
#Este es el código generado por la linea 23 de la instrucción break
j next_while_18_1
next_if_23_1:
#Este es el código generado por la linea 24 de la llamada a la función: prom
addi $s0 $zero 20
add $s0 $s0 $sp
sw $a3 4($s0)
li $s0 1
li $s1 4
mul $s2 $s0 $s1
addi $s2 $s2 0
add $s2 $s2 $sp
lw $s3 4($s2)
addi $sp $sp -4
sw $s3 4($sp)
li $s4 0
li $s5 4
mul $s6 $s4 $s5
addi $s6 $s6 0
add $s6 $s6 $sp
lw $s7 4($s6)
addi $sp $sp -4
sw $s7 4($sp)
addi $sp $sp -4
la $t8 prom
jal $t8
lw $t8 0($sp)
addi $sp $sp 8
#Este es el código generado por la linea 26 de la instrucción if que termina en next_if_26_1
li $t9 20
add $t9 $t9 $sp
lw $t9 4($t9)
li $t0 4
seq $t1 $t9 $t0
beqz $t1 next_if_26_1
#Este es el código generado por la linea 26 de la instrucción i := 0
li $a2 0
move $t9 $a2
next_if_26_1:
#Este es el código generado por la linea 27 de la instrucción i := i + 1
li $t2 1
add $t3 $t9 $t2
move $t9 $t3
j begin_while_18_1
next_while_18_1:
li $v0 10
syscall
#Definición de Función prom: linea 3
prom:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 6 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
