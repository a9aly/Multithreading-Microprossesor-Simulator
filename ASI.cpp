#include "ASI.h"
ASI::ASI(int _rs1, int _rd, int* _data_memory)
{
	rs1 = _rs1;
	rd = _rd;
	data_memory = _data_memory;
	name = "ASI";
	cout << "The SIM just introduced an ASI operation to the instruction memory with value " 
		<< rs1 << " to be stored at " << rd <<endl; 
}

 void ASI::executeInstruction()
{
	m.lock();
	data_memory[rd] = rs1;
	m.unlock();
	cout << "The SIM just stored in memory location " << rd << " now with value: " << rs1 << endl;
}

ASI::~ASI()
{

}