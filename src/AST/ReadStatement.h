#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "Statement.h"
#include "../SymTable.h"

#ifndef X_READST
#define X_READST


class ReadStatement : public Statement {
  public:
  Expression *var;
  
  ReadStatement(Expression *v){ var = v; }
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "READ STATEMENT\n";
   std::cout << std::string(tab, ' ') << "variable:\n";
   var->print(tab+2);
  }
  
  void firstcheck(SymTable *symtb){
  
    var->firstcheck(symtb);
  
  }

  void generateTAC(GeneratorTAC * generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
    Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción read");
    VarQuad * res = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
    std::stringstream toString;
    toString << var->ntype->numtype;
    ConstQuad * numtype = new ConstQuad(var->ntype->numtype);
    ReadQuad * read = new ReadQuad(res, numtype);
    generator->gen(read);

    Quad * instr = var->lval_generateTAC(generator, table);

    if (NULL == instr->arg1) {
      instr->arg1 = res;
    } else {
      instr->arg2 = res;
    }

    generator->gen(instr);
  }

};

#endif
