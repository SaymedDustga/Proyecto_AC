#ifndef TESTBENCH_H2
#define TESTBENCH_H2

#include <iostream>
#include <systemc.h>


class Testbench2 : public sc_module {
public:


	sc_in_clk clk;
	
  	//if_ex
	sc_in<bool> Ex_ALUSrcOut;
	sc_in<sc_uint<2>>	Ex_ALUOpOut;			
	sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut; 	
	sc_in<sc_int<32>> Imm_gen1Out;
	sc_in<sc_int<32>> Imm_gen2Out;
	sc_in<sc_int<32>> id_ex0Out;
	sc_in<sc_int<8>> id_ex1Out;
	sc_in<sc_int<8>> id_ex2Out;
	sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_Out, 2); 

	//mux
  	sc_in<sc_int<32>> aIn, bIn;
  	sc_in<sc_int<32>> cOut;
  	sc_in<bool> sIn;	

	//adders
  	sc_in<sc_int<32>> number_1In, number_2In;
  	sc_in<sc_int<32>> resultOut;	

  	//alu control
  	sc_in<sc_uint<2>> Ex_ALUOpIn;
	sc_in<sc_int<8>> dir_In;
	sc_in<sc_int<8>> instruction_aluOut;

	//alu
 	sc_in<sc_int<8>> insIn_alu;
	sc_in<sc_int<32>> number_1In_alu, number_2In_alu;
  	sc_in<sc_int<32>>  resultOut_alu;	
  	sc_in<bool> zeroOut_alu;

  	//ex_men
	sc_in<bool> alu_to_brachIn;
	sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;
	sc_in<sc_int<32>> memo_In[3];
	sc_in<sc_int<8>> dir_In_;

	SC_CTOR(Testbench2);

private:
	void operation();
	void print();
};

#endif
