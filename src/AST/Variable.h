#ifndef X_VARIABLEEXP
#define X_VARIABLEEXP

#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "ArrayType.h"
#include "TupleType.h"
#include "../SymTable.h"
#include "../ErrorLog.h"
#include "../Token.h"

extern ErrorLog *errorlog;

class Variable : public Expression {
  public:

    std::list<Xplode::Token *> *varList;
    std::list<std::pair<int, Expression *> > *indexList;

    Variable(Xplode::Token *v){
      varList = new std::list<Xplode::Token *>;
      indexList = new std::list<std::pair<int, Expression *> >;
      varList->push_back(v);
    }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "VARIABLE\n";
      for(std::list<Xplode::Token *>::iterator iter = varList->begin();
          iter != varList->end(); ++iter){

        std::cout << std::string(tab, ' ') << "field: " << (*iter)->value << "\n";
      }
      for(std::list<std::pair<int, Expression *> >::iterator iter = indexList->begin();
          iter != indexList->end(); ++iter){

        std::cout << std::string(tab, ' ') << "index: " << (*iter).first <<"|"<<"\n";
        iter->second->print(tab+2);
      }
    }

    void addIndex(Expression *exp){
      indexList->push_back(std::make_pair(0, exp));
    }

    void concat(Variable *v){

      varList->push_back(*v->varList->begin());

      std::list<std::pair<int, Expression *> >::iterator it;

      for(it=v->indexList->begin(); it != v->indexList->end();++it){

        indexList->push_back(std::make_pair(varList->size()-1, (*it).second));

      }


    }

    void firstcheck(SymTable *symtb){

      /*   Symbol *tempsymv, *tempsymt=NULL;
           SymTable *temptb = symtb;
           std::string arrstr[3];
           std::list<Xplode::Token *>::iterator itvar;
           std::list<std::pair<int, Expression *> >::iterator itindex;
           int index=0, dim,i,tam;
           Xplode::Token *auxtk;
           tam = varList->size()-1;
           itvar = varList->begin();
           itindex = indexList->begin();

           while(true){

           tempsymv = temptb->find((*itvar)->value);

           if(tempsymv==NULL) {//sin declarar en ningun ambito, campo incorrecto

           if(!tempsymt){
           errorlog->addError(8,(*itvar)->line,(*itvar)->column,&(*itvar)->value);
           }else{
           arrstr[0] = (*itvar)->value;
           arrstr[1] = tempsymt->name;
           arrstr[2] = tempsymt->ntype;
           errorlog->addError(9,(*itvar)->line,(*itvar)->column,arrstr);
           }
           return;
           }

           dim = tempsymv->dimensions;
           i=0;
           while ((itindex!=indexList->end())&&(itindex->first==index)){

           ++itindex;
           ++i;
           }

           if((index!=tam)&&(i!=dim)) { //index malo

           errorlog->addError(10, (*itvar)->line, (*itvar)->column, &(*itvar)->value);
           return;
           }

           if(i>dim) { //ultimo posee mas [] de lo maximo

           errorlog->addError(10, (*itvar)->line, (*itvar)->column, &(*itvar)->value);
           return;
           }

           tempsymt = temptb->find(tempsymv->ntype);

           if(tempsymt==NULL){ //no consiguio el tipo

           arrstr[0] = (*itvar)->value;
           arrstr[1] = tempsymt->name;
           errorlog->addError(7, tempsymv->line, tempsymv->line, arrstr);
           return;
           }

           ++index;
           auxtk = *itvar;
           ++itvar;
           temptb = (SymTable *) tempsymt->pt;

           if(!temptb){  // primitivo o arreglo

           if((itvar==varList->end())&&(itindex==indexList->end())){

           return; //correcto
           } else { //mal tipo para .

           errorlog->addError(11,auxtk->line,auxtk->column, &tempsymt->name);
      return;
    }
    } else {

      if (itvar==varList->end()){ //faltan campos


        //errorlog->addError(12, 0, 0, &tempsymt->name);
        return;
      }


    }


    }

    // (){std::cout << std::string(tab, ' ') << "Declarada "<<*varList->begin()<<"\n";}
    // else {std::cout << std::string(tab, ' ') << "No declarada "<<*varList->begin()<<"\n";}
    */
    }

    std::string toString(SymTable *table) {
      if (varList->size() == 1 && indexList->size() == 0) {
        return varList->front()->value;
      } else {
        std::list<Xplode::Token *>::iterator vnames;
        std::list<std::pair<int, Expression *> >::iterator indexes;
        vnames = varList->begin();
        indexes = indexList->begin();
        Symbol *var = table->find(varList->front()->value);
        TypeDeclaration *type = var->ntype;
        std::stringstream finalStr;
        finalStr << var->name;

        while (vnames != varList->end()) {
          if (type->isarray()) {
            ArrayType* array = (ArrayType *) type;
            finalStr << "[" << indexes->second->toString(table) << "]";
            ++indexes;
            type = array->ntype;
            std::vector<int>* dimensions = array->findDimensions();

            for (int i=1; i<dimensions->size(); ++i) {
              finalStr << "[" << indexes->second->toString(table) << "]";
              type = type->ntype;
            }
          } else if (type->haveattributes()) {
            ++vnames;
            TupleType * tuple = (TupleType *) type;
            std::pair<TypeDeclaration*, int> *attribute = tuple->findAttribute((*vnames)->value);

            finalStr << "." << (*vnames)->value;
            type = attribute->first;
          } else {
            ++vnames;
          }
        }
        return finalStr.str();
        //FIXME
        // Ahorita solo se considera el caso donde está una variable sola.
      // No se han considerado ninguno de los casos especiales.
      }
    }

    ExpQuad * generateTAC(GeneratorTAC *generator, SymTable *table) {
      if (varList->size() == 1 && indexList->size() == 0) {
        std::string var(varList->front()->value);
        std::transform(var.begin(), var.end(), var.begin(), ::tolower);
        Symbol * v = table->find(var);
        return new VarQuad(var, v->offset, v->porref, v->isarg, v->ntype->size, v->ntype->numtype, false, v->isglob);
      }

      std::list<Xplode::Token *>::iterator vnames;
      std::list<Xplode::Token *>::iterator vnamesaux;
      std::list<std::pair<int, Expression *> >::iterator indexes;

      vnames = varList->begin();
      vnamesaux = varList->begin();
      ++vnamesaux;
      indexes = indexList->begin();
      ExpQuad * res;

      Symbol *base = table->find((*vnames)->value);
      res = NULL;
      TypeDeclaration *type = base->ntype;

      while (vnames != varList->end()) {
        if (type->isarray()) {

          if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

          if (base->isByReference()) {
            Comment * comment = new Comment ("Aquí va el acceso a un arreglo que es por referencia ==> dope vector");
            generator->gen(comment);

            ArrayType* array = (ArrayType *) type;
            std::vector<int>* dimensions = array->findDimensions();

            ExpQuad * res_fin = res;

            res = indexes->second->generateTAC(generator, table);
            ++indexes;
            type = array->ntype;

            // Esto va a estar en el dope vector
            // bp + 4 (return address) + 4 (tamaño de un elemento) + 4 (numero dimensiones) + 4 * num_dims + 4 (offset de los datos)
            int offset_tam = base->getOffsetStack();
            int offset_num_dims = offset_tam + 4;
            int offset_datos = offset_num_dims;
            for (int i = 1; i < dimensions->size(); ++i) offset_datos += 4; // por cada dimension sumo 4
            offset_datos += 4; // Desplazamiento final para donde están los datos (dirección)


            for (int i=1; i<dimensions->size(); ++i) {

              if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

              std::stringstream toString;
              toString << offset_num_dims + 4 + (4 * i); // El primer 4 es por la primera dimension que no se usa
              ConstQuad * arg2 = new ConstQuad(offset_num_dims + 4 + (4 * i));
              VarQuad * bp = new VarQuad("bp");
              AddQuad * add = new AddQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), bp, arg2);
              generator->gen(add);
              VarQuad * dimension = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              DerefQuad * deref = new DerefQuad(dimension, add->getResult());
              generator->gen(deref);
              VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              MulQuad *mult = new MulQuad(result, res, deref->getResult());
              generator->gen(mult);
              res = mult->result;

              ExpQuad * arg = indexes->second->generateTAC(generator, table);
              ++indexes;
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              add = new AddQuad(result, res, arg);
              generator->gen(add);
              res = add->result;

              type = type->ntype;
            }

            std::stringstream toString;
            toString << offset_tam;
            ConstQuad * size = new ConstQuad(offset_tam);
            VarQuad * bp = new VarQuad("bp");
            AddQuad * add = new AddQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), bp, size);
            generator->gen(add);
            DerefQuad * deref = new DerefQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), add->getResult());
            generator->gen(deref);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            MulQuad * mult = new MulQuad(result, res, deref->getResult());
            generator->gen(mult);
            res = mult->result;

            if (NULL != res_fin) {
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad * add = new AddQuad(result, res, res_fin);
              generator->gen(add);
              res = add->result;
            }

          } else {

            ArrayType* array = (ArrayType *) type;
            std::vector<int>* dimensions = array->findDimensions();

            ExpQuad * res_fin = res;

            res = indexes->second->generateTAC(generator, table);
            ++indexes;
            type = array->ntype;

            for (int i=1; i<dimensions->size(); ++i) {

              if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

              std::stringstream toString;
              toString << (*dimensions)[i];
              ConstQuad * arg2 = new ConstQuad((*dimensions)[i]);
              VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              MulQuad *mult = new MulQuad(result, res, arg2);
              generator->gen(mult);
              res = mult->result;

              ExpQuad * arg = indexes->second->generateTAC(generator, table);
              ++indexes;
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad *add = new AddQuad(result, res, arg);
              generator->gen(add);
              res = add->result;

              type = type->ntype;
            }

            std::stringstream toString;
            toString << type->size;
            ConstQuad * size = new ConstQuad(type->size);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            MulQuad * mult = new MulQuad(result, res, size);
            generator->gen(mult);
            res = mult->result;

            if (NULL != res_fin) {
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad * add = new AddQuad(result, res, res_fin);
              generator->gen(add);
              res = add->result;
            }
          }
        } else if (type->haveattributes()) {
          ++vnames;
          ++vnamesaux;

          if ((vnames ==varList->end()) && (indexes == indexList->end())) break;

          TupleType * tuple = (TupleType *) type;
          std::pair<TypeDeclaration*, int> *attribute = tuple->findAttribute((*vnames)->value);

          if (NULL == res) {
            std::stringstream toString;
            toString << attribute->second;
            res = new ConstQuad(attribute->second);
          } else {
            std::stringstream toString;
            toString << attribute->second;
            ConstQuad * size = new ConstQuad(attribute->second);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            AddQuad * add = new AddQuad(result, res, size);
            generator->gen(add);
            res = add->result;
          }
          type = attribute->first;
        } else {
          ++vnames;
          ++vnamesaux;
        }
      }

      ExpQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      VarQuad * basevar = new VarQuad(base->name, base->offset, base->porref, base->isarg, base->ntype->size, base->ntype->numtype, false, base->isglob);
      AssignArrayQuad *assign = new AssignArrayQuad(result, basevar, res);
      generator->gen(assign);

      return result;

      //FIXME
      // Ahorita solo se considera el caso donde está una variable sola.
      // No se han considerado ninguno de los casos especiales.
    }

    void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      ExpQuad * res = this->generateTAC(generator, table);

      if ( "fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(res, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(new VarQuad(falseLabel));
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(res, new VarQuad(trueLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(res, new VarQuad(falseLabel));
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    }

    Quad * lval_generateTAC(GeneratorTAC *generator, SymTable *table) {
      if (varList->size() == 1 && indexList->size() == 0) {
        std::string var(varList->front()->value);
        std::transform(var.begin(), var.end(), var.begin(), ::tolower);
        Symbol * v = table->find(var);
        VarQuad * variable = new VarQuad(var, v->offset, v->porref, v->isarg, v->ntype->size, v->ntype->numtype, false, v->isglob);
        return new AssignQuad(variable, NULL);
      }

      std::list<Xplode::Token *>::iterator vnames;
      std::list<Xplode::Token *>::iterator vnamesaux;
      std::list<std::pair<int, Expression *> >::iterator indexes;


      vnames = varList->begin();
      vnamesaux = varList->begin();
      ++vnamesaux;
      indexes = indexList->begin();
      ExpQuad * res;

      Symbol *base = table->find((*vnames)->value);
      res = NULL;
      TypeDeclaration *type = base->ntype;

      while (vnames != varList->end()) {
        if (type->isarray()) {

          if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

          if (base->isByReference()) {
            Comment * comment = new Comment ("Aquí va el acceso a un arreglo que es por referencia ==> dope vector");
            generator->gen(comment);

            ArrayType* array = (ArrayType *) type;
            std::vector<int>* dimensions = array->findDimensions();

            ExpQuad * res_fin = res;

            res = indexes->second->generateTAC(generator, table);
            ++indexes;
            type = array->ntype;

            // Esto va a estar en el dope vector
            // bp + 4 (return address) + 4 (tamaño de un elemento) + 4 (numero dimensiones) + 4 * num_dims + 4 (offset de los datos)
            int offset_tam = base->getOffsetStack();
            int offset_num_dims = offset_tam + 4;
            int offset_datos = offset_num_dims;
            for (int i = 1; i < dimensions->size(); ++i) offset_datos += 4; // por cada dimension sumo 4
            offset_datos += 4; // Desplazamiento final para donde están los datos (dirección)

            for (int i=1; i<dimensions->size(); ++i) {

              if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

              std::stringstream toString;
              toString << offset_num_dims + 4 + (4 * i); // El primer 4 es por la primera dimension que no se usa
              ConstQuad * arg2 = new ConstQuad(offset_num_dims + 4 + (4 * i));
              VarQuad * bp = new VarQuad("bp");
              AddQuad * add = new AddQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), bp, arg2);
              generator->gen(add);
              VarQuad * dimension = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              DerefQuad * deref = new DerefQuad(dimension, add->getResult());
              generator->gen(deref);
              VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              MulQuad *mult = new MulQuad(result, res, deref->getResult());
              generator->gen(mult);
              res = mult->result;

              ExpQuad * arg = indexes->second->generateTAC(generator, table);
              ++indexes;
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              add = new AddQuad(result, res, arg);
              generator->gen(add);
              res = add->result;

              type = type->ntype;
            }


            std::stringstream toString;
            toString << offset_tam;
            ConstQuad * size = new ConstQuad(offset_tam);
            VarQuad * bp = new VarQuad("bp");
            AddQuad * add = new AddQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), bp, size);
            generator->gen(add);
            DerefQuad * deref = new DerefQuad(new VarQuad(generator->labelmaker->getLabel(TEMPORAL)), add->getResult());
            generator->gen(deref);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            MulQuad * mult = new MulQuad(result, res, deref->getResult());
            generator->gen(mult);
            res = mult->result;

            if (NULL != res_fin) {
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad * add = new AddQuad(result, res, res_fin);
              generator->gen(add);
              res = add->result;
            }

          } else {

            ArrayType* array = (ArrayType *) type;
            std::vector<int>* dimensions = array->findDimensions();

            ExpQuad * res_fin = res;

            res = indexes->second->generateTAC(generator, table);
            ++indexes;
            type = array->ntype;

            for (int i=1; i<dimensions->size(); ++i) {
              if ((vnamesaux == varList->end()) && (indexes == indexList->end())) break;

              std::stringstream toString;
              toString << (*dimensions)[i];
              ConstQuad * arg2 = new ConstQuad((*dimensions)[i]);
              VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              MulQuad *mult = new MulQuad(result, res, arg2);
              generator->gen(mult);
              res = mult->result;

              ExpQuad * arg = indexes->second->generateTAC(generator, table);
              ++indexes;
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad *add = new AddQuad(result, res, arg);
              generator->gen(add);
              res = add->result;

              type = type->ntype;
            }


            std::stringstream toString;
            toString << type->size;
            ConstQuad * size = new ConstQuad(type->size);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            MulQuad * mult = new MulQuad(result, res, size);
            generator->gen(mult);
            res = mult->result;

            if (NULL != res_fin) {
              result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
              AddQuad * add = new AddQuad(result, res, res_fin);
              generator->gen(add);
              res = add->result;
            }
          }
        } else if (type->haveattributes()) {
          ++vnames;
          ++vnamesaux;

          if ((vnames == varList->end()) && (indexes == indexList->end())) break;

          TupleType * tuple = (TupleType *) type;
          std::pair<TypeDeclaration*, int> *attribute = tuple->findAttribute((*vnames)->value);

          if (NULL == res) {
            std::stringstream toString;
            toString << attribute->second;
            res = new ConstQuad(attribute->second);
          } else {
            std::stringstream toString;
            toString << attribute->second;
            ConstQuad * size = new ConstQuad(attribute->second);
            VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
            AddQuad * add = new AddQuad(result, res, size);
            generator->gen(add);
            res = add->result;
          }
          type = attribute->first;
        } else {
          ++vnames;
          ++vnamesaux;
        }
      }

      VarQuad * result = new VarQuad(generator->labelmaker->getLabel(TEMPORAL));
      VarQuad * basevar = new VarQuad(base->name, base->offset, base->porref, base->isarg, base->ntype->size, base->ntype->numtype, false, base->isglob);
      AssignToArrayQuad *assign = new AssignToArrayQuad(basevar, res, NULL);

      return assign;

      //FIXME
      // Ahorita solo se considera el caso donde está una variable sola.
      // No se han considerado ninguno de los casos especiales.
    }

    bool isvariable() { return true; }
};


#endif
