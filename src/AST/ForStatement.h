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
  Node *init;
  Expression *condition;
  Node *increment; 
  ForStatement(Node *i, Expression *c, Node *inc, Node *b){
    init = i;
    increment = inc;
    condition = c;
    block = (Block *) b;
  }
  void print(){
   std::cout << "FOR STATEMENT \n";
   std::cout << "intialization: \n";
   init->print();
   std::cout << "increment: \n";
   increment->print();
   std::cout << "condition: \n";
   condition->print();
   block->print();
  }

  void firstcheck(SymTable *symtb){
  
    if (block!=NULL) block->firstcheck();  
  
  }

};


#endif