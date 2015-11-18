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

  ExpQuad * generateTAC(GeneratorTAC *generator, SymTable *table) {
    ExpQuad * leftop = lexp->generateTAC(generator, table);
    ExpQuad * rightop = rexp->generateTAC(generator, table);
    ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
    std::string op = opname;

    if ("+" == opname) {
      AddQuad *binop = new AddQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "-" == opname) {
      SubQuad *binop = new SubQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "*" == opname) {
      MulQuad *binop = new MulQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "/" == opname) {
      DivQuad *binop = new DivQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "%" == opname) {
      ModQuad *binop = new ModQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "<" == opname) {
      LessQuad *binop = new LessQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "<=" == opname) {
      LessEqualQuad *binop = new LessEqualQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( ">" == opname) {
      GreaterQuad *binop = new GreaterQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( ">=" == opname) {
      GreaterEqualQuad *binop = new GreaterEqualQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "==" == opname) {
      EqualQuad *binop = new EqualQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "!=" == opname) {
      NotEqualQuad *binop = new NotEqualQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "&&" == opname) {
      AndQuad *binop = new AndQuad(result, leftop, rightop);
      generator->gen(binop);
    } else if ( "||" == opname) {
      OrQuad *binop = new OrQuad(result, leftop, rightop);
      generator->gen(binop);
    }

    return result;
  }

  virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
    // FIXME creo que hay un error en el or porque creo que se genera un goto extra
    if ( "<" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      LessQuad *binop = new LessQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ( "<=" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      LessEqualQuad *binop = new LessEqualQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ( ">" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      GreaterQuad *binop = new GreaterQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ( ">=" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      GreaterEqualQuad *binop = new GreaterEqualQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ( "==" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      EqualQuad *binop = new EqualQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ( "!=" == opname ) {
      ExpQuad * leftop = lexp->generateTAC(generator, table);
      ExpQuad * rightop = rexp->generateTAC(generator, table);
      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      std::string op = opname;

      NotEqualQuad *binop = new NotEqualQuad(result, leftop, rightop);
      generator->gen(binop);


      if ("fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(result, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(result, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    } else if ("||" == opname) {
      if ( "fall" == trueLabel ) {
        Label *label = new Label(generator->labelmaker->getLabel("true"));
        lexp->generateJumpingCode(generator, table, label->getOp(), "fall");
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
//FIXME capaz tengo que agregar new_block aqui
        generator->new_block();
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
//FIXME capaz tengo que agregar new_block aqui
        generator->new_block();
        generator->gen(label);
      } else {
        lexp->generateJumpingCode(generator, table, "fall", falseLabel);
        rexp->generateJumpingCode(generator, table, trueLabel, falseLabel);
      }
    } else {}
  }

};


#endif
