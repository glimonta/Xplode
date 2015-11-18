#ifndef X_GENERATORMIPS
#define X_GENERATORMIPS


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "MipsInstruction.h"
#include "../TAC/GeneratorTAC.h"

class GeneratorMIPS {

  public:

    std::string filename;
    std::ofstream tempFile;
    std::vector<MipsInstruction *> *instructions;
    std::map<std::string, std::string> strings;

    GeneratorMIPS(std::string file) {
      filename = file + ".s";
      tempFile.open(filename.c_str(), std::ofstream::out);
      instructions = new std::vector<MipsInstruction *>();
    }

    void create(GeneratorTAC *generator) {
      strings = generator->strings;
      for (int i = 0; i < generator->tac->size(); ++i) {
        generateMipsFromBlock(generator->tac->at(i));
      }
    }

    void generateMipsFromBlock(BlockTAC * block) {
      for (int i = 0; i < block->size(); ++i) {
        Quad* quad = block->instructions->at(i);
        if ("write" == quad->op) {
          WriteQuad * write = (WriteQuad *) quad;
          write->generateMips(instructions);
        } else if ("exit" == quad->op) {
          ExitQuad * exit = (ExitQuad *) quad;
          exit->generateMips(instructions);
        } else if (NULL != dynamic_cast<Comment *> (quad)){
          Comment * comment = (Comment *) quad;
          comment->generateMips(instructions);
        } else if (NULL != dynamic_cast<Label *> (quad)){
          Label * label = (Label *) quad;
          label->generateMips(instructions);
        //} else if ("read" == quad->op) {
        //  ReadQuad * read = (ReadQuad *) quad;
        //  read->generateMips(instructions);
        } else {
          //Faltan los demás casos
        }
      }
    }

    void close() {
      if (tempFile != NULL) tempFile.close();
    }

    void gen(MipsInstruction * instr) {
      instructions->push_back(instr);
    }

    void printToFile() {
      tempFile << ".data" << std::endl;
      for (std::map<std::string, std::string>::iterator str = strings.begin(); str != strings.end(); ++str) {
        tempFile << str->first << ":    .asciiz " << str->second << std::endl;
      }
      tempFile << std::endl;

      tempFile << ".text" << std::endl;
      tempFile << "main:" << std::endl;

      for (int i = 0; i < instructions->size(); ++i) {
        tempFile << instructions->at(i)->toString() << std::endl;
      }

    }

};

#endif
