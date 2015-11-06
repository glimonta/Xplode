#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_QUAD
#define X_QUAD


class Quad {

  public:

    std::string op;
    std::string result;
    std::string arg1;
    std::string arg2;

    Quad(){}

    Quad(std::string o, std::string r, std::string a1, std::string a2){
      op = o;
      result = r;
      arg1 = a1;
      arg2 = a2;
    }

    std::string getOp()     { return op;     }
    std::string getResult() { return result; }
    std::string getArg1()   { return arg1;   }
    std::string getArg2()   { return arg2;   }

    void setOp(std::string o)     { op = o;    }
    void setResult(std::string r) { r = r;     }
    void setArg1(std::string a1)  { arg1 = a1; }
    void setArg2(std::string a2)  { arg2 = a2; }

    virtual std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1() + " " + getArg2();
    }
};

class Comment : public Quad {
  public:

    Comment(std::string comment) : Quad(comment, "", "", "") {}

    std::string toString() {
      return "#" + getOp();
    }

};

class Label : public Quad {
  public:

    Label(std::string comment) : Quad(comment, "", "", "") {}

    std::string toString() {
      return getOp() + ":";
    }

};

class AssignQuad : public Quad {
  public:

    AssignQuad(std::string r, std::string a1) : Quad(":=", r, a1, "") {}

    std::string toString() {
      return  getResult() + " " + getOp() + " " +getArg1();
    }

};

class AssignArrayQuad : public Quad {
  public:

    AssignArrayQuad(std::string r, std::string a1, std::string a2) : Quad(":=[]", r, a1, a2) {}

    std::string toString() {
      return  getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class AssignToArrayQuad : public Quad {
  public:

    AssignToArrayQuad(std::string r, std::string a1, std::string a2) : Quad("[]:=", r, a1, a2) {}

    std::string toString() {
      return  getResult() + " " + getArg1() + " " + getOp() + " " +getArg2();
    }

};

class AddQuad : public Quad {
  public:

    AddQuad(std::string r, std::string a1, std::string a2) : Quad("+", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class SubQuad : public Quad {
  public:

    SubQuad(std::string r, std::string a1, std::string a2) : Quad("-", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class MulQuad : public Quad {
  public:

    MulQuad(std::string r, std::string a1, std::string a2) : Quad("*", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class DivQuad : public Quad {
  public:

    DivQuad(std::string r, std::string a1, std::string a2) : Quad("/", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class ModQuad : public Quad {
  public:

    ModQuad(std::string r, std::string a1, std::string a2) : Quad("%", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class LessQuad : public Quad {
  public:

    LessQuad(std::string r, std::string a1, std::string a2) : Quad("<", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class LessEqualQuad : public Quad {
  public:

    LessEqualQuad(std::string r, std::string a1, std::string a2) : Quad("<=", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class GreaterQuad : public Quad {
  public:

    GreaterQuad(std::string r, std::string a1, std::string a2) : Quad(">", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class GreaterEqualQuad : public Quad {
  public:

    GreaterEqualQuad(std::string r, std::string a1, std::string a2) : Quad(">=", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class EqualQuad : public Quad {
  public:

    EqualQuad(std::string r, std::string a1, std::string a2) : Quad("==", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class NotEqualQuad : public Quad {
  public:

    NotEqualQuad(std::string r, std::string a1, std::string a2) : Quad("!=", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class AndQuad : public Quad {
  public:

    AndQuad(std::string r, std::string a1, std::string a2) : Quad("&&", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class OrQuad : public Quad {
  public:

    OrQuad(std::string r, std::string a1, std::string a2) : Quad("||", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class IfQuad : public Quad {
  public:

    IfQuad(std::string r, std::string a2) : Quad("if", r, "goto", a2) {}

    std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1() + " " + getArg2();
    }

};

class IfNotQuad : public Quad {
  public:

    IfNotQuad(std::string r, std::string a2) : Quad("ifnot", r, "goto", a2) {}

    std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1() + " " + getArg2();
    }

};

class GotoQuad : public Quad {
  public:

    GotoQuad(std::string r) : Quad("goto", r, "", "") {}

    std::string toString() {
      return getOp() + " " + getResult();
    }

};

class ParamQuad : public Quad {
  public:

    ParamQuad(std::string a1) : Quad("param", "", a1, "") {}

    std::string toString() {
      return getOp() + " " + getArg1();
    }

};

class ParamRefQuad : public Quad {
  public:

    ParamRefQuad(std::string r, std::string a1, std::string a2) : Quad("param_ref", r, a1, a2) {}

    std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1() + " " + getArg2();
    }

};

class FunctionCallReturn : public Quad {
  public:

    FunctionCallReturn(std::string r, std::string a1, std::string a2) : Quad("call", r, a1, a2) {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class UnaryMinusQuad : public Quad {
  public:

    UnaryMinusQuad(std::string r, std::string a1) : Quad("neg", r, a1, "") {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1();
    }

};

class NotQuad : public Quad {
  public:

    NotQuad(std::string r, std::string a1) : Quad("not", r, a1, "") {}

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1();
    }

};

class CastQuad : public Quad {
  public:

    CastQuad(std::string o, std::string r, std::string a1) : Quad(o, r, a1, "") {}

    std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1();
    }

};

class WriteQuad : public Quad {
  public:

    WriteQuad(std::string r) : Quad("write", r, "", "") {}

    std::string toString() {
      return getOp() + " " + getResult();
    }

};

class ReadQuad : public Quad {
  public:

    ReadQuad(std::string r, std::string a1) : Quad("read", r, a1, "") {}

    std::string toString() {
      return getOp() + " " + getResult() + " " + getArg1();
    }

};

class SleepQuad : public Quad {
  public:

    SleepQuad(std::string r) : Quad("sleep", r, "", "") {}

    std::string toString() {
      return getOp() + " " + getResult();
    }

};

class ReturnQuad : public Quad {
  public:

    ReturnQuad() : Quad("return", "", "", "") {}

    std::string toString() {
      return getOp();
    }

};

class ReturnExpQuad : public Quad {
  public:

    ReturnExpQuad(std::string r) : Quad("return", r, "", "") {}

    std::string toString() {
      return getOp() + " " + getResult();
    }

};

class ExitQuad : public Quad {
  public:

    ExitQuad() : Quad("exit", "", "", "") {}

    std::string toString() {
      return getOp();
    }

};

#endif
