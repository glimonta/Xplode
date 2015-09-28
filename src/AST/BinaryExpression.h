

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

#ifndef X_BINARYEXP
#define X_BINARYEXP

class BinaryExpression : public Expression {
  public:
  std::string opname;
  Expression *lexp, *rexp;
  BinaryExpression(std::string op,Expression *l, Expression *r){
    opname = op;
    lexp = l;
    rexp = r;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "EXPRESSION" << opname << "\n";
   std::cout << std::string(tab, ' ') << "left expression:\n";
   lexp->print(tab+2);
   std::cout << std::string(tab, ' ') << "right expression: \n";
   rexp ->print(tab+2);
  }

  void firstcheck(SymTable *symtb){

    lexp->firstcheck(symtb);
    rexp-> firstcheck(symtb);

  }

  std::string toString() {
    return lexp->toString() + " " + opname + " " + rexp->toString();
  }

  std::string generateTAC(GeneratorTAC *generator) {
    std::string leftop = lexp->generateTAC(generator);
    std::string rightop = rexp->generateTAC(generator);
    std::string result = generator->labelmaker->getLabel(TEMPORAL);
    std::string op = opname;

    Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la instrucción " + toString());
    BinaryInstruction *binop = new BinaryInstruction(op, result, leftop, rightop);
    generator->gen(comment);
    generator->gen(binop);
    return result;
  }

};


#endif
