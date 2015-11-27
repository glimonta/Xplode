.data
string_7_1:    .asciiz "Escriba el tamanio del arreglo\n"
string_7_2:    .asciiz "Escriba los elementos del arreglo\n"
string_7_3:    .asciiz "El arreglo ordenado es:\n"
string_7_4:    .asciiz " "
string_7_5:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -408
#Este es el código generado por la linea 54 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 57 de la instrucción i := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 59 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 60 de la instrucción while que inicia en begin_while_60_1 y termina en next_while_60_1
begin_while_60_1:
slt $t2 $t1 $a3
bnez $t2 true_while_60_1
j next_while_60_1
true_while_60_1:
li $v0 5
syscall
move $t3 $v0
li $t4 4
mul $t5 $t1 $t4
addi $t5 $t5 8
add $t5 $t5 $sp
sw $t3 4($t5)
#Este es el código generado por la linea 62 de la instrucción i := i + 1
li $t6 1
add $t7 $t1 $t6
move $t1 $t7
j begin_while_60_1
next_while_60_1:
#Este es el código generado por la linea 65 de la llamada a la función: sort
addi $s0 $zero 4
add $s0 $s0 $sp
sw $t1 4($s0)
addi $s0 $zero 0
add $s0 $s0 $sp
sw $a3 4($s0)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $s0 $zero 212
add $s0 $s0 $sp
sw $s0 0($sp)
addi $sp $sp -4
li $s0 50
addi $sp $sp -4
sw $s0 4($sp)
li $s1 1
addi $sp $sp -4
sw $s1 4($sp)
li $s2 4
addi $sp $sp -4
sw $s2 4($sp)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $s3 $zero 12
add $s3 $s3 $sp
sw $s3 0($sp)
addi $sp $sp -4
li $s3 50
addi $sp $sp -4
sw $s3 4($sp)
li $s4 1
addi $sp $sp -4
sw $s4 4($sp)
li $s5 4
addi $sp $sp -4
sw $s5 4($sp)
li $s6 1
sub $s7 $a3 $s6
addi $sp $sp -4
sw $s7 4($sp)
li $t8 0
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
la $t9 sort
jal $t9
lw $t9 0($sp)
addi $sp $sp 40
#Este es el código generado por la linea 67 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 69 de la instrucción i := 0
li $a2 0
move $t0 $a2
#Este es el código generado por la linea 71 de la instrucción while que inicia en begin_while_71_1 y termina en next_while_71_1
begin_while_71_1:
li $t2 0
add $t2 $t2 $sp
lw $t2 4($t2)
slt $t4 $t0 $t2
bnez $t4 true_while_71_1
j next_while_71_1
true_while_71_1:
#Este es el código generado por la linea 72 de la instrucción write
li $t5 4
mul $t3 $t0 $t5
addi $t3 $t3 8
add $t3 $t3 $sp
lw $t6 4($t3)
move $a0 $t6
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
#Este es el código generado por la linea 73 de la instrucción i := i + 1
li $t7 1
add $s0 $t0 $t7
move $t0 $s0
j begin_while_71_1
next_while_71_1:
#Este es el código generado por la linea 75 de la instrucción write
la $a0 string_7_5
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función sort: linea 3
sort:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -16
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $s1 -8
add $s1 $s1 $fp
lw $s1 4($s1)
li $s2 -4
add $s2 $s2 $fp
lw $s2 4($s2)
sge $s3 $s1 $s2
beqz $s3 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción return
addi $s4 $zero -8
add $s4 $s4 $fp
sw $s1 4($s4)
addi $s4 $zero -4
add $s4 $s4 $fp
sw $s2 4($s4)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 9 de la instrucción mid := x1 + x2 / 2
li $s4 -8
add $s4 $s4 $fp
lw $s4 4($s4)
li $s5 -4
add $s5 $s5 $fp
lw $s5 4($s5)
add $s6 $s4 $s5
li $s7 2
div $s6 $s7
mflo $t8
move $t1 $t8
#Este es el código generado por la linea 11 de la llamada a la función: sort
addi $a3 $zero 0
add $a3 $a3 $sp
sw $t1 4($a3)
addi $a3 $zero -8
add $a3 $a3 $fp
sw $s4 4($a3)
addi $a3 $zero -4
add $a3 $a3 $fp
sw $s5 4($a3)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $a3 $zero -4
add $a3 $a3 $fp
lw $a3 4($a3)
sw $a3 0($sp)
addi $sp $sp -4
li $a3 -1
addi $sp $sp -4
sw $a3 4($sp)
li $a2 1
addi $sp $sp -4
sw $a2 4($sp)
li $t4 4
addi $sp $sp -4
sw $t4 4($sp)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $t5 $zero 0
add $t5 $t5 $fp
lw $t5 4($t5)
sw $t5 0($sp)
addi $sp $sp -4
li $t5 -1
addi $sp $sp -4
sw $t5 4($sp)
li $t3 1
addi $sp $sp -4
sw $t3 4($sp)
li $t6 4
addi $sp $sp -4
sw $t6 4($sp)
addi $sp $sp -4
sw $t1 4($sp)
addi $sp $sp -4
sw $s4 4($sp)
addi $sp $sp -4
la $t7 sort
jal $t7
lw $t7 0($sp)
addi $sp $sp 40
#Este es el código generado por la linea 12 de la llamada a la función: sort
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $s0 $zero -4
add $s0 $s0 $fp
lw $s0 4($s0)
sw $s0 0($sp)
addi $sp $sp -4
li $s0 -1
addi $sp $sp -4
sw $s0 4($sp)
li $t0 1
addi $sp $sp -4
sw $t0 4($sp)
li $t9 4
addi $sp $sp -4
sw $t9 4($sp)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $t2 $zero 0
add $t2 $t2 $fp
lw $t2 4($t2)
sw $t2 0($sp)
addi $sp $sp -4
li $t2 -1
addi $sp $sp -4
sw $t2 4($sp)
li $s3 1
addi $sp $sp -4
sw $s3 4($sp)
li $s1 4
addi $sp $sp -4
sw $s1 4($sp)
li $s2 -4
add $s2 $s2 $fp
lw $s2 4($s2)
addi $sp $sp -4
sw $s2 4($sp)
li $s6 0
add $s6 $s6 $sp
lw $s6 4($s6)
li $s7 1
add $t8 $s6 $s7
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
la $a3 sort
jal $a3
lw $a3 0($sp)
addi $sp $sp 40
#Este es el código generado por la linea 14 de la instrucción i := x1
li $a2 -8
add $a2 $a2 $fp
lw $a2 4($a2)
move $t4 $a2
#Este es el código generado por la linea 15 de la instrucción j := mid + 1
li $t5 0
add $t5 $t5 $sp
lw $t5 4($t5)
li $t3 1
add $t6 $t5 $t3
move $t1 $t6
#Este es el código generado por la linea 16 de la instrucción ind := x1
move $s4 $a2
#Este es el código generado por la linea 18 de la instrucción while que inicia en begin_while_18_1 y termina en next_while_18_1
begin_while_18_1:
slt $s5 $t4 $t5
beqz $s5 next_while_18_1
li $s0 -4
add $s0 $s0 $fp
lw $s0 4($s0)
slt $t0 $t1 $s0
bnez $t0 true_while_18_1
j next_while_18_1
true_while_18_1:
#Este es el código generado por la linea 19 de la instrucción if que termina en next_if_19_1
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t2 20
add $s3 $t9 $t2
lw $s1 0($s3)
mul $s7 $t4 $s1
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s7 $s7 $s6
lw $t8 0($s7)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 20
add $t7 $t9 $s6
lw $s2 0($t7)
mul $t3 $t1 $s2
addi $s5 $zero 0
add $s5 $s5 $fp
lw $s5 4($s5)
add $t3 $t3 $s5
lw $t6 0($t3)
slt $s5 $t8 $t6
beqz $s5 false_if_19_1
#Este es el código generado por la linea 20 de la instrucción res[ind] := x[i]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t0 20
add $t2 $t9 $t0
lw $s3 0($t2)
mul $s1 $t4 $s3
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s1 $s1 $s6
lw $s7 0($s1)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 36
add $t7 $t9 $s6
lw $s2 0($t7)
mul $t3 $s4 $s2
addi $t8 $zero -4
add $t8 $t8 $fp
lw $t8 4($t8)
add $t3 $t3 $t8
sw $s7 0($t3)
#Este es el código generado por la linea 21 de la instrucción i := i + 1
li $t8 1
add $t6 $t4 $t8
move $t4 $t6
j next_if_19_1
false_if_19_1:
#Este es el código generado por la linea 24 de la instrucción res[ind] := x[j]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s5 20
add $t0 $t9 $s5
lw $t2 0($t0)
mul $s3 $t1 $t2
addi $s6 $zero 0
add $s6 $s6 $fp
lw $s6 4($s6)
add $s3 $s3 $s6
lw $s1 0($s3)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 36
add $t7 $t9 $s6
lw $s2 0($t7)
mul $t3 $s4 $s2
addi $s7 $zero -4
add $s7 $s7 $fp
lw $s7 4($s7)
add $t3 $t3 $s7
sw $s1 0($t3)
#Este es el código generado por la linea 25 de la instrucción j := j + 1
li $s7 1
add $t8 $t1 $s7
move $t1 $t8
next_if_19_1:
#Este es el código generado por la linea 27 de la instrucción ind := ind + 1
li $t6 1
add $s5 $s4 $t6
move $s4 $s5
j begin_while_18_1
next_while_18_1:
#Este es el código generado por la linea 30 de la instrucción while que inicia en begin_while_30_1 y termina en next_while_30_1
begin_while_30_1:
slt $t0 $t4 $t5
bnez $t0 true_while_30_1
j next_while_30_1
true_while_30_1:
#Este es el código generado por la linea 31 de la instrucción res[ind] := x[i]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t2 20
add $s3 $t9 $t2
lw $s6 0($s3)
mul $t7 $t4 $s6
addi $t3 $zero 0
add $t3 $t3 $fp
lw $t3 4($t3)
add $t7 $t7 $t3
lw $s2 0($t7)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t3 36
add $s1 $t9 $t3
lw $s7 0($s1)
mul $t8 $s4 $s7
addi $t6 $zero -4
add $t6 $t6 $fp
lw $t6 4($t6)
add $t8 $t8 $t6
sw $s2 0($t8)
#Este es el código generado por la linea 32 de la instrucción i := i + 1
li $t6 1
add $s5 $t4 $t6
move $t4 $s5
#Este es el código generado por la linea 33 de la instrucción ind := ind + 1
li $t0 1
add $t2 $s4 $t0
move $s4 $t2
j begin_while_30_1
next_while_30_1:
#Este es el código generado por la linea 35 de la instrucción while que inicia en begin_while_35_1 y termina en next_while_35_1
begin_while_35_1:
slt $s3 $t1 $s0
bnez $s3 true_while_35_1
j next_while_35_1
true_while_35_1:
#Este es el código generado por la linea 36 de la instrucción res[ind] := x[j]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 20
add $t7 $t9 $s6
lw $t3 0($t7)
mul $s1 $t1 $t3
addi $t8 $zero 0
add $t8 $t8 $fp
lw $t8 4($t8)
add $s1 $s1 $t8
lw $s7 0($s1)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t8 36
add $s2 $t9 $t8
lw $t6 0($s2)
mul $s5 $s4 $t6
addi $t0 $zero -4
add $t0 $t0 $fp
lw $t0 4($t0)
add $s5 $s5 $t0
sw $s7 0($s5)
#Este es el código generado por la linea 37 de la instrucción j := j + 1
li $t0 1
add $t2 $t1 $t0
move $t1 $t2
#Este es el código generado por la linea 38 de la instrucción ind := ind + 1
li $s3 1
add $s6 $s4 $s3
move $s4 $s6
j begin_while_35_1
next_while_35_1:
#Este es el código generado por la linea 41 de la instrucción i := x1
move $t4 $a2
#Este es el código generado por la linea 42 de la instrucción while que inicia en begin_while_42_1 y termina en next_while_42_1
begin_while_42_1:
sle $t7 $t4 $s0
bnez $t7 true_while_42_1
j next_while_42_1
true_while_42_1:
#Este es el código generado por la linea 43 de la instrucción x[i] := res[i]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t3 36
add $s1 $t9 $t3
lw $t8 0($s1)
mul $s2 $t4 $t8
addi $s5 $zero -4
add $s5 $s5 $fp
lw $s5 4($s5)
add $s2 $s2 $s5
lw $t6 0($s2)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s5 20
add $s7 $t9 $s5
lw $t0 0($s7)
mul $t2 $t4 $t0
addi $s3 $zero 0
add $s3 $s3 $fp
lw $s3 4($s3)
add $t2 $t2 $s3
sw $t6 0($t2)
#Este es el código generado por la linea 44 de la instrucción i := i + 1
li $s3 1
add $s6 $t4 $s3
move $t4 $s6
j begin_while_42_1
next_while_42_1:
addi $t7 $zero 4
add $t7 $t7 $sp
sw $t4 4($t7)
addi $t7 $zero 12
add $t7 $t7 $sp
sw $s4 4($t7)
addi $t7 $zero 8
add $t7 $t7 $sp
sw $t1 4($t7)
addi $t7 $zero 0
add $t7 $t7 $sp
sw $t5 4($t7)
addi $t7 $zero -8
add $t7 $t7 $fp
sw $a2 4($t7)
addi $t7 $zero -4
add $t7 $t7 $fp
sw $s0 4($t7)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
