.data
string_7_1:    .asciiz "\n"
string_7_2:    .asciiz "\n"
string_7_3:    .asciiz "\n"
string_7_4:    .asciiz "\n"


.text
main:
addi $sp $sp -248
#Este es el código generado por la linea 14 de la instrucción j := 0
li $a2 0
li $a3 244
add $a3 $a3 $sp
sw $a2 0($a3)
#Este es el código generado por la linea 16 de la instrucción i := 0
li $t0 0
li $t1 240
add $t1 $t1 $sp
sw $t0 0($t1)
#Este es el código generado por la linea 17 de la instrucción j := j + 1
li $t2 1
add $t3 $a3 $t2
li $a3 244
add $a3 $a3 $sp
la $a3 0($a3)
sw $t3 0($a3)
#Este es el código generado por la linea 18 de la instrucción write
lw $a0 0($t1)
li $v0 1
syscall
la $t4 string_7_1
move $a0 $t4
li $v0 4
syscall
#Este es el código generado por la linea 19 de la instrucción write
lw $a0 0($a3)
li $v0 1
syscall
la $t5 string_7_2
move $a0 $t5
li $v0 4
syscall
#Este es el código generado por la linea 22 de la instrucción i := 4
li $t6 4
li $t1 240
add $t1 $t1 $sp
la $t1 0($t1)
sw $t6 0($t1)
#Este es el código generado por la linea 23 de la instrucción j := j + 2
li $t7 2
add $s0 $a3 $t7
li $a3 244
add $a3 $a3 $sp
la $a3 0($a3)
sw $s0 0($a3)
#Este es el código generado por la linea 24 de la instrucción write
lw $a0 0($t1)
li $v0 1
syscall
la $s1 string_7_3
move $a0 $s1
li $v0 4
syscall
#Este es el código generado por la linea 25 de la instrucción write
lw $a0 0($a3)
li $v0 1
syscall
la $s2 string_7_4
move $a0 $s2
li $v0 4
syscall
li $v0 10
syscall
