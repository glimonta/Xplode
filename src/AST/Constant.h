
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

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      return toString(table);
    }

    virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      if ("true" == value) {
        ResultInstruction *goto_instr = new ResultInstruction("goto", trueLabel);
        generator->gen(goto_instr);
      } else if ("false" == value) {
        ResultInstruction *goto_instr = new ResultInstruction("goto", falseLabel);
        generator->gen(goto_instr);
      }
    }

};

#endif
