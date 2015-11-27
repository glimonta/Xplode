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
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 11 de la instrucción punto := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 13 de la instrucción i := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 15 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 16 de la instrucción while que inicia en begin_while_16_1 y termina en next_while_16_1
begin_while_16_1:
slt $t4 $t3 $a3
bnez $t4 true_while_16_1
j next_while_16_1
true_while_16_1:
li $v0 5
syscall
move $t5 $v0
li $t6 4
mul $t7 $t3 $t6
addi $t7 $t7 12
add $t7 $t7 $sp
sw $t5 4($t7)
#Este es el código generado por la linea 18 de la instrucción i := i + 1
li $s0 1
add $s1 $t3 $s0
move $t3 $s1
j begin_while_16_1
next_while_16_1:
#Este es el código generado por la linea 21 de la instrucción i := 0
li $s2 0
move $t3 $s2
#Este es el código generado por la linea 22 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 23 de la instrucción while que inicia en begin_while_23_1 y termina en next_while_23_1
begin_while_23_1:
slt $s3 $t3 $a3
bnez $s3 true_while_23_1
j next_while_23_1
true_while_23_1:
li $v0 5
syscall
move $s4 $v0
li $s5 4
mul $s6 $t3 $s5
addi $s6 $s6 132
add $s6 $s6 $sp
sw $s4 4($s6)
#Este es el código generado por la linea 25 de la instrucción i := i + 1
li $s7 1
add $t8 $t3 $s7
move $t3 $t8
j begin_while_23_1
next_while_23_1:
#Este es el código generado por la linea 28 de la instrucción i := 0
li $t9 0
move $t3 $t9
#Este es el código generado por la linea 30 de la instrucción while que inicia en begin_while_30_1 y termina en next_while_30_1
begin_while_30_1:
slt $a2 $t3 $a3
bnez $a2 true_while_30_1
j next_while_30_1
true_while_30_1:
#Este es el código generado por la linea 31 de la instrucción punto := punto + x[i] * x2[i]
li $t0 4
mul $t2 $t3 $t0
addi $t2 $t2 12
add $t2 $t2 $sp
lw $t4 4($t2)
li $t6 4
mul $t7 $t3 $t6
addi $t7 $t7 132
add $t7 $t7 $sp
lw $t5 4($t7)
mul $s0 $t4 $t5
add $s1 $t1 $s0
move $t1 $s1
#Este es el código generado por la linea 32 de la instrucción i := i + 1
li $s2 1
add $s3 $t3 $s2
move $t3 $s3
j begin_while_30_1
next_while_30_1:
#Este es el código generado por la linea 36 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_5
li $v0 4
syscall
li $v0 10
syscall
