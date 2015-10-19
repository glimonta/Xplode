#ifndef X_GENERATORTAC
#define X_GENERATORTAC


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "LabelMaker.h"
#include "BlockTAC.h"


class GeneratorTAC {

  public:

    std::string filename;
    std::ofstream tempFile;
    LabelMaker *labelmaker;
    std::vector<BlockTAC *> *tac;

    GeneratorTAC(const std::string &file) {
      filename = file + ".temp";
      tempFile.open(filename.c_str(), std::ofstream::out);
      labelmaker = new LabelMaker();
      tac = new std::vector<BlockTAC *>;
      BlockTAC *init_block = new BlockTAC();
      Label *quad = new Label(labelmaker->getLabel(BLOCK_LABEL));
      init_block->addQuad(quad);
      tempFile << quad->toString() << std::endl;
      quad = new Label("INIT");
      init_block->addQuad(quad);
      tempFile << quad->toString() << std::endl;
      tac->push_back(init_block);
    }

    void new_block() {
      tempFile << "\n#############################################################\n";
      this->gen(new Comment(labelmaker->getLabel(BLOCK_LABEL)));
      tempFile << "\n#############################################################\n";
      tac->push_back(new BlockTAC());
    }

    void addQuad(Quad *quad) {
      ((*tac)[(*tac).size()-1])->addQuad(quad);
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
