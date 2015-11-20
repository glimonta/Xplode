#ifndef X_GENERATORTAC
#define X_GENERATORTAC


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <map>
#include "LabelMaker.h"
#include "BlockTAC.h"


class GeneratorTAC {

  public:

    std::string filename;
    std::ofstream tempFile;
    LabelMaker *labelmaker;
    std::vector<BlockTAC *> *tac;
    std::map<std::string, std::string> strings;
    std::map<VarQuad *, std::pair<std::string, int> > globals;

    GeneratorTAC(const std::string &file) {
      filename = file + ".temp";
      tempFile.open(filename.c_str(), std::ofstream::out);
      labelmaker = new LabelMaker();
      tac = new std::vector<BlockTAC *>;
      BlockTAC *init_block = new BlockTAC();
      BlockComment * quad = new BlockComment(labelmaker->getLabel(BLOCK_LABEL));
      init_block->addQuad(quad);
      //tempFile << "\n#############################################################\n";
      //tempFile << quad->toString() << std::endl;
      //tempFile << "#############################################################\n\n";
      tac->push_back(init_block);
    }

    void new_block() {
      if (0 != ((*tac)[(*tac).size()-1])->size() && !((*tac)[(*tac).size()-1])->onlyLabelsOrComments()) {
        //tempFile << "\n#############################################################\n";
        this->gen(new BlockComment(labelmaker->getLabel(BLOCK_LABEL)));
        //tempFile << "#############################################################\n\n";
        tac->push_back(new BlockTAC());
      }
    }

    void printToFile() {
      for (std::map<std::string, std::string>::iterator str = strings.begin(); str != strings.end(); ++str) {
        tempFile << str->first << " : " << str->second << std::endl;
      }

      tempFile << std::endl;

      for (int i = 0; i < tac->size(); ++i) {
        printBlockToFile(tac->at(i));
      }
    }

    void printBlockToFile(BlockTAC *block) {
      for (int i = 0; i < block->size(); ++i) {
        tempFile << block->instructions->at(i)->toString() << std::endl;
      }
    }

    void addQuad(Quad *quad) {
      ((*tac)[(*tac).size()-1])->addQuad(quad);
    }

    void addString(std::string id, std::string val) {
      strings[id] = val;
    }

    void close() {
      if (tempFile != NULL) tempFile.close();
    }

    void gen(Quad *quad) {
      //if (NULL != dynamic_cast<DeclQuad *>(quad)) {
      //  DeclQuad * glob_decl = (DeclQuad *) quad;
      //  int size;
      //  std::string type;
      //  ConstQuad *typenum = (ConstQuad *) glob_decl->getArg1();
      //  switch (typenum->num) {
      //    case 2:
      //      size = 0;
      //      type = ".word";
      //    case 3:
      //      size = 1;
      //      
      //    case 4:
      //      size = 1;
      //    case 5:
      //      size = 4;
      //  }
      //  if
      //  globals[glob_decl->getResult()] = std::makepair(glob_decl->getArg1())
      //}
      addQuad(quad);
      //tempFile << quad->toString() << std::endl;
    }

};

#endif
