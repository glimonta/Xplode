#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "Block.h"
#include "../SymTable.h"
#include "Expression.h"


#ifndef X_IFSTATEMENT
#define X_IFSTATEMENT

class IfStatement : public CompoundStatement {
  public:
    Expression *condition;
    Block *elseBlock;
    IfStatement(Expression *c, Node *t, Node *e = 0){
      condition = c;
      block = (Block *) t;
      elseBlock = (Block *) e;
    }
    void print(int tab){
      std::cout << std::string(tab, ' ') << "IF STATEMENT \n";
      std::cout << std::string(tab, ' ') << "condition: \n";
      condition->print(tab+2);
      std::cout << std::string(tab, ' ') << "then: \n";
      block->print(tab+2);
      if (elseBlock != 0){
        std::cout << std::string(tab, ' ') << "else: \n";
        elseBlock->print(tab+2);
      }
    }

    void setFather(SymTable *s){

      block->setFather(s);
      if (elseBlock!=NULL) elseBlock->setFather(s);

    }

    virtual void printTable() {

      if (block!=NULL) block->printTable();
      if (elseBlock!=NULL) elseBlock->printTable();

    }

    void firstcheck(SymTable *symtb){

      condition->firstcheck(symtb);
      if(block != NULL) block->firstcheck();
      if (elseBlock != NULL) elseBlock->firstcheck();

    }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      //FIXME Hay que arreglar este comentario para tener el toString()
      Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la instrucción if");
      generator->gen(comment);

      Label *true_lab  = new Label(generator->labelmaker->getLabel("true"));
      Label *false_lab = new Label(generator->labelmaker->getLabel("false"));
      Label *next_lab  = new Label(generator->labelmaker->getLabel("next"));

      std::string res = condition->generateTAC(generator, table);
      Quad *if_instr = new Quad("if", res, "goto", true_lab->getOp());
      generator->gen(if_instr);

      if (NULL == elseBlock) {
        ResultInstruction *goto_instr = new ResultInstruction("goto", next_lab->getOp());
        generator->gen(goto_instr);

        generator->gen(true_lab);
        res = block->generateTAC(generator, table);
        generator->gen(next_lab);
      } else {
        ResultInstruction *goto_instr = new ResultInstruction("goto", false_lab->getOp());
        generator->gen(goto_instr);

        generator->gen(true_lab);
        res = block->generateTAC(generator, block->table);
        goto_instr = new ResultInstruction("goto", next_lab->getOp());
        generator->gen(goto_instr);

        generator->gen(false_lab);
        res = elseBlock->generateTAC(generator, elseBlock->table);
        generator->gen(next_lab);
      }

      return res;
      //TODO
    }

};

#endif

