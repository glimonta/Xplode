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
      Comment *quad = new Comment(labelmaker->getLabel(BLOCK_LABEL));
      init_block->addQuad(quad);
      tempFile << "\n#############################################################\n";
      tempFile << quad->toString() << std::endl;
      tempFile << "#############################################################\n\n";
      tac->push_back(init_block);
    }

    void new_block() {
      if (0 != ((*tac)[(*tac).size()-1])->size() && !((*tac)[(*tac).size()-1])->onlyLabelsOrComments()) {
        tempFile << "\n#############################################################\n";
        this->gen(new Comment(labelmaker->getLabel(BLOCK_LABEL)));
        tempFile << "#############################################################\n\n";
        tac->push_back(new BlockTAC());
      }
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
