#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "ExpQuad.h"
#include "../MIPS/MipsInstruction.h"
#include "../MIPS/MipsArgument.h"

#ifndef X_QUAD
#define X_QUAD


class Quad {

  public:

    std::string op;
    ExpQuad * result;
    ExpQuad * arg1;
    ExpQuad * arg2;

    Quad(){}

    Quad(std::string o, ExpQuad * r, ExpQuad * a1, ExpQuad * a2){
      op = o;
      result = r;
      arg1 = a1;
      arg2 = a2;
    }

    std::string getOp()        { return op;                                         }
    std::string getResultStr() { return (NULL != result) ? result->toString() : ""; }
    std::string getArg1Str()   { return (NULL != arg1)   ? arg1->toString()   : ""; }
    std::string getArg2Str()   { return (NULL != arg2)   ? arg2->toString()   : ""; }
    ExpQuad * getResult()      { return result;                                     }
    ExpQuad * getArg1()        { return arg1;                                       }
    ExpQuad * getArg2()        { return arg2;                                       }

    void setOp(std::string o)   { op = o;    }
    void setResult(ExpQuad * r) { r = r;     }
    void setArg1(ExpQuad * a1)  { arg1 = a1; }
    void setArg2(ExpQuad * a2)  { arg2 = a2; }

    virtual std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class Comment : public Quad {
  public:

    Comment(std::string comment) : Quad(comment, NULL, NULL, NULL) {}

    std::string toString() {
      return "#" + getOp();
    }

};

class BlockComment : public Quad {
  public:

    BlockComment(std::string comment) : Quad(comment, NULL, NULL, NULL) {}

    std::string toString() {
      return "#############################################################\n#"
          + getOp() + "\n"
          + "#############################################################\n\n";
    }

};

class Label : public Quad {
  public:

    Label(std::string comment) : Quad(comment, NULL, NULL, NULL) {}

    std::string toString() {
      return getOp() + ":";
    }

};

class AssignQuad : public Quad {
  public:

    AssignQuad(ExpQuad * r, ExpQuad * a1) : Quad(":=", r, a1, NULL) {}

    std::string toString() {
      return  getResultStr() + " " + getOp() + " " +getArg1Str();
    }

};

class AssignArrayQuad : public Quad {
  public:

    AssignArrayQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad(":=[]", r, a1, a2) {}

    std::string toString() {
      return  getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class AssignToArrayQuad : public Quad {
  public:

    AssignToArrayQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("[]:=", r, a1, a2) {}

    std::string toString() {
      return  getResultStr() + " " + getArg1Str() + " " + getOp() + " " +getArg2Str();
    }

};

class AddQuad : public Quad {
  public:

    AddQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("+", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class SubQuad : public Quad {
  public:

    SubQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("-", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class MulQuad : public Quad {
  public:

    MulQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("*", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class DivQuad : public Quad {
  public:

    DivQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("/", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class ModQuad : public Quad {
  public:

    ModQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("%", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class LessQuad : public Quad {
  public:

    LessQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("<", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class LessEqualQuad : public Quad {
  public:

    LessEqualQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("<=", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class GreaterQuad : public Quad {
  public:

    GreaterQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad(">", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class GreaterEqualQuad : public Quad {
  public:

    GreaterEqualQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad(">=", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class EqualQuad : public Quad {
  public:

    EqualQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("==", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class NotEqualQuad : public Quad {
  public:

    NotEqualQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("!=", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class AndQuad : public Quad {
  public:

    AndQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("&&", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class OrQuad : public Quad {
  public:

    OrQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("||", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class IfQuad : public Quad {
  public:

    IfQuad(ExpQuad * r, ExpQuad * a2) : Quad("if", r, new GotoConstQuad(), a2) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class IfNotQuad : public Quad {
  public:

    IfNotQuad(ExpQuad * r, ExpQuad * a2) : Quad("ifnot", r, new GotoConstQuad(), a2) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class GotoQuad : public Quad {
  public:

    GotoQuad(ExpQuad * r) : Quad("goto", r, NULL, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr();
    }

};

class ParamQuad : public Quad {
  public:

    ParamQuad(ExpQuad * a1) : Quad("param", NULL, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getArg1Str();
    }

};

class ParamRefQuad : public Quad {
  public:

    ParamRefQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("param_ref", r, a1, a2) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class FunctionCallReturn : public Quad {
  public:

    FunctionCallReturn(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("call", r, a1, a2) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str() + " " + getArg2Str();
    }

};

class UnaryMinusQuad : public Quad {
  public:

    UnaryMinusQuad(ExpQuad * r, ExpQuad * a1) : Quad("neg", r, a1, NULL) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str();
    }

};

class NotQuad : public Quad {
  public:

    NotQuad(ExpQuad * r, ExpQuad * a1) : Quad("not", r, a1, NULL) {}

    std::string toString() {
      return getResultStr() + " " + getOp() + " " + getArg1Str();
    }

};

class CastQuad : public Quad {
  public:

    CastQuad(std::string o, ExpQuad * r, ExpQuad * a1) : Quad(o, r, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str();
    }

};

class WriteQuad : public Quad {
  public:

    WriteQuad(ExpQuad * r, ExpQuad * a1) : Quad("write", r, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str();
    }

};

class ReadQuad : public Quad {
  public:

    ReadQuad(ExpQuad * r, ExpQuad * a1) : Quad("read", r, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str();
    }

};

class SleepQuad : public Quad {
  public:

    SleepQuad(ExpQuad * r) : Quad("sleep", r, NULL, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr();
    }

};

class ReturnQuad : public Quad {
  public:

    ReturnQuad() : Quad("return", NULL, NULL, NULL) {}

    std::string toString() {
      return getOp();
    }

};

class ReturnExpQuad : public Quad {
  public:

    ReturnExpQuad(ExpQuad * r) : Quad("return", r, NULL, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr();
    }

};

class ExitQuad : public Quad {
  public:

    ExitQuad() : Quad("exit", NULL, NULL, NULL) {}

    std::string toString() {
      return getOp();
    }

};

class DerefQuad : public Quad {
  public:

    DerefQuad(ExpQuad * r, ExpQuad * a1) : Quad("=*", r, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str();
    }

};

class RefQuad : public Quad {
  public:

    RefQuad(ExpQuad * r, ExpQuad * a1) : Quad("*=", r, a1, NULL) {}

    std::string toString() {
      return getOp() + " " + getResultStr() + " " + getArg1Str();
    }

};

class DeclQuad : public Quad {
  public:

    DeclQuad(ExpQuad * r, ExpQuad * a1, ExpQuad * a2) : Quad("glob_decl", r, a1, a2) {}

    std::string toString() {
      return "";
    }

};

class AllocateStackQuad : public Quad {
  public:

    AllocateStackQuad(ExpQuad * r) : Quad("allocate", r, NULL, NULL) {}

    std::string toString() {
      return  getOp() + " " + getResultStr();
    }

};

#endif
