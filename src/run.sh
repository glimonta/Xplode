#!/bin/bash

TEST_NAMES_TAC=(../xpcode/TAC/for.xp ../xpcode/TAC/jumpingcodewhile.xp ../xpcode/TAC/jumpingcode.xp ../xpcode/TAC/parcial2012.xp ../xpcode/TAC/recursion.xp
    ../xpcode/TAC/take_a_real_parameter.xp ../xpcode/TAC/infinite.xp ../xpcode/TAC/cadenas.xp)
TEST_NAMES_CORRECTOS=(../xpcode/correctos/auth.xp ../xpcode/correctos/castTest.xp ../xpcode/correctos/magicNumber.xp ../xpcode/correctos/matrix.xp ../xpcode/correctos/matrix2.xp
    ../xpcode/correctos/personArray.xp ../xpcode/correctos/personComp.xp ../xpcode/correctos/person.xp ../xpcode/correctos/scientific.xp ../xpcode/correctos/secondclass.xp 
    ../xpcode/correctos/simpleUnion.xp ../xpcode/correctos/suma.xp)
TEST_NAMES_MIPS=(../xpcode/MIPS/ackerman.xp ../xpcode/MIPS/align.xp ../xpcode/MIPS/dijkstra.xp ../xpcode/MIPS/factorial_iterativo.xp ../xpcode/MIPS/factorial_recursivo.xp
    ../xpcode/MIPS/fibonacci_recursivo.xp ../xpcode/MIPS/foldr.xp ../xpcode/MIPS/hanoi.xp ../xpcode/MIPS/helloworld.xp ../xpcode/MIPS/mergesort.xp ../xpcode/MIPS/multmatrices.xp
    ../xpcode/MIPS/quicksort.xp ../xpcode/MIPS/raiz_newton.xp ../xpcode/MIPS/referencia.xp ../xpcode/MIPS/segundaclase.xp ../xpcode/MIPS/subarreglo.xp ../xpcode/MIPS/unitarios.xp
    ../xpcode/MIPS/vectores.xp)

CORRECTOS=../xpcode/correctos
TAC=../xpcode/TAC/
MIPS=../xpcode/MIPS/

for test_name in ${TEST_NAMES_TAC[@]}
do
  echo -e "Corriendo la prueba ${test_name}";
  echo $(./xplode ${test_name});
done

for test_name in ${TEST_NAMES_CORRECTOS[@]}
do
  echo -e "Corriendo la prueba ${test_name}";
  echo $(./xplode ${test_name});
done
for test_name in ${TEST_NAMES_MIPS[@]}
do
  echo -e "Corriendo la prueba ${test_name}";
  echo $(./xplode ${test_name});
done
