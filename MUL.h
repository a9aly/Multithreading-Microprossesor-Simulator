#ifndef MUL_H
#define MUL_H
#include "instruction.h"

class MUL : public instruction
{
	public:
		MUL(int _rs1, int _rs2, int _rd, int* _data_memory);
		void executeInstruction() override;
		~MUL();
	private:
		int rs1;
		int rs2;
		int rd;
		int* data_memory;
};
#endif 
