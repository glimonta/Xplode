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

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      if (varList->size() == 1 && indexList->size() == 0) {
        std::string var(varList->front()->value);
        std::transform(var.begin(), var.end(), var.begin(), ::tolower);
        return var;
      }

      std::list<Xplode::Token *>::iterator vnames;
      std::list<std::pair<int, Expression *> >::iterator indexes;
      vnames = varList->begin();
      indexes = indexList->begin();
      std::string res;

      Symbol *base = table->find((*vnames)->value);
      res = EMPTY_LABEL;
      TypeDeclaration *type = base->ntype;

      while (vnames != varList->end()) {
        if (type->isarray()) {
          ArrayType* array = (ArrayType *) type;
          std::vector<int>* dimensions = array->findDimensions();

          res = indexes->second->generateTAC(generator, table);
          ++indexes;
          type = array->ntype;

          for (int i=1; i<dimensions->size(); ++i) {
            std::stringstream toString;
            toString << (*dimensions)[i];
            std::string arg2 = toString.str();
            std::string result = generator->labelmaker->getLabel(TEMPORAL);
            MulQuad *mult = new MulQuad(result, res, arg2);
            generator->gen(mult);
            res = mult->result;

            arg2 = indexes->second->generateTAC(generator, table);
            result = generator->labelmaker->getLabel(TEMPORAL);
            AddQuad *add = new AddQuad(result, res, arg2);
            generator->gen(add);
            res = add->result;

            type = type->ntype;
          }

          std::stringstream toString;
          toString << type->size;
          std::string size = toString.str();
          std::string result = generator->labelmaker->getLabel(TEMPORAL);
          MulQuad * mult = new MulQuad(result, res, size);
          generator->gen(mult);
          res = mult->result;

          result = generator->labelmaker->getLabel(TEMPORAL);
          AddQuad * add = new AddQuad(result, res, base->name);
          generator->gen(add);
          res = add->result;
        } else if (type->haveattributes()) {
          ++vnames;
          TupleType * tuple = (TupleType *) type;
          std::pair<TypeDeclaration*, int> *attribute = tuple->findAttribute((*vnames)->value);

          if (EMPTY_LABEL == res) {
            std::stringstream toString;
            toString << attribute->second;
            std::string size = toString.str();
            std::string result = generator->labelmaker->getLabel(TEMPORAL);
            AddQuad * add = new AddQuad(result, base->name, size);
            generator->gen(add);
            type = attribute->first;
            res = add->result;
          } else {
            std::stringstream toString;
            toString << attribute->second;
            std::string size = toString.str();
            std::string result = generator->labelmaker->getLabel(TEMPORAL);
            AddQuad * add = new AddQuad(result, res, size);
            generator->gen(add);
            type = attribute->first;
            res = add->result;
          }
        } else {
          ++vnames;
        }
      }

      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      AssignArrayQuad *assign = new AssignArrayQuad(result, base->name, res);
      generator->gen(assign);

      return result;

      //FIXME
      // Ahorita solo se considera el caso donde está una variable sola.
      // No se han considerado ninguno de los casos especiales.
    }

    void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      std::string res = this->generateTAC(generator, table);

      if ( "fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(res, trueLabel);
        generator->gen(if_instr);

        GotoQuad *goto_instr = new GotoQuad(falseLabel);
        generator->gen(goto_instr);
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(res, trueLabel);
        generator->gen(if_instr);
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(res, falseLabel);
        generator->gen(if_instr);
      } else {
      }
    }
};


#endif
