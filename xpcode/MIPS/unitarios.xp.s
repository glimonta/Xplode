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
sw $t1 4($t0)
#Este es el código generado por la linea 24 de la instrucción write
li $t2 7
li $t3 4
mul $t4 $t2 $t3
addi $t4 $t4 0
add $t4 $t4 $sp
lw $t5 4($t4)
move $a0 $t5
li $v0 1
syscall
#Este es el código generado por la linea 25 de la llamada a la función: prueba
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $t6 $zero 4
add $t6 $t6 $sp
sw $t6 0($sp)
addi $sp $sp -4
li $t6 20
addi $sp $sp -4
sw $t6 4($sp)
li $t7 1
addi $sp $sp -4
sw $t7 4($sp)
li $s0 4
addi $sp $sp -4
sw $s0 4($sp)
addi $sp $sp -4
la $s1 prueba
jal $s1
lw $s1 0($sp)
addi $sp $sp 16
#Este es el código generado por la linea 26 de la instrucción write
li $s2 7
li $s3 4
mul $s4 $s2 $s3
addi $s4 $s4 0
add $s4 $s4 $sp
lw $s5 4($s4)
move $a0 $s5
li $v0 1
syscall
li $v0 10
syscall
#Definición de Función prueba: linea 3
prueba:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 6 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s7 8
add $t8 $s6 $s7
lw $t9 0($t8)
li $a2 7
mul $a3 $a2 $t9
addi $t1 $zero 0
add $t1 $t1 $fp
lw $t1 4($t1)
add $a3 $a3 $t1
lw $t0 0($a3)
move $a0 $t0
li $v0 1
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
