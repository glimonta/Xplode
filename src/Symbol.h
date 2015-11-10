#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>


#ifndef X_SYMBOL_
#define X_SYMBOL_

#include "AST/TypeDeclaration.h"

/*
   nombre
   tipo (apuntador)
   linea
   columna

*/




class Symbol {

  public:

    std::string name;
    TypeDeclaration *ntype;
    int line;
    bool hidden;
    bool istype;
    int offset;
    int column;
    bool porref;
    bool isarg;
    int offset_stack;


    /* define defined
       0 variable
       1 primitives
       2 type
       3 union
       4 function
       5 proc
       */

    Symbol(bool h, std::string n, TypeDeclaration *t, int l, int c,bool i, bool pr=false){

      name=n;
      ntype = t;
      line = l;
      column = c;
      offset = 0;
      hidden = h;
      istype = i;
      porref = pr;
      isarg = false;
      //defined = e;
      //dimensions = d;
      //pt = p;

    }

    std::string getname() {return name;}

    bool isByReference() { return porref; }

    bool isArg() { return isarg; }

    void setArg(bool a) { isarg = a; }

    int getOffsetStack() { return offset_stack; }

    void setOffsetStack(int ofs) { offset_stack = ofs; }

};

#endif
