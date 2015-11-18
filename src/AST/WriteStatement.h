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
#include "../SymTable.h"


#ifndef X_WRITESTATEMENT
#define X_WRITESTATEMENT

class WriteStatement : public Statement {
  public:
    std::list<Expression *> *writeList;

    WriteStatement(std::list<Expression *> *a){writeList = a; }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "WRITE STATEMENT\n";
      for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter){
        std::cout << std::string(tab, ' ') << "write: \n";
        (*iter)->print(tab+2);
      }
    }

    void firstcheck(SymTable *symtb){

      for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter)
        (*iter)->firstcheck(symtb);


    }

    void generateTAC(GeneratorTAC * generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción write");
      generator->gen(comment);
      for (std::list<Expression *>::iterator i = writeList->begin(); i != writeList->end(); ++i) {
        std::string exp = (*i)->generateTAC(generator, table);
        WriteQuad *write = new WriteQuad(exp);
        generator->gen(write);
      }
    }


};

#endif
