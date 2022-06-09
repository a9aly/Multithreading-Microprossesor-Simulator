#ifndef JPA_H
#define JPA_H
#include "instruction.h"

class JPA : public instruction
{
public:
	JPA(int _rs1, int* _curr_instMEM);
	void executeInstruction() override;
	~JPA();

private:
	int rs1;
	int* curr_instMEM;
};
#endif