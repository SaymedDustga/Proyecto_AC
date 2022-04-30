#ifndef TESTBENCH_H4
#define TESTBENCH_H4

#include <iostream>
#include <systemc.h>


class Testbench4 : public sc_module {
public:


	sc_in_clk clk;
	//ex men
  	sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
 	sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_Out, 2);
 	sc_in<sc_int<8>> dir_Out;
	//mux
 	sc_in<sc_int<32>> aIn, bIn;
  	sc_in<sc_int<32>> cOut;
  	sc_in<bool> sIn;
	SC_CTOR(Testbench4);

private:
	void operation();
	void print();
};

#endif
