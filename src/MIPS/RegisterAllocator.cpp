#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "RegisterAllocator.h"
#include "../TAC/Quad.h"
#include "GeneratorMIPS.h"


RegisterAllocator::RegisterAllocator() {
  for (int i = MIN_REGISTER; i <= MAX_REGISTER; ++i) {
    free_registers.push(new MipsRegister(i));
  }
}

void RegisterAllocator::getReg (GeneratorMIPS * generator, Quad * quad, MipsRegister **rd, MipsRegister **rl, MipsRegister **rr) {
  //Determinar registros para todas las expresiones
  if (quad->getArg1() && rl) *rl = allocate_register(generator, quad->getArg1());
  if (quad->getArg2() && rr) *rr = allocate_register(generator, quad->getArg2());
  if (quad->getResult() && rd && (rl || rr)) {
    *rd = allocate_dest_register(generator, quad->getResult());
  } else {
    *rd = allocate_register(generator, quad->getResult());
  }

  if (rd && quad->getResult()->isconstant()) free_registers.push(*rd);
  if (rl && quad->getArg1()->isconstant()) free_registers.push(*rl);
  if (rr && quad->getArg2()->isconstant()) free_registers.push(*rr);
}

MipsRegister * RegisterAllocator::allocate_register(GeneratorMIPS * generator, ExpQuad * exp) {
  //Caso simple 1: La expresión es una constante y no puede estar en un registro ya
  //Falta considerar caso donde no hayan registros libres
  if (exp->isconstant()) {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    ConstQuad * c = (ConstQuad *) exp;
    generator->gen(new LoadImmMips(r, new MipsImmediate(c->num)));
    return r;
  }

  // Caso simple: Ya está en un registro
  VarQuad * var = (VarQuad *) exp;
  if(variables.count(var->vname) != 0) {
    MipsRegister *r = find_register_location(variables[var->vname]);
    //if (variables[var->vname]->istemporal()) {
    //  free_registers.push(r);
    //  variables.erase(var->vname);
    //  registers.erase(var->vname);
    //}

    return r;
  } else {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    registers[r].push_back(var->vname);
    Location l;
    l.reg = r;
    variables[var->vname].push_back(l);

    if (var->offset != NO_OFFSET) {

      if (var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
        return r;
      }

      generator->gen(new LoadImmMips(r, new MipsImmediate(var->offset)));

      generator->gen(new AddMips(r, r, ((var->is_ref) ? FP_REGISTER : SP_REGISTER)));

      generator->gen(new LoadWordMips(r, new MipsOffset(r->num, 0)));
      //FIXME esto capaz es 4

      if ((var->is_ref) && (var->typenum != 8)) {
        generator->gen(new LoadWordMips(r, new MipsOffset(0, r->num)));
      }

    } else {
      if (var->is_string || var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
      }
    }


    return r;
  //TODO caso en donde no está en algun registro
  }
}


MipsRegister * RegisterAllocator::allocate_dest_register(GeneratorMIPS * generator, ExpQuad * exp) {
  //Caso simple 1: La expresión es una constante y no puede estar en un registro ya
  //Falta considerar caso donde no hayan registros libres
  if (exp->isconstant()) {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    //registers[r] = "";
    ConstQuad * c = (ConstQuad *) exp;
    generator->gen(new LoadImmMips(r, new MipsImmediate(c->num)));
    return r;
  }

  // Caso simple: Ya está en un registro
  VarQuad * var = (VarQuad *) exp;
  if(variables.count(var->vname) != 0) {
    MipsRegister *r = find_register_location(variables[var->vname]);
    //if (variables[var->vname]->istemporal()) {
    //  free_registers.push(r);
    //  variables.erase(var->vname);
    //  registers.erase(var->vname);
    //}

    if (var->offset != NO_OFFSET) {

      if (var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
        return r;
      }

      generator->gen(new LoadImmMips(r, new MipsImmediate(var->offset)));

      generator->gen(new AddMips(r, r, ((var->is_ref) ? FP_REGISTER : SP_REGISTER)));

      generator->gen(new LoadAddressMips(r, new MipsOffset(r->num, 0)));
      //FIXME esto capaz es 4

      if ((var->is_ref) && (var->typenum != 8)) {
        generator->gen(new LoadWordMips(r, new MipsOffset(0, r->num)));
      }

    } else {
      if (var->is_string || var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
      }
    }

    return r;
  } else {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    registers[r].push_back(var->vname);
    Location l;
    l.reg = r;
    variables[var->vname].push_back(l);

    if (var->offset != NO_OFFSET) {

      if (var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
        return r;
      }

      generator->gen(new LoadImmMips(r, new MipsImmediate(var->offset)));

      generator->gen(new AddMips(r, r, ((var->is_ref) ? FP_REGISTER : SP_REGISTER)));

      if ((var->is_ref) && (var->typenum != 8)) {
        generator->gen(new LoadWordMips(r, new MipsOffset(0, r->num)));
      }

    } else {
      if (var->is_string || var->is_glob) {
        generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
      }
    }

    return r;
  }
}

  MipsRegister * RegisterAllocator::find_register_location(std::vector<Location> variables) {
    for(std::vector<Location>::iterator i = variables.begin(); i != variables.end(); ++i) {
      if (NULL != (*i).reg) {
        return (*i).reg;
      }
    }
    return NULL;
  }

