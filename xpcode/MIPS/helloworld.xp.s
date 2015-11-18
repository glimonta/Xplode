.data
string_7_1:    .asciiz "Hello world!\n"

.text
main:
#Este es el código generado por la linea 4 de la instrucción write
la $4 string_7_1
li $2 4
syscall
li $2 10
syscall
