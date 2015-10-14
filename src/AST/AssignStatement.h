
#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "Expression.h"


#ifndef X_ASSIGN
#define X_ASSIGN

class AssignStatement : public Statement {
  public:
    Expression *lvalue, *rvalue;
    AssignStatement(Expression *l, Expression *r){
      lvalue = l;
      rvalue = r;
    }
    void print(int tab){
      std::cout << std::string(tab, ' ') << "ASSIGN STATEMENT\n";
      std::cout << std::string(tab, ' ') << "left value:\n";
      lvalue->print(tab+2);
      std::cout << std::string(tab, ' ') << "right value: \n";
      rvalue ->print(tab+2);
    }

    void firstcheck(SymTable *symtb){

      lvalue->firstcheck(symtb);
      rvalue->firstcheck(symtb);

    }

  std::string toString(SymTable *table) {
    return lvalue->toString(table) + " := " + rvalue->toString(table);
  }

  std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
    Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción " + toString(table));
    generator->gen(comment);

    std::string result = lvalue->generateTAC(generator, table);
    std::string rightop = rvalue->generateTAC(generator, table);
    std::string op = ":=";

    AssignQuad *assign = new AssignQuad(op, result, rightop);
    generator->gen(assign);
    return result;
//FIXME
  }

};

#endif

