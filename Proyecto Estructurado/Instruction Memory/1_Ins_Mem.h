#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <systemc.h>
#include <fstream>
#include <string>

class InstructionMemory : public sc_module
{

public:
	sc_in<sc_int<32>> instructionNumberIn;
	sc_out<sc_int<32>> operationOut;

	SC_CTOR(InstructionMemory);
	~InstructionMemory();

private:
	size_t numberOfInstructions;
	std::string *instructionList;
	sc_int<32> intAux;
	void operation();
	void list(std::string);
};

#endif
