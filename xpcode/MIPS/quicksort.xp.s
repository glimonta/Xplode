.data
string_7_1:    .asciiz "Escriba el tamanio del arreglo\n"
string_7_2:    .asciiz "Escriba los elementos del arreglo\n"
string_7_3:    .asciiz "Arreglo ordenado:\n"
string_7_4:    .asciiz " "
string_7_5:    .asciiz "Arreglo ordenado:\n"
string_7_6:    .asciiz " "
string_7_7:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -408
#Este es el código generado por la linea 47 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 50 de la instrucción i := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 52 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 53 de la instrucción while que inicia en begin_while_53_1 y termina en next_while_53_1
begin_while_53_1:
slt $t2 $t1 $a3
bnez $t2 true_while_53_1
j next_while_53_1
true_while_53_1:
li $v0 5
syscall
move $t3 $v0
li $t4 4
mul $t5 $t1 $t4
addi $t5 $t5 8
add $t5 $t5 $sp
sw $t3 4($t5)
#Este es el código generado por la linea 55 de la instrucción i := i + 1
li $t6 1
add $t7 $t1 $t6
move $t1 $t7
j begin_while_53_1
next_while_53_1:
#Este es el código generado por la linea 58 de la instrucción i := 0
li $s0 0
move $t1 $s0
#Este es el código generado por la linea 59 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
#Este es el código generado por la linea 60 de la instrucción while que inicia en begin_while_60_1 y termina en next_while_60_1
begin_while_60_1:
slt $s1 $t1 $a3
bnez $s1 true_while_60_1
j next_while_60_1
true_while_60_1:
#Este es el código generado por la linea 61 de la instrucción write
li $s2 4
mul $s3 $t1 $s2
addi $s3 $s3 8
add $s3 $s3 $sp
lw $s4 4($s3)
move $a0 $s4
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
#Este es el código generado por la linea 62 de la instrucción i := i + 1
li $s5 1
add $s6 $t1 $s5
move $t1 $s6
j begin_while_60_1
next_while_60_1:
#Este es el código generado por la linea 65 de la llamada a la función: quicksort
addi $s7 $zero 4
add $s7 $s7 $sp
sw $t1 4($s7)
addi $s7 $zero 0
add $s7 $s7 $sp
sw $a3 4($s7)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $s7 $zero 12
add $s7 $s7 $sp
sw $s7 0($sp)
addi $sp $sp -4
li $s7 50
addi $sp $sp -4
sw $s7 4($sp)
li $t8 1
addi $sp $sp -4
sw $t8 4($sp)
li $t9 4
addi $sp $sp -4
sw $t9 4($sp)
li $a2 1
sub $t0 $a3 $a2
addi $sp $sp -4
sw $t0 4($sp)
li $t2 0
addi $sp $sp -4
sw $t2 4($sp)
addi $sp $sp -4
la $t4 quicksort
jal $t4
lw $t4 0($sp)
addi $sp $sp 24
#Este es el código generado por la linea 66 de la instrucción i := 0
li $t5 0
move $t3 $t5
#Este es el código generado por la linea 67 de la instrucción write
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 68 de la instrucción while que inicia en begin_while_68_1 y termina en next_while_68_1
begin_while_68_1:
li $t6 0
add $t6 $t6 $sp
lw $t6 4($t6)
slt $t7 $t3 $t6
bnez $t7 true_while_68_1
j next_while_68_1
true_while_68_1:
#Este es el código generado por la linea 69 de la instrucción write
li $s0 4
mul $s1 $t3 $s0
addi $s1 $s1 8
add $s1 $s1 $sp
lw $s2 4($s1)
move $a0 $s2
li $v0 1
syscall
la $a0 string_7_6
li $v0 4
syscall
#Este es el código generado por la linea 70 de la instrucción i := i + 1
li $s3 1
add $s4 $t3 $s3
move $t3 $s4
j begin_while_68_1
next_while_68_1:
#Este es el código generado por la linea 72 de la instrucción write
la $a0 string_7_7
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función quicksort: linea 3
quicksort:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -16
#Este es el código generado por la linea 6 de la instrucción if que termina en next_if_6_1
li $s5 4
add $s5 $s5 $fp
lw $s5 4($s5)
li $s6 0
add $s6 $s6 $fp
lw $s6 4($s6)
sle $s7 $s5 $s6
beqz $s7 next_if_6_1
#Este es el código generado por la linea 7 de la instrucción return
addi $t8 $zero 0
add $t8 $t8 $fp
sw $s6 4($t8)
addi $t8 $zero 4
add $t8 $t8 $fp
sw $s5 4($t8)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_6_1:
#Este es el código generado por la linea 10 de la instrucción i := m - 1
li $t8 0
add $t8 $t8 $fp
lw $t8 4($t8)
li $t9 1
sub $a2 $t8 $t9
move $t0 $a2
#Este es el código generado por la linea 11 de la instrucción j := n
li $t2 4
add $t2 $t2 $fp
lw $t2 4($t2)
move $t1 $t2
#Este es el código generado por la linea 12 de la instrucción v := a[n]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t5 16
add $t7 $a3 $t5
lw $s0 0($t7)
mul $s1 $t2 $s0
addi $s3 $zero 8
add $s3 $s3 $fp
lw $s3 4($s3)
add $s1 $s1 $s3
lw $s2 0($s1)
move $s3 $s2
#Este es el código generado por la linea 14 de la instrucción while que inicia en begin_while_14_1 y termina en next_while_14_1
begin_while_14_1:
j true_while_14_1
true_while_14_1:
#Este es el código generado por la linea 16 de la instrucción i := i + 1
li $s4 1
add $t3 $t0 $s4
move $t0 $t3
#Este es el código generado por la linea 17 de la instrucción while que inicia en begin_while_17_1 y termina en next_while_17_1
begin_while_17_1:
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t4 16
add $t6 $a3 $t4
lw $s7 0($t6)
mul $s6 $t0 $s7
addi $t9 $zero 8
add $t9 $t9 $fp
lw $t9 4($t9)
add $s6 $s6 $t9
lw $s5 0($s6)
slt $t9 $s5 $s3
bnez $t9 true_while_17_1
j next_while_17_1
true_while_17_1:
#Este es el código generado por la linea 18 de la instrucción i := i + 1
li $a2 1
add $t5 $t0 $a2
move $t0 $t5
j begin_while_17_1
next_while_17_1:
#Este es el código generado por la linea 21 de la instrucción j := j - 1
li $t7 1
sub $s0 $t1 $t7
move $t1 $s0
#Este es el código generado por la linea 22 de la instrucción while que inicia en begin_while_22_1 y termina en next_while_22_1
begin_while_22_1:
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s1 16
add $s2 $a3 $s1
lw $s4 0($s2)
mul $t3 $t1 $s4
addi $t6 $zero 8
add $t6 $t6 $fp
lw $t6 4($t6)
add $t3 $t3 $t6
lw $t4 0($t3)
sgt $t6 $t4 $s3
bnez $t6 true_while_22_1
j next_while_22_1
true_while_22_1:
#Este es el código generado por la linea 23 de la instrucción j := j - 1
li $s7 1
sub $s6 $t1 $s7
move $t1 $s6
j begin_while_22_1
next_while_22_1:
#Este es el código generado por la linea 25 de la instrucción if que termina en next_if_25_1
sge $s5 $t0 $t1
beqz $s5 next_if_25_1
#Este es el código generado por la linea 26 de la instrucción break
j next_while_14_1
next_if_25_1:
#Este es el código generado por la linea 29 de la instrucción x := a[i]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t9 16
add $a2 $a3 $t9
lw $t5 0($a2)
mul $t7 $t0 $t5
addi $s1 $zero 8
add $s1 $s1 $fp
lw $s1 4($s1)
add $t7 $t7 $s1
lw $s0 0($t7)
move $s1 $s0
#Este es el código generado por la linea 30 de la instrucción a[i] := a[j]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s2 16
add $s4 $a3 $s2
lw $t3 0($s4)
mul $t4 $t1 $t3
addi $s7 $zero 8
add $s7 $s7 $fp
lw $s7 4($s7)
add $t4 $t4 $s7
lw $t6 0($t4)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s7 16
add $s6 $a3 $s7
lw $s5 0($s6)
mul $t9 $t0 $s5
addi $a2 $zero 8
add $a2 $a2 $fp
lw $a2 4($a2)
add $t9 $t9 $a2
sw $t6 0($t9)
#Este es el código generado por la linea 31 de la instrucción a[j] := x
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $a2 16
add $t5 $a3 $a2
lw $t7 0($t5)
mul $s0 $t1 $t7
addi $s2 $zero 8
add $s2 $s2 $fp
lw $s2 4($s2)
add $s0 $s0 $s2
sw $s1 0($s0)
j begin_while_14_1
next_while_14_1:
#Este es el código generado por la linea 33 de la instrucción x := a[i]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s2 16
add $s4 $a3 $s2
lw $t3 0($s4)
mul $t4 $t0 $t3
addi $s6 $zero 8
add $s6 $s6 $fp
lw $s6 4($s6)
add $t4 $t4 $s6
lw $s7 0($t4)
move $s1 $s7
#Este es el código generado por la linea 34 de la instrucción a[i] := a[n]
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s6 16
add $s5 $a3 $s6
lw $t9 0($s5)
mul $t6 $t2 $t9
addi $t5 $zero 8
add $t5 $t5 $fp
lw $t5 4($t5)
add $t6 $t6 $t5
lw $a2 0($t6)
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t5 16
add $t7 $a3 $t5
lw $s0 0($t7)
mul $s2 $t0 $s0
addi $s4 $zero 8
add $s4 $s4 $fp
lw $s4 4($s4)
add $s2 $s2 $s4
sw $a2 0($s2)
#Este es el código generado por la linea 35 de la instrucción a[n] := x
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s4 16
add $t3 $a3 $s4
lw $t4 0($t3)
mul $s7 $t2 $t4
addi $s6 $zero 8
add $s6 $s6 $fp
lw $s6 4($s6)
add $s7 $s7 $s6
sw $s1 0($s7)
#Este es el código generado por la linea 37 de la llamada a la función: quicksort
addi $s6 $zero 0
add $s6 $s6 $sp
sw $t0 4($s6)
addi $s6 $zero 4
add $s6 $s6 $sp
sw $t1 4($s6)
addi $s6 $zero 0
add $s6 $s6 $fp
sw $t8 4($s6)
addi $s6 $zero 4
add $s6 $s6 $fp
sw $t2 4($s6)
addi $s6 $zero 8
add $s6 $s6 $sp
sw $s3 4($s6)
addi $s6 $zero 12
add $s6 $s6 $sp
sw $s1 4($s6)
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $s6 $zero 8
add $s6 $s6 $fp
lw $s6 4($s6)
sw $s6 0($sp)
addi $sp $sp -4
li $s6 -1
addi $sp $sp -4
sw $s6 4($sp)
li $s5 1
addi $sp $sp -4
sw $s5 4($sp)
li $t9 4
addi $sp $sp -4
sw $t9 4($sp)
addi $sp $sp -4
sw $t1 4($sp)
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
la $t6 quicksort
jal $t6
lw $t6 0($sp)
addi $sp $sp 24
#Este es el código generado por la linea 38 de la llamada a la función: quicksort
#Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector
addi $t5 $zero 8
add $t5 $t5 $fp
lw $t5 4($t5)
sw $t5 0($sp)
addi $sp $sp -4
li $t5 -1
addi $sp $sp -4
sw $t5 4($sp)
li $t7 1
addi $sp $sp -4
sw $t7 4($sp)
li $s0 4
addi $sp $sp -4
sw $s0 4($sp)
li $s2 4
add $s2 $s2 $fp
lw $s2 4($s2)
addi $sp $sp -4
sw $s2 4($sp)
li $a2 0
add $a2 $a2 $sp
lw $a2 4($a2)
li $s4 1
add $t3 $a2 $s4
addi $sp $sp -4
sw $t3 4($sp)
addi $sp $sp -4
la $t4 quicksort
jal $t4
lw $t4 0($sp)
addi $sp $sp 24
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
