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

    Comment(std::string comment) {
      op = comment;
    }

    std::string toString() {
      return "#" + getOp();
    }

};

class Label : public Quad {
  public:

    Label(std::string comment) {
      op = comment;
    }

    std::string toString() {
      return getOp() + ":";
    }

};

class BinaryInstruction : public Quad {
  public:

    BinaryInstruction(std::string o, std::string r, std::string a1, std::string a2) {
      op = o;
      result = r;
      arg1 = a1;
      arg2 = a2;
    }

    std::string toString() {
      return getResult() + " := " + getArg1() + " " + getOp() + " " + getArg2();
    }

};

class FunctionCallReturn : public Quad {
  public:

    FunctionCallReturn(std::string o, std::string r, std::string a1, std::string a2) {
      op = o;
      result = r;
      arg1 = a1;
      arg2 = a2;
    }

    std::string toString() {
      return getResult() + " := " + getOp() + " " + getArg1() + " " + getArg2();
    }

};

class NoArg1Instruction : public Quad {
  public:

    NoArg1Instruction(std::string o, std::string r, std::string a2) {
      op = o;
      result = r;
      arg2 = a2;
    }

    std::string toString() {
      return  getResult() + " " + getOp() + " " +getArg2();
    }

};

class NoArg2Instruction : public Quad {
  public:

    NoArg2Instruction(std::string o, std::string r, std::string a1) {
      op = o;
      result = r;
      arg1 = a1;
    }

    std::string toString() {
      return getResult() + " " + getOp() + " " + getArg1();
    }

};

class NoResultInstruction : public Quad {
  public:

    NoResultInstruction(std::string o, std::string a1, std::string a2) {
      op = o;
      arg1 = a1;
      arg2 = a2;
    }

    std::string toString() {
      return getOp() + " " + getArg1() + " " + getArg2();
    }

};

class OneArgInstruction : public Quad {
  public:

    OneArgInstruction(std::string o, std::string a1) {
      op = o;
      arg1 = a1;
    }

    std::string toString() {
      return getOp() + " " + getArg1();
    }

};

class ResultInstruction : public Quad {
  public:

    ResultInstruction(std::string o, std::string r) {
      op = o;
      result = r;
    }

    std::string toString() {
      return getOp() + " " + getResult();
    }

};


#endif
