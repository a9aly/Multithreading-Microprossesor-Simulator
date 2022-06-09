#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include<thread>
#include <mutex>
using namespace std;

class instruction
{
public:
    string name;
    virtual void executeInstruction() {};
   mutex m;
};

#endif