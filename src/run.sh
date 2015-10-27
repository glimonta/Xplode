#!/bin/bash

TEST_NAMES_TAC=(../xpcode/TAC/for.xp ../xpcode/TAC/jumpingcodewhile.xp ../xpcode/TAC/jumpingcode.xp ../xpcode/TAC/parcial2012.xp ../xpcode/TAC/recursion.xp
  ../xpcode/TAC/take_a_real_parameter.xp)
TEST_NAMES_CORRECTOS=(../xpcode/correctos/auth.xp ../xpcode/correctos/castTest.xp ../xpcode/correctos/magicNumber.xp ../xpcode/correctos/matrix.xp ../xpcode/correctos/matrix2.xp
  ../xpcode/correctos/personArray.xp ../xpcode/correctos/personComp.xp ../xpcode/correctos/person.xp ../xpcode/correctos/scientific.xp ../xpcode/correctos/secondclass.xp 
  ../xpcode/correctos/simpleUnion.xp ../xpcode/correctos/suma.xp)

CORRECTOS=../xpcode/correctos
TAC=../xpcode/TAC/

for test_name in ${TEST_NAMES_TAC[@]}
do
  res=$(./xplode ${test_name});
done

for test_name in ${TEST_NAMES_CORRECTOS[@]}
do
  res=$(./xplode ${test_name});
done
