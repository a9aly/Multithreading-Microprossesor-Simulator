#include "LOE.h"

LOE::LOE(int _rs1, int _rs2, int _rd, int* _data_memory)
{
	rs1 = _rs1;
	rs2 = _rs2;
	rd = _rd;
	name = "LOE";
	data_memory = _data_memory;
	cout << "The SIM just introduced a LOE operation to the instruction memory using memory locations "
		<< rs1 << " with value " << data_memory[rs1] <<
		" and location " << rs2 << " with value " << data_memory[rs2]
		<< " to be stored at " << rd << endl;
}

void  LOE::executeInstruction()
{
	if (data_memory[rs1] <= data_memory[rs2])
	{
		m.lock();
		data_memory[rd] = data_memory[rs1];
		m.unlock();
	}
	else
	{
		m.lock();
		data_memory[rd] = data_memory[rs2];
		m.unlock();
	}

	cout << "The SIM just compared memory location " << rs1
		<< " with value " << data_memory[rs1]
		<< " & memory location " << rs2 << " with value " << data_memory[rs2]
		<< " and stored smaller value in memory location " << rd << " which is " << data_memory[rd] <<  endl;

}

LOE::~LOE()
{

}