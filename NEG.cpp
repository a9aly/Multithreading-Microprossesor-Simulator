#include "NEG.h"

NEG::NEG(int _rs1, int _rd, int* _data_memory)
{
	rs1 = _rs1;
	rd = _rd;
	name = "NEG";
	data_memory = _data_memory;
	cout << "The SIM just introduced a NEG operation to the instruction memory using memory locations "
		<< rs1 << " with value " << data_memory[rs1] << " to be stored at " << rd << endl;
}

void NEG::executeInstruction()
{
	cout << "The SIM just negated memory location " << rs1
		<< " with value " << data_memory[rs1];
	m.lock();
	data_memory[rd] = -data_memory[rs1];
	m.unlock();
	cout << " and stored it in memory location " << rd << " now with value: " << data_memory[rd] << endl;
};
