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
  } else if (quad->getResult() && rd) {
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
  //MipsRegister * r = find_register_location(variables[var->vname]);
  //if(r) {
  if (registers.count(var->vname) != 0) {
    MipsRegister * r = registers[var->vname];
    //if (variables[var->vname]->istemporal()) {
    //  free_registers.push(r);
    //  variables.erase(var->vname);
    //  registers.erase(var->vname);
    //}

    return r;
  } else {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    //LocationEntry l;
    //l.type = 1;
    //l.loc.reg = r;
    //std::vector<std::string> vars;
    //vars.push_back(var->vname);
    //replace_register_descriptor(r,vars);
    //add_to_variable_descriptor(var->vname, l);
    registers[var->vname] = r;

    if (var->offset != NO_OFFSET) {


      generator->gen(new LoadImmMips(r, new MipsImmediate(var->offset)));

      if (var->is_glob) {
        MipsRegister * raux = getAuxReg();
        generator->gen(new LoadAddressMips(raux, new MipsVariable(var->vname)));
        generator->gen(new AddMips(r, r, raux));
      } else {
        generator->gen(new AddMips(r, r, ((var->is_arg) ? FP_REGISTER : SP_REGISTER)));
      }

      generator->gen(new LoadWordMips(r, new MipsOffset(r->num, 4)));
      //FIXME esto capaz es 4

      if ((var->is_ref) && (var->typenum != 8)) {
        generator->gen(new LoadWordMips(r, new MipsOffset(r->num, 0)));
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
  //MipsRegister * r = find_register_location(variables[var->vname]);
  //if(r) {
  if (registers.count(var->vname) != 0) {
    MipsRegister * r = registers[var->vname];
    //if (variables[var->vname]->istemporal()) {
    //  free_registers.push(r);
    //  variables.erase(var->vname);
    //  registers.erase(var->vname);
    //}

    return r;
  } else {
    MipsRegister * r = free_registers.front();
    free_registers.pop();
    //LocationEntry l;
    //l.type = 1;
    //l.loc.reg = r;
    //std::vector<std::string> vars;
    //vars.push_back(var->vname);
    //replace_register_descriptor(r,vars);
    //add_to_variable_descriptor(var->vname, l);

    registers[var->vname] = r;

    //if (var->offset != NO_OFFSET) {


    //  generator->gen(new LoadImmMips(r, new MipsImmediate(var->offset)));

    //  if (var->is_glob) {
    //    MipsRegister * raux = getAuxReg();
    //    free_registers.pop();
    //    generator->gen(new LoadAddressMips(raux, new MipsVariable(var->vname)));
    //    generator->gen(new AddMips(r, r, raux));
    //  } else {
    //    generator->gen(new AddMips(r, r, ((var->is_ref) ? FP_REGISTER : SP_REGISTER)));
    //  }

    //  if ((var->is_ref) && (var->typenum != 8)) {
    //    generator->gen(new LoadWordMips(r, new MipsOffset(0, r->num)));
    //  }

    //} else {
    //  if (var->is_string || var->is_glob) {
    //    generator->gen(new LoadAddressMips(r, new MipsVariable(var->vname)));
    //  }
    //}


    return r;
  //TODO caso en donde no está en algun registro
  }
}

  //MipsRegister * RegisterAllocator::find_register_location(std::vector<LocationEntry> variables) {
  //  for(std::vector<LocationEntry>::iterator i = variables.begin(); i != variables.end(); ++i) {
  //    if (1 == (*i).type) {
  //      return (*i).loc.reg;
  //    }
  //  }
  //  return NULL;
  //}

  //void RegisterAllocator::add_to_register_descriptor(MipsRegister * r, std::string var) {
  //  registers[r].push_back(var);
  //}

  //void RegisterAllocator::replace_register_descriptor(MipsRegister * r, std::vector<std::string> vars) {
  //  registers[r] = vars;
  //}

  //void RegisterAllocator::add_to_variable_descriptor(std::string var, LocationEntry l) {
  //  variables[var].push_back(l);
  //}

  //void RegisterAllocator::replace_variable_descriptor(std::string var, std::vector<LocationEntry> locs) {
  //  variables[var] = locs;
  //}

  //void RegisterAllocator::delete_from_register_descriptor(MipsRegister * r, std::string var) {
  //  for (std::vector<std::string>::iterator i = registers[r].begin(); i != registers[r].end(); ++i) {
  //    if ((*i) == var) {
  //      registers[r].erase(i);
  //    }
  //  }
  //}

  //void RegisterAllocator::delete_from_variable_descriptor(std::string v, LocationEntry l) {
  //  for (std::vector<LocationEntry>::iterator i = variables[v].begin(); i != variables[v].end(); ++i) {
  //    if ((*i).type == l.type) {
  //      switch (l.type) {
  //        case 1:
  //          if ((*i).loc.reg->num == l.loc.reg->num)
  //            variables[v].erase(i);
  //        case 2:
  //          if (((*i).loc.stack->reg == l.loc.stack->reg) && ((*i).loc.stack->offset == l.loc.stack->offset))
  //            variables[v].erase(i);
  //        case 3:
  //          if (*((*i).loc.mem) == *(l.loc.mem))
  //            variables[v].erase(i);
  //      }
  //    }
  //  }
  //}

  MipsRegister * RegisterAllocator::getAuxReg() {
    return free_registers.front();
  }

  void RegisterAllocator::clear() {}

  void RegisterAllocator::flush(GeneratorMIPS * generator) {}


