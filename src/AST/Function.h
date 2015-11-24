#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "NodeList.h"
#include "../Symbol.h"
#include "Block.h"
#include "TypeDeclaration.h"
#include "TupleType.h"
#include "FunctionType.h"
#include "ArrayType.h"
#include "../Token.h"


#ifndef X_FUNCTIONDEF
#define X_FUNCTIONDEF

class Function : public CompoundStatement {
  public:

    TypeDeclaration *ntype;
    SymTable* symtb;
    std::string returnType;
    std::string fname;

    Function(SymTable *s,std::string name,Node *t,Node *b) {

      symtb = s;
      ntype = (TypeDeclaration *) t;
      //TypeDeclaration *tp = (TypeDeclaration *) r;
      fname =name;
      //parameters = (TupleType *) p;
      block  = (Block *) b;
      //if (parameters != 0){
      //  block->table->add(parameters);
      //}
    }

    void print(int tab){

      std::cout << std::string(tab, ' ') << "FUNCTION\n";
      std::cout << std::string(tab, ' ') << "name: " << fname << "\n";
      ntype->print(tab);
      block->print(tab+2);
    }

    void setFather(SymTable *s){

      if(block!=NULL) block->setFather(s);

    }

    Symbol *toSymbol() {}//return new Symbol(name,NULL, line, column); }

    void firstcheck(SymTable *symtb){

      /*SymTable *root = symtb->getRoot();
        Declaration *decl;
        std::list<Node *>::iterator iter;

        if(parameters != NULL)
        for(iter = (*parameters).nodeList.begin();
        iter != (*parameters).nodeList.end(); ++iter){

        decl = (Declaration *) *iter;
        decl->firstcheck(root);
        }

       */ //falta verificar los parametros de las funciones

      if(block!=NULL) block->firstcheck();

    }

    void printTable() {

      symtb->print();
      if (block!=NULL) block->printTable();

    }

    void generateTAC(GeneratorTAC *generator, SymTable *table, std::string continueLabel, std::string breakLabel) {
      generator->new_block();

      Comment *comment = new Comment("Definición de Función " + fname + ": linea " + getLineStr());
      generator->gen(comment);

      Label *function_label = new Label(fname);
      generator->gen(function_label);

      Symbol * f = table->find(fname);
      VarQuad * function = new VarQuad(fname, f->offset, f->porref, f->isarg, f->ntype->size, f->ntype->numtype);
      PrologueQuad * prologue =  new PrologueQuad(function);
      generator->gen(prologue);

      FunctionType *ftype = (FunctionType *) ntype;
      TupleType *args = (TupleType *) ftype->arguments;
      int offset = 4; //Already included return address
      std::list<std::string>::iterator itNames;
      std::list<std::pair<TypeDeclaration*, int>*>::iterator itTypes = args->types->begin();

      for(itNames = args->names->begin(); itNames != args->names->end(); ++itNames, ++itTypes) {
        Symbol *arg = symtb->find(*itNames);
        if (!(*itTypes)->first->isarray()) {
          offset += 4;
          arg->setArg(true);
          arg->setOffsetStack(offset);
        }
      }

      offset += 4;
      itTypes = args->types->begin();

      for(itNames = args->names->begin(); itNames != args->names->end(); ++itNames, ++itTypes) {
        Symbol *arg = symtb->find(*itNames);
        if ((*itTypes)->first->isarray()) {
          ArrayType * array = (ArrayType *) (*itTypes)->first;
          arg->setArg(true);
          arg->setOffsetStack(offset);
          offset += 8; // tamaño del elemento y numero de dimensiones
          std::vector<int>* dimensions = array->findDimensions();
          for (int i = 1; i < dimensions->size(); ++i) offset += 4; // por cada dimension sumo 4
          offset += 8; // Desplazamiento final para donde están los datos (dirección) y uno más para que quede libre
        }
      }

      block->generateTAC(generator, symtb, EMPTY_LABEL, EMPTY_LABEL);

      EpilogueQuad * epilogue =  new EpilogueQuad(function);
      generator->gen(epilogue);

    }

};

#endif

