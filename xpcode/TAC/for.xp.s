.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"
string_7_3:    .asciiz "\n"
string_7_4:    .asciiz "\n"
string_7_5:    .asciiz "\n"

.align 4
a:    .space    40

.text
main:
addi $sp $sp -288
#Este es el código generado por la linea 17 de la instrucción j := 0
li $a2 0
move $a3 $a2
#Este es el código generado por la linea 19 de la instrucción i := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 20 de la instrucción j := j + 1
li $t2 1
add $t3 $a3 $t2
move $a3 $t3
#Este es el código generado por la linea 21 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $t4 string_7_1
move $a0 $t4
li $v0 4
syscall
#Este es el código generado por la linea 22 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $t5 string_7_2
move $a0 $t5
li $v0 4
syscall
#Este es el código generado por la linea 25 de la instrucción i := 4
li $t6 4
move $t1 $t6
#Este es el código generado por la linea 26 de la instrucción j := j + 2
li $t7 2
add $s0 $a3 $t7
move $a3 $s0
#Este es el código generado por la linea 27 de la instrucción write
move $a0 $t1
li $v0 1
syscall
la $s1 string_7_3
move $a0 $s1
li $v0 4
syscall
#Este es el código generado por la linea 28 de la instrucción write
move $a0 $a3
li $v0 1
syscall
la $s2 string_7_4
move $a0 $s2
li $v0 4
syscall
#Este es el código generado por la linea 31 de la instrucción b[0] := 4
li $s4 4
addi $s3 $s3 240
add $s3 $s3 $sp
sw $s4 0($s3)
#Este es el código generado por la linea 32 de la instrucción write
addi $s5 $s5 240
add $s5 $s5 $sp
lw $s6 0($s5)
move $a0 $s6
li $v0 1
syscall
la $s7 string_7_5
move $a0 $s7
li $v0 4
syscall
li $v0 10
syscall
