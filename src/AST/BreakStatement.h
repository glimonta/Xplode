#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../SymTable.h"
#include "Statement.h"

#ifndef X_BREAKST
#define X_BREAKST

class BreakStatement : public Statement {
  public:
    BreakStatement(){ }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "BREAK STATEMENT\n";
    }

    void firstcheck(SymTable *symtb){
    }

    void generateTAC(GeneratorTAC * generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción break");
      generator->gen(comment);

      GotoQuad *goto_instr = new GotoQuad(new VarQuad(breakLabel));
      generator->gen(goto_instr);

      generator->new_block();
    }

};

#endif
