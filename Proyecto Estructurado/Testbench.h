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

	sc_in<sc_int<32>> PcIn;
	sc_in<sc_int<32>> InsMemIn; //Aqui leemos la cadena de 32 bits en forma separada
	sc_in<sc_int<32>> fileRegister1In; 
	sc_in<sc_int<32>> fileRegister2In;  // Este también puede ser el mismo valor a guardar en la cache L!
	sc_in<bool> zeroIn; 
	sc_in<sc_int<32>> ALUResultIn; 
	sc_in<sc_int<32>> DataMemoryIn; 
	sc_in<bool> RegisterFileIn;
	sc_in<bool> MemIn;
	sc_in<bool> Branch;
	sc_in<bool> MemToReg;
	sc_in<bool> RegWrite;

	sc_in<sc_int<32>> ID_EX0In;
	sc_in<sc_int<32>> register1In;
	sc_in<sc_int<32>> register2In;
	sc_in<sc_int<8>> Imm_genIn;
	sc_in<sc_int<8>> ID_EX1IN;
	sc_in<sc_int<8>> ID_EX2IN;

	sc_out<bool> muxSgOut;
	sc_out<sc_int<32>> muxIn2;
	sc_out<sc_int<32>> adderIn2;
	sc_out<sc_int<8>> writeRegisterOut;
	sc_out<sc_int<32>> writeDataOut;


	SC_CTOR(Testbench);

private:
	void operation();
	//void print();
};

#endif
