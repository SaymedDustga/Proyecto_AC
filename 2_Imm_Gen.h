#ifndef IMM_GEN_H
#define IMM_GEN_H

#include <systemc.h>

class Imm_Gen : public sc_module
{

public:

	sc_in_clk clk;               //señal de reloj
	sc_in<sc_int<18>> IF_IDIn;   //cable que viene desde el registro IF_ID
	sc_out<sc_int<32>> ID_EXOut; //cable que va hacia el registro ID_EX

	SC_CTOR(Imm_Gen);

private:
	void operation();
};

#endif
