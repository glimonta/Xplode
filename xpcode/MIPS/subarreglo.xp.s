.data
string_7_1:    .asciiz "Escriba el tamano de la cadena\n"
string_7_2:    .asciiz "Escriba el tamano del posible substring\n"
string_7_3:    .asciiz "Escriba la primera cadena que desea saber si esta contenida en la segunda\n"
string_7_4:    .asciiz "Escriba la segunda cadena\n"
string_7_5:    .asciiz "\nSi esta contenida\n"
string_7_6:    .asciiz "\nNo esta contenida\n"

.align 4

.text
main:
addi $sp $sp -636
#Este es el código generado por la linea 11 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 13 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
li $v0 5
syscall
move $t0 $v0
move $t1 $t0
#Este es el código generado por la linea 16 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 17 de la instrucción tam1 := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 18 de la instrucción tam2 := 0
li $t4 0
move $t5 $t4
#Este es el código generado por la linea 19 de la instrucción while que inicia en begin_while_19_1 y termina en next_while_19_1
begin_while_19_1:
slt $t6 $t3 $a3
bnez $t6 true_while_19_1
j next_while_19_1
true_while_19_1:
li $v0 5
syscall
move $t7 $v0
li $s0 1
mul $s1 $t3 $s0
addi $s1 $s1 0
add $s1 $s1 $sp
sw $t7 4($s1)
#Este es el código generado por la linea 21 de la instrucción tam1 := tam1 + 1
li $s2 1
add $s3 $t3 $s2
move $t3 $s3
j begin_while_19_1
next_while_19_1:
li $v0 5
syscall
move $s4 $v0
move $s5 $s4
#Este es el código generado por la linea 26 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
move $s7 $s6
#Este es el código generado por la linea 29 de la instrucción while que inicia en begin_while_29_1 y termina en next_while_29_1
begin_while_29_1:
slt $t8 $t5 $t1
bnez $t8 true_while_29_1
j next_while_29_1
true_while_29_1:
li $v0 5
syscall
move $t9 $v0
li $a2 1
mul $t0 $t5 $a2
addi $t0 $t0 300
add $t0 $t0 $sp
sw $t9 4($t0)
#Este es el código generado por la linea 31 de la instrucción tam2 := tam2 + 1
li $t2 1
add $t4 $t5 $t2
move $t5 $t4
j begin_while_29_1
next_while_29_1:
li $v0 5
syscall
move $t6 $v0
move $s5 $t6
#Este es el código generado por la linea 36 de la instrucción i := 0
li $s0 0
move $s1 $s0
#Este es el código generado por la linea 37 de la instrucción j := 0
li $t7 0
move $s2 $t7
#Este es el código generado por la linea 38 de la instrucción k := 0
li $s3 0
move $s4 $s3
#Este es el código generado por la linea 39 de la instrucción res := 0
li $t8 0
move $a2 $t8
#Este es el código generado por la linea 41 de la instrucción while que inicia en begin_while_41_1 y termina en next_while_41_1
begin_while_41_1:
slt $t0 $s1 $a3
beqz $t0 next_while_41_1
li $t9 0
seq $t2 $a2 $t9
bnez $t2 true_while_41_1
j next_while_41_1
true_while_41_1:
#Este es el código generado por la linea 43 de la instrucción if que termina en next_if_43_1
li $t4 1
mul $t6 $s1 $t4
addi $t6 $t6 0
add $t6 $t6 $sp
lw $s0 4($t6)
li $t7 0
li $s3 1
mul $t8 $t7 $s3
addi $t8 $t8 300
add $t8 $t8 $sp
lw $t0 4($t8)
seq $t9 $s0 $t0
beqz $t9 next_if_43_1
#Este es el código generado por la linea 45 de la instrucción k := i
move $s4 $s1
#Este es el código generado por la linea 46 de la instrucción j := 0
li $t2 0
move $s2 $t2
#Este es el código generado por la linea 47 de la instrucción while que inicia en begin_while_47_1 y termina en next_while_47_1
begin_while_47_1:
slt $t4 $s2 $t1
bnez $t4 true_while_47_1
j next_while_47_1
true_while_47_1:
#Este es el código generado por la linea 49 de la instrucción if que termina en next_if_49_1
li $t6 1
mul $t7 $s4 $t6
addi $t7 $t7 0
add $t7 $t7 $sp
lw $s3 4($t7)
li $t8 1
mul $s0 $s2 $t8
addi $s0 $s0 300
add $s0 $s0 $sp
lw $t0 4($s0)
sne $t9 $s3 $t0
beqz $t9 next_if_49_1
#Este es el código generado por la linea 51 de la instrucción break
j next_while_47_1
next_if_49_1:
#Este es el código generado por la linea 54 de la instrucción j := j + 1
li $t2 1
add $t4 $s2 $t2
move $s2 $t4
#Este es el código generado por la linea 55 de la instrucción k := k + 1
li $t6 1
add $t7 $s4 $t6
move $s4 $t7
j begin_while_47_1
next_while_47_1:
#Este es el código generado por la linea 57 de la instrucción if que termina en next_if_57_1
seq $t8 $s2 $t1
beqz $t8 next_if_57_1
#Este es el código generado por la linea 59 de la instrucción res := 1
li $s0 1
move $a2 $s0
next_if_57_1:
next_if_43_1:
#Este es el código generado por la linea 66 de la instrucción i := i + 1
li $s3 1
add $t0 $s1 $s3
move $s1 $t0
j begin_while_41_1
next_while_41_1:
#Este es el código generado por la linea 69 de la instrucción if que termina en next_if_69_1
li $t9 1
seq $t2 $a2 $t9
beqz $t2 false_if_69_1
#Este es el código generado por la linea 70 de la instrucción write
la $a0 string_7_5
li $v0 4
syscall
j next_if_69_1
false_if_69_1:
#Este es el código generado por la linea 73 de la instrucción write
la $a0 string_7_6
li $v0 4
syscall
next_if_69_1:
li $v0 10
syscall
