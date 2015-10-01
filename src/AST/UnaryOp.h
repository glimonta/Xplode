#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"
#include "Expression.h"

#ifndef X_UNARYOP
#define X_UNARYOP


class UnaryOp : public Expression {
  public:
    Expression *exp;
    std::string opname;
    UnaryOp( std::string op, Expression *e){
      exp = e;
      if (op == "-"){
        opname = "UMINUS";
      } else if (op == "!"){
        opname = "NOT";
      } else {
        opname = "UNKNOWN";
      }

    }
    void print(int tab){
      std::cout << std::string(tab, ' ') << opname << "\n";
      std::cout << std::string(tab, ' ') << "expression:\n";
      exp->print(tab+2);
    }

    void firstcheck(SymTable *symtb){
    }

    std::string toString(SymTable *table) {
      return opname + " " + exp->toString(table);
    }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      std::string a1 = exp->generateTAC(generator, table);
      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      std::string op;

      if(opname=="UMINUS"){
        op = UMINUS_LABEL;
      } else if(opname=="NOT"){
        op = NOT_LABEL;
      } else {}

      Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la instrucción " + toString(table));
      NoArg2Instruction *unop = new NoArg2Instruction(op, result, a1);
      generator->gen(comment);
      generator->gen(unop);
      return result;
    }


};

#endif
