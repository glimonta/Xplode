.data
string_7_1:    .asciiz "Hello world!\n"
string_7_2:    .asciiz "Hoooooola Mundo!\n"
string_7_3:    .asciiz "\n"

foo:    .word    0

.text
main:
addi $sp $sp 0
#Este es el código generado por la linea 6 de la instrucción write
la $a2 string_7_1
move $a0 $a2
li $v0 4
syscall
li $v0 5
syscall
move $a3 $v0
la $t0 foo
sw $a3 0($t0)
#Este es el código generado por la linea 8 de la instrucción write
la $t1 string_7_2
move $a0 $t1
li $v0 4
syscall
#Este es el código generado por la linea 9 de la instrucción write
lw $a0 0($t0)
li $v0 1
syscall
la $t2 string_7_3
move $a0 $t2
li $v0 4
syscall
li $v0 10
syscall
