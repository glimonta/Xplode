.data

.align 4
lenguajes:    .space    8

.text
main:
addi $sp $sp -24
#Este es el código generado por la linea 40 de la instrucción write
#Este es el código generado por la linea 40 de la llamada a la función: porcodigo
#Este es el código generado por la linea 41 de la instrucción write
#Este es el código generado por la linea 41 de la llamada a la función: porlab
li $v0 10
syscall
#Definición de Función porcodigo: linea 20
porcodigo:
#Este es el código generado por la linea 22 de la instrucción return
li $t0 0
addi $t2 $zero 0
add $t2 $t2 $fp
lw $t2 0($t2)
add $t0 $t0 $t2
lw $t1 0($t0)
li $t2 0
addi $t4 $zero 8
add $t4 $t4 $fp
lw $t4 0($t4)
add $t2 $t2 $t4
lw $t3 0($t2)
sgt $t4 $t1 $t3
#Definición de Función porlab: linea 26
porlab:
#Este es el código generado por la linea 28 de la instrucción return
li $t5 4
addi $t7 $zero 0
add $t7 $t7 $fp
lw $t7 0($t7)
add $t5 $t5 $t7
lw $t6 0($t5)
