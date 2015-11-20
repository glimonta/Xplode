.data
string_7_1:    .asciiz "Hello world!\n"

.text
main:
#Este es el código generado por la linea 5 de la instrucción write
la $a2 string_7_1
move $a0 $a2
li $v0 4
syscall
move $a0 $a3
li $a1 4
li $v0 8
syscall
#Este es el código generado por la linea 7 de la instrucción write
li $t0 0
add $t0 $t0 $sp
lw $t0 4($8)
move $a0 $t0
li $v0 4
syscall
li $v0 10
syscall
