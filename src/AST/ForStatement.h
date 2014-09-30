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
  
  
  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label ){

    std::string init = tac->labelmaker->getlabel(LABEL_LABEL);
    std::string medio = tac->labelmaker->getlabel(LABEL_LABEL);
    std::string end = tac->labelmaker->getlabel(LABEL_LABEL);
    std::string primer_for = tac->labelmaker->getlabel(LABEL_LABEL);
   /* 
    tac->push_quad(new Label(init));
    std::string cond = condition->toTAC(tac, symtab);
    tac->push_quad(new Label(primer_for));
    tac->push_quad(new Instruction(EQUAL_ZERO_LABEL, cond, end));
    tac->new_block();  
    tac->push_quad(new Label(medio));
    block->toTAC(tac, init, end);
    cond = condition->toTAC(tac, symtab);
    tac->push_quad(new Instruction(NEQUAL_ZERO_LABEL, cond, medio)); 
    tac->new_block();         
    tac->push_quad(new Label(end));
*/
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
  
  

};


#endif
