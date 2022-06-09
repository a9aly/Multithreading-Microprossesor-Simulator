#ifndef LOE_H
#define LOE_H
#include "instruction.h"
class LOE : public instruction {
public:
	LOE(int _rs1, int _rs2, int _rd, int* _data_memory);
	void executeInstruction() override;
	~LOE();
private:
	int rs1;
	int rs2;
	int rd;
	int* data_memory;
};

#endif