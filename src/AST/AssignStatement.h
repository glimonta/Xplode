
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

  std::string toString() {
    return lvalue->toString() + " := " + rvalue->toString();
  }

  std::string generateTAC(GeneratorTAC *generator) {
        printf("Entre al generateTAC de la asignacion\n");
    std::string result = lvalue->generateTAC(generator);
        printf("generateTAC del left value sirve %s\n", lvalue->toString().c_str());
    std::string rightop = rvalue->generateTAC(generator);
        printf("generateTAC del right value sirve\n");
    std::string op = ":=";
        printf("Asigno un nuevo operador :=\n");

    Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la instrucción " + toString());
        printf("Creo el comentario\n");
    NoArg1Instruction *noarg1 = new NoArg1Instruction(op, result, rightop);
        printf("Creo la instruccion\n");
    generator->gen(comment);
        printf("genero el comentario\n");
    generator->gen(noarg1);
        printf("genero la operacion\n");
    return "hello";
//FIXME
  }

};

#endif

