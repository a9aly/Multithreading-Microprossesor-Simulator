#ifndef ADD_H
#define ADD_H
#include "instruction.h"
class ADD : public instruction
{
	public:
		ADD(int _rs1, int _rs2, int _rd, int* _data_memory);
		void executeInstruction() override;
		~ADD();
	private:
		int rs1;
		int rs2;
		int rd;
		int* data_memory;
};

#endif