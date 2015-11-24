#ifndef X_GENERATORTAC
#define X_GENERATORTAC


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <map>
#include "LabelMaker.h"
#include "../AST/TypeDeclaration.h"
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
      if (NULL != dynamic_cast<DeclQuad *>(quad)) {
        DeclQuad * glob_decl = (DeclQuad *) quad;
        int size;
        std::string type;
        bool ok = true;
        ConstQuad *typenum = (ConstQuad *) glob_decl->getArg1();
        ConstQuad *typesize = (ConstQuad *) glob_decl->getArg2();
        VarQuad *var = (VarQuad *) glob_decl->getResult();
        switch (typenum->num) {
          case TYPE_INT:
            size = 0;
            type = ".word";
            break;
          case TYPE_BOOL:
            size = 0;
            type =".word";
            break;
          case TYPE_CHAR:
            size = 0;
            type = ".byte";
            break;
          case TYPE_FLOAT:
            size = 0;
            type = ".word";
            break;
          case TYPE_ARRAY:
            size = ((typesize->num%ALIGNMENT) != 0) ? typesize->num += ALIGNMENT - (typesize->num%ALIGNMENT) : typesize->num;
            type = ".space";
            break;
          case TYPE_TYPE:
            size = ((typesize->num%ALIGNMENT) != 0) ? typesize->num += ALIGNMENT - (typesize->num%ALIGNMENT) : typesize->num;
            type = ".space";
            break;
          default:
            ok = false;
            break;
        }
        if (ok) {
          globals[var] = std::make_pair(type, size);
        }
        return;
      }
      addQuad(quad);
      //tempFile << quad->toString() << std::endl;
    }

};

#endif
