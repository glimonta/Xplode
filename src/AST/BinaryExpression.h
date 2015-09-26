

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
        printf("Entre al generateTAC de la binexp %s\n");
    std::string leftop = lexp->generateTAC(generator);
        printf("generateTAC del left value sirve %s\n", leftop.c_str());
    std::string rightop = rexp->generateTAC(generator);
        printf("generateTAC del right value sirve %s\n", rightop.c_str());
    std::string result = generator->labelmaker->getLabel(TEMPORAL);
        printf("la labelmaker me hace un nuevo temporal %s\n", result.c_str());
    std::string op = opname;
        printf("Asigno un nuevo operador %s\n", opname.c_str());

    Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la instrucción " + toString());
        printf("Creo el comentario\n");
    BinaryInstruction *binop = new BinaryInstruction(op, result, leftop, rightop);
        printf("Creo la instruccion\n");
    generator->gen(comment);
        printf("genero el comentario\n");
    generator->gen(binop);
        printf("genero la operacion\n");
    return result;
  }

};


#endif
