#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../SymTable.h"
#include "Expression.h"
#include "Statement.h"

#ifndef X_SLEEPST
#define X_SLEEPST

class SleepStatement : public Statement {
  public:
    Expression *var;
    SleepStatement(Expression *v){ var = v; }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "SLEEP STATEMENT\n";
      std::cout << std::string(tab, ' ') << "argument:\n";
      var->print(tab+2);
    }

    void firstcheck(SymTable *symtb){

      var->firstcheck(symtb);

    }

    void generateTAC(GeneratorTAC * generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción sleep");
      generator->gen(comment);

      std::string res = var->generateTAC(generator, table);
      SleepQuad *sleep = new SleepQuad(res);
      generator->gen(sleep);
    }

};

#endif
