.data
string_7_1:    .asciiz "Escriba el valor al que le quiere conocer su raiz\n\n"
string_7_2:    .asciiz "La raiz de "
string_7_3:    .asciiz " es: "
string_7_4:    .asciiz "\n\n"

.align 4

.text
main:
addi $sp $sp -16
#Este es el código generado por la linea 8 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 6
syscall
mov.s $f1 $f0
mov.s $f2 $f1
#Este es el código generado por la linea 11 de la instrucción x := 1.0
li.s $f3 1.0
mov.s $f4 $f3
#Este es el código generado por la linea 13 de la instrucción i := 1
li $a2 1
move $a3 $a2
#Este es el código generado por la linea 15 de la instrucción while que inicia en begin_while_15_1 y termina en next_while_15_1
begin_while_15_1:
li $t0 100
sle $t1 $a3 $t0
bnez $t1 true_while_15_1
j next_while_15_1
true_while_15_1:
#Este es el código generado por la linea 17 de la instrucción nuevox := 0.5 * x + y / x
div.s $f5 $f2 $f4
add.s $f6 $f4 $f5
li.s $f7 0.5
mul.s $f8 $f7 $f6
mov.s $f9 $f8
#Este es el código generado por la linea 19 de la instrucción x := nuevox
mov.s $f4 $f9
#Este es el código generado por la linea 20 de la instrucción i := i + 1
li $t2 1
add $t3 $a3 $t2
move $a3 $t3
j begin_while_15_1
next_while_15_1:
#Este es el código generado por la linea 23 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
mov.s $f12 $f2
li $v0 2
syscall
la $a0 string_7_3
li $v0 4
syscall
mov.s $f12 $f4
li $v0 2
syscall
la $a0 string_7_4
li $v0 4
syscall
li $v0 10
syscall
