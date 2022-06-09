#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H
#define MEMORY_SIZE 1024
#include <vector>
#include <mutex>
#include "instruction.h"
#include "add.h"
#include "NEG.h"
#include "MUL.h"
#include "JPA.h"
#include "JPo.h"
#include "ASI.h"
#include "LOE.h"
#include "HLT.h"

class memoryHandler
{
public:
    memoryHandler(int number_of_inst_memories);
    void newInstruction(vector<string> instruction);
    void executeInstructions(int i);
    ~memoryHandler();
    mutex z;

private:
    vector <vector<instruction*>> inst_memory;
    int data_memory[MEMORY_SIZE];
    int inst_mem_num = 0;
    vector <int> curr_instMEM;
};
#endif 
