#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>
#include "Imm_Gen.h"


class Testbench : public sc_module {
public:

	sc_in_clk clk;													
	sc_out<sc_uint<32>> IF_IDOut;						
	sc_in<sc_uint<32>> ID_EXIn;
	SC_CTOR(Testbench);

private:
	void operation();
	void print();
};

#endif
