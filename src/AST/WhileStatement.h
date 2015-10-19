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

#ifndef X_WHILESTATEMENT
#define X_WHILESTATEMENT

class WhileStatement : public CompoundStatement {
  public:

    Expression *condition;
    WhileStatement(Expression *c, Node *b){
      condition = c;
      block = (Block *) b;
    }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "WHILE STATEMENT \n";
      std::cout << std::string(tab, ' ') << "condition: \n";
      condition->print(tab+2);
      block->print(tab+2);
    }

    void firstcheck(SymTable *symtb){

      condition->firstcheck(symtb);
      if(block!=NULL) block->firstcheck();

    }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      //FIXME Hay que arreglar este comentario para tener el toString()
      Comment *comment = new Comment("Este es el código generado por la linea " + this->getLineStr() + " de la instrucción while");
      generator->gen(comment);

      Label *begin_lab  = new Label(generator->labelmaker->getLabel("begin"));
      Label *true_lab = new Label(generator->labelmaker->getLabel("true"));
      Label *next_lab  = new Label(generator->labelmaker->getLabel("next"));

      std::string res;

      generator->new_block();
      generator->gen(begin_lab);
      condition->generateJumpingCode(generator, table, true_lab->getOp(), next_lab->getOp());

      generator->gen(true_lab);

      res = block->generateTAC(generator, table);
      GotoQuad *goto_instr = new GotoQuad(begin_lab->getOp());
      generator->gen(goto_instr);
      generator->new_block();

      generator->gen(next_lab);

      return res;
    }

};

#endif
