#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H

#include <systemc.h>

class ALU_CONTROL : public sc_module
{
public:
	sc_in_clk clk;
	sc_in<sc_uint<2>> Ex_ALUOpIn;
	sc_in<sc_uint<4>> dir_In;
	sc_out<sc_uint<4>> instruction_aluOut;

	SC_CTOR(ALU_CONTROL);

private:
	void operation();
};

#endif
