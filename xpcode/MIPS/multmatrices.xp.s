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
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 12 de la instrucción i := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 13 de la instrucción j := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 14 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 15 de la instrucción while que inicia en begin_while_15_1 y termina en next_while_15_1
begin_while_15_1:
slt $t4 $t1 $a3
bnez $t4 true_while_15_1
j next_while_15_1
true_while_15_1:
#Este es el código generado por la linea 16 de la instrucción j := 0
li $t5 0
move $t3 $t5
#Este es el código generado por la linea 17 de la instrucción while que inicia en begin_while_17_1 y termina en next_while_17_1
begin_while_17_1:
slt $t6 $t3 $a3
bnez $t6 true_while_17_1
j next_while_17_1
true_while_17_1:
li $v0 5
syscall
move $t7 $v0
li $s0 50
mul $s1 $t1 $s0
add $s2 $s1 $t3
li $s3 4
mul $s4 $s2 $s3
addi $s4 $s4 0
add $s4 $s4 $sp
sw $t7 4($s4)
#Este es el código generado por la linea 19 de la instrucción j := j + 1
li $s5 1
add $s6 $t3 $s5
move $t3 $s6
j begin_while_17_1
next_while_17_1:
#Este es el código generado por la linea 21 de la instrucción i := i + 1
li $s7 1
add $t8 $t1 $s7
move $t1 $t8
j begin_while_15_1
next_while_15_1:
#Este es el código generado por la linea 23 de la instrucción i := 0
li $t9 0
move $t1 $t9
#Este es el código generado por la linea 24 de la instrucción j := 0
li $a2 0
move $t3 $a2
#Este es el código generado por la linea 25 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 26 de la instrucción while que inicia en begin_while_26_1 y termina en next_while_26_1
begin_while_26_1:
slt $t0 $t1 $a3
bnez $t0 true_while_26_1
j next_while_26_1
true_while_26_1:
#Este es el código generado por la linea 27 de la instrucción j := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 28 de la instrucción while que inicia en begin_while_28_1 y termina en next_while_28_1
begin_while_28_1:
slt $t4 $t3 $a3
bnez $t4 true_while_28_1
j next_while_28_1
true_while_28_1:
li $v0 5
syscall
move $t5 $v0
li $t6 50
mul $s0 $t1 $t6
add $s1 $s0 $t3
li $s2 4
mul $s3 $s1 $s2
addi $s3 $s3 10000
add $s3 $s3 $sp
sw $t5 4($s3)
#Este es el código generado por la linea 30 de la instrucción j := j + 1
li $s4 1
add $t7 $t3 $s4
move $t3 $t7
j begin_while_28_1
next_while_28_1:
#Este es el código generado por la linea 32 de la instrucción i := i + 1
li $s5 1
add $s6 $t1 $s5
move $t1 $s6
j begin_while_26_1
next_while_26_1:
#Este es el código generado por la linea 35 de la instrucción i := 0
li $s7 0
move $t1 $s7
#Este es el código generado por la linea 36 de la instrucción j := 0
li $t8 0
move $t3 $t8
#Este es el código generado por la linea 37 de la instrucción k := 0
li $t9 0
move $a2 $t9
#Este es el código generado por la linea 38 de la instrucción while que inicia en begin_while_38_1 y termina en next_while_38_1
begin_while_38_1:
slt $t0 $t1 $a3
bnez $t0 true_while_38_1
j next_while_38_1
true_while_38_1:
#Este es el código generado por la linea 39 de la instrucción j := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 40 de la instrucción while que inicia en begin_while_40_1 y termina en next_while_40_1
begin_while_40_1:
slt $t4 $t3 $a3
bnez $t4 true_while_40_1
j next_while_40_1
true_while_40_1:
#Este es el código generado por la linea 41 de la instrucción tmp := 0
li $t6 0
move $s0 $t6
#Este es el código generado por la linea 42 de la instrucción k := 0
li $s1 0
move $a2 $s1
#Este es el código generado por la linea 43 de la instrucción while que inicia en begin_while_43_1 y termina en next_while_43_1
begin_while_43_1:
slt $s2 $a2 $a3
bnez $s2 true_while_43_1
j next_while_43_1
true_while_43_1:
#Este es el código generado por la linea 44 de la instrucción tmp := tmp + mat1[i][k] * mat2[k][j]
li $s3 50
mul $t5 $t1 $s3
add $s4 $t5 $a2
li $t7 4
mul $s5 $s4 $t7
addi $s5 $s5 0
add $s5 $s5 $sp
lw $s6 4($s5)
li $s7 50
mul $t8 $a2 $s7
add $t9 $t8 $t3
li $t0 4
mul $t2 $t9 $t0
addi $t2 $t2 10000
add $t2 $t2 $sp
lw $t4 4($t2)
mul $t6 $s6 $t4
add $s1 $s0 $t6
move $s0 $s1
#Este es el código generado por la linea 45 de la instrucción k := k + 1
li $s2 1
add $s3 $a2 $s2
move $a2 $s3
j begin_while_43_1
next_while_43_1:
#Este es el código generado por la linea 47 de la instrucción mat3[i][j] := tmp
li $t5 50
mul $s4 $t1 $t5
add $t7 $s4 $t3
li $s5 4
mul $s7 $t7 $s5
addi $s7 $s7 20000
add $s7 $s7 $sp
sw $s0 4($s7)
#Este es el código generado por la linea 48 de la instrucción j := j + 1
li $t8 1
add $t9 $t3 $t8
move $t3 $t9
j begin_while_40_1
next_while_40_1:
#Este es el código generado por la linea 50 de la instrucción i := i + 1
li $t0 1
add $t2 $t1 $t0
move $t1 $t2
j begin_while_38_1
next_while_38_1:
#Este es el código generado por la linea 53 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
#Este es el código generado por la linea 55 de la instrucción i := 0
li $s6 0
move $t1 $s6
#Este es el código generado por la linea 56 de la instrucción j := 0
li $t4 0
move $t3 $t4
#Este es el código generado por la linea 57 de la instrucción while que inicia en begin_while_57_1 y termina en next_while_57_1
begin_while_57_1:
slt $t6 $t1 $a3
bnez $t6 true_while_57_1
j next_while_57_1
true_while_57_1:
#Este es el código generado por la linea 58 de la instrucción j := 0
li $s1 0
move $t3 $s1
#Este es el código generado por la linea 59 de la instrucción while que inicia en begin_while_59_1 y termina en next_while_59_1
begin_while_59_1:
slt $s2 $t3 $a3
bnez $s2 true_while_59_1
j next_while_59_1
true_while_59_1:
#Este es el código generado por la linea 60 de la instrucción write
li $s3 50
mul $t5 $t1 $s3
add $s4 $t5 $t3
li $t7 4
mul $s5 $s4 $t7
addi $s5 $s5 20000
add $s5 $s5 $sp
lw $s7 4($s5)
move $a0 $s7
li $v0 1
syscall
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 61 de la instrucción j := j + 1
li $t8 1
add $t9 $t3 $t8
move $t3 $t9
j begin_while_59_1
next_while_59_1:
#Este es el código generado por la linea 63 de la instrucción write
la $a0 string_7_6
li $v0 4
syscall
#Este es el código generado por la linea 64 de la instrucción i := i + 1
li $t0 1
add $t2 $t1 $t0
move $t1 $t2
j begin_while_57_1
next_while_57_1:
li $v0 10
syscall
