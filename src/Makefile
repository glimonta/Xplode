all:  bis fle FlexScanner.o ErrorLog.o SymTable.o regalloc.o
	g++ -g lex.xp.cc lex.cl.cc FlexScanner.o ErrorLog.o SymTable.o RegisterAllocator.o Main.cpp xplode.tab.c -o xplode
	
FlexScanner.o:  FlexScanner.h FlexScanner.cpp bis
	g++ -g -c FlexScanner.cpp	

ErrorLog.o: ErrorLog.h ErrorLog.cpp
	g++ -g -c ErrorLog.cpp

SymTable.o: SymTable.h SymTable.cpp
	g++ -g -c SymTable.cpp
	
bis: xplode.y
	bison -v xplode.y

fle: classic.l xplode.l
	flex -i classic.l
	flex -i xplode.l

regalloc.o: MIPS/RegisterAllocator.h MIPS/RegisterAllocator.cpp
	g++ -g -c MIPS/RegisterAllocator.cpp

clean:
	rm -rf xplode.tab.c xplode.tab.h location.hh position.hh stack.hh
	rm -rf lex.xp.cc lex.cl.cc
	rm -rf xplode *.o xplode.output
	rm -rf *~
