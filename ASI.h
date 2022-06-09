#ifndef ASI_H
#define ASI_H
#include "Instruction.h"

class ASI : public instruction
{
public:
	ASI(int _rs1, int _rd, int* _data_memory);
	void executeInstruction() override;
	~ASI();

private:
	int rs1;
	int rd;
	int* data_memory;
};

#endif