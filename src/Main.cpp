#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "ErrorLog.h"
#include "XplodeScanner.h"
#include "ClassicScanner.h"
#include "XplodeParser.h"
#include "FlexScanner.h"
#include "TAC/LabelMaker.h"
#include "TAC/Quad.h"
#include "TAC/GeneratorTAC.h"


int line = 1;
int column = 1;
std::string tok;
ErrorLog *errorlog = new ErrorLog();


int selectLexer(char* fp){

  std::ifstream input(fp);
  int progcl=0,comment=0, progxp=0;

  for( std::string line; getline(input, line); ){

    comment = line.find("//");
    progxp  =  line.find("xplodegram");
    progcl  = line.find("program");

    if ((progcl!=-1)&&((comment==-1)||(progcl<comment)))
      return 1;

    if ((progxp!=-1)&&((comment==-1)||(progxp<comment)))
      return 2;

  }

  return 2;

}

// Entry Point
int main(int argc, char * argv[]) {

  bool st = false, ast = false;
  std::filebuf fb;
  int lexdecision=0;
  const char *filename = argv[argc-1];


  if (argc < 2){
    std::cout << "No filename was given." << std::endl;
    exit(0);
  }

  if (argc > 2){
    for (int i = 1; i < argc-1; i++) {
      if (strcmp(argv[i], "-a") ==0) ast= true;
      if (strcmp(argv[i], "-t") ==0) st= true;

    }
    //std::cout << argv[argc-1];
    fb.open (filename ,std::ios::in);
    lexdecision = selectLexer(argv[argc-1]);
  } else {
    fb.open (argv[1] ,std::ios::in);
    lexdecision = selectLexer(argv[1]);
  }

  std::istream is(&fb);
  Xplode::FlexScanner *scanner;
  Program *program;
  if (lexdecision==1) scanner = new Xplode::ClassicScanner(&is);
  else scanner = new Xplode::XplodeScanner(&is);
  Xplode::Parser parser(&program,scanner);
  parser.parse();
  //program->check();
  if(errorlog->existError()){
    errorlog->print();
  return 0;
  }
  else {
    if (st) program->printTable();
    if (ast) program->print();
  }
  //if (st) program->printTable();

  GeneratorTAC *generator;
  generator = new GeneratorTAC(filename);
  program->generateTAC(generator);
  generator->close();

}

