#ifndef X_EXPRESSION
#define X_EXPRESSION

#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "../SymTable.h"
#include "TypeDeclaration.h"

class Expression : public Node {
  public:
    TypeDeclaration *ntype; //Used for type checks

    virtual void print(int tab) {}

    virtual void firstcheck(SymTable *symtb) {}

    virtual std::string toString(SymTable *table) {}

    virtual ExpQuad * generateTAC(GeneratorTAC *generator, SymTable * table) {}

    virtual void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {}

    virtual Quad * lval_generateTAC(GeneratorTAC *generator, SymTable *table) {}

    virtual bool isvariable() { return false; }

};

#endif
