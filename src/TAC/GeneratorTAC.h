#ifndef X_GENERATORTAC
#define X_GENERATORTAC


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "LabelMaker.h"
#include "Quad.h"


class GeneratorTAC {

  public:

    std::string filename;
    std::ofstream tempFile;
    LabelMaker *labelmaker;
    std::vector<Quad*> *tac;

    GeneratorTAC(const std::string &file) {
      filename = file + ".temp";
      tempFile.open(filename.c_str(), std::ofstream::out);
      labelmaker = new LabelMaker();
      tac = new std::vector<Quad*>;
    }

    void addQuad(Quad *quad) {
      tac->push_back(quad);
    }

    void close() {
      if (tempFile != NULL) tempFile.close();
    }

    void gen(Quad *quad) {
      addQuad(quad);
      tempFile << quad->toString() << std::endl;
    }

};

#endif
