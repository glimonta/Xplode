.data

.align 4

.text
main:
addi $sp $sp -12
#Este es el código generado por la linea 8 de la instrucción i := 1
li $a2 1
move $a3 $a2
#Este es el código generado por la linea 9 de la instrucción j := 2
li $t0 2
move $t1 $t0
#Este es el código generado por la linea 11 de la instrucción k := j < j && j > 6
slt $t2 $t1 $t1
li $t3 6
sgt $t4 $t1 $t3
and $t5 $t2 $t4
move $t6 $t5
#Este es el código generado por la linea 12 de la instrucción k := i < j && true
slt $t7 $a3 $t1
and $s1 $t7 $s0
move $t6 $s1
#Este es el código generado por la linea 14 de la instrucción if que termina en next_if_14_1
slt $s2 $a3 $t1
bnez $s2 true1
j false_if_14_1
true1:
#Este es el código generado por la linea 15 de la instrucción if que termina en next_if_15_1
j next_if_15_1
#Este es el código generado por la linea 16 de la instrucción j := 4
li $s3 4
move $t1 $s3
next_if_15_1:
#Este es el código generado por la linea 18 de la instrucción i := 2
li $s4 2
move $a3 $s4
j next_if_14_1
false_if_14_1:
#Este es el código generado por la linea 20 de la instrucción i := 4
li $s5 4
move $a3 $s5
next_if_14_1:
li $v0 10
syscall
