.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -8
#Este es el código generado por la linea 10 de la instrucción f := 6
li $a2 6
move $a3 $a2
#Este es el código generado por la linea 11 de la instrucción g := 9
li $t0 9
move $t1 $t0
#Este es el código generado por la linea 12 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $t2 string_7_1
move $a0 $t2
li $v0 4
syscall
#Este es el código generado por la linea 13 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $t3 string_7_2
move $a0 $t3
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función suma: linea 3
suma:
#Este es el código generado por la linea 3 de la instrucción return
#Este es el código generado por la linea 3 de la llamada a la función: suma
