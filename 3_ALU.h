#ifndef ALU_H
#define ALU_H

#include <systemc.h>

class ALU : public sc_module
{
public:
	sc_in_clk clk;
 	sc_in<sc_uint<4>> insIn;						//valor instantaneo
	sc_in<sc_int<32>> number_1In, number_2In;	//primer operando
  	sc_out<sc_int<32>>  resultOut;					//segundo operando
  	sc_out<bool> zeroOut;							//bit que va hacia el branch para indicar salto


	SC_CTOR(ALU);

private:
	void operation();
};

#endif
