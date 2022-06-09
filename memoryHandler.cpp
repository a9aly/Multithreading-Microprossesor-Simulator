#include "memoryHandler.h"

memoryHandler::memoryHandler(int number_of_inst_memories)
{
	curr_instMEM.push_back(0);
    for (int i = 0; i < 1024; i++)
        data_memory[i] = 0;

	for (int k = 0; k < number_of_inst_memories; k++)
	{
		inst_memory.push_back(vector<instruction*>());
		for (int z = 0; z < 1024; z++)
		{
			inst_memory[k].push_back(NULL);
		}
	}
	inst_mem_num += 1;
}

void memoryHandler::newInstruction( vector<string> instruction)
{
	int vectorSize = instruction.size();
	string operation;
	if (vectorSize > 0 && curr_instMEM[inst_mem_num-1]<1024)
	{
		operation = instruction.at(0);
		/*check for operation type and if it is enterd correctly*/
		if (operation == "ADD")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num-1]] = new ADD(stoi(instruction.at(1)), stoi(instruction.at(2)), stoi(instruction.at(3)), data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num-1]++;
		}
		else if (operation == "NEG")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num-1]] = new NEG(stoi(instruction.at(1)), stoi(instruction.at(2)), data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			curr_instMEM[inst_mem_num-1]++;
		}
		else if (operation == "MUL")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num-1]] = new MUL(stoi(instruction.at(1)), stoi(instruction.at(2)), stoi(instruction.at(3)), data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num-1]++;
		}
		else if (operation == "JPA")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num - 1]] = new JPA(stoi(instruction.at(1)), &curr_instMEM[inst_mem_num - 1]);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num - 1]++;
		}
		else if (operation == "JP0")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num - 1]] = new JPo(stoi(instruction.at(1)), stoi(instruction.at(2)), &curr_instMEM[inst_mem_num - 1], data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num - 1]++;
		}
		else if (operation == "ASI")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num - 1]] = new ASI (stoi(instruction.at(1)), stoi(instruction.at(2)), data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num - 1]++;
		}
		else if (operation == "LOE")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num - 1]] = new LOE(stoi(instruction.at(1)), stoi(instruction.at(2)), stoi(instruction.at(3)), data_memory);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << endl;
			curr_instMEM[inst_mem_num - 1]++;
		}
		else if (operation == "HLT")
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			inst_memory[inst_mem_num-1][curr_instMEM[inst_mem_num - 1]] = new HLT (&curr_instMEM[inst_mem_num - 1]);
			//inst_memory[curr_instMEM]->executeInstruction();	// test the instruction work
			//cout << curr_instMEM;
			curr_instMEM[inst_mem_num - 1]++;
		}
		else if (operation == "NEW")
		{
			inst_mem_num += 1;
			curr_instMEM.push_back(0);
		}
		else
		{
			cout << "Instruction Memory: " << inst_mem_num - 1 << endl;
			cout << operation << " THIS IS A WRONG INSTRUCTION NAME" << endl;
		}
	}
}

void memoryHandler::executeInstructions(int i)
{

	int count_instMEM = curr_instMEM[i];
	curr_instMEM[i] = 0;
	cout << endl << "--------------------------- EXECUTION --------------------------- " << endl;
	do
	{
		z.lock();
		cout << "Thread: " << this_thread::get_id() << " working on instruction memory " << i <<endl;
		cout << "Instruction: " << curr_instMEM[i] << endl;
		z.unlock();
		int tempBeforeExecution = curr_instMEM[i];
		inst_memory[i][curr_instMEM[i]]->executeInstruction();
		int temp = curr_instMEM[i];
		if (temp > count_instMEM)
		{
			cout << "INVALID INSTUCTION MEMORY ADDRESSING USING " << inst_memory[i][curr_instMEM[i]]->name << " instruction\n";
			cout << "NEXT INSTRUCTION WILL BE EXECUTED AND THIS ONE WILL BE NEGLECTED \n" << endl;
		}
		/*avoid incrementing by jump instructions using conditional if and also avoiding jumb infinite loop*/
		if(curr_instMEM[i] == tempBeforeExecution)
			curr_instMEM[i]++;

	} while (curr_instMEM[i] >= 0 && curr_instMEM[i] < 1024 && curr_instMEM[i] < count_instMEM);
}
memoryHandler:: ~memoryHandler()
{
	
}
