.data
string_7_1:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -92
#Este es el código generado por la linea 8 de la instrucción i := 4
li $a2 4
move $a3 $a2
#Este es el código generado por la linea 9 de la instrucción j := 1
li $t0 1
move $t1 $t0
#Este es el código generado por la linea 10 de la instrucción k := 2
li $t2 2
move $t3 $t2
#Este es el código generado por la linea 11 de la instrucción bar[i] := 2
li $t4 4
mul $t5 $a3 $t4
li $t6 2
addi $t5 $t5 20
add $t5 $t5 $sp
sw $t6 4($t5)
#Este es el código generado por la linea 12 de la instrucción qux[j] := 4
li $t7 4
mul $s0 $t1 $t7
li $s1 4
addi $s0 $s0 60
add $s0 $s0 $sp
sw $s1 4($s0)
#Este es el código generado por la linea 13 de la instrucción baz[4] := 9
li $s2 4
li $s3 4
mul $s4 $s2 $s3
li $s5 9
addi $s4 $s4 40
add $s4 $s4 $sp
sw $s5 4($s4)
#Este es el código generado por la linea 14 de la instrucción foo[k] := bar[i] + baz[qux[j]]
li $s6 4
mul $s7 $a3 $s6
addi $s7 $s7 20
add $s7 $s7 $sp
lw $t8 4($s7)
li $t9 4
mul $a2 $t1 $t9
addi $a2 $a2 60
add $a2 $a2 $sp
lw $t0 4($a2)
li $t2 4
mul $t4 $t0 $t2
addi $t4 $t4 40
add $t4 $t4 $sp
lw $t5 4($t4)
add $t6 $t8 $t5
li $t7 4
mul $s0 $t3 $t7
addi $s0 $s0 0
add $s0 $s0 $sp
sw $t6 4($s0)
#Este es el código generado por la linea 16 de la instrucción write
li $s1 4
mul $s2 $t3 $s1
addi $s2 $s2 0
add $s2 $s2 $sp
lw $s3 4($s2)
move $a0 $s3
li $v0 1
syscall
la $s4 string_7_1
move $a0 $s4
li $v0 4
syscall
li $v0 10
syscall
