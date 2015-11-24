#ifndef X_GENERATORMIPS
#define X_GENERATORMIPS


#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "MipsInstruction.h"
#include "RegisterAllocator.h"
#include "../TAC/GeneratorTAC.h"

//System call codes
#define PRINT_INT_SYSCALL    new MipsImmediate(1)
#define PRINT_FLOAT_SYSCALL  new MipsImmediate(2)
#define PRINT_DOUBLE_SYSCALL new MipsImmediate(3)
#define PRINT_STRING_SYSCALL new MipsImmediate(4)
#define READ_INT_SYSCALL     new MipsImmediate(5)
#define READ_FLOAT_SYSCALL   new MipsImmediate(6)
#define READ_DOUBLE_SYSCALL  new MipsImmediate(7)
#define READ_STRING_SYSCALL  new MipsImmediate(8)
#define SBRK_SYSCALL         new MipsImmediate(9)
#define EXIT_SYSCALL         new MipsImmediate(10)
#define PRINT_CHAR_SYSCALL   new MipsImmediate(11)
#define READ_CHAR_SYSCALL    new MipsImmediate(12)

class GeneratorMIPS {

  public:

    std::string filename;
    std::ofstream tempFile;
    std::vector<MipsInstruction *> *instructions;
    std::map<std::string, std::string> strings;
    std::map<VarQuad *, std::pair<std::string, int> > globals;
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
      globals = generator->globals;
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
        } else if (":=" == quad->op) {
          AssignQuad * assign = (AssignQuad *) quad;
          assignToMips(assign);
        } else if ("allocate" == quad->op) {
          AllocateStackQuad * alloc = (AllocateStackQuad *) quad;
          allocateToMips(alloc);
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

      for (std::map<VarQuad *, std::pair<std::string, int> >::iterator decl = globals.begin(); decl != globals.end(); ++decl) {
        tempFile << decl->first->toString() << ":    " << decl->second.first << "    " << decl->second.second << std::endl;
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
      VarQuad * variable = (VarQuad *) write->getResult();
      ConstQuad * typenum = (ConstQuad *) write->getArg1();

      if (TYPE_INT == typenum->num) {
        instructions->push_back(new LoadWordMips(A0_REGISTER, new MipsOffset(rd->num, 0)));
        instructions->push_back(new LoadImmMips(V0_REGISTER, PRINT_INT_SYSCALL));
        instructions->push_back(new SyscallMips());
      } else if (TYPE_STRING == typenum->num){
        instructions->push_back(new MoveMips(new MipsRegister(4), rd));
        instructions->push_back(new LoadImmMips(new MipsRegister(2), new MipsImmediate(4)));
        instructions->push_back(new SyscallMips());
      }
    }

    void commentToMips(Comment * comment) {
      instructions->push_back(new CommentMips(comment->getOp()));
    }

    void labelToMips(Label * label) {
      instructions->push_back(new LabelMips(label->getOp()));
    }

    // Primer intento en un generateMips para read, falta considerar la dirección a la que se va a leer
    void readToMips(ReadQuad * read) {
      ConstQuad *typenum = (ConstQuad *) read->getArg1();
      if (TYPE_INT == typenum->num) {
        MipsRegister *rd;
        allocator->getReg(this, read, &rd, NULL, NULL);
        instructions->push_back(new LoadImmMips(V0_REGISTER, READ_INT_SYSCALL));
        instructions->push_back(new SyscallMips());
        instructions->push_back(new MoveMips(rd, V0_REGISTER));
      }
    }

    void exitToMips(ExitQuad * exit) {
      instructions->push_back(new LoadImmMips(new MipsRegister(2), new MipsImmediate(10)));
      instructions->push_back(new SyscallMips());
    }

    void assignToMips(AssignQuad * assign) {
      VarQuad * var = (VarQuad *) assign->getResult();
      MipsRegister * rd, * rl;
      allocator->getReg(this, assign, &rd, &rl, NULL);
      instructions->push_back(new StoreWordMips(rl, new MipsOffset(rd->num, 0)));
    }

    void allocateToMips(AllocateStackQuad * allocate) {
      ConstQuad * space = (ConstQuad *) allocate->getResult();
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-(space->num))));
    }


};

#endif
