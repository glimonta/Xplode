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
lw $a3 0($a3)
li $t0 4
mul $t1 $a3 $t0
addi $t1 $t1 0
add $t1 $t1 $sp
sw $a2 0($t1)
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
lw $t5 0($t4)
li $t6 1
neg $t7 $t6
