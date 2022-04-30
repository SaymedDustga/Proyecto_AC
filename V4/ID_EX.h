#ifndef ID_EX
#define ID_EX

#include <systemc.h>

class id_ex : public sc_module
{
public:
	sc_in<bool> clkIn;
	sc_in<bool> Ex_ALUSrcIn, Ex_ALUOpIn;
	sc_in<bool> Men_MemWriteIn, Men_MemReadIn, Men_BranchIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_no_ideaIn; // ni idea para sirve sea esa señal de control
	// TB
	sc_out<bool> Ex_ALUSrcOut, Ex_ALUOpOut;
	sc_out<bool> Men_MemWriteOut, Men_MemReadOut, Men_BranchOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_no_ideaOut; // ni idea para sirve sea esa señal de control
  
	sc_in<sc_int<8>> Imm_genIn;
	sc_out<sc_int<8>> Imm_genOut;

	sc_in<sc_int<32>> id_ex0In;
	sc_out<sc_int<32>> id_ex0Out;

	sc_in<sc_int<8>> id_ex1In;
	sc_out<sc_int<8>> id_ex1out;

	sc_in<sc_int<8>> id_ex2In;
	sc_out<sc_int<8>> id_exOut;

	sc_in<sc_int<32>> memo_In[2];
	sc_out<sc_int<32>> memo_Out[2]; // TB


	SC_CTOR(id_ex);

private:
	void operation();
};

#endif
