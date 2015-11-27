.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"
string_7_3:    .asciiz "\n"
string_7_4:    .asciiz "\n"

.align 4
a:    .space    40

.text
main:
addi $sp $sp -288
#Este es el código generado por la linea 17 de la instrucción j := 0
li $a2 0
move $a3 $a2
#Este es el código generado por la linea 18 de la instrucción for que inicia en begin_for_18_1 y termina en end_for_18_1
#Este es el código generado por la linea 18 de la instrucción i := 0
li $t0 0
move $t1 $t0
j first_for_18_1
begin_for_18_1:
#Este es el código generado por la linea 18 de la instrucción i := i + 1
li $t2 1
add $t3 $t1 $t2
move $t1 $t3
first_for_18_1:
li $t4 10
slt $t5 $t1 $t4
bnez $t5 mid1
j end_for_18_1
mid1:
#Este es el código generado por la linea 19 de la instrucción j := j + 1
li $t6 1
add $t7 $a3 $t6
move $a3 $t7
#Este es el código generado por la linea 20 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_1
li $v0 4
syscall
j begin_for_18_1
end_for_18_1:
#Este es el código generado por la linea 22 de la instrucción for que inicia en begin_for_22_1 y termina en end_for_22_1
#Este es el código generado por la linea 22 de la instrucción i := 0
li $s0 0
move $t1 $s0
j first_for_22_1
begin_for_22_1:
#Este es el código generado por la linea 22 de la instrucción i := i + 1
li $s1 1
add $s2 $t1 $s1
move $t1 $s2
first_for_22_1:
li $s3 10
slt $s4 $t1 $s3
bnez $s4 mid2
j end_for_22_1
mid2:
#Este es el código generado por la linea 23 de la instrucción j := j + 2
li $s5 2
add $s6 $a3 $s5
move $a3 $s6
#Este es el código generado por la linea 24 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 25 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
j begin_for_22_1
end_for_22_1:
#Este es el código generado por la linea 28 de la instrucción b[0] := 4
li $s7 0
li $t8 4
mul $t9 $s7 $t8
li $a2 4
addi $t9 $t9 240
add $t9 $t9 $sp
sw $a2 4($t9)
#Este es el código generado por la linea 29 de la instrucción write
li $t0 0
li $t2 4
mul $t3 $t0 $t2
addi $t3 $t3 240
add $t3 $t3 $sp
lw $t4 4($t3)
move $a0 $t4
li $v0 1
syscall
la $a0 string_7_4
li $v0 4
syscall
li $v0 10
syscall
