#include "MUL.h"

MUL::MUL(int _rs1, int _rs2, int _rd, int* _data_memory)
{
	rs1 = _rs1;
	rs2 = _rs2;
	rd = _rd;
	name = "MUL";
	data_memory = _data_memory;
	cout << "The SIM just introduced a MUL operation to the instruction memory using memory locations "
		<< rs1 << " with value " << data_memory[rs1] <<
		" and location " << rs2 << " with value " << data_memory[rs2]
		<< " to be stored at " << rd << endl;
}

void MUL::executeInstruction ()
{
	cout << "The SIM just multiplied memory location " << rs1
		<< " with value " << data_memory[rs1]
		<< " & memory location " << rs2 << " with value " << data_memory[rs2];
	m.lock();
	data_memory[rd] = data_memory[rs1] * data_memory[rs2];
	m.unlock();
	cout << " and stored it in memory location " << rd << " now with value: " << data_memory[rd] << endl;
}

MUL::~MUL()
{}