
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
#include "TypeDeclaration.h"

#ifndef X_CONSTANTEXP
#define X_CONSTANTEXP


class Constant : public Expression {
  public:
    std::string value;
    Constant(std::string v, TypeDeclaration *n){value = v; ntype = n; }
    void print(int tab){
      std::cout << std::string(tab, ' ') << "CONSTANT\n";
      std::cout << std::string(tab, ' ') << "value: " << value << "\n";
      std::cout << std::string(tab, ' ') << "type: " <<(long int ) ntype << std::endl;
    }

    void firstcheck(SymTable *symtb){}

    std::string toString(SymTable *table) {
      return value;
    }

    ExpQuad * generateTAC(GeneratorTAC *generator, SymTable *table) {
      if (ntype->isstring()) {
        std::string id = generator->labelmaker->getLabel("string_" + getLineStr() + "_");
        generator->addString(id, value);
        return new VarQuad(id, NO_OFFSET, false, false, -1, -1, true);
      } else if (ntype->isnumeric()) {
        if (TYPE_FLOAT == ntype->numtype) {
          return new ConstQuad(value);
        } else if (TYPE_INT == ntype->numtype) {
          return new ConstQuad(atoi(value.c_str()));
        }
      } else if (ntype->isbool()) {
        if ("true" == value) {
          return new ConstQuad(1);
        } else if ("false" == value) {
          return new ConstQuad(0);
        }
      }
      return new VarQuad(value);
    }

    virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      if ("true" == value) {
        if ( "fall" == trueLabel ) {
          return;
        } else {
          GotoQuad *goto_instr = new GotoQuad(new VarQuad(trueLabel));
          generator->gen(goto_instr);
          generator->new_block();
        }
      } else if ("false" == value) {
        if ( "fall" == falseLabel ) {
          return;
        } else {
          GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
          generator->gen(goto_instr);
          generator->new_block();
        }
      }
    }

};

#endif
