.data
string_7_1:    .asciiz "Introduzca el numero de nodos:\n"
string_7_10:    .asciiz "\n"
string_7_2:    .asciiz "Introduzca el nodo fuente (0-indexed):\n"
string_7_3:    .asciiz "Introduzca el nodo destino (0-indexed):\n"
string_7_4:    .asciiz "Introduzca el numero de arcos:\n"
string_7_5:    .asciiz "Ahora debe introducir los arcos\n"
string_7_6:    .asciiz "Introduzca el fuente de un arco (0-indexed)\n"
string_7_7:    .asciiz "Introduzca el destino del arco (0-indexed)\n"
string_7_8:    .asciiz "Introduzca el costo del arco\n"
string_7_9:    .asciiz "Camino de menor costo: "

.align 4

.text
main:
addi $sp $sp -10452
#Este es el código generado por la linea 12 de la instrucción write
la $a0 string_7_1
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $a3 $a2
#Este es el código generado por la linea 15 de la instrucción i := 0
li $t0 0
move $t1 $t0
#Este es el código generado por la linea 16 de la instrucción j := 0
li $t2 0
move $t3 $t2
#Este es el código generado por la linea 17 de la instrucción while que inicia en begin_while_17_1 y termina en next_while_17_1
begin_while_17_1:
slt $t4 $t1 $a3
bnez $t4 true_while_17_1
j next_while_17_1
true_while_17_1:
#Este es el código generado por la linea 18 de la instrucción j := 0
li $t5 0
move $t3 $t5
#Este es el código generado por la linea 19 de la instrucción while que inicia en begin_while_19_1 y termina en next_while_19_1
begin_while_19_1:
slt $t6 $t3 $a3
bnez $t6 true_while_19_1
j next_while_19_1
true_while_19_1:
#Este es el código generado por la linea 20 de la instrucción ady[i][j] := 10000000
li $t7 50
mul $s0 $t1 $t7
add $s1 $s0 $t3
li $s2 4
mul $s3 $s1 $s2
li $s4 10000000
addi $s3 $s3 44
add $s3 $s3 $sp
sw $s4 4($s3)
#Este es el código generado por la linea 22 de la instrucción j := j + 1
li $s5 1
add $s6 $t3 $s5
move $t3 $s6
j begin_while_19_1
next_while_19_1:
#Este es el código generado por la linea 24 de la instrucción costo[i] := 10000000
li $s7 4
mul $t8 $t1 $s7
li $t9 10000000
addi $t8 $t8 10044
add $t8 $t8 $sp
sw $t9 4($t8)
#Este es el código generado por la linea 25 de la instrucción pick[i] := 0
li $a2 4
mul $t0 $t1 $a2
li $t2 0
addi $t0 $t0 10244
add $t0 $t0 $sp
sw $t2 4($t0)
#Este es el código generado por la linea 26 de la instrucción i := i + 1
li $t4 1
add $t5 $t1 $t4
move $t1 $t5
j begin_while_17_1
next_while_17_1:
#Este es el código generado por la linea 29 de la instrucción write
la $a0 string_7_2
li $v0 4
syscall
li $v0 5
syscall
move $t6 $v0
move $t7 $t6
#Este es el código generado por la linea 32 de la instrucción write
la $a0 string_7_3
li $v0 4
syscall
li $v0 5
syscall
move $s0 $v0
move $s1 $s0
#Este es el código generado por la linea 35 de la instrucción write
la $a0 string_7_4
li $v0 4
syscall
li $v0 5
syscall
move $s2 $v0
move $s3 $s2
#Este es el código generado por la linea 37 de la instrucción i := 0
li $s4 0
move $t1 $s4
#Este es el código generado por la linea 38 de la instrucción write
la $a0 string_7_5
li $v0 4
syscall
#Este es el código generado por la linea 39 de la instrucción while que inicia en begin_while_39_1 y termina en next_while_39_1
begin_while_39_1:
slt $s5 $t1 $s3
bnez $s5 true_while_39_1
j next_while_39_1
true_while_39_1:
#Este es el código generado por la linea 40 de la instrucción write
la $a0 string_7_6
li $v0 4
syscall
li $v0 5
syscall
move $s6 $v0
move $s7 $s6
#Este es el código generado por la linea 42 de la instrucción write
la $a0 string_7_7
li $v0 4
syscall
li $v0 5
syscall
move $t8 $v0
move $t9 $t8
#Este es el código generado por la linea 44 de la instrucción write
la $a0 string_7_8
li $v0 4
syscall
li $v0 5
syscall
move $a2 $v0
move $t0 $a2
#Este es el código generado por la linea 46 de la instrucción ady[x][y] := cost
li $t2 50
mul $t4 $s7 $t2
add $t5 $t4 $t9
li $t6 4
mul $s0 $t5 $t6
addi $s0 $s0 44
add $s0 $s0 $sp
sw $t0 4($s0)
#Este es el código generado por la linea 48 de la instrucción i := i + 1
li $s2 1
add $s4 $t1 $s2
move $t1 $s4
j begin_while_39_1
next_while_39_1:
#Este es el código generado por la linea 50 de la instrucción costo[src] := 0
li $s5 4
mul $s6 $t7 $s5
li $t8 0
addi $s6 $s6 10044
add $s6 $s6 $sp
sw $t8 4($s6)
#Este es el código generado por la linea 51 de la instrucción i := 0
li $a2 0
move $t1 $a2
#Este es el código generado por la linea 53 de la instrucción while que inicia en begin_while_53_1 y termina en next_while_53_1
begin_while_53_1:
slt $t2 $t1 $a3
bnez $t2 true_while_53_1
j next_while_53_1
true_while_53_1:
#Este es el código generado por la linea 55 de la instrucción menor := UMINUS 1
li $t4 1
neg $t5 $t4
move $t6 $t5
#Este es el código generado por la linea 56 de la instrucción tmp := 0
li $s0 0
move $s2 $s0
#Este es el código generado por la linea 57 de la instrucción while que inicia en begin_while_57_1 y termina en next_while_57_1
begin_while_57_1:
slt $s4 $s2 $a3
bnez $s4 true_while_57_1
j next_while_57_1
true_while_57_1:
#Este es el código generado por la linea 58 de la instrucción if que termina en next_if_58_1
li $s5 4
mul $s6 $s2 $s5
addi $s6 $s6 10244
add $s6 $s6 $sp
lw $t8 4($s6)
li $a2 0
seq $t2 $t8 $a2
beqz $t2 next_if_58_1
#Este es el código generado por la linea 59 de la instrucción if que termina en next_if_59_1
li $t4 1
neg $t5 $t4
seq $s0 $t6 $t5
beqz $s0 false_if_59_1
#Este es el código generado por la linea 60 de la instrucción menor := tmp
move $t6 $s2
j next_if_59_1
false_if_59_1:
#Este es el código generado por la linea 63 de la instrucción if que termina en next_if_63_1
li $s4 4
mul $s5 $s2 $s4
addi $s5 $s5 10044
add $s5 $s5 $sp
lw $s6 4($s5)
li $t8 4
mul $a2 $t6 $t8
addi $a2 $a2 10044
add $a2 $a2 $sp
lw $t2 4($a2)
slt $t4 $s6 $t2
beqz $t4 next_if_63_1
#Este es el código generado por la linea 64 de la instrucción menor := tmp
move $t6 $s2
next_if_63_1:
next_if_59_1:
next_if_58_1:
#Este es el código generado por la linea 69 de la instrucción tmp := tmp + 1
li $t5 1
add $s0 $s2 $t5
move $s2 $s0
j begin_while_57_1
next_while_57_1:
#Este es el código generado por la linea 72 de la instrucción if que termina en next_if_72_1
li $s4 1
neg $s5 $s4
seq $t8 $t6 $s5
beqz $t8 next_if_72_1
#Este es el código generado por la linea 73 de la instrucción break
j next_while_53_1
next_if_72_1:
#Este es el código generado por la linea 75 de la instrucción tmp := 0
li $a2 0
move $s2 $a2
#Este es el código generado por la linea 76 de la instrucción pick[menor] := 1
li $s6 4
mul $t2 $t6 $s6
li $t4 1
addi $t2 $t2 10244
add $t2 $t2 $sp
sw $t4 4($t2)
#Este es el código generado por la linea 77 de la instrucción while que inicia en begin_while_77_1 y termina en next_while_77_1
begin_while_77_1:
slt $t5 $s2 $a3
bnez $t5 true_while_77_1
j next_while_77_1
true_while_77_1:
#Este es el código generado por la linea 78 de la instrucción if que termina en next_if_78_1
li $s0 4
mul $s4 $s2 $s0
addi $s4 $s4 10244
add $s4 $s4 $sp
lw $s5 4($s4)
li $t8 0
seq $a2 $s5 $t8
beqz $a2 next_if_78_1
li $s6 4
mul $t2 $t6 $s6
addi $t2 $t2 10044
add $t2 $t2 $sp
lw $t4 4($t2)
li $t5 50
mul $s0 $t6 $t5
add $s4 $s0 $s2
li $s5 4
mul $t8 $s4 $s5
addi $t8 $t8 44
add $t8 $t8 $sp
lw $a2 4($t8)
add $s6 $t4 $a2
li $t2 4
mul $t5 $s2 $t2
addi $t5 $t5 10044
add $t5 $t5 $sp
lw $s0 4($t5)
slt $s4 $s6 $s0
beqz $s4 next_if_78_1
#Este es el código generado por la linea 79 de la instrucción costo[tmp] := costo[menor] + ady[menor][tmp]
li $s5 4
mul $t8 $t6 $s5
addi $t8 $t8 10044
add $t8 $t8 $sp
lw $t4 4($t8)
li $a2 50
mul $t2 $t6 $a2
add $t5 $t2 $s2
li $s6 4
mul $s0 $t5 $s6
addi $s0 $s0 44
add $s0 $s0 $sp
lw $s4 4($s0)
add $s5 $t4 $s4
li $t8 4
mul $a2 $s2 $t8
addi $a2 $a2 10044
add $a2 $a2 $sp
sw $s5 4($a2)
next_if_78_1:
#Este es el código generado por la linea 81 de la instrucción tmp := tmp + 1
li $t2 1
add $t5 $s2 $t2
move $s2 $t5
j begin_while_77_1
next_while_77_1:
#Este es el código generado por la linea 84 de la instrucción i := i + 1
li $s6 1
add $s0 $t1 $s6
move $t1 $s0
j begin_while_53_1
next_while_53_1:
#Este es el código generado por la linea 87 de la instrucción write
la $a0 string_7_9
li $v0 4
syscall
li $t4 4
mul $s4 $s1 $t4
addi $s4 $s4 10044
add $s4 $s4 $sp
lw $t8 4($s4)
move $a0 $t8
li $v0 1
syscall
la $a0 string_7_10
li $v0 4
syscall
li $v0 10
syscall
