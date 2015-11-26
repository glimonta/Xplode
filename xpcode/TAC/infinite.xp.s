.data
string_7_1:    .asciiz "Lei un numero"
string_7_2:    .asciiz "Ciclo infinito"
string_7_3:    .asciiz "Aca saco el promedio con la magia de next, length y la desconocida"

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
la $t2 string_7_1
move $a0 $t2
li $v0 4
syscall
#Este es el código generado por la linea 23 de la instrucción if que termina en next_if_23_1
li $t3 4
mul $t4 $a3 $t3
addi $t4 $t4 0
add $t4 $t4 $sp
lw $t5 4($t4)
li $t6 1
neg $t7 $t6
seq $s0 $t5 $t7
beqz $s0 next_if_23_1
#Este es el código generado por la linea 23 de la instrucción break
j next_while_18_1
next_if_23_1:
#Este es el código generado por la linea 24 de la llamada a la función: prom
addi $s1 $zero 20
add $s1 $s1 $sp
sw $a3 4($s1)
li $s1 1
li $s2 4
mul $s3 $s1 $s2
addi $s3 $s3 0
add $s3 $s3 $sp
lw $s4 4($s3)
addi $sp $sp -4
sw $s4 4($sp)
li $s5 0
li $s6 4
mul $s7 $s5 $s6
addi $s7 $s7 0
add $s7 $s7 $sp
lw $t8 4($s7)
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
la $t9 prom
jal $t9
lw $t9 0($sp)
addi $sp $sp 8
#Este es el código generado por la linea 26 de la instrucción if que termina en next_if_26_1
li $t0 20
add $t0 $t0 $sp
lw $t0 4($t0)
li $t3 4
seq $t6 $t0 $t3
beqz $t6 next_if_26_1
#Este es el código generado por la linea 26 de la instrucción i := 0
li $s1 0
move $t0 $s1
next_if_26_1:
#Este es el código generado por la linea 27 de la instrucción i := i + 1
li $s2 1
add $s5 $t0 $s2
move $t0 $s5
j begin_while_18_1
next_while_18_1:
#Este es el código generado por la linea 32 de la instrucción while que inicia en begin_while_32_1 y termina en next_while_32_1
begin_while_32_1:
j true_while_32_1
true_while_32_1:
#Este es el código generado por la linea 32 de la instrucción write
la $s6 string_7_2
move $a0 $s6
li $v0 4
syscall
j begin_while_32_1
next_while_32_1:
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
la $a3 string_7_3
move $a0 $a3
li $v0 4
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
