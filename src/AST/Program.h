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
#include "../SymTable.h"
#include "Block.h"


#ifndef X_MAINPROGRAM
#define X_MAINPROGRAM

#define INT_SYMBOL    new Symbol(true,"_int",    new TypeDeclaration(TYPE_INT,SIZE_INT),     0,0,true)
#define FLOAT_SYMBOL  new Symbol(true, "_float", new TypeDeclaration(TYPE_FLOAT,SIZE_FLOAT), 0,0,true)
#define CHAR_SYMBOL   new Symbol(true,"_char",   new TypeDeclaration(TYPE_CHAR,SIZE_CHAR),   0,0,true)
#define BOOL_SYMBOL   new Symbol(true,"_bool",   new TypeDeclaration(TYPE_BOOL,SIZE_BOOL),   0,0,true)
#define VOID_SYMBOL   new Symbol(true,"_void",   new TypeDeclaration(TYPE_VOID),             0,0,true)
#define STRING_SYMBOL new Symbol(true,"_string", new TypeDeclaration(TYPE_STRING),           0,0,true)
#define ERROR_SYMBOL  new Symbol(true,"_error",  new TypeDeclaration(TYPE_ERROR),            0,0,true)

class Program : public CompoundStatement {

  public:
    NodeList *definitionList;
    SymTable *table;

    Program(SymTable *stb, Node *b){

      table= stb;
      //this->insertPrimitives();
      definitionList = 0;
      block = (Block *) b;
      block->setFather(table);

    }

    Program(SymTable *stb, NodeList *d, Node *b){

      table = stb;
      //this->insertPrimitives();
      definitionList = d;
      //this->setFathers();
      block = (Block *) b;
      block->setFather(table);

    }

    void insertPrimitives(){

      table->insert(INT_SYMBOL);
      table->insert(FLOAT_SYMBOL);
      table->insert(CHAR_SYMBOL);
      table->insert(BOOL_SYMBOL);
      table->insert(VOID_SYMBOL);

    }

    void print(int tab = 0){
      std::cout << std::string(tab, ' ') << "PROGRAM \n";
      if (definitionList != 0 ){
        std::cout << std::string(tab, ' ') << "DEFINITIONS \n";
        definitionList->print(tab+2);
      }
      block->print(tab+2);
    }

    void printTable(){

      if(table!=NULL) table->print();
      std::list<Node *>::iterator iter;
      Statement *st;
      if (definitionList!=NULL)
        for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
          st = (Statement *) *iter;
          st->printTable();
        }

      if(block!=NULL) block->printTable();

    }

    void setFathers() {

      Statement *st;
      std::list<Node *>::iterator iter;
      for(iter = (*definitionList).nodeList.begin();
          iter != (*definitionList).nodeList.end(); ++iter){

        st = (Statement *) *iter;
        st->setFather(table);
      }


    }

    void check(){

      this->firstcheck();

    }

    void firstcheck(){

      //this->checktypes(table, table, NULL);
      std::list<Node *>::iterator iter;
      Statement *st;
      if (definitionList!=NULL)
        for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
          st = (Statement *) *iter;
          st->firstcheck(table);
        }

      if(block!=NULL) block->firstcheck();


    }

    void checktypes(SymTable *tb, SymTable* root, Symbol *s){

      /*  std::map<std::string, Symbol *>::iterator it;

          for(it=tb->table->begin();it!=tb->table->end();++it){

          if(s==it->second) error;
          if(it->second->defined>1)
          checktypes((SymTable *) it->second->pt, root,it->second);


          }
          */
    }

    void generateTAC(GeneratorTAC *generator, SymTable *table) {
      //FIXME

      int padding = (block->table->totaloffset%ALIGNMENT) ? (ALIGNMENT - block->table->totaloffset%ALIGNMENT) : 0;
      generator->gen(new AllocateStackQuad(new ConstQuad(block->table->totaloffset + padding)));

      std::list<Node *>::iterator iter;
      Statement *st;
      if (definitionList!=NULL) {
        for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
          st = (Statement *) *iter;
          if (dynamic_cast<DeclarationMult *>(st))
            st->generateTAC(generator, table, EMPTY_LABEL, EMPTY_LABEL);
        }
      }

      if(block!=NULL) {
         block->generateTAC(generator, table, EMPTY_LABEL, EMPTY_LABEL);
      }

      generator->gen(new ExitQuad());

      if (definitionList!=NULL) {
        for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
          st = (Statement *) *iter;
          if (!dynamic_cast<DeclarationMult *>(st))
            st->generateTAC(generator, table, EMPTY_LABEL, EMPTY_LABEL);
        }
      }


    }

};

#endif
