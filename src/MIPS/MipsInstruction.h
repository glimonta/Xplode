#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "MipsArgument.h"

#ifndef X_MIPSINSTRUCTION
#define X_MIPSINSTRUCTION


class MipsInstruction {

  public:

    std::string op;
    MipsArgument * result;
    MipsArgument * arg1;
    MipsArgument * arg2;

    MipsInstruction(){}

    MipsInstruction(std::string o, MipsArgument * r, MipsArgument * a1, MipsArgument * a2){
      op = o;
      result = r;
      arg1 = a1;
      arg2 = a2;
    }

    std::string getOp()     { return op;     }
    MipsArgument * getResult() { return result; }
    MipsArgument * getArg1()   { return arg1;   }
    MipsArgument * getArg2()   { return arg2;   }

    void setOp(std::string o)     { op = o;    }
    void setResult(MipsArgument * r) { r = r;     }
    void setArg1(MipsArgument * a1)  { arg1 = a1; }
    void setArg2(MipsArgument * a2)  { arg2 = a2; }

    virtual std::string toString() {
      return getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }
};

class AddMips : public MipsInstruction {

  public:

    AddMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("add", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class AddiMips : public MipsInstruction {

  public:

    AddiMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("addi", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class AndMips : public MipsInstruction {

  public:

    AndMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("and", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class BranchEqualMips : public MipsInstruction {

  public:

    BranchEqualMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("beq", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class BranchGreaterEqualZeroMips : public MipsInstruction {

  public:

    BranchGreaterEqualZeroMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("beqz", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class BranchGreaterZeroMips : public MipsInstruction {

  public:

    BranchGreaterZeroMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("bgtz", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class BranchLessEqualZeroMips : public MipsInstruction {

  public:

    BranchLessEqualZeroMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("blez", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class BranchLessZeroMips : public MipsInstruction {

  public:

    BranchLessZeroMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("bltz", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class BranchNotEqualMips : public MipsInstruction {

  public:

    BranchNotEqualMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("bne", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class DivMips : public MipsInstruction {

  public:

    DivMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("div", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class JumpMips : public MipsInstruction {

  public:

    JumpMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("j", r, NULL, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString();
    }

};

class JumpRegisterMips : public MipsInstruction {

  public:

    JumpRegisterMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("jr", r, NULL, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString();
    }

};

class LoadByteMips : public MipsInstruction {

  public:

    LoadByteMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("lb", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class LoadAddressMips : public MipsInstruction {

  public:

    LoadAddressMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("la", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class LoadImmMips : public MipsInstruction {

  public:

    LoadImmMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("li", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class LoadWordMips : public MipsInstruction {

  public:

    LoadWordMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("lw", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class MoveMips : public MipsInstruction {

  public:

    MoveMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("mfhi", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class MoveFromHighMips : public MipsInstruction {

  public:

    MoveFromHighMips(MipsArgument * r) : MipsInstruction("mfhi", r, NULL, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString();
    }

};

class MoveFromLowMips : public MipsInstruction {

  public:

    MoveFromLowMips(MipsArgument * r) : MipsInstruction("mflo", r, NULL, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString();
    }

};

class MultMips : public MipsInstruction {

  public:

    MultMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("mult", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class OrMips : public MipsInstruction {

  public:

    OrMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("or", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class StoreByteMips : public MipsInstruction {

  public:

    StoreByteMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("sb", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class SubMips : public MipsInstruction {

  public:

    SubMips(MipsArgument * r, MipsArgument * a1, MipsArgument * a2) : MipsInstruction("sub", r, a1, a2) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString() + " " + getArg2()->toString();
    }

};

class StoreWordMips : public MipsInstruction {

  public:

    StoreWordMips(MipsArgument * r, MipsArgument * a1) : MipsInstruction("sw", r, a1, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResult()->toString() + " " + getArg1()->toString();
    }

};

class SyscallMips : public MipsInstruction {

  public:

    SyscallMips() : MipsInstruction("syscall", NULL, NULL, NULL) {}

    std::string toString() {
      return  getOp();
    }

};

class LabelMips : public MipsInstruction {

  public:

    LabelMips(std::string op) : MipsInstruction(op, NULL, NULL, NULL) {}

    std::string toString() {
      return  getOp() + ":";
    }

};

class CommentMips : public MipsInstruction {

  public:

    CommentMips(std::string op) : MipsInstruction(op, NULL, NULL, NULL) {}

    std::string toString() {
      return  "#" + getOp();
    }

};

#endif
