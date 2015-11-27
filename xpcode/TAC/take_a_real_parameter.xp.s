.data
string_7_1:    .asciiz "doing something!"

.align 4

.text
main:
addi $sp $sp -144
#Este es el código generado por la linea 31 de la instrucción yo.tni := 0
li $a2 0
li $a3 0
addi $a2 $a2 0
add $a2 $a2 $sp
sw $a3 4($a2)
#Este es el código generado por la linea 32 de la instrucción yo.elcaro.ahok[yo.tni][1][1][1][1] := 7
li $t0 8
li $t1 0
add $t2 $t0 $t1
li $t3 0
addi $t3 $t3 0
add $t3 $t3 $sp
lw $t4 4($t3)
li $t5 2
mul $t6 $t4 $t5
li $t7 1
add $s0 $t6 $t7
li $s1 2
mul $s2 $s0 $s1
li $s3 1
add $s4 $s2 $s3
li $s5 2
mul $s6 $s4 $s5
li $s7 1
add $t8 $s6 $s7
li $t9 2
mul $a2 $t8 $t9
li $a3 1
add $t0 $a2 $a3
li $t1 4
mul $t3 $t0 $t1
add $t4 $t3 $t2
li $t5 7
addi $t4 $t4 0
add $t4 $t4 $sp
sw $t5 4($t4)
#Este es el código generado por la linea 35 de la llamada a la función: wtf_this_parameters
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
li $t6 8
li $t7 0
add $s0 $t6 $t7
li $s1 0
addi $s1 $s1 0
add $s1 $s1 $sp
lw $s2 4($s1)
li $s3 2
mul $s4 $s2 $s3
li $s5 1
add $s6 $s4 $s5
li $s7 32
mul $t8 $s6 $s7
add $t9 $t8 $s0
addi $a2 $zero 4
add $a2 $a2 $sp
sw $a2 0($sp)
addi $sp $sp -4
li $a2 2
addi $sp $sp -4
sw $a2 4($sp)
li $a3 2
addi $sp $sp -4
sw $a3 4($sp)
li $t0 2
addi $sp $sp -4
sw $t0 4($sp)
li $t1 3
addi $sp $sp -4
sw $t1 4($sp)
li $t3 4
addi $sp $sp -4
sw $t3 4($sp)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
li $t2 8
li $t4 0
add $t5 $t2 $t4
li $t6 0
addi $t6 $t6 0
add $t6 $t6 $sp
lw $t7 4($t6)
li $s1 2
mul $s2 $t7 $s1
li $s3 1
add $s4 $s2 $s3
li $s5 32
mul $s6 $s4 $s5
add $s7 $s6 $t5
addi $t8 $zero 4
add $t8 $t8 $sp
sw $t8 0($sp)
addi $sp $sp -4
li $t8 2
addi $sp $sp -4
sw $t8 4($sp)
li $s0 2
addi $sp $sp -4
sw $s0 4($sp)
li $a2 2
addi $sp $sp -4
sw $a2 4($sp)
li $a3 3
addi $sp $sp -4
sw $a3 4($sp)
li $t0 4
addi $sp $sp -4
sw $t0 4($sp)
li $t1 8
li $t3 128
add $t2 $t1 $t3
addi $t2 $t2 0
add $t2 $t2 $sp
lw $t4 4($t2)
addi $sp $sp -4
sw $t4 4($sp)
addi $sp $sp -4
la $t6 wtf_this_parameters
jal $t6
lw $t6 0($sp)
addi $sp $sp 52
li $v0 10
syscall
#Definición de Función wtf_this_parameters: linea 3
wtf_this_parameters:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 4 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s1 24
add $s2 $t7 $s1
lw $s3 0($s2)
li $s4 1
mul $s5 $s4 $s3
li $s6 1
add $t5 $s5 $s6
li $t8 28
add $s0 $t7 $t8
lw $a2 0($s0)
mul $a3 $t5 $a2
li $t0 1
add $t1 $a3 $t0
li $t3 12
add $t2 $t7 $t3
lw $t4 0($t2)
mul $t9 $t1 $t4
addi $t6 $zero 0
add $t6 $t6 $fp
lw $t6 4($t6)
add $t9 $t9 $t6
lw $s7 0($t9)
move $a0 $s7
li $v0 1
syscall
#Este es el código generado por la linea 5 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t6 48
add $s1 $t7 $t6
lw $s2 0($s1)
li $s3 1
mul $s4 $s3 $s2
li $s5 1
add $s6 $s4 $s5
li $t8 52
add $s0 $t7 $t8
lw $t5 0($s0)
mul $a2 $s6 $t5
li $a3 1
add $t0 $a2 $a3
li $t3 36
add $t2 $t7 $t3
lw $t1 0($t2)
mul $t4 $t0 $t1
addi $s7 $zero 4
add $s7 $s7 $fp
lw $s7 4($s7)
add $t4 $t4 $s7
lw $t9 0($t4)
move $a0 $t9
li $v0 1
syscall
#Este es el código generado por la linea 6 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
