#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"

#ifndef X_BLOCKTAC
#define X_BLOCKTAC

class BlockTAC {

  public:

    std::vector<Quad *> *instructions;

    BlockTAC() {
      instructions = new std::vector<Quad *>;
    }

    void addQuad(Quad *q) {
      instructions->push_back(q);
    }

    std::string toString() {
      std::stringstream toString;

      for (int i = 0; i < instructions->size(); ++i) {
        toString << ((*instructions)[i])->toString();
      }

      return toString.str();

    }

};

#endif
