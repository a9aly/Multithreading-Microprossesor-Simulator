#ifndef JPo_H
#define JPo_H
#include "instruction.h"

class JPo : public instruction
{
public:
	JPo(int _rs1, int _rs2, int* _curr_instMEM, int * _datamemory);
	void executeInstruction() override;
	~JPo();

private:
	int rs1;
	int rs2;
	int* datamemory;
	int* curr_instMEM;
};

#endif