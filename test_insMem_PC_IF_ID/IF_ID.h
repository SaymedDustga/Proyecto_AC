#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class IF_ID : public sc_module{

	public:

		sc_in_clk clk;													
		sc_in<sc_int<32>> pcIn;
		sc_in<sc_int<32>> insMemIn;						
		sc_out<sc_int<32>> register1Out;
		sc_out<sc_int<32>> ID_EXOut;
//		sc_out<sc_int<32>> register2Out;
//		sc_out<sc_int<32>> instruction1Out;
//		sc_out<sc_int<32>> instruction2Out;
//		sc_out<sc_int<32>> instruction3Out;
		SC_CTOR(IF_ID);
		
	private:

		void operation();
};

#endif
