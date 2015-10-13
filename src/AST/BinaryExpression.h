

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
    // FIXME creo que hay un error en el or porque creo que se genera un goto extra
    if ("<" == opname || "<=" == opname || ">" == opname || ">=" == opname || "==" == opname || "!=" == opname) {
      std::string leftop = lexp->generateTAC(generator, table);
      std::string rightop = rexp->generateTAC(generator, table);
      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      std::string op = opname;

      BinaryInstruction *binop = new BinaryInstruction(op, result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        Quad *if_instr = new Quad("if", result, "goto", trueLabel);
        generator->gen(if_instr);

        ResultInstruction *goto_instr = new ResultInstruction("goto", falseLabel);
        generator->gen(goto_instr);
      } else if ("fall" != trueLabel) {
        Quad *if_instr = new Quad("if", result, "goto", trueLabel);
        generator->gen(if_instr);
      } else if ("fall" != falseLabel) {
        Quad *if_instr = new Quad("ifnot", result, "goto", falseLabel);
        generator->gen(if_instr);
      } else {
      }
    } else if ("||" == opname) {
      if ( "fall" == trueLabel ) {
        Label *label = new Label(generator->labelmaker->getLabel("true"));
        lexp->generateJumpingCode(generator, table, label->getOp(), "fall");
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
        generator->gen(label);
      } else {
        lexp->generateJumpingCode(generator, table, trueLabel, "fall");
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
      }
    } else if ("&&" == opname) {
      if ( "fall" == falseLabel ) {
        Label *label = new Label(generator->labelmaker->getLabel("false"));
        lexp->generateJumpingCode(generator, table, "fall", label->getOp());
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
        generator->gen(label);
      } else {
        lexp->generateJumpingCode(generator, table, "fall", falseLabel);
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
      }
    } else {}
  }

};


#endif
