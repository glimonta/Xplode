.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"


.text
main:
addi $sp $sp -8
#Este es el código generado por la linea 10 de la instrucción f := 6
li $a2 6
li $a3 0
add $a3 $a3 $sp
sw $a2 0($a3)
#Este es el código generado por la linea 11 de la instrucción g := 9
li $t0 9
li $t1 4
add $t1 $t1 $sp
sw $t0 0($t1)
#Este es el código generado por la linea 12 de la instrucción write
lw $a0 0($a3)
li $v0 1
syscall
la $t2 string_7_1
move $a0 $t2
li $v0 4
syscall
#Este es el código generado por la linea 13 de la instrucción write
lw $a0 0($t1)
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
