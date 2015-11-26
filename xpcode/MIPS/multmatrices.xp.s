.data
string_7_1:    .asciiz "Escriba la dimension de una matriz cuadrada\n"
string_7_2:    .asciiz "Escriba la primera matriz\n"
string_7_3:    .asciiz "Escriba la segunda matriz\n"
string_7_4:    .asciiz "Matriz resultante:\n"
string_7_5:    .asciiz " "
string_7_6:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -30020
#Este es el código generado por la linea 10 de la instrucción write
la $a2 string_7_1
move $a0 $a2
li $v0 4
syscall
li $v0 5
syscall
move $a3 $v0
move $t0 $a3
#Este es el código generado por la linea 12 de la instrucción i := 0
li $t1 0
move $t2 $t1
#Este es el código generado por la linea 13 de la instrucción j := 0
li $t3 0
move $t4 $t3
#Este es el código generado por la linea 14 de la instrucción write
la $t5 string_7_2
move $a0 $t5
li $v0 4
syscall
#Este es el código generado por la linea 15 de la instrucción while que inicia en begin_while_15_1 y termina en next_while_15_1
begin_while_15_1:
slt $t6 $t2 $t0
bnez $t6 true_while_15_1
j next_while_15_1
true_while_15_1:
#Este es el código generado por la linea 16 de la instrucción j := 0
li $t7 0
move $t4 $t7
#Este es el código generado por la linea 17 de la instrucción while que inicia en begin_while_17_1 y termina en next_while_17_1
begin_while_17_1:
slt $s0 $t4 $t0
bnez $s0 true_while_17_1
j next_while_17_1
true_while_17_1:
li $v0 5
syscall
move $s1 $v0
li $s2 50
mul $s3 $t2 $s2
add $s4 $s3 $t4
li $s5 4
mul $s6 $s4 $s5
addi $s6 $s6 0
add $s6 $s6 $sp
sw $s1 4($s6)
#Este es el código generado por la linea 19 de la instrucción j := j + 1
li $s7 1
add $t8 $t4 $s7
move $t4 $t8
j begin_while_17_1
next_while_17_1:
#Este es el código generado por la linea 21 de la instrucción i := i + 1
li $t9 1
add $a3 $t2 $t9
move $t2 $a3
j begin_while_15_1
next_while_15_1:
#Este es el código generado por la linea 23 de la instrucción i := 0
li $t1 0
move $t2 $t1
#Este es el código generado por la linea 24 de la instrucción j := 0
li $t3 0
move $t4 $t3
#Este es el código generado por la linea 25 de la instrucción write
la $t6 string_7_3
move $a0 $t6
li $v0 4
syscall
#Este es el código generado por la linea 26 de la instrucción while que inicia en begin_while_26_1 y termina en next_while_26_1
begin_while_26_1:
slt $t7 $t2 $t0
bnez $t7 true_while_26_1
j next_while_26_1
true_while_26_1:
#Este es el código generado por la linea 27 de la instrucción j := 0
li $s0 0
move $t4 $s0
#Este es el código generado por la linea 28 de la instrucción while que inicia en begin_while_28_1 y termina en next_while_28_1
begin_while_28_1:
slt $s2 $t4 $t0
bnez $s2 true_while_28_1
j next_while_28_1
true_while_28_1:
li $v0 5
syscall
move $s3 $v0
li $s4 50
mul $s5 $t2 $s4
add $s6 $s5 $t4
li $s1 4
mul $s7 $s6 $s1
addi $s7 $s7 10000
add $s7 $s7 $sp
sw $s3 4($s7)
#Este es el código generado por la linea 30 de la instrucción j := j + 1
li $t8 1
add $t9 $t4 $t8
move $t4 $t9
j begin_while_28_1
next_while_28_1:
#Este es el código generado por la linea 32 de la instrucción i := i + 1
li $a3 1
add $t1 $t2 $a3
move $t2 $t1
j begin_while_26_1
next_while_26_1:
#Este es el código generado por la linea 35 de la instrucción i := 0
li $t3 0
move $t2 $t3
#Este es el código generado por la linea 36 de la instrucción j := 0
li $t7 0
move $t4 $t7
#Este es el código generado por la linea 37 de la instrucción k := 0
li $s0 0
move $s2 $s0
#Este es el código generado por la linea 38 de la instrucción while que inicia en begin_while_38_1 y termina en next_while_38_1
begin_while_38_1:
slt $s4 $t2 $t0
bnez $s4 true_while_38_1
j next_while_38_1
true_while_38_1:
#Este es el código generado por la linea 39 de la instrucción j := 0
li $s5 0
move $t4 $s5
#Este es el código generado por la linea 40 de la instrucción while que inicia en begin_while_40_1 y termina en next_while_40_1
begin_while_40_1:
slt $s6 $t4 $t0
bnez $s6 true_while_40_1
j next_while_40_1
true_while_40_1:
#Este es el código generado por la linea 41 de la instrucción tmp := 0
li $s1 0
move $s7 $s1
#Este es el código generado por la linea 42 de la instrucción k := 0
li $s3 0
move $s2 $s3
#Este es el código generado por la linea 43 de la instrucción while que inicia en begin_while_43_1 y termina en next_while_43_1
begin_while_43_1:
slt $t8 $s2 $t0
bnez $t8 true_while_43_1
j next_while_43_1
true_while_43_1:
#Este es el código generado por la linea 44 de la instrucción tmp := tmp + mat1[i][k] * mat2[k][j]
li $t9 50
mul $a3 $t2 $t9
add $t1 $a3 $s2
li $t3 4
mul $t7 $t1 $t3
addi $t7 $t7 0
add $t7 $t7 $sp
lw $s0 4($t7)
li $s4 50
mul $s5 $s2 $s4
add $s6 $s5 $t4
li $s1 4
mul $s3 $s6 $s1
addi $s3 $s3 10000
add $s3 $s3 $sp
lw $t8 4($s3)
mul $t9 $s0 $t8
add $a3 $s7 $t9
move $s7 $a3
#Este es el código generado por la linea 45 de la instrucción k := k + 1
li $t1 1
add $t3 $s2 $t1
move $s2 $t3
j begin_while_43_1
next_while_43_1:
#Este es el código generado por la linea 47 de la instrucción mat3[i][j] := tmp
li $t7 50
mul $s4 $t2 $t7
add $s5 $s4 $t4
li $s6 4
mul $s1 $s5 $s6
addi $s1 $s1 20000
add $s1 $s1 $sp
sw $s7 4($s1)
#Este es el código generado por la linea 48 de la instrucción j := j + 1
li $s3 1
add $s0 $t4 $s3
move $t4 $s0
j begin_while_40_1
next_while_40_1:
#Este es el código generado por la linea 50 de la instrucción i := i + 1
li $t8 1
add $t9 $t2 $t8
move $t2 $t9
j begin_while_38_1
next_while_38_1:
#Este es el código generado por la linea 53 de la instrucción write
la $a3 string_7_4
move $a0 $a3
li $v0 4
syscall
#Este es el código generado por la linea 55 de la instrucción i := 0
li $t1 0
move $t2 $t1
#Este es el código generado por la linea 56 de la instrucción j := 0
li $t3 0
move $t4 $t3
#Este es el código generado por la linea 57 de la instrucción while que inicia en begin_while_57_1 y termina en next_while_57_1
begin_while_57_1:
slt $t7 $t2 $t0
bnez $t7 true_while_57_1
j next_while_57_1
true_while_57_1:
#Este es el código generado por la linea 58 de la instrucción j := 0
li $s4 0
move $t4 $s4
#Este es el código generado por la linea 59 de la instrucción while que inicia en begin_while_59_1 y termina en next_while_59_1
begin_while_59_1:
slt $s5 $t4 $t0
bnez $s5 true_while_59_1
j next_while_59_1
true_while_59_1:
#Este es el código generado por la linea 60 de la instrucción write
li $s6 50
mul $s1 $t2 $s6
add $s3 $s1 $t4
li $s0 4
mul $t8 $s3 $s0
addi $t8 $t8 20000
add $t8 $t8 $sp
lw $t9 4($t8)
move $a0 $t9
li $v0 1
syscall
la $t1 string_7_5
move $a0 $t1
li $v0 4
syscall
#Este es el código generado por la linea 61 de la instrucción j := j + 1
li $t3 1
add $t7 $t4 $t3
move $t4 $t7
j begin_while_59_1
next_while_59_1:
#Este es el código generado por la linea 63 de la instrucción write
la $s4 string_7_6
move $a0 $s4
li $v0 4
syscall
#Este es el código generado por la linea 64 de la instrucción i := i + 1
li $s5 1
add $s6 $t2 $s5
move $t2 $s6
j begin_while_57_1
next_while_57_1:
li $v0 10
syscall
