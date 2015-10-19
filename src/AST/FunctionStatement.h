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

#ifndef X_FUNCTIONST
#define X_FUNCTIONST

class FunctionStatement : public Statement {
  public:
  Expression *exp;
  FunctionStatement(Expression *e){ exp = e; }
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "FUNCTION STATEMENT\n";
   exp->print(tab +2 );
  }

  void firstcheck(SymTable *symtb){
    exp->firstcheck(symtb);
  }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {

      return exp->generateTAC(generator, table);

    }

};

#endif
