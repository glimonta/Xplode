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

    void generateTAC(GeneratorTAC *generator, SymTable *table, std::string continueLabel, std::string breakLabel) {

      Label *fall_lab  = new Label("fall");
      Label *false_lab = new Label(generator->labelmaker->getLabel("false_if_" + getLineStr() + "_"));
      Label *next_lab  = new Label(generator->labelmaker->getLabel("next_if_" + getLineStr() + "_"));

      Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() +
        " de la instrucción if que termina en " + next_lab->getOp());
      generator->gen(comment);

      std::string res;


      if (NULL == elseBlock) {
        condition->generateJumpingCode(generator, table, fall_lab->getOp(), next_lab->getOp());
        res = block->generateTAC(generator, table, continueLabel, breakLabel);
        generator->new_block();
        generator->gen(next_lab);
      } else {
        condition->generateJumpingCode(generator, table, fall_lab->getOp(), false_lab->getOp());
        res = block->generateTAC(generator, table, continueLabel, breakLabel);
        GotoQuad *goto_instr = new GotoQuad(next_lab->getOp());
        generator->gen(goto_instr);
        generator->new_block();

        generator->gen(false_lab);
        res = elseBlock->generateTAC(generator, table, continueLabel, breakLabel);
        generator->new_block();
        generator->gen(next_lab);
      }

      //TODO
    }

};

#endif

