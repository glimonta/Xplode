.data
string_7_1:    .asciiz "\n"


.text
main:
addi $sp $sp -4
#Este es el código generado por la linea 9 de la instrucción f := 6
li $a2 6
li $a3 0
add $a3 $a3 $sp
sw $a2 0($a3)
#Este es el código generado por la linea 10 de la instrucción write
lw $a0 0($a3)
li $v0 1
syscall
la $t0 string_7_1
move $a0 $t0
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función suma: linea 3
suma:
#Este es el código generado por la linea 3 de la instrucción return
#Este es el código generado por la linea 3 de la llamada a la función: suma
