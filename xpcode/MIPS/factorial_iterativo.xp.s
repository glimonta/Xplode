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
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 10 de la instrucción i := 1
li $t0 1
move $t1 $t0
#Este es el código generado por la linea 11 de la instrucción fact := 1
li $t2 1
move $t3 $t2
#Este es el código generado por la linea 13 de la instrucción while que inicia en begin_while_13_1 y termina en next_while_13_1
begin_while_13_1:
sle $t4 $t1 $a3
bnez $t4 true_while_13_1
j next_while_13_1
true_while_13_1:
#Este es el código generado por la linea 15 de la instrucción fact := fact * i
mul $t5 $t3 $t1
move $t3 $t5
#Este es el código generado por la linea 16 de la instrucción i := i + 1
li $t6 1
add $t7 $t1 $t6
move $t1 $t7
j begin_while_13_1
next_while_13_1:
#Este es el código generado por la linea 19 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
move $a0 $t3
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
li $v0 10
syscall
