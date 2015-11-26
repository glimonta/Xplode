.data
string_7_1:    .asciiz "Escriba la dimension del los vectores:\n"
string_7_2:    .asciiz "Escriba los valores del primer vector:\n"
string_7_3:    .asciiz "Escriba los valores del segundo vector:\n"
string_7_4:    .asciiz "El producto punto da: "
string_7_5:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -252
#Este es el código generado por la linea 9 de la instrucción write
la $a2 string_7_1
move $a0 $a2
li $v0 4
syscall
li $v0 5
syscall
move $a3 $v0
move $t0 $a3
#Este es el código generado por la linea 11 de la instrucción punto := 0
li $t1 0
move $t2 $t1
#Este es el código generado por la linea 13 de la instrucción i := 0
li $t3 0
move $t4 $t3
#Este es el código generado por la linea 15 de la instrucción write
la $t5 string_7_2
move $a0 $t5
li $v0 4
syscall
#Este es el código generado por la linea 16 de la instrucción while que inicia en begin_while_16_1 y termina en next_while_16_1
begin_while_16_1:
slt $t6 $t4 $t0
bnez $t6 true_while_16_1
j next_while_16_1
true_while_16_1:
li $v0 5
syscall
move $t7 $v0
li $s0 4
mul $s1 $t4 $s0
addi $s1 $s1 12
add $s1 $s1 $sp
sw $t7 4($s1)
#Este es el código generado por la linea 18 de la instrucción i := i + 1
li $s2 1
add $s3 $t4 $s2
move $t4 $s3
j begin_while_16_1
next_while_16_1:
#Este es el código generado por la linea 21 de la instrucción i := 0
li $s4 0
move $t4 $s4
#Este es el código generado por la linea 22 de la instrucción write
la $s5 string_7_3
move $a0 $s5
li $v0 4
syscall
#Este es el código generado por la linea 23 de la instrucción while que inicia en begin_while_23_1 y termina en next_while_23_1
begin_while_23_1:
slt $s6 $t4 $t0
bnez $s6 true_while_23_1
j next_while_23_1
true_while_23_1:
li $v0 5
syscall
move $s7 $v0
li $t8 4
mul $t9 $t4 $t8
addi $t9 $t9 132
add $t9 $t9 $sp
sw $s7 4($t9)
#Este es el código generado por la linea 25 de la instrucción i := i + 1
li $a3 1
add $t1 $t4 $a3
move $t4 $t1
j begin_while_23_1
next_while_23_1:
#Este es el código generado por la linea 28 de la instrucción i := 0
li $t3 0
move $t4 $t3
#Este es el código generado por la linea 30 de la instrucción while que inicia en begin_while_30_1 y termina en next_while_30_1
begin_while_30_1:
slt $t6 $t4 $t0
bnez $t6 true_while_30_1
j next_while_30_1
true_while_30_1:
#Este es el código generado por la linea 31 de la instrucción punto := punto + x[i] * x2[i]
li $s0 4
mul $s1 $t4 $s0
addi $s1 $s1 12
add $s1 $s1 $sp
lw $t7 4($s1)
li $s2 4
mul $s3 $t4 $s2
addi $s3 $s3 132
add $s3 $s3 $sp
lw $s4 4($s3)
mul $s6 $t7 $s4
add $t8 $t2 $s6
move $t2 $t8
#Este es el código generado por la linea 32 de la instrucción i := i + 1
li $t9 1
add $s7 $t4 $t9
move $t4 $s7
j begin_while_30_1
next_while_30_1:
#Este es el código generado por la linea 36 de la instrucción write
la $a3 string_7_4
move $a0 $a3
li $v0 4
syscall
move $a0 $t2
li $v0 1
syscall
la $t1 string_7_5
move $a0 $t1
li $v0 4
syscall
li $v0 10
syscall
