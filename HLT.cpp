#include "HLT.h"

HLT::HLT(int* _curr_instMEM)
{
	curr_instMEM = _curr_instMEM;
	name = "HLT";
	cout << "The SIM just introduced a HLT instruction the instruction memory at address " << *curr_instMEM << endl;
}

void HLT::executeInstruction()
{
	m.lock();
	*curr_instMEM = -2;
	m.unlock();
	cout << "HLT instruction is executed"<<endl;
}

HLT::~HLT()
{

}
