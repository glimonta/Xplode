#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../TAC/Quad.h"
#include "MipsArgument.h"

#define MIN_REGISTER 6
#define MAX_REGISTER 25

#ifndef X_REGALLOC
#define X_REGALLOC

class GeneratorMIPS;

class RegisterAllocator {

  public:

    std::queue<MipsRegister *> free_registers;
    std::map<MipsRegister *, std::vector<std::string> > registers;
    std::map<std::string, MipsRegister *> variables;

    RegisterAllocator();
    void getReg (GeneratorMIPS * generator, Quad * quad, MipsRegister **rd, MipsRegister **rl, MipsRegister **rr);
    MipsRegister * allocate_register(GeneratorMIPS * generator, ExpQuad * exp);
    MipsRegister * allocate_dest_register(GeneratorMIPS * generator, ExpQuad * exp);

};

#endif
