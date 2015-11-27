.data
string_7_1:    .asciiz " "
string_7_2:    .asciiz "\n"
string_7_3:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -124
#Este es el código generado por la linea 37 de la instrucción s := 3
li $a2 3
move $a3 $a2
#Este es el código generado por la linea 39 de la instrucción for que inicia en begin_for_39_1 y termina en end_for_39_1
#Este es el código generado por la linea 39 de la instrucción i := 0
li $t0 0
move $t1 $t0
j first_for_39_1
begin_for_39_1:
#Este es el código generado por la linea 39 de la instrucción i := i + 1
li $t2 1
add $t3 $t1 $t2
move $t1 $t3
first_for_39_1:
slt $t4 $t1 $a3
bnez $t4 mid1
j end_for_39_1
mid1:
#Este es el código generado por la linea 40 de la instrucción for que inicia en begin_for_40_1 y termina en end_for_40_1
#Este es el código generado por la linea 40 de la instrucción j := 0
li $t5 0
move $t6 $t5
j first_for_40_1
begin_for_40_1:
#Este es el código generado por la linea 40 de la instrucción j := j + 1
li $t7 1
add $s0 $t6 $t7
move $t6 $s0
first_for_40_1:
slt $s1 $t6 $a3
bnez $s1 mid2
j end_for_40_1
mid2:
#Este es el código generado por la linea 41 de la instrucción for que inicia en begin_for_41_1 y termina en end_for_41_1
#Este es el código generado por la linea 41 de la instrucción k := 0
li $s2 0
move $s3 $s2
j first_for_41_1
begin_for_41_1:
#Este es el código generado por la linea 41 de la instrucción k := k + 1
li $s4 1
add $s5 $s3 $s4
move $s3 $s5
first_for_41_1:
slt $s6 $s3 $a3
bnez $s6 mid3
j end_for_41_1
mid3:
li $v0 5
syscall
move $s7 $v0
li $t8 3
mul $t9 $t1 $t8
add $a2 $t9 $t6
li $t0 3
mul $t2 $a2 $t0
add $t3 $t2 $s3
li $t4 4
mul $t5 $t3 $t4
addi $t5 $t5 0
add $t5 $t5 $sp
sw $s7 4($t5)
j begin_for_41_1
end_for_41_1:
j begin_for_40_1
end_for_40_1:
j begin_for_39_1
end_for_39_1:
#Este es el código generado por la linea 48 de la instrucción for que inicia en begin_for_48_1 y termina en end_for_48_1
#Este es el código generado por la linea 48 de la instrucción i := 0
li $t7 0
move $t1 $t7
j first_for_48_1
begin_for_48_1:
#Este es el código generado por la linea 48 de la instrucción i := i + 1
li $s0 1
add $s1 $t1 $s0
move $t1 $s1
first_for_48_1:
slt $s2 $t1 $a3
bnez $s2 mid4
j end_for_48_1
mid4:
#Este es el código generado por la linea 49 de la instrucción for que inicia en begin_for_49_1 y termina en end_for_49_1
#Este es el código generado por la linea 49 de la instrucción j := 0
li $s4 0
move $t6 $s4
j first_for_49_1
begin_for_49_1:
#Este es el código generado por la linea 49 de la instrucción j := j + 1
li $s5 1
add $s6 $t6 $s5
move $t6 $s6
first_for_49_1:
slt $t8 $t6 $a3
bnez $t8 mid5
j end_for_49_1
mid5:
#Este es el código generado por la linea 50 de la instrucción for que inicia en begin_for_50_1 y termina en end_for_50_1
#Este es el código generado por la linea 50 de la instrucción k := 0
li $t9 0
move $s3 $t9
j first_for_50_1
begin_for_50_1:
#Este es el código generado por la linea 50 de la instrucción k := k + 1
li $a2 1
add $t0 $s3 $a2
move $s3 $t0
first_for_50_1:
slt $t2 $s3 $a3
bnez $t2 mid6
j end_for_50_1
mid6:
#Este es el código generado por la linea 51 de la instrucción write
li $t3 3
mul $t4 $t1 $t3
add $t5 $t4 $t6
li $s7 3
mul $t7 $t5 $s7
add $s0 $t7 $s3
li $s1 4
mul $s2 $s0 $s1
addi $s2 $s2 0
add $s2 $s2 $sp
lw $s4 4($s2)
move $a0 $s4
li $v0 1
syscall
la $a0 string_7_1
li $v0 4
syscall
j begin_for_50_1
end_for_50_1:
#Este es el código generado por la linea 53 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
j begin_for_49_1
end_for_49_1:
j begin_for_48_1
end_for_48_1:
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
li $s5 0
move $s6 $s5
j first_for_7_1
begin_for_7_1:
#Este es el código generado por la linea 7 de la instrucción i := i + 1
li $t8 1
add $t9 $s6 $t8
move $s6 $t9
first_for_7_1:
li $a2 -4
add $a2 $a2 $fp
lw $a2 4($a2)
slt $t0 $s6 $a2
bnez $t0 mid7
j end_for_7_1
mid7:
#Este es el código generado por la linea 8 de la instrucción for que inicia en begin_for_8_1 y termina en end_for_8_1
#Este es el código generado por la linea 8 de la instrucción j := 0
li $t2 0
move $t3 $t2
j first_for_8_1
begin_for_8_1:
#Este es el código generado por la linea 8 de la instrucción j := j + 1
li $t4 1
add $t5 $t3 $t4
move $t3 $t5
first_for_8_1:
slt $s7 $t3 $a2
bnez $s7 mid8
j end_for_8_1
mid8:
#Este es el código generado por la linea 9 de la instrucción for que inicia en begin_for_9_1 y termina en end_for_9_1
#Este es el código generado por la linea 9 de la instrucción k := 0
li $t7 0
move $s0 $t7
j first_for_9_1
begin_for_9_1:
#Este es el código generado por la linea 9 de la instrucción k := k + 1
li $s1 1
add $s2 $s0 $s1
move $s0 $s2
first_for_9_1:
slt $s4 $s0 $a2
bnez $s4 mid9
j end_for_9_1
mid9:
li $v0 5
syscall
move $t1 $v0
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $s3 24
add $a3 $t6 $s3
lw $s5 0($a3)
mul $t8 $s6 $s5
add $t9 $t8 $t3
li $t0 28
add $t2 $t6 $t0
lw $t4 0($t2)
mul $t5 $t9 $t4
add $s7 $t5 $s0
li $t7 12
add $s1 $t6 $t7
lw $s2 0($s1)
mul $s4 $s7 $s2
addi $s3 $zero 0
add $s3 $s3 $fp
lw $s3 4($s3)
add $s4 $s4 $s3
sw $t1 0($s4)
j begin_for_9_1
end_for_9_1:
j begin_for_8_1
end_for_8_1:
j begin_for_7_1
end_for_7_1:
addi $s3 $zero 0
add $s3 $s3 $sp
sw $s6 4($s3)
addi $s3 $zero 4
add $s3 $s3 $sp
sw $t3 4($s3)
addi $s3 $zero 8
add $s3 $s3 $sp
sw $s0 4($s3)
addi $s3 $zero -4
add $s3 $s3 $fp
sw $a2 4($s3)
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
li $s3 0
move $a3 $s3
j first_for_20_1
begin_for_20_1:
#Este es el código generado por la linea 20 de la instrucción i := i + 1
li $s5 1
add $t8 $a3 $s5
move $a3 $t8
first_for_20_1:
li $t0 -4
add $t0 $t0 $fp
lw $t0 4($t0)
slt $t2 $a3 $t0
bnez $t2 mid10
j end_for_20_1
mid10:
#Este es el código generado por la linea 21 de la instrucción for que inicia en begin_for_21_1 y termina en end_for_21_1
#Este es el código generado por la linea 21 de la instrucción j := 0
li $t9 0
move $t4 $t9
j first_for_21_1
begin_for_21_1:
#Este es el código generado por la linea 21 de la instrucción j := j + 1
li $t5 1
add $t7 $t4 $t5
move $t4 $t7
first_for_21_1:
slt $s1 $t4 $t0
bnez $s1 mid11
j end_for_21_1
mid11:
#Este es el código generado por la linea 22 de la instrucción for que inicia en begin_for_22_1 y termina en end_for_22_1
#Este es el código generado por la linea 22 de la instrucción k := 0
li $s7 0
move $s2 $s7
j first_for_22_1
begin_for_22_1:
#Este es el código generado por la linea 22 de la instrucción k := k + 1
li $s4 1
add $t1 $s2 $s4
move $s2 $t1
first_for_22_1:
slt $t6 $s2 $t0
bnez $t6 mid12
j end_for_22_1
mid12:
#Este es el código generado por la linea 23 de la instrucción write
#Aquí va el acceso a un arreglo que es por referencia ==> dope vector
li $t3 24
add $s0 $s6 $t3
lw $a2 0($s0)
mul $s3 $a3 $a2
add $s5 $s3 $t4
li $t8 28
add $t2 $s6 $t8
lw $t9 0($t2)
mul $t5 $s5 $t9
add $t7 $t5 $s2
li $s1 12
add $s7 $s6 $s1
lw $s4 0($s7)
mul $t1 $t7 $s4
addi $t3 $zero 0
add $t3 $t3 $fp
lw $t3 4($t3)
add $t1 $t1 $t3
lw $t6 0($t1)
move $a0 $t6
li $v0 1
syscall
j begin_for_22_1
end_for_22_1:
#Este es el código generado por la linea 25 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
j begin_for_21_1
end_for_21_1:
j begin_for_20_1
end_for_20_1:
addi $t3 $zero 0
add $t3 $t3 $sp
sw $a3 4($t3)
addi $t3 $zero 4
add $t3 $t3 $sp
sw $t4 4($t3)
addi $t3 $zero 8
add $t3 $t3 $sp
sw $s2 4($t3)
addi $t3 $zero -4
add $t3 $t3 $fp
sw $t0 4($t3)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
