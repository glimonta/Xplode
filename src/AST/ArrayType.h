#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "TypeDeclaration.h"

#ifndef X_ARRAYTYPE
#define X_ARRAYTYPE

class ArrayType : public TypeDeclaration {

  public:

    int limit;

    ArrayType(Node *n, int lim){

      ntype = (TypeDeclaration *) n;
      size = lim*ntype->size;
      numtype = TYPE_ARRAY;
      limit = lim;

    }

    void print(int tab){}

    std::vector<int>* findDimensions() {
      std::vector<int>* dims;

      if (ntype->isarray()) {
        ArrayType * array = (ArrayType *) ntype;
        dims = array->findDimensions();
        dims->push_back(limit);
      } else {
        dims = new std::vector<int>;
        dims->push_back(limit);
      }

      return dims;
    }


};

#endif
