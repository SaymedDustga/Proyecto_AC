#ifndef TESTBENCH_H1
#define TESTBENCH_H1

#include <iostream>
#include <systemc.h>


class Testbench1 : public sc_module {
public:


	sc_in_clk clk;
	
  	//if_id
	sc_in<sc_int<8>> fileRegister1Out;
	sc_in<sc_int<8>> fileRegister2Out;
	sc_in<sc_int<8>> immGenOut;
	sc_in<sc_int<32>> ID_EX0Out;
	sc_in<sc_int<8>> ID_EX1Out;
	sc_in<sc_int<8>> ID_unidadControl;
	sc_in<sc_int<8>> ID_EX2Out;

	//Unidad control
	sc_in<sc_uint<2>> Ex_ALUOpOut;
 	sc_in<bool> Ex_ALUSrcOut;
 	sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
 	sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
  	sc_in<sc_int<8>> dir_In;

  	//imm gem
  	sc_in<sc_int<8>> IF_IDIn;						
	sc_in<sc_int<32>> ID_EXOut;

	//register
  	sc_in<sc_int<8>> rwIn; 	  
  	sc_in<sc_int<8>> raIn; 	  
  	sc_in<sc_int<8>> rbIn; 	  
 	sc_in<sc_int<32>> wIn;  	
  	sc_in<bool> weIn; 			   
 	sc_in<sc_int<32>> aOut;  
  	sc_in<sc_int<32>> bOut;  

  	//id_ex
	sc_in<bool> Ex_ALUSrcIn;
	sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn; 
	sc_in<sc_uint<2>>	Ex_ALUOpIn;	
	sc_in<sc_int<32>> Imm_genIn;
	sc_in<sc_int<32>> id_ex0In;
	sc_in<sc_int<8>> id_ex1In;
	sc_in<sc_int<8>> id_ex2In;
	sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_In, 2);


	SC_CTOR(Testbench1);

private:
	void operation();
	void print();
};

#endif
