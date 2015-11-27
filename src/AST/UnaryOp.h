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

    ExpQuad * generateTAC(GeneratorTAC *generator, SymTable *table) {
      ExpQuad * a1 = exp->generateTAC(generator, table);
      VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));

      if(opname=="UMINUS"){
        if (TYPE_INT == exp->ntype->numtype) {
          UnaryMinusQuad *unop = new UnaryMinusQuad(result, a1);
          generator->gen(unop);
        } else {
          UnaryMinusFloatQuad *unop = new UnaryMinusFloatQuad(result, a1);
          generator->gen(unop);
        }
      } else if(opname=="NOT"){
        NotQuad *unop = new NotQuad(result, a1);
        generator->gen(unop);
      }

      return result;
    }

    virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      if ("NOT" == opname) {
        exp->generateJumpingCode(generator, table, falseLabel, trueLabel);
      }
    }

};

#endif
