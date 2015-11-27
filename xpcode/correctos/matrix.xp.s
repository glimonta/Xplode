.data
string_7_1:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -4012
#Este es el código generado por la linea 36 de la llamada a la función: readMat
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $a2 $zero 4
add $a2 $a2 $sp
sw $a2 0($sp)
addi $sp $sp -4
li $a2 10
addi $sp $sp -4
sw $a2 4($sp)
li $a3 10
addi $sp $sp -4
sw $a3 4($sp)
li $t0 10
addi $sp $sp -4
sw $t0 4($sp)
li $t1 3
addi $sp $sp -4
sw $t1 4($sp)
li $t2 4
addi $sp $sp -4
sw $t2 4($sp)
li $t3 10
addi $sp $sp -4
sw $t3 4($sp)
addi $sp $sp -4
la $t4 readMat
jal $t4
lw $t4 0($sp)
addi $sp $sp 28
#Este es el código generado por la linea 37 de la llamada a la función: printMat
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $t5 $zero 4
add $t5 $t5 $sp
sw $t5 0($sp)
addi $sp $sp -4
li $t5 10
addi $sp $sp -4
sw $t5 4($sp)
li $t6 10
addi $sp $sp -4
sw $t6 4($sp)
li $t7 10
addi $sp $sp -4
sw $t7 4($sp)
li $s0 3
addi $sp $sp -4
sw $s0 4($sp)
li $s1 4
addi $sp $sp -4
sw $s1 4($sp)
li $s2 10
addi $sp $sp -4
sw $s2 4($sp)
addi $sp $sp -4
la $s3 printMat
jal $s3
lw $s3 0($sp)
addi $sp $sp 28
li $v0 10
syscall
#Definición de Función readMat: linea 3
readMat:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -12
#Este es el código generado por la linea 7 de la instrucción for que inicia en begin_for_7_1 y termina en end_for_7_1
#Este es el código generado por la linea 7 de la instrucción i := 0
li $s4 0
move $s5 $s4
j first_for_7_1
begin_for_7_1:
#Este es el código generado por la linea 7 de la instrucción i := i + 1
li $s6 1
add $s7 $s5 $s6
move $s5 $s7
first_for_7_1:
li $t8 -4
add $t8 $t8 $fp
lw $t8 4($t8)
slt $t9 $s5 $t8
bnez $t9 mid1
j end_for_7_1
mid1:
#Este es el código generado por la linea 8 de la instrucción for que inicia en begin_for_8_1 y termina en end_for_8_1
#Este es el código generado por la linea 8 de la instrucción j := 0
li $a2 0
move $a3 $a2
j first_for_8_1
begin_for_8_1:
#Este es el código generado por la linea 8 de la instrucción j := j + 1
li $t0 1
add $t1 $a3 $t0
move $a3 $t1
first_for_8_1:
slt $t2 $a3 $t8
bnez $t2 mid2
j end_for_8_1
mid2:
#Este es el código generado por la linea 9 de la instrucción for que inicia en begin_for_9_1 y termina en end_for_9_1
#Este es el código generado por la linea 9 de la instrucción k := 0
li $t3 0
move $t5 $t3
j first_for_9_1
begin_for_9_1:
#Este es el código generado por la linea 9 de la instrucción k := k + 1
li $t6 1
add $t7 $t5 $t6
move $t5 $t7
first_for_9_1:
slt $s0 $t5 $t8
bnez $s0 mid3
j end_for_9_1
mid3:
li $v0 5
syscall
move $s1 $v0
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t4 28
add $s3 $s2 $t4
lw $s4 0($s3)
mul $s6 $s5 $s4
add $s7 $s6 $a3
li $t9 32
add $a2 $s2 $t9
lw $t0 0($a2)
mul $t1 $s7 $t0
add $t2 $t1 $t5
li $t3 16
add $t6 $s2 $t3
lw $t7 0($t6)
mul $s0 $t2 $t7
addi $t4 $zero 0
add $t4 $t4 $fp
lw $t4 4($t4)
add $s0 $s0 $t4
sw $s1 0($s0)
j begin_for_9_1
end_for_9_1:
j begin_for_8_1
end_for_8_1:
j begin_for_7_1
end_for_7_1:
addi $t4 $zero 0
add $t4 $t4 $sp
sw $s5 4($t4)
addi $t4 $zero 4
add $t4 $t4 $sp
sw $a3 4($t4)
addi $t4 $zero 8
add $t4 $t4 $sp
sw $t5 4($t4)
addi $t4 $zero -4
add $t4 $t4 $fp
sw $t8 4($t4)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función printMat: linea 16
printMat:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -12
#Este es el código generado por la linea 20 de la instrucción for que inicia en begin_for_20_1 y termina en end_for_20_1
#Este es el código generado por la linea 20 de la instrucción i := 0
li $t4 0
move $s3 $t4
j first_for_20_1
begin_for_20_1:
#Este es el código generado por la linea 20 de la instrucción i := i + 1
li $s4 1
add $s6 $s3 $s4
move $s3 $s6
first_for_20_1:
li $t9 -4
add $t9 $t9 $fp
lw $t9 4($t9)
slt $a2 $s3 $t9
bnez $a2 mid4
j end_for_20_1
mid4:
#Este es el código generado por la linea 21 de la instrucción for que inicia en begin_for_21_1 y termina en end_for_21_1
#Este es el código generado por la linea 21 de la instrucción j := 0
li $s7 0
move $t0 $s7
j first_for_21_1
begin_for_21_1:
#Este es el código generado por la linea 21 de la instrucción j := j + 1
li $t1 1
add $t3 $t0 $t1
move $t0 $t3
first_for_21_1:
slt $t6 $t0 $t9
bnez $t6 mid5
j end_for_21_1
mid5:
#Este es el código generado por la linea 22 de la instrucción for que inicia en begin_for_22_1 y termina en end_for_22_1
#Este es el código generado por la linea 22 de la instrucción k := 0
li $t2 0
move $t7 $t2
j first_for_22_1
begin_for_22_1:
#Este es el código generado por la linea 22 de la instrucción k := k + 1
li $s0 1
add $s1 $t7 $s0
move $t7 $s1
first_for_22_1:
slt $s2 $t7 $t9
bnez $s2 mid6
j end_for_22_1
mid6:
#Este es el código generado por la linea 23 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $a3 28
add $t5 $s5 $a3
lw $t8 0($t5)
mul $t4 $s3 $t8
add $s4 $t4 $t0
li $s6 32
add $a2 $s5 $s6
lw $s7 0($a2)
mul $t1 $s4 $s7
add $t3 $t1 $t7
li $t6 16
add $t2 $s5 $t6
lw $s0 0($t2)
mul $s1 $t3 $s0
addi $a3 $zero 0
add $a3 $a3 $fp
lw $a3 4($a3)
add $s1 $s1 $a3
lw $s2 0($s1)
move $a0 $s2
li $v0 1
syscall
j begin_for_22_1
end_for_22_1:
#Este es el código generado por la linea 25 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
j begin_for_21_1
end_for_21_1:
j begin_for_20_1
end_for_20_1:
addi $a3 $zero 0
add $a3 $a3 $sp
sw $s3 4($a3)
addi $a3 $zero 4
add $a3 $a3 $sp
sw $t0 4($a3)
addi $a3 $zero 8
add $a3 $a3 $sp
sw $t7 4($a3)
addi $a3 $zero -4
add $a3 $a3 $fp
sw $t9 4($a3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
