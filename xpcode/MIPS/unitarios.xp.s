.data

.align 4

.text
main:
addi $sp $sp -80
#Este es el código generado por la linea 22 de la instrucción a[7] := 98
li $a2 7
li $a3 4
mul $t0 $a2 $a3
li $t1 98
addi $t0 $t0 0
add $t0 $t0 $sp
sw $t1 0($t0)
#Este es el código generado por la linea 24 de la instrucción write
li $t2 7
li $t3 4
mul $t4 $t2 $t3
addi $t4 $t4 0
add $t4 $t4 $sp
lw $t5 0($t4)
move $a0 $t5
li $v0 1
syscall
#Este es el código generado por la linea 25 de la llamada a la función: prueba
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
#Este es el código generado por la linea 26 de la instrucción write
li $t6 7
li $t7 4
mul $s0 $t6 $t7
addi $s0 $s0 0
add $s0 $s0 $sp
lw $s1 0($s0)
move $a0 $s1
li $v0 1
syscall
li $v0 10
syscall
#Definición de Función prueba: linea 3
prueba:
#Este es el código generado por la linea 6 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s3 8
add $s4 $s2 $s3
li $s5 7
mul $s7 $s5 $s6
addi $t9 $zero 0
add $t9 $t9 $fp
lw $t9 0($t9)
add $s7 $s7 $t9
lw $t8 0($s7)
move $a0 $t8
li $v0 1
syscall
