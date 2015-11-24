#ifndef X_DECLARATION
#define X_DECLARATION

#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "TypeDeclaration.h"
#include "../Symbol.h"
#include "Node.h"
#include "Statement.h"
#include "../Token.h"
#include "../ErrorLog.h"

extern ErrorLog *errorlog;

class Declaration : public Statement {
  public:
    TypeDeclaration *ntype;
    std::string var;

    Declaration(Node *n, Xplode::Token *v) {
      ntype = (TypeDeclaration *) n;
      var = v->value;
      line = v->line;
      column = v->column;
    }

    void print(int tab){/*
                           std::string tab = std::string(4, ' ');

                           std::cout << "DECLARATION\n";
                           std::cout << "type: " << ntype->name << "\n";
                           std::cout << "var: " << var << "\n";

*/
    }

    Symbol *toSymbol(){
      /*
         return new Symbol(var,ntype->name, line, column, false,
         ntype->max_index->size());

*/
    }

    void firstcheck(SymTable *symtb){

      Symbol *nvar, *ntp;
      /*
           nvar = symtb->find(var);
           ntp = symtb->find(ntype->name);
      //falta
      if((nvar)&&(nvar->defined)) errorlog->addError(6,line, column,&var);
      if(!ntp) errorlog->addError(7,line,column,&ntype->name);
      if((ntp)&&(!ntp->defined)) errorlog->addError(7,line,column,&ntype->name);
      */
    }

    void generateTAC(GeneratorTAC *generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
      std::cout << "Entre a generar para una declaración" << std::endl;
      generator->gen(new DeclQuad(new VarQuad(var), new ConstQuad(ntype->numtype), new ConstQuad(ntype->size)));
    }

};


#endif
