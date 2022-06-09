#ifndef NEG_H
#define NEG_H
#include "instruction.h"

class NEG : public instruction
{
	public:
		NEG(int _rs1, int _rd, int* _data_memory);
		void executeInstruction() override;
		~NEG() {};

	private:
		int rs1;
		int rd;
		int* data_memory;
};
#endif