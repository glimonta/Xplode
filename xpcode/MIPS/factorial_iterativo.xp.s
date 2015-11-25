.data
string_7_1:    .asciiz "Escriba el numero al cual quiere saber el factorial:\n"
string_7_2:    .asciiz "fact["
string_7_3:    .asciiz "]="
string_7_4:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -12
#Este es el código generado por la linea 8 de la instrucción write
la $a2 string_7_1
move $a0 $a2
li $v0 4
syscall
li $v0 5
syscall
move $a3 $v0
move $t0 $a3
#Este es el código generado por la linea 10 de la instrucción i := 1
li $t1 1
move $t2 $t1
#Este es el código generado por la linea 11 de la instrucción fact := 1
li $t3 1
move $t4 $t3
#Este es el código generado por la linea 13 de la instrucción while que inicia en begin_while_13_1 y termina en next_while_13_1
begin_while_13_1:
sle $t5 $t2 $t0
bnez $t5 true_while_13_1
j next_while_13_1
true_while_13_1:
#Este es el código generado por la linea 15 de la instrucción fact := fact * i
mul $t6 $t4 $t2
move $t4 $t6
#Este es el código generado por la linea 16 de la instrucción i := i + 1
li $t7 1
add $s0 $t2 $t7
move $t2 $s0
j begin_while_13_1
next_while_13_1:
#Este es el código generado por la linea 19 de la instrucción write
la $s1 string_7_2
move $a0 $s1
li $v0 4
syscall
move $a0 $t0
li $v0 1
syscall
la $s2 string_7_3
move $a0 $s2
li $v0 4
syscall
move $a0 $t4
li $v0 1
syscall
la $s3 string_7_4
move $a0 $s3
li $v0 4
syscall
li $v0 10
syscall
