
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../Symbol.h"
#include "../TAC/GeneratorTAC.h"


#ifndef X_NODE
#define X_NODE


class Node {
  public:
    int line;
    int column;

    virtual ~Node () {}

    int getLine()      { return line;   }
    int getColumn()    { return column; }

    std::string getLineStr()   {
      std::ostringstream aux;
      aux << line;
      return aux.str();
    }

    //virtual Node *clone() = 0;

    virtual void print(int tab) = 0;

    virtual std::string generateTAC(GeneratorTAC *generator) {}

};


#endif
