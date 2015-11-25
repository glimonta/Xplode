#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#define ZERO_REGISTER new MipsRegister(0)
#define V0_REGISTER new MipsRegister(2)
#define V1_REGISTER new MipsRegister(3)
#define A0_REGISTER new MipsRegister(4)
#define A1_REGISTER new MipsRegister(5)
#define SP_REGISTER new MipsRegister(29)
#define FP_REGISTER new MipsRegister(30)
#define RA_REGISTER new MipsRegister(31)

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
      std::string reg_name = getRegName(num);
      return "$" + reg_name;
    }

    std::string getRegName(int num) {
      switch (num) {
        case 0:  return "zero";
        case 1:  return "at";
        case 2:  return "v0";
        case 3:  return "v1";
        case 4:  return "a0";
        case 5:  return "a1";
        case 6:  return "a2";
        case 7:  return "a3";
        case 8:  return "t0";
        case 9:  return "t1";
        case 10: return "t2";
        case 11: return "t3";
        case 12: return "t4";
        case 13: return "t5";
        case 14: return "t6";
        case 15: return "t7";
        case 16: return "s0";
        case 17: return "s1";
        case 18: return "s2";
        case 19: return "s3";
        case 20: return "s4";
        case 21: return "s5";
        case 22: return "s6";
        case 23: return "s7";
        case 24: return "t8";
        case 25: return "t9";
        case 26: return "k0";
        case 27: return "k1";
        case 28: return "gp";
        case 29: return "sp";
        case 30: return "fp";
        case 31: return "ra";
      }
    }

};

class MipsOffset : public MipsArgument {

  public:
    int offset;
    int reg;

    MipsOffset(int r, int o) {
      offset = o;
      reg = r;
    }

    std::string toString() {
      std::stringstream ofs;
      ofs << offset << "($" << getRegName(reg) << ")";
      return ofs.str();
    }

    std::string getRegName(int num) {
      switch (num) {
        case 0:  return "zero";
        case 1:  return "at";
        case 2:  return "v0";
        case 3:  return "v1";
        case 4:  return "a0";
        case 5:  return "a1";
        case 6:  return "a2";
        case 7:  return "a3";
        case 8:  return "t0";
        case 9:  return "t1";
        case 10: return "t2";
        case 11: return "t3";
        case 12: return "t4";
        case 13: return "t5";
        case 14: return "t6";
        case 15: return "t7";
        case 16: return "s0";
        case 17: return "s1";
        case 18: return "s2";
        case 19: return "s3";
        case 20: return "s4";
        case 21: return "s5";
        case 22: return "s6";
        case 23: return "s7";
        case 24: return "t8";
        case 25: return "t9";
        case 26: return "k0";
        case 27: return "k1";
        case 28: return "gp";
        case 29: return "sp";
        case 30: return "fp";
        case 31: return "ra";
      }
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
