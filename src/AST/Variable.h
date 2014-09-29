#ifndef X_VARIABLEEXP
#define X_VARIABLEEXP

#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <vector> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"
#include "../ErrorLog.h"
#include "../Token.h"
#include "TupleType.h"
#include "ArrayType.h"

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

  virtual std::string toTAC(TAC_Program *tac, SymTable *symtab){

     std::list<Xplode::Token *>::iterator itvar;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     itvar = varList->begin();
     itindex = indexList->begin();
     std::string res;
     
     
     Symbol *sym = symtab->find((*itvar)->value);
     Instruction *inst = new Instruction(ASSIGN_LABEL);
     inst->result = tac->labelmaker->getlabel(TEMPORAL);      
     inst->leftop = sym->name;
     res= inst->result;
     tac->push_quad(inst);
     TypeDeclaration *tipo = sym->ntype; 
        
     while(itvar != varList->end()){
     

      
      if(tipo->isarray()){

        ArrayType *arrtp = (ArrayType *) tipo;
        std::vector<int> *index= arrtp->takeindex();
        std::string res_fin=res;
        
        //std::cout << "Pase 1\n";
        res = itindex->second->toTAC(tac, symtab);
        ++itindex;
        tipo = tipo->ntype;
        int i=1;
        
        while(i<index->size()){
          //std::cout << "Pase 2\n";
          inst=new Instruction(MUL_LABEL);
          inst->leftop = res;
          std::stringstream aux;
          aux << (*index)[i];
          inst->rightop = aux.str();
          inst->result = tac->labelmaker->getlabel(TEMPORAL);      
          tac->push_quad(inst);
          res = inst->result;
          
          inst=new Instruction(ADD_LABEL);
          inst->leftop = res;
          inst->rightop = itindex->second->toTAC(tac, symtab);
          inst->result = tac->labelmaker->getlabel(TEMPORAL);      
          tac->push_quad(inst);
          tipo = tipo->ntype;
                                    
          i++;
        }
          //std::cout << "Pase 3\n";        
          inst=new Instruction(MUL_LABEL);
          inst->leftop = res;
          std::stringstream aux;
          aux << tipo->size;
          inst->rightop = aux.str();
          inst->result = tac->labelmaker->getlabel(TEMPORAL);      
          tac->push_quad(inst);
          res = inst->result;
          
          inst=new Instruction(ADD_LABEL);
          inst->leftop = res_fin;
          inst->rightop = res;
          inst->result = tac->labelmaker->getlabel(TEMPORAL);      
          tac->push_quad(inst);
          res=inst->result;
        
       
      } else if (tipo->haveattributes()) {
      
        ++itvar;
        TupleType *tup= (TupleType *) tipo;
        std::pair<TypeDeclaration*, int> *info = tup->takeattribute((*itvar)->value); 
        inst=new Instruction(ADD_LABEL);
        inst->result = tac->labelmaker->getlabel(TEMPORAL);      
        inst->leftop = res;
        std::stringstream aux;
        aux << info->second;
        inst->rightop = aux.str();
        tac->push_quad(inst); 
        res= inst->result; 
        tipo = info->first;
        //std::cout << (long) tipo<< std::endl;
      
      } else {
      
        ++itvar;
      
                    
      }
     
      
      
     }

     return res;
        

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

};


#endif
