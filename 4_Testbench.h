#ifndef TESTBENCH_H3
#define TESTBENCH_H3

#include <iostream>
#include <systemc.h>


class Testbench3 : public sc_module {
public:


	sc_in_clk clk;
	//ex men
	sc_in<bool> alu_to_brachOut, Wb_MemtoRegOut;
	sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_in<bool>  Wb_RegWriteOut; 
	sc_in<sc_int<32>> memo_Out[4];
	sc_in<sc_int<8>> dir_Out;	
	

	//data_memory
  	sc_in<sc_int<32>> addressIn;     //dirección de registro 
 	sc_in<sc_int<32>> read_dataOut;     //valor a escribir
 	sc_in<sc_int<32>> write_dataIn;   // valor a
 	sc_in<bool> writeIn, readIn;        //	

 	//branch
    sc_in<bool>  jumpIn, addressIn_;
    sc_in<bool> answerOut;	

    //men_wb
  	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;
  	sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_In, 2);
  	sc_in<sc_int<8>> dir_In;



	SC_CTOR(Testbench3);

private:
	void operation();
	void print();
};

#endif
