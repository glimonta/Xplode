#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_MIPSARGUMENT
#define X_MIPSARGUMENT


class MipsArgument {

  public:

    MipsArgument() {}

    virtual std::string toString() { return ""; }

};

class MipsRegister : public MipsArgument {

  public:
    int num;

    MipsRegister(int n) {
      num = n;
    }

    std::string toString() {
      std::stringstream reg;
      reg << "$" << num;
      return reg.str();
    }

};

class MipsOffset : public MipsArgument {

  public:
    int offset;
    int reg;

    MipsOffset(int o, int r) {
      offset = o;
      reg = r;
    }

    std::string toString() {
      std::stringstream ofs;
      ofs << offset << "($" << reg << ")";
      return ofs.str();
    }

};

class MipsVariable : public MipsArgument {

  public:
    std::string name;

    MipsVariable(std::string n) {
      name = n;
    }

    std::string toString() {
      return name;
    }

};

class MipsImmediate : public MipsArgument {

  public:
    int value;

    MipsImmediate(int v) {
      value = v;
    }

    std::string toString() {
      std::stringstream val;
      val << value;
      return val.str();
    }

};
#endif
