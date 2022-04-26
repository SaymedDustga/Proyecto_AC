#ifndef PC_H
#define PC_H

#include <systemc.h>

class PC : public sc_module
{
public:
	sc_in_clk clk;
	sc_in<sc_uint<32>> adressIn;
	sc_out<sc_uint<32>> adressOut;
	SC_CTOR(PC);
private:
	sc_uint<32> adress;
	void read();
	void write();
};

#endif