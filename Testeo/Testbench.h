#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>
#include "Ins_Mem.h"
#include "PC.h"
#include "IF_ID.h"

class Testbench : public sc_module {
public:

	sc_in_clk clk;

	sc_out<bool> muxSgOut;
	sc_in<sc_int<32>> ID_EXIn;
	sc_in<sc_int<32>> register1In;

	sc_out<sc_int<32>> adderIn2;
	sc_out<sc_int<32>> muxIn2;


	SC_CTOR(Testbench);

private:
	void operation();
	//void print();
};

#endif
