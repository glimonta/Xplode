.data
string_7_1:    .asciiz "Hello world!\n"

.text
main:
la $4 string_7_1
li $2 4
syscall
li $2 10
syscall
