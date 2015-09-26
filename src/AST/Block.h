#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "NodeList.h"
#include "Declaration.h"
#include "../SymTable.h"
#include "Statement.h"

#ifndef X_BLOCK
#define X_BLOCK


class Block : public Node {
  public:
    NodeList *declarationList;
    NodeList *statementList;
    SymTable *table;

    Block(SymTable *stb, NodeList *s){

      table= stb; //new SymTable();
      declarationList = 0;
      statementList = s;
      this->setFathers();
    }

    Block(SymTable *stb, NodeList *d, NodeList *s) {

      table = stb; //new SymTable();
      declarationList = d;
      statementList = s;
      this->setFathers();
    }

    void print(int tab){
      std::cout << std::string(tab, ' ') << "BLOCK \n";
      if (declarationList != 0 ){
        std::cout << std::string(tab, ' ') << "DECLARATIONS \n";
        declarationList->print(tab+2);
      }
      std::cout << std::string(tab, ' ') << "STATEMENTS\n";
      statementList->print(tab+2);
    }

    void printTable(){

      table->print();
      Statement *st;
      std::list<Node *>::iterator iter;
      for(iter = (*statementList).nodeList.begin();
          iter != (*statementList).nodeList.end(); ++iter){

        st = (Statement *) *iter;
        st->printTable();
      }
    }

    virtual void setFathers() {

      Statement *st;
      std::list<Node *>::iterator iter;
      for(iter = (*statementList).nodeList.begin();
          iter != (*statementList).nodeList.end(); ++iter){

        st = (Statement *) *iter;
        st->setFather(table);
      }

    }

    virtual void setFather(SymTable *s){

      table->setFather(s);

    }

    void firstcheck(){
      Declaration *decl;
      Statement *st;
      std::list<Node *>::iterator iter;
      SymTable *root = table->getRoot();

      if(declarationList != NULL)
        for(iter = (*declarationList).nodeList.begin();
            iter != (*declarationList).nodeList.end(); ++iter){

          decl = (Declaration *) *iter;
          decl->firstcheck(root);
        }

      for(iter = (*statementList).nodeList.begin();
          iter != (*statementList).nodeList.end(); ++iter){

        st = (Statement *) *iter;
        st->firstcheck(table);
      }
    }

    std::string generateTAC(GeneratorTAC *generator) {
      Declaration *decl;
      Statement *st;
      std::string aux;
      std::list<Node *>::iterator iter;

      //if(declarationList != NULL) {
      //printf("La lista de declaraciones no es nula\n");
      //  for(iter = (*declarationList).nodeList.begin();
      //      iter != (*declarationList).nodeList.end(); ++iter){

      //    decl = (Declaration *) *iter;
      //printf("Llego hasta despues de castear\n");
      //    decl->generateTAC(generator);
      //printf("Paso el genTAC\n");
      //  }
      //}

      if(statementList != NULL) {
        printf("La lista de statements no es nula\n");
        for(iter = (*statementList).nodeList.begin();
            iter != (*statementList).nodeList.end(); ++iter){
        printf("entre al for\n");

          st = (Statement *) *iter;
      printf("Llego hasta despues de castear\n");
          st->generateTAC(generator);
        }
      }

      //FIXME
      return "";
    }


};

#endif
