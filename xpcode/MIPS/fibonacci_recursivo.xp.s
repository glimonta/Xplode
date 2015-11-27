.data
string_7_1:    .asciiz "fibonacci["
string_7_2:    .asciiz "]="
string_7_3:    .asciiz "\n"

.align 4

.text
main:
addi $sp $sp -8
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 27 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
move $a0 $a3
li $v0 1
syscall
la $a0 string_7_2
li $v0 4
syscall
#Este es el código generado por la linea 27 de la llamada a la función: fib
addi $t0 $zero 4
add $t0 $t0 $sp
sw $a3 4($t0)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t0 fib
jal $t0
lw $t0 0($sp)
addi $sp $sp 4
move $a0 $t0
li $v0 1
syscall
la $a0 string_7_3
li $v0 4
syscall
li $v0 10
syscall
#Definición de Función fib: linea 3
fib:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp -8
#Este es el código generado por la linea 7 de la instrucción if que termina en next_if_7_1
li $t1 0
add $t1 $t1 $fp
lw $t1 4($t1)
li $t2 0
seq $t3 $t1 $t2
beqz $t3 next_if_7_1
#Este es el código generado por la linea 8 de la instrucción return
li $t4 0
sw $t4 0($fp)
addi $t5 $zero 0
add $t5 $t5 $fp
sw $t1 4($t5)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_7_1:
#Este es el código generado por la linea 11 de la instrucción if que termina en next_if_11_1
li $t5 0
add $t5 $t5 $fp
lw $t5 4($t5)
li $t6 1
seq $t7 $t5 $t6
beqz $t7 next_if_11_1
#Este es el código generado por la linea 12 de la instrucción return
li $s0 1
sw $s0 0($fp)
addi $s1 $zero 0
add $s1 $s1 $fp
sw $t5 4($s1)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_11_1:
#Este es el código generado por la linea 15 de la instrucción j := fib(num - 1)
#Este es el código generado por la linea 15 de la llamada a la función: fib
li $s1 0
add $s1 $s1 $fp
lw $s1 4($s1)
li $s2 1
sub $s3 $s1 $s2
addi $sp $sp -4
sw $s3 4($sp)
addi $sp $sp -4
la $s4 fib
jal $s4
lw $s4 0($sp)
addi $sp $sp 4
move $s5 $s4
#Este es el código generado por la linea 16 de la instrucción k := fib(num - 2)
#Este es el código generado por la linea 16 de la llamada a la función: fib
addi $s6 $zero 0
add $s6 $s6 $sp
sw $s5 4($s6)
li $s6 0
add $s6 $s6 $fp
lw $s6 4($s6)
li $s7 2
sub $t8 $s6 $s7
addi $sp $sp -4
sw $t8 4($sp)
addi $sp $sp -4
la $t9 fib
jal $t9
lw $t9 0($sp)
addi $sp $sp 4
move $a2 $t9
#Este es el código generado por la linea 17 de la instrucción return
li $a3 0
add $a3 $a3 $sp
lw $a3 4($a3)
add $t0 $a2 $a3
sw $t0 0($fp)
addi $t2 $zero 0
add $t2 $t2 $sp
sw $a3 4($t2)
addi $t2 $zero 4
add $t2 $t2 $sp
sw $a2 4($t2)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t2 0
sw $t2 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
