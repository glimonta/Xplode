

#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"

#ifndef X_BINARYEXP
#define X_BINARYEXP

class BinaryExpression : public Expression {
  public:
  std::string opname;
  Expression *lexp, *rexp;
  BinaryExpression(std::string op,Expression *l, Expression *r){
    opname = op;
    lexp = l;
    rexp = r;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "EXPRESSION" << opname << "\n";
   std::cout << std::string(tab, ' ') << "left expression:\n";
   lexp->print(tab+2);
   std::cout << std::string(tab, ' ') << "right expression: \n";
   rexp ->print(tab+2);
  }

  void firstcheck(SymTable *symtb){

    lexp->firstcheck(symtb);
    rexp-> firstcheck(symtb);

  }

  std::string toString(SymTable *table) {
    return lexp->toString(table) + " " + opname + " " + rexp->toString(table);
  }

  std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
    std::string leftop = lexp->generateTAC(generator, table);
    std::string rightop = rexp->generateTAC(generator, table);
    std::string result = generator->labelmaker->getLabel(TEMPORAL);
    std::string op = opname;

    BinaryInstruction *binop = new BinaryInstruction(op, result, leftop, rightop);
    generator->gen(binop);
    return result;
  }

  virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
    if ("<" == opname) {
      std::string leftop = lexp->generateTAC(generator, table);
      std::string rightop = rexp->generateTAC(generator, table);
      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      std::string op = opname;

      BinaryInstruction *binop = new BinaryInstruction(op, result, leftop, rightop);
      generator->gen(binop);

      Quad *if_instr = new Quad("if", result, "goto", trueLabel);
      generator->gen(if_instr);

      ResultInstruction *goto_instr = new ResultInstruction("goto", falseLabel);
      generator->gen(goto_instr);
    } else if ("||" == opname) {
      Label *label  = new Label(generator->labelmaker->getLabel(LAB_LABEL));
      lexp->generateJumpingCode(generator, table, trueLabel, label->getOp());
      generator->gen(label);
      rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
    } else if ("&&" == opname) {
      Label *label  = new Label(generator->labelmaker->getLabel(LAB_LABEL));
      lexp->generateJumpingCode(generator, table, label->getOp(), falseLabel);
      generator->gen(label);
      rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
    }
  }

};


#endif
