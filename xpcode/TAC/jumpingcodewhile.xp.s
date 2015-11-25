.data

.align 4

.text
main:
addi $sp $sp -12
#Este es el código generado por la linea 8 de la instrucción i := 0
li $a2 0
move $a3 $a2
#Este es el código generado por la linea 10 de la instrucción while que inicia en begin_while_10_1 y termina en next_while_10_1
begin_while_10_1:
li $t0 13
slt $t1 $a3 $t0
bnez $t1 true_while_10_1
j next_while_10_1
true_while_10_1:
#Este es el código generado por la linea 11 de la instrucción if que termina en next_if_11_1
j next_if_11_1
#Este es el código generado por la linea 12 de la instrucción i := 42
li $t2 42
move $a3 $t2
next_if_11_1:
#Este es el código generado por la linea 14 de la instrucción i := i + 1
li $t3 1
add $t4 $a3 $t3
move $a3 $t4
j begin_while_10_1
next_while_10_1:
#Este es el código generado por la linea 17 de la instrucción i := 13
li $t5 13
move $a3 $t5
#Este es el código generado por la linea 19 de la instrucción while que inicia en begin_while_19_1 y termina en next_while_19_1
begin_while_19_1:
li $t6 13
slt $t7 $a3 $t6
bnez $t7 true_while_19_1
j next_while_19_1
true_while_19_1:
#Este es el código generado por la linea 20 de la instrucción if que termina en next_if_20_1
j next_if_20_1
#Este es el código generado por la linea 21 de la instrucción i := 42
li $s0 42
move $a3 $s0
next_if_20_1:
#Este es el código generado por la linea 23 de la instrucción i := i + 1
li $s1 1
add $s2 $a3 $s1
move $a3 $s2
j begin_while_19_1
next_while_19_1:
li $v0 10
syscall
