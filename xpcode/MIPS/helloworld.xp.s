.data
string_7_1:    .asciiz "Hello world!\n"
string_7_2:    .asciiz "Hoooooola Mundo!\n"
string_7_3:    .asciiz "\n"

.align 4
foo:    .word    0

.text
main:
addi $sp $sp 0
#Este es el código generado por la linea 6 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 8 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 9 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
li $v0 10
syscall
