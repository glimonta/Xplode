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

#ifndef X_CONTINUEST
#define X_CONTINUEST

class ContinueStatement : public Statement {
  public:
    ContinueStatement(){ }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "CONTINUE STATEMENT\n";
    }

    void firstcheck(SymTable *symtb){
    }

//    std::string generateTAC(GeneratorTAC * generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
//      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción continue");
//      generator->gen(comment);
//
//      GotoQuad *goto_instr = new GotoQuad(continueLabel);
//      generator->gen(goto_instr);
//      return "";
//    }

};

#endif
