#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench0 : public sc_module {
public:


	sc_in_clk clk;
	//uno
  	sc_in<sc_int<32>> uno;

	//pc
	sc_in<sc_int<32>> adressIn;
	sc_in<sc_int<32>> adressAdderOut;
	sc_in<sc_int<32>> adressPC_IF_IDOut;
	sc_in<sc_int<32>> adressInstructionMemoryOut;

	//adders
  	sc_in<sc_int<32>> number_1In, number_2In;
  	sc_in<sc_int<32>> resultOut;	

	//ins_men
	sc_in<sc_int<32>> instructionNumberIn;
	sc_in<sc_int<32>> operationOut;

	//mux
  	sc_in<sc_int<32>> aIn, bIn;
  	sc_in<sc_int<32>> cOut;
  	sc_in<bool> sIn;
  	//if_id
  	sc_in<sc_int<32>> pcIn;
	sc_in<sc_int<32>> insMemIn;


	SC_CTOR(Testbench0);

private:
	void operation();
	void print();
};

#endif
