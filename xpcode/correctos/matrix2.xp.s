.data
string_7_1:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -4012
#Este es el código generado por la linea 31 de la llamada a la función: readMat
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
#Este es el código generado por la linea 32 de la llamada a la función: printMat
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
#Este es el código generado por la linea 5 de la instrucción for que inicia en begin_for_5_1 y termina en end_for_5_1
#Este es el código generado por la linea 5 de la instrucción i := 0
li $s4 0
move $s5 $s4
j first_for_5_1
begin_for_5_1:
#Este es el código generado por la linea 5 de la instrucción i := i + 1
li $s6 1
add $s7 $s5 $s6
move $s5 $s7
first_for_5_1:
li $t8 -4
add $t8 $t8 $fp
lw $t8 4($t8)
slt $t9 $s5 $t8
bnez $t9 mid1
j end_for_5_1
mid1:
#Este es el código generado por la linea 6 de la instrucción for que inicia en begin_for_6_1 y termina en end_for_6_1
#Este es el código generado por la linea 6 de la instrucción j := 0
li $a2 0
move $a3 $a2
j first_for_6_1
begin_for_6_1:
#Este es el código generado por la linea 6 de la instrucción j := j + 1
li $t0 1
add $t1 $a3 $t0
move $a3 $t1
first_for_6_1:
slt $t2 $a3 $t8
bnez $t2 mid2
j end_for_6_1
mid2:
#Este es el código generado por la linea 7 de la instrucción for que inicia en begin_for_7_1 y termina en end_for_7_1
#Este es el código generado por la linea 7 de la instrucción k := 0
li $t3 0
move $t5 $t3
j first_for_7_1
begin_for_7_1:
#Este es el código generado por la linea 7 de la instrucción k := k + 1
li $t6 1
add $t7 $t5 $t6
move $t5 $t7
first_for_7_1:
slt $s0 $t5 $t8
bnez $s0 mid3
j end_for_7_1
mid3:
#Este es el código generado por la linea 8 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s2 24
add $t4 $s1 $s2
lw $s3 0($t4)
li $s4 0
mul $s6 $s4 $s3
li $s7 0
add $t9 $s6 $s7
li $a2 28
add $t0 $s1 $a2
lw $t1 0($t0)
mul $t2 $t9 $t1
li $t3 0
add $t6 $t2 $t3
li $t7 12
add $s0 $s1 $t7
lw $s2 0($s0)
mul $t4 $t6 $s2
addi $s4 $zero 0
add $s4 $s4 $fp
lw $s4 4($s4)
add $t4 $t4 $s4
lw $s3 0($t4)
move $a0 $s3
li $v0 1
syscall
li $v0 5
syscall
move $s4 $v0
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 24
add $s7 $s1 $s6
lw $a2 0($s7)
mul $t0 $s5 $a2
add $t9 $t0 $a3
li $t1 28
add $t2 $s1 $t1
lw $t3 0($t2)
mul $t7 $t9 $t3
add $s0 $t7 $t5
li $t6 12
add $s2 $s1 $t6
lw $t4 0($s2)
mul $s3 $s0 $t4
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s3 $s3 $s6
sw $s4 0($s3)
j begin_for_7_1
end_for_7_1:
j begin_for_6_1
end_for_6_1:
j begin_for_5_1
end_for_5_1:
addi $s6 $zero 0
add $s6 $s6 $sp
sw $s5 4($s6)
addi $s6 $zero 4
add $s6 $s6 $sp
sw $a3 4($s6)
addi $s6 $zero 8
add $s6 $s6 $sp
sw $t5 4($s6)
addi $s6 $zero -4
add $s6 $s6 $fp
sw $t8 4($s6)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función printMat: linea 15
printMat:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -12
#Este es el código generado por la linea 17 de la instrucción for que inicia en begin_for_17_1 y termina en end_for_17_1
#Este es el código generado por la linea 17 de la instrucción i := 0
li $s6 0
move $s7 $s6
j first_for_17_1
begin_for_17_1:
#Este es el código generado por la linea 17 de la instrucción i := i + 1
li $a2 1
add $t0 $s7 $a2
move $s7 $t0
first_for_17_1:
li $t1 -4
add $t1 $t1 $fp
lw $t1 4($t1)
slt $t2 $s7 $t1
bnez $t2 mid4
j end_for_17_1
mid4:
#Este es el código generado por la linea 18 de la instrucción for que inicia en begin_for_18_1 y termina en end_for_18_1
#Este es el código generado por la linea 18 de la instrucción j := 0
li $t9 0
move $t3 $t9
j first_for_18_1
begin_for_18_1:
#Este es el código generado por la linea 18 de la instrucción j := j + 1
li $t7 1
add $t6 $t3 $t7
move $t3 $t6
first_for_18_1:
slt $s2 $t3 $t1
bnez $s2 mid5
j end_for_18_1
mid5:
#Este es el código generado por la linea 19 de la instrucción for que inicia en begin_for_19_1 y termina en end_for_19_1
#Este es el código generado por la linea 19 de la instrucción k := 0
li $s0 0
move $t4 $s0
j first_for_19_1
begin_for_19_1:
#Este es el código generado por la linea 19 de la instrucción k := k + 1
li $s3 1
add $s4 $t4 $s3
move $t4 $s4
first_for_19_1:
slt $s1 $t4 $t1
bnez $s1 mid6
j end_for_19_1
mid6:
#Este es el código generado por la linea 20 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $a3 24
add $t5 $s5 $a3
lw $t8 0($t5)
mul $s6 $s7 $t8
add $a2 $s6 $t3
li $t0 28
add $t2 $s5 $t0
lw $t9 0($t2)
mul $t7 $a2 $t9
add $t6 $t7 $t4
li $s2 12
add $s0 $s5 $s2
lw $s3 0($s0)
mul $s4 $t6 $s3
addi $a3 $zero 0
add $a3 $a3 $fp
lw $a3 4($a3)
add $s4 $s4 $a3
lw $s1 0($s4)
move $a0 $s1
li $v0 1
syscall
j begin_for_19_1
end_for_19_1:
#Este es el código generado por la linea 22 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
j begin_for_18_1
end_for_18_1:
j begin_for_17_1
end_for_17_1:
addi $a3 $zero 0
add $a3 $a3 $sp
sw $s7 4($a3)
addi $a3 $zero 4
add $a3 $a3 $sp
sw $t3 4($a3)
addi $a3 $zero 8
add $a3 $a3 $sp
sw $t4 4($a3)
addi $a3 $zero -4
add $a3 $a3 $fp
sw $t1 4($a3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
