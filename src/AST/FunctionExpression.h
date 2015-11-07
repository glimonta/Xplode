#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "Variable.h"
#include "../SymTable.h"
#include "FunctionType.h"

#ifndef X_FUNCTIONEXP
#define X_FUNCTIONEXP

class FunctionExpression : public Expression {
  public:
    std::string fname;
    std::list<Expression *> *argList;
    std::set<int> *reference;

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


      FunctionType * fun = (FunctionType *) table->find(fname);

      std::list<Expression *>::iterator params;
      params = argList->end();
      --params;

      // Se empilan primero los parámetros de longitud variable (arreglos).
      for (int i = argList->size(); i > 0; --params, --i) {
        if (reference && reference->count(i) != 0 && (*params)->ntype->isarray()) {
          Variable * v = (Variable *) *params;
          comment = new Comment("Aquí debería pasar el parámetro que es un arreglo pero me falta solucionar lo del dope vector");
          generator->gen(comment);

          TypeDeclaration * type = v->ntype;
          TypeDeclaration * base_type = v->ntype;
          ArrayType * array = (ArrayType *) v->ntype;
          std::vector<int> * dims = array->findDimensions();

          for (int j = 0; j < dims->size(); ++j) base_type = base_type->ntype;

          std::stringstream basetype;
          basetype << base_type->size;
          // Tamaño de un elemento del arreglo
          ParamQuad * param = new ParamQuad(basetype.str());
          generator->gen(param);

          std::stringstream size_dims;
          size_dims << dims->size();
          // Número de dimensiones
          param = new ParamQuad(size_dims.str());
          generator->gen(param);

          for (int j = 0; j < dims->size(); ++j) {
            std::stringstream dimension;
            dimension << (*dims)[i];
            // Dimensión del arreglo
            param = new ParamQuad(dimension.str());
            generator->gen(param);

            type = type->ntype;
          }

          Quad * res_instr = (*params)->lval_generateTAC(generator, table);
          ParamRefQuad *param_ref = new ParamRefQuad(res_instr->getResult(), res_instr->getArg1(), res_instr->getArg2());
          generator->gen(param_ref);
        }
      }

      params = argList->end();
      --params;
      // Se empilan el resto de los parámetros de derecha a izquierda
      for (int i = argList->size(); i > 0; --params, --i) {
        if (reference && reference->count(i) != 0 && !(*params)->ntype->isarray()) {
          Quad * res_instr = (*params)->lval_generateTAC(generator, table);
          ParamRefQuad *param = new ParamRefQuad(res_instr->getResult(), res_instr->getArg1(), res_instr->getArg2());
          generator->gen(param);
        } else {
          std::string res = (*params)->generateTAC(generator, table);
          ParamQuad *param = new ParamQuad(res);
          generator->gen(param);
        }
      }


      std::string result = generator->labelmaker->getLabel(TEMPORAL);
      std::stringstream str;
      str << argList->size();
      FunctionCallReturn *call = new FunctionCallReturn(result, fname, str.str());
      generator->gen(call);

      return result;
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
