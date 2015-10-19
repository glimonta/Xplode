#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "Expression.h"
#include "Block.h"
#include "../SymTable.h"

#ifndef X_FORSTATEMENT
#define X_FORSTATEMENT


class ForStatement : public CompoundStatement {
  public:
    Statement *init;
    Expression *condition;
    Statement *increment;
    ForStatement(Node *i, Expression *c, Node *inc, Node *b){
      init = (Statement *) i;
      increment = (Statement *) inc;
      condition = c;
      block = (Block *) b;
    }
    void print(int tab){
      std::cout << std::string(tab, ' ') << "FOR STATEMENT \n";
      std::cout << std::string(tab, ' ') << "intialization: \n";
      init->print(tab+2);
      std::cout << std::string(tab, ' ') << "increment: \n";
      increment->print(tab+2);
      std::cout << std::string(tab, ' ') << "condition: \n";
      condition->print(tab+2);
      block->print(tab+2);
    }

    void firstcheck(SymTable *symtb){

      init->firstcheck(symtb);
      condition->firstcheck(symtb);
      increment->firstcheck(symtb);
      if (block!=NULL) block->firstcheck(); 

    }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      //FIXME Hay que arreglar este comentario para tener el toString() y tampoco se que retornar
      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción for");
      generator->gen(comment);

      Label *begin_lab  = new Label(generator->labelmaker->getLabel("begin"));
      Label *end_lab = new Label(generator->labelmaker->getLabel("end"));
      Label *first_for_lab  = new Label(generator->labelmaker->getLabel("first_for"));

      init->generateTAC(generator, table);
      GotoQuad *goto_first = new GotoQuad(first_for_lab->getOp());
      generator->gen(goto_first);
      generator->new_block();
      generator->gen(begin_lab);
      increment->generateTAC(generator, table);
      generator->new_block();
      generator->gen(first_for_lab);
      Label *mid_lab = new Label(generator->labelmaker->getLabel("mid"));
      condition->generateJumpingCode(generator, table, mid_lab->getOp(), end_lab->getOp());
      generator->gen(mid_lab);
      block->generateTAC(generator, table);
      GotoQuad *goto_begin = new GotoQuad(begin_lab->getOp());
      generator->gen(goto_begin);
      generator->new_block();
      generator->gen(end_lab);

      return "";
    }

};


#endif
