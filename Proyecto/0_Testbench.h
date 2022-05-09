#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:
	sc_in_clk clk;
	//ins_men
	sc_in<sc_int<32>> instructionNumberIn;
	sc_in<sc_uint<32>> operationOut;

	//Unidad control
	sc_in<sc_uint<2>> Ex_ALUOpOut;
 	sc_in<bool> Ex_ALUSrcOut;
 	sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
 	sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
  	sc_in<sc_uint<4>> dir_In;

	//register
  	sc_in<sc_uint<5>> rwIn; 	  
  	sc_in<sc_uint<5>> raIn; 	  
  	sc_in<sc_uint<5>> rbIn; 	  
 	sc_in<sc_int<32>> wIn;  	
  	sc_in<bool> weIn; 			   
 	sc_in<sc_int<32>> aOut;  
  	sc_in<sc_int<32>> bOut;  


	//alu
 	sc_in<sc_uint<4>> insIn_alu;
	sc_in<sc_int<32>> number_1In_alu, number_2In_alu;
  	sc_in<sc_int<32>>  resultOut_alu;	
  	sc_in<bool> zeroOut_alu;


	//data_memory
  	sc_in<sc_int<32>> addressIn;     //dirección de registro 
 	sc_in<sc_int<32>> read_dataOut;     //valor a escribir
 	sc_in<sc_int<32>> write_dataIn;   // valor a
 	sc_in<bool> writeIn, readIn;        //	
	SC_CTOR(Testbench);

	//mux
 	sc_in<sc_int<32>> aIn, bIn;
  	sc_in<sc_int<32>> cOut;
  	sc_in<bool> sIn;	

private:
	void operation();
	void print();
};

#endif
