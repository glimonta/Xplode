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
la $s0 string_7_1
move $a0 $s0
li $v0 4
syscall
j begin_for_18_1
end_for_18_1:
#Este es el código generado por la linea 22 de la instrucción for que inicia en begin_for_22_1 y termina en end_for_22_1
#Este es el código generado por la linea 22 de la instrucción i := 0
li $s1 0
move $t1 $s1
j first_for_22_1
begin_for_22_1:
#Este es el código generado por la linea 22 de la instrucción i := i + 1
li $s2 1
add $s3 $t1 $s2
move $t1 $s3
first_for_22_1:
li $s4 10
slt $s5 $t1 $s4
bnez $s5 mid2
j end_for_22_1
mid2:
#Este es el código generado por la linea 23 de la instrucción j := j + 2
li $s6 2
add $s7 $a3 $s6
move $a3 $s7
#Este es el código generado por la linea 24 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $t8 string_7_2
move $a0 $t8
li $v0 4
syscall
#Este es el código generado por la linea 25 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $t9 string_7_3
move $a0 $t9
li $v0 4
syscall
j begin_for_22_1
end_for_22_1:
#Este es el código generado por la linea 28 de la instrucción b[0] := 4
li $a2 0
li $t0 4
mul $t2 $a2 $t0
li $t4 4
addi $t2 $t2 240
add $t2 $t2 $sp
sw $t4 0($t2)
#Este es el código generado por la linea 29 de la instrucción write
li $t6 0
li $s1 4
mul $s2 $t6 $s1
addi $s2 $s2 240
add $s2 $s2 $sp
lw $s4 0($s2)
move $a0 $s4
li $v0 1
syscall
la $s6 string_7_4
move $a0 $s6
li $v0 4
syscall
li $v0 10
syscall
