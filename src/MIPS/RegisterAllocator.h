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

    //struct LocationEntry {
    //  int type; //1 es reg, 2 es stack, 3 es mem
    //  union Location {
    //    MipsRegister * reg;
    //    MipsOffset * stack;
    //    std::string * mem;
    //  } loc;
    //};

    //std::queue<MipsRegister *> free_registers;
    //std::map<MipsRegister *, std::vector<std::string> > registers;
    //std::map<std::string, std::vector<LocationEntry> > variables;

    std::queue<MipsRegister *> free_registers;
    std::map<std::string, MipsRegister *> registers;
    std::map<std::string, VarQuad *> variables;

    RegisterAllocator();
    void getReg (GeneratorMIPS * generator, Quad * quad, MipsRegister **rd, MipsRegister **rl, MipsRegister **rr);
    MipsRegister * allocate_register(GeneratorMIPS * generator, ExpQuad * exp);
    MipsRegister * allocate_dest_register(GeneratorMIPS * generator, ExpQuad * exp);

    //MipsRegister * find_register_location(std::vector<LocationEntry> variables);

  //void add_to_register_descriptor(MipsRegister * r, std::string var);
  //void replace_register_descriptor(MipsRegister * r, std::vector<std::string> vars);
  //void add_to_variable_descriptor(std::string var, LocationEntry l);
  //void replace_variable_descriptor(std::string var, std::vector<LocationEntry> locs);
  //void delete_from_register_descriptor(MipsRegister * r, std::string var);
  //void delete_from_variable_descriptor(std::string v, LocationEntry l);
  MipsRegister * getAuxReg();
  void clear();
  void flush(GeneratorMIPS * generator);

};

#endif
