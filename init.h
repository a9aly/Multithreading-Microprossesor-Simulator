#ifndef INIT_H 
#define INIT_H 
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>
#include "memoryHandler.h"
using namespace std;
namespace fs = std::filesystem;

void init (string fileName);
vector<string> Tokenize(string const& input);
#endif 
