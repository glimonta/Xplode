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
        } else if ("+" == quad->op) {
          AddQuad * add = (AddQuad *) quad;
          addToMips(add);
        } else if ("-" == quad->op) {
          SubQuad * sub = (SubQuad *) quad;
          subToMips(sub);
        } else if ("*" == quad->op) {
          MulQuad * mul = (MulQuad *) quad;
          mulToMips(mul);
        } else if ("/" == quad->op) {
          DivQuad * div = (DivQuad *) quad;
          divToMips(div);
        } else if ("%" == quad->op) {
          ModQuad * mod = (ModQuad *) quad;
          modToMips(mod);
        } else if ("<" == quad->op) {
          LessQuad * less = (LessQuad *) quad;
          lessToMips(less);
        } else if ("<=" == quad->op) {
          LessEqualQuad * lesseq = (LessEqualQuad *) quad;
          lesseqToMips(lesseq);
        } else if (">" == quad->op) {
          GreaterQuad * greater = (GreaterQuad *) quad;
          greaterToMips(greater);
        } else if (">=" == quad->op) {
          GreaterEqualQuad * greatereq = (GreaterEqualQuad *) quad;
          greatereqToMips(greatereq);
        } else if ("==" == quad->op) {
          EqualQuad * equal = (EqualQuad *) quad;
          equalToMips(equal);
        } else if ("!=" == quad->op) {
          NotEqualQuad * notequal = (NotEqualQuad *) quad;
          notequalToMips(notequal);
        } else if ("&&" == quad->op) {
          AndQuad * andquad = (AndQuad *) quad;
          andToMips(andquad);
        } else if ("&&" == quad->op) {
          OrQuad * orquad = (OrQuad *) quad;
          orToMips(orquad);
        } else if ("if" == quad->op) {
          IfQuad * ifquad = (IfQuad *) quad;
          ifToMips(ifquad);
        } else if ("ifnot" == quad->op) {
          IfNotQuad * ifnotquad = (IfNotQuad *) quad;
          ifnotToMips(ifnotquad);
        } else if ("goto" == quad->op) {
          GotoQuad * gotoquad = (GotoQuad *) quad;
          gotoToMips(gotoquad);
        } else if ("param" == quad->op) {
          ParamQuad * param = (ParamQuad *) quad;
          paramToMips(param);
        } else if ("param_ref" == quad->op) {
          ParamRefQuad * param = (ParamRefQuad *) quad;
          paramrefToMips(param);
        } else if ("call" == quad->op) {
          FunctionCallReturn * call = (FunctionCallReturn *) quad;
          callToMips(call);
        } else if ("neg" == quad->op) {
          UnaryMinusQuad * minus = (UnaryMinusQuad *) quad;
          minusToMips(minus);
        } else if ("not" == quad->op) {
          NotQuad * notquad = (NotQuad *) quad;
          notToMips(notquad);
        } else if ("sleep" == quad->op) {
          SleepQuad * sleep = (SleepQuad *) quad;
          sleepToMips(sleep);
        } else if ("return" == quad->op) {
          ReturnQuad * ret = (ReturnQuad *) quad;
          returnToMips(ret);
        } else if ("return_exp" == quad->op) {
          ReturnExpQuad * ret = (ReturnExpQuad *) quad;
          returnexpToMips(ret);
        } else if ("[]:=" == quad->op) {
          AssignToArrayQuad * assign = (AssignToArrayQuad *) quad;
          assignToArrayToMips(assign);
        } else if (":=[]" == quad->op) {
          AssignArrayQuad * assign = (AssignArrayQuad *) quad;
          assignArrayToMips(assign);
        } else if ("=*" == quad->op) {
          DerefQuad * deref = (DerefQuad *) quad;
          derefToMips(deref);
        } else if ("*=" == quad->op) {
          RefQuad * ref = (RefQuad *) quad;
          refToMips(ref);
        } else if ("prologue" == quad->op) {
          PrologueQuad * prologue = (PrologueQuad *) quad;
          prologueToMips(prologue);
        } else if ("epilogue" == quad->op) {
          EpilogueQuad * epilogue = (EpilogueQuad *) quad;
          epilogueToMips(epilogue);
        } else if ("ctoi" == quad->op) {
          CastQuad * ctoi = (CastQuad *) quad;
          charToIntToMips(ctoi);
        } else if ("itoc" == quad->op) {
          CastQuad * itoc = (CastQuad *) quad;
          intToCharToMips(itoc);
        } else if ("itof" == quad->op) {
          CastQuad * itof = (CastQuad *) quad;
          intToFloatToMips(itof);
        } else if ("ftoi" == quad->op) {
          CastQuad * ftoi = (CastQuad *) quad;
          floatToIntToMips(ftoi);
        } else if ("begin_function" == quad->op) {
          BeginFunctionQuad * begfun = (BeginFunctionQuad *) quad;
          beginToMips(begfun);
        } else {
          // Caso de declaraciones y block comments, esos se ignoran
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

      tempFile << ".align 4" << std::endl;

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
        instructions->push_back(new MoveMips(A0_REGISTER, rd));
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
      allocator->clear();
    }

    void assignToMips(AssignQuad * assign) {
      VarQuad * var = (VarQuad *) assign->getResult();
      MipsRegister * rd, * rl;
      allocator->getReg(this, assign, &rd, &rl, NULL);
      instructions->push_back(new MoveMips(rd, rl));
    }

    void assignToArrayToMips(AssignToArrayQuad * assign) {
      VarQuad * var = (VarQuad *) assign->getResult();
      MipsRegister * rl, * rr;
      allocator->getReg(this, assign, NULL, &rl, &rr);
//FIXME global

      if (var->is_arg) {
        MipsRegister * raux = allocator->getAuxReg();
        instructions->push_back(new AddiMips(raux, ZERO_REGISTER, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(raux, raux, FP_REGISTER));
        instructions->push_back(new LoadWordMips(raux, new MipsOffset(raux->num, 4)));
        instructions->push_back(new AddMips(rl, rl, raux));
        instructions->push_back(new StoreWordMips(rr, new MipsOffset(rl->num, 0)));
      } else if (var->is_glob) {
        MipsRegister * raux = allocator->getAuxReg();
        instructions->push_back(new LoadAddressMips(raux, new MipsVariable(var->vname)));
        instructions->push_back(new AddiMips(raux, raux, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(rr, rr, raux));
        instructions->push_back(new StoreWordMips(rr, new MipsOffset(rl->num, 0)));
      } else {
        instructions->push_back(new AddiMips(rl, rl, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(rl, rl, SP_REGISTER));
        instructions->push_back(new StoreWordMips(rr, new MipsOffset(rl->num, 4)));
      }

    }

    void assignArrayToMips(AssignArrayQuad * assign) {
      VarQuad * var = (VarQuad *) assign->getArg1();
      MipsRegister * rd, * rr;
      allocator->getReg(this, assign, &rd, NULL, &rr);
//FIXME global

      if (var->is_arg) {
        MipsRegister * raux = allocator->getAuxReg();
        instructions->push_back(new AddiMips(raux, ZERO_REGISTER, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(raux, raux, FP_REGISTER));
        instructions->push_back(new LoadWordMips(raux, new MipsOffset(raux->num, 4)));
        instructions->push_back(new AddMips(rr, rr, raux));
        instructions->push_back(new LoadWordMips(rd, new MipsOffset(rr->num, 0)));
      } else if (var->is_glob) {
        MipsRegister * raux = allocator->getAuxReg();
        instructions->push_back(new LoadAddressMips(raux, new MipsVariable(var->vname)));
        instructions->push_back(new AddiMips(raux, raux, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(rr, rr, raux));
        instructions->push_back(new LoadWordMips(rd, new MipsOffset(rr->num, 0)));
      } else {
        instructions->push_back(new AddiMips(rr, rr, new MipsImmediate(var->offset)));
        instructions->push_back(new AddMips(rr, rr, SP_REGISTER));
        instructions->push_back(new LoadWordMips(rd, new MipsOffset(rr->num, 4)));
      }

    }

    void allocateToMips(AllocateStackQuad * allocate) {
      ConstQuad * space = (ConstQuad *) allocate->getResult();
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-(space->num))));
    }

    void addToMips(AddQuad * add) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, add, &rd, &rl, &rr);
      instructions->push_back(new AddMips(rd, rl, rr));
    }

    void subToMips(SubQuad * sub) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, sub, &rd, &rl, &rr);
      instructions->push_back(new SubMips(rd, rl, rr));
    }

    void mulToMips(MulQuad * mul) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, mul, &rd, &rl, &rr);
      instructions->push_back(new MultMips(rd, rl, rr));
    }

    void divToMips(DivQuad * div) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, div, &rd, &rl, &rr);
      instructions->push_back(new DivMips(rl, rr));
      instructions->push_back(new MoveFromLowMips(rd));
    }

    void modToMips(ModQuad * mod) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, mod, &rd, &rl, &rr);
      instructions->push_back(new DivMips(rl, rr));
      instructions->push_back(new MoveFromHighMips(rd));
    }

    void lessToMips(LessQuad * less) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, less, &rd, &rl, &rr);
      instructions->push_back(new SetLessMips(rd, rl, rr));
    }

    void lesseqToMips(LessEqualQuad * lesseq) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, lesseq, &rd, &rl, &rr);
      instructions->push_back(new SetLessEqualMips(rd, rl, rr));
    }

    void greaterToMips(GreaterQuad * greater) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, greater, &rd, &rl, &rr);
      instructions->push_back(new SetGreaterMips(rd, rl, rr));
    }

    void greatereqToMips(GreaterEqualQuad * greatereq) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, greatereq, &rd, &rl, &rr);
      instructions->push_back(new SetGreaterEqualMips(rd, rl, rr));
    }

    void equalToMips(EqualQuad * equal) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, equal, &rd, &rl, &rr);
      VarQuad * jumpLabel = (VarQuad *) equal->getArg2();
      instructions->push_back(new SetEqualMips(rd, rl, rr));
    }

    void notequalToMips(NotEqualQuad * notequal) {
      //Creo que no funciona para el caso donde de verdad quiero usar el valor x < y
      //solo sirve para una condición donde se genera jumping code
      MipsRegister * rd, * rl, *rr;
      allocator->getReg(this, notequal, &rd, &rl, &rr);
      VarQuad * jumpLabel = (VarQuad *) notequal->getArg2();
      instructions->push_back(new SetNotEqualMips(rd, rl, rr));
    }

    void andToMips(AndQuad * andquad) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, andquad, &rd, &rl, &rr);
      instructions->push_back(new AndMips(rd, rl, rr));
    }

    void orToMips(OrQuad * orquad) {
      MipsRegister * rd, * rl, * rr;
      allocator->getReg(this, orquad, &rd, &rl, &rr);
      instructions->push_back(new OrMips(rd, rl, rr));
    }

    void ifToMips(IfQuad * ifquad) {
      MipsRegister *rd;
      allocator->getReg(this, ifquad, &rd, NULL, NULL);
      VarQuad * jumpLabel = (VarQuad *) ifquad->getArg2();
      instructions->push_back(new BranchNotEqualZeroMips(rd, new MipsVariable(jumpLabel->vname)));
    }

    void ifnotToMips(IfNotQuad * ifnotquad) {
      MipsRegister *rd;
      allocator->getReg(this, ifnotquad, &rd, NULL, NULL);
      VarQuad * jumpLabel = (VarQuad *) ifnotquad->getArg2();
      instructions->push_back(new BranchEqualZeroMips(rd, new MipsVariable(jumpLabel->vname)));
    }

    void gotoToMips(GotoQuad * gotoquad) {
      VarQuad * jumpLabel = (VarQuad *) gotoquad->getResult();
      instructions->push_back(new JumpMips(new MipsVariable(jumpLabel->vname)));
    }

    void paramToMips(ParamQuad * param) {
      MipsRegister *rd;
      allocator->getReg(this, param, &rd, NULL, NULL);
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      instructions->push_back(new StoreWordMips(rd, new MipsOffset((SP_REGISTER)->num, 4)));
    }

    void paramrefToMips(ParamRefQuad * param) {
      MipsRegister *rb, *rd;
      rd = allocator->getAuxReg();
      VarQuad * variable = (VarQuad *) param->getResult();

      if (variable->is_ref) {
        instructions->push_back(new AddiMips(rd, ZERO_REGISTER, new MipsImmediate(variable->offset)));
        rb = (variable->is_arg) ? FP_REGISTER : SP_REGISTER;
        instructions->push_back(new AddMips(rd, rd, rb));
        instructions->push_back(new LoadWordMips(rd, new MipsOffset(rd->num, 4)));
        instructions->push_back(new StoreWordMips(rd, new MipsOffset((SP_REGISTER)->num, 0)));
        instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      } else {
        instructions->push_back(new AddiMips(rd, ZERO_REGISTER, new MipsImmediate(variable->offset + 4)));
        rb = (variable->is_arg) ? FP_REGISTER : SP_REGISTER;
        instructions->push_back(new AddMips(rd, rd, rb));
        instructions->push_back(new StoreWordMips(rd, new MipsOffset((SP_REGISTER)->num, 0)));
        instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      }
    }

    void callToMips(FunctionCallReturn * call) {
      MipsRegister *rl;
      VarQuad * function = (VarQuad *) call->getArg1();

      if (function->is_ref) {
        allocator->getReg(this, call, NULL, &rl, NULL);
        instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      } else {
        rl = allocator->getAuxReg();
        instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
        instructions->push_back(new LoadAddressMips(rl, new MipsVariable(function->vname)));
      }

      instructions->push_back(new JumpFunctionMips(rl));
      allocator->clear();
    }

    void minusToMips(UnaryMinusQuad * minus) {
      MipsRegister *rd, *rl;
      allocator->getReg(this, minus, &rd, &rl, NULL);
      instructions->push_back(new UnaryMinusMips(rd, rl));
    }

    void notToMips(NotQuad * notquad) {
      MipsRegister *rd, *rl;
      allocator->getReg(this, notquad, &rd, &rl, NULL);
      instructions->push_back(new NotMips(rd, rl));
    }

    void sleepToMips(SleepQuad * sleep) {}

    void returnToMips(ReturnQuad * ret) {
      allocator->flush(this);
      allocator->clear();
      instructions->push_back(new LoadWordMips(RA_REGISTER, new MipsOffset((FP_REGISTER)->num, -4)));
      instructions->push_back(new MoveMips(SP_REGISTER, FP_REGISTER));
      instructions->push_back(new LoadWordMips(FP_REGISTER, new MipsOffset((FP_REGISTER)->num, -8)));
      instructions->push_back(new JumpRegisterMips(RA_REGISTER));
    }

    void returnexpToMips(ReturnExpQuad * ret) {
      MipsRegister *rd;
      allocator->getReg(this, ret, &rd, NULL, NULL);
      instructions->push_back(new StoreWordMips(rd, new MipsOffset((FP_REGISTER)->num, 0)));
      allocator->flush(this);
      allocator->clear();
      instructions->push_back(new LoadWordMips(RA_REGISTER, new MipsOffset((FP_REGISTER)->num, -4)));
      instructions->push_back(new MoveMips(SP_REGISTER, FP_REGISTER));
      instructions->push_back(new LoadWordMips(FP_REGISTER, new MipsOffset((FP_REGISTER)->num, -8)));
      instructions->push_back(new JumpRegisterMips(RA_REGISTER));
    }

    void derefToMips(DerefQuad * deref) {}
    void refToMips(RefQuad * ref) {}

    void prologueToMips(PrologueQuad * prologue) {
      ConstQuad *space = (ConstQuad *) prologue->getResult();
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      instructions->push_back(new StoreWordMips(RA_REGISTER, new MipsOffset((SP_REGISTER)->num, 4)));
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-4)));
      instructions->push_back(new StoreWordMips(FP_REGISTER, new MipsOffset((SP_REGISTER)->num, 4)));
      instructions->push_back(new AddiMips(FP_REGISTER, SP_REGISTER, new MipsImmediate(12)));
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(-(space->num))));
    }

    void epilogueToMips(EpilogueQuad * epilogue) {
      ConstQuad *space = (ConstQuad *) epilogue->getArg1();
      MipsRegister *rd;
      allocator->getReg(this, epilogue, &rd, NULL, NULL);
      instructions->push_back(new LoadWordMips(rd, new MipsOffset((SP_REGISTER)->num, 0)));
      instructions->push_back(new AddiMips(SP_REGISTER, SP_REGISTER, new MipsImmediate(space->num)));
    }

    void beginToMips(BeginFunctionQuad * begfun) {
      allocator->flush(this);
    }

    void charToIntToMips(CastQuad * ctoi) {}
    void intToCharToMips(CastQuad * itoc) {}
    void intToFloatToMips(CastQuad * itof) {}
    void floatToIntToMips(CastQuad * ftoi) {}




};

#endif
