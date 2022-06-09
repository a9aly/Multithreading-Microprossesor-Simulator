#include "init.h"
void init(string fileName)
{
	/*read directory file names*/
	vector <string> fileNames;
	for (const auto& files : fs::directory_iterator(fileName))
	{
		stringstream temp;
		temp << files.path();
		string temp2 = temp.str();
		if (temp2.find("\\") != -1)
		{
			int start = temp2.find("\\") + 2;
			temp2 = temp2.substr(start,temp2.length()-start-1);
		}
		fileNames.push_back(fileName + '/' + temp2);
	}
	
	int number_of_inst_memories = fileNames.size();
	memoryHandler obj (number_of_inst_memories);
	
	/*read file name*/
	for (auto i : fileNames)
	{
		ifstream file;
		vector<string> readTokenized;
		/*check if file is opened successfully */
		try
		{
			file.open(i);
			if (!file.is_open())
			{
				throw 1;
			}
			/*read file line by line and add prepare instruction memory*/
			else
			{
				string read;
				while (!file.eof())
				{ 
					getline(file, read);
					readTokenized = Tokenize(read);
					obj.newInstruction(readTokenized);
				}
				vector<string> tempN;
				tempN.push_back("NEW");
				obj.newInstruction(tempN);
			}
		}
		catch (int errMsg)
		{
			std::cout << "Exception " << errMsg << ": Couldn't open the file \n";
		}
	}

	std::vector<std::thread> threads(number_of_inst_memories);

	for (int a = 0; a < number_of_inst_memories; a++)
	{
		threads[a] = thread(&memoryHandler::executeInstructions, ref(obj),a);

	}
	for (int w = 0; w < number_of_inst_memories; w++)
	{
		threads[w].join();
	}
	
}

vector<string> Tokenize(string const& input)
{
	vector<string> TokenizedString;
	stringstream inputStream(input);	    // construct a stream from the string
	string inputStorage;

	while (getline(inputStream, inputStorage, ' '))
		TokenizedString.push_back(inputStorage);

	return TokenizedString;
}

