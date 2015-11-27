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
#Este es el código generado por la linea 25 de la instrucción write
la $t0 string_7_1
move $a0 $t0
li $v0 4
syscall
move $a0 $a3
li $v0 1
syscall
la $t1 string_7_2
move $a0 $t1
li $v0 4
syscall
#Este es el código generado por la linea 25 de la llamada a la función: fib
addi $t2 $zero 4
add $t2 $t2 $sp
sw $a3 4($t2)
addi $sp $sp -4
sw $a3 4($sp)
addi $sp $sp -4
la $t2 fib
jal $t2
lw $t2 0($sp)
addi $sp $sp 4
move $a0 $t2
li $v0 1
syscall
la $t3 string_7_3
move $a0 $t3
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
li $t4 0
add $t4 $t4 $fp
lw $t4 4($t4)
li $t5 2
slt $t6 $t4 $t5
beqz $t6 next_if_7_1
#Este es el código generado por la linea 9 de la instrucción return
li $t7 1
sw $t7 0($fp)
addi $s0 $zero 0
add $s0 $s0 $fp
sw $t4 4($s0)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
next_if_7_1:
#Este es el código generado por la linea 13 de la instrucción j := fib(num - 1)
#Este es el código generado por la linea 13 de la llamada a la función: fib
li $s0 0
add $s0 $s0 $fp
lw $s0 4($s0)
li $s1 1
sub $s2 $s0 $s1
addi $sp $sp -4
sw $s2 4($sp)
addi $sp $sp -4
la $s3 fib
jal $s3
lw $s3 0($sp)
addi $sp $sp 4
move $s4 $s3
#Este es el código generado por la linea 14 de la instrucción k := fib(num - 2)
#Este es el código generado por la linea 14 de la llamada a la función: fib
addi $s5 $zero 0
add $s5 $s5 $sp
sw $s4 4($s5)
li $s5 0
add $s5 $s5 $fp
lw $s5 4($s5)
li $s6 2
sub $s7 $s5 $s6
addi $sp $sp -4
sw $s7 4($sp)
addi $sp $sp -4
la $t8 fib
jal $t8
lw $t8 0($sp)
addi $sp $sp 4
move $t9 $t8
#Este es el código generado por la linea 15 de la instrucción return
li $a2 0
add $a2 $a2 $sp
lw $a2 4($a2)
add $a3 $t9 $a2
sw $a3 0($fp)
addi $t0 $zero 0
add $t0 $t0 $sp
sw $a2 4($t0)
addi $t0 $zero 4
add $t0 $t0 $sp
sw $t9 4($t0)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t0 0
sw $t0 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
