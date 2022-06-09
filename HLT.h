#ifndef HLT_H
#define HLT_H
#include "instruction.h"
class HLT : public instruction {
public:
	HLT(int* _curr_instMEM);
	void executeInstruction() override;
	~HLT();
private:
	int* curr_instMEM;
};

#endif