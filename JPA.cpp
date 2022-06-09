#include "JPA.h"

JPA::JPA(int _rs1, int* _curr_instMEM)
{
	rs1 = _rs1;
	curr_instMEM = _curr_instMEM;
	name = "JPA";
	cout << "The SIM just introduced a JPA operation to the instruction memory with value "
		<< rs1 << endl;
}

void JPA::executeInstruction()
{
	m.lock();
	*curr_instMEM = rs1;
	m.unlock();
	cout << "Current instruction changed to " << *curr_instMEM << endl;
}

JPA::~JPA()
{

}