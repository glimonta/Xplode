.data

.align 4

.text
main:
addi $sp $sp -24
#Este es el código generado por la linea 37 de la instrucción lenguajes.codigo := 3641
li $a2 0
li $a3 3641
addi $a2 $a2 0
add $a2 $a2 $sp
sw $a3 4($a2)
#Este es el código generado por la linea 38 de la instrucción lenguajes.tieneLab := true
li $t0 4
addi $t0 $t0 0
add $t0 $t0 $sp
sw $t1 4($t0)
#Este es el código generado por la linea 39 de la instrucción bases.codigo := 3311
li $t2 0
li $t3 3311
addi $t2 $t2 8
add $t2 $t2 $sp
sw $t3 4($t2)
#Este es el código generado por la linea 40 de la instrucción bases.tieneLab := true
li $t4 4
addi $t4 $t4 8
add $t4 $t4 $sp
sw $t1 4($t4)
#Este es el código generado por la linea 41 de la instrucción diseno.codigo := 5651
li $t5 0
li $t6 5651
addi $t5 $t5 16
add $t5 $t5 $sp
sw $t6 4($t5)
#Este es el código generado por la linea 42 de la instrucción diseno.tieneLab := false
li $t7 4
addi $t7 $t7 16
add $t7 $t7 $sp
sw $s0 4($t7)
#Este es el código generado por la linea 45 de la instrucción write
#Este es el código generado por la linea 45 de la llamada a la función: porcodigo
addi $s1 $zero 12
add $s1 $s1 $sp
sw $s1 0($sp)
addi $sp $sp -4
addi $s1 $zero 4
add $s1 $s1 $sp
sw $s1 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s1 porcodigo
jal $s1
lw $s1 0($sp)
addi $sp $sp 8
#Este es el código generado por la linea 46 de la instrucción write
#Este es el código generado por la linea 46 de la llamada a la función: porlab
addi $s2 $zero 20
add $s2 $s2 $sp
sw $s2 0($sp)
addi $sp $sp -4
addi $s2 $zero 4
add $s2 $s2 $sp
sw $s2 0($sp)
addi $sp $sp -4
addi $sp $sp -4
la $s2 porlab
jal $s2
lw $s2 0($sp)
addi $sp $sp 8
li $v0 10
syscall
#Definición de Función porcodigo: linea 20
porcodigo:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 22 de la instrucción return
li $s3 0
addi $s5 $zero 0
add $s5 $s5 $fp
lw $s5 4($s5)
add $s3 $s3 $s5
lw $s4 0($s3)
li $s5 0
addi $s7 $zero 8
add $s7 $s7 $fp
lw $s7 4($s7)
add $s5 $s5 $s7
lw $s6 0($s5)
sgt $s7 $s4 $s6
sw $s7 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $t8 0
sw $t8 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
#Definición de Función porlab: linea 26
porlab:
addi $sp $sp -4
sw $ra 4($sp)
addi $sp $sp -4
sw $fp 4($sp)
addi $fp $sp 12
addi $sp $sp 0
#Este es el código generado por la linea 28 de la instrucción return
li $t9 4
addi $a3 $zero 0
add $a3 $a3 $fp
lw $a3 4($a3)
add $t9 $t9 $a3
lw $a2 0($t9)
sw $a2 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
li $a3 0
sw $a3 0($fp)
lw $ra -4($fp)
move $sp $fp
lw $fp -8($fp)
jr $ra
