#ifndef X_GENERATORMIPS
#define X_GENERATORMIPS


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "MipsInstruction.h"
#include "RegisterAllocator.h"
#include "../TAC/GeneratorTAC.h"

class GeneratorMIPS {

  public:

    std::string filename;
    std::ofstream tempFile;
    std::vector<MipsInstruction *> *instructions;
    std::map<std::string, std::string> strings;
    std::map<VarQuad *, std::string, int> globals;
    RegisterAllocator * allocator;

    GeneratorMIPS(std::string file) {
      filename = file + ".s";
      tempFile.open(filename.c_str(), std::ofstream::out);
      instructions = new std::vector<MipsInstruction *>();
      allocator = new RegisterAllocator();
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
          writeToMips(write);
        } else if ("exit" == quad->op) {
          ExitQuad * exit = (ExitQuad *) quad;
          exitToMips(exit);
        } else if (NULL != dynamic_cast<Comment *> (quad)){
          Comment * comment = (Comment *) quad;
          commentToMips(comment);
        } else if (NULL != dynamic_cast<Label *> (quad)){
          Label * label = (Label *) quad;
          labelToMips(label);
        } else if ("read" == quad->op) {
          ReadQuad * read = (ReadQuad *) quad;
          readToMips(read);
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

//toMips functions:

    void writeToMips(WriteQuad * write) {
//Falta considerar si es una variable a lo que se le hace write
      MipsRegister *rd;
      allocator->getReg(this, write, &rd, NULL, NULL);
      instructions->push_back(new MoveMips(new MipsRegister(4), rd));
      instructions->push_back(new LoadImmMips(new MipsRegister(2), new MipsImmediate(4)));
      instructions->push_back(new SyscallMips());
    }

    void commentToMips(Comment * comment) {
      instructions->push_back(new CommentMips(comment->getOp()));
    }

    void labelToMips(Label * label) {
      instructions->push_back(new LabelMips(label->getOp()));
    }

    // Primer intento en un generateMips para read, falta considerar la dirección a la que se va a leer
    void readToMips(ReadQuad * read) {
      MipsRegister *rd;
      allocator->getReg(this, read, &rd, NULL, NULL);
      instructions->push_back(new MoveMips(new MipsRegister(4), rd));
      int size;
      ConstQuad *typenum = (ConstQuad *) read->getArg1();
      switch (typenum->num) {
        case 2: size = 4;
        case 3: size = 1;
        case 4: size = 1;
        case 5: size = 4;
      }
      instructions->push_back(new LoadImmMips(new MipsRegister(5), new MipsImmediate(size)));
      instructions->push_back(new LoadImmMips(new MipsRegister(2), new MipsImmediate(8)));
      instructions->push_back(new SyscallMips());
    }

    void exitToMips(ExitQuad * exit) {
      instructions->push_back(new LoadImmMips(new MipsRegister(2), new MipsImmediate(10)));
      instructions->push_back(new SyscallMips());
    }



};

#endif
