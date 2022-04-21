#ifndef IMM_GEN_H
#define IMM_GEN_H

#include <systemc.h>

class Imm_Gen : public sc_module{

	public:

		sc_in_clk clk;													
		sc_in<sc_uint<32>> IF_IDIn;						
		sc_out<sc_uint<32>> ID_EXOut;
		SC_CTOR(Imm_Gen);
		
	private:

		void operation();
};

#endif
