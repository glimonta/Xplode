#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_LABELMAKER
#define X_LABELMAKER

#define COMMENT_LABEL          "#"
#define INIT_LABEL             "INIT "
#define ADD_LABEL              "ADD "
#define ASSIGN_LABEL           "ASSIGN "
#define ADD_LABEL              "ADD "
#define SUB_LABEL              "SUB "
#define MUL_LABEL              "MUL "
#define DIV_LABEL              "DIV "
#define MOD_LABEL              "MOD "
#define EQUAL_LABEL            "EQ  "
#define NEQUAL_LABEL           "NEQ "
#define LESS_LABEL             "LESS"
#define GREATER_LABEL          "GRET"
#define GEQ_LABEL              "GEQ "
#define LEQ_LABEL              "LEQ "
#define CALL_LABEL             "CALL"
#define PARAM_LABEL            "PARM "
#define TEMPORAL               "t"
#define UMINUS_LABEL           "NEG "
#define NOT_LABEL              "NOT "

class LabelMaker {
  public:

    std::map<std::string, int> *counter;

    LabelMaker() {
      counter = new std::map<std::string, int>;
    }

    std::string getLabel(std::string prefix){

      char label[60];
      (*counter)[prefix]++;
      sprintf(label,"%s%d", prefix.c_str(), (*counter)[prefix]);
      return std::string(label);

    }

};

#endif
