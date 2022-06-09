#include "JPo.h"

JPo::JPo(int _rs1, int _rs2, int* _curr_instMEM, int* _datamemory)
{
	rs1 = _rs1;
	rs2 = _rs2;
	curr_instMEM = _curr_instMEM;
	datamemory = _datamemory;
	cout << "The SIM just introduced a JP0 operation to the instruction memory on data memory number" << rs1 << endl;
}

void JPo::executeInstruction()
{
	cout << "The SIM just executed a JPo operation" << endl;
	if (datamemory[rs1] == 0)
	{
		m.lock();
		*curr_instMEM = rs2;
		m.unlock();
		cout << "Current instruction changed to " << *curr_instMEM << " since memory location " << rs1 << " is equal to 0 now"  << endl;
	}
	else
	{
		cout << "Data stored in memory location " << rs1 << " is not 0" << endl;
	}
}

JPo::~JPo()
{

}