#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <systemc.h>
#include <fstream>

class InstructionMemory : public sc_module {

public:

	sc_in_clk clk;
	sc_in<sc_uint<32>> instructionNumberIn;
	sc_out<sc_uint<32>> operationOut;
	SC_CTOR(InstructionMemory); 

private:
	void operation();
	void list(string);
	bool initialized;
};

#endif
