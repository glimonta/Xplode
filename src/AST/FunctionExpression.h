#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"

#ifndef X_FUNCTIONEXP
#define X_FUNCTIONEXP

class FunctionExpression : public Expression {
  public:
    std::string fname;
    std::list<Expression *> *argList;

    FunctionExpression(std::string n, std::list<Expression *> *a = 0){fname = n; argList = a; }
    void print(int tab){
      std::cout << std::string(tab, ' ') << "FUNCTION \n";
      std::cout << std::string(tab, ' ') << "name: " << fname << "\n";
      if ( argList != 0 ){
        for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
          std::cout << std::string(tab, ' ') << "argument: \n";
          (*iter)->print(tab+2);
        }
      }
    }

    void firstcheck(SymTable *symtb){
      //Symbol *sym = symtb->getRoot()->find(fname); //verificar si el nombre pertenece a una funcion
      //if((!sym)||((sym)&&((sym->defined!=4)&&(sym->defined!=5)))) errorlog->addError(15,0,0,&fname);
      for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
        (*iter)->firstcheck(symtb);
      }
    }

    std::string toString(SymTable *table) {
      std::stringstream str;
      str << fname;
      if (0 != argList->size()) {
        str << "(";
        std::list<Expression *>::iterator params;
        for (params = argList->begin(); params != argList->end(); ++params) {
          str << (*params)->toString(table);
          if (params != --argList->end()) {
            str << ", ";
          }
        }
        str << ")";
      }
      return str.str();
    }

    std::string generateTAC(GeneratorTAC *generator, SymTable *table) {
      Comment *comment = new Comment("Este es el código generado por la linea " + getLineStr() + " de la llamada a la función: " + fname);
      generator->gen(comment);

      std::list<Expression *>::iterator params;
      for (params = argList->begin(); params != argList->end(); ++params) {
        std::string res = (*params)->generateTAC(generator, table);
        ParamQuad *param = new ParamQuad(res);
        generator->gen(param);
      }

      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      std::stringstream str;
      str << argList->size();
      FunctionCallReturn *call = new FunctionCallReturn(result, fname, str.str());
      generator->gen(call);

      return result;
      //FIXME solo estoy considerando cuando retorna un valor, esto es mas complicado de lo que creo
    }

    void generateJumpingCode(GeneratorTAC *generator, SymTable * table, std::string trueLabel, std::string falseLabel) {
      std::string res = this->generateTAC(generator, table);

      if ( "fall" != trueLabel && "fall" != falseLabel) {
        IfQuad *if_instr = new IfQuad(res, trueLabel);
        generator->gen(if_instr);
        generator->new_block();

        GotoQuad *goto_instr = new GotoQuad(falseLabel);
        generator->gen(goto_instr);
        generator->new_block();
      } else if ("fall" != trueLabel) {
        IfQuad *if_instr = new IfQuad(res, trueLabel);
        generator->gen(if_instr);
        generator->new_block();
      } else if ("fall" != falseLabel) {
        IfNotQuad *if_instr = new IfNotQuad(res, falseLabel);
        generator->gen(if_instr);
        generator->new_block();
      } else {
      }
    }

};


#endif
