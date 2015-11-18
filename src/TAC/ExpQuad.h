#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../MIPS/MipsInstruction.h"
#include "../MIPS/MipsArgument.h"

#define NO_OFFSET -1000000

#ifndef X_EXPQUAD
#define X_EXPQUAD

class ExpQuad {

  public:
    ExpQuad() {}

    virtual std::string toString() { return ""; }

};

class GotoConstQuad : public ExpQuad {

  public:
    GotoConstQuad() {}

    virtual std::string toString() { return "goto"; }

};

class ConstQuad : public ExpQuad {

  public:

    int num;
    std::string value;

    ConstQuad(int n) {
      num = n;
      std::stringstream str;
      str << n;
      value = str.str();
    }

    std::string toString() {
      return value;
    }

};

class VarQuad : public ExpQuad {

  public:

    std::string vname;
    int offset;
    bool is_ref;
    bool is_arg;
    int size;
    int typenum;

    VarQuad(std::string v, int o = NO_OFFSET, bool r = false, bool a = false, int s = -1, int tn = -1) {
      vname = v;
      offset = o;
      is_ref = r;
      is_arg = a;
      size = s;
      typenum = tn;
    }

    std::string toString() {
      return vname;
    }

};


#endif
