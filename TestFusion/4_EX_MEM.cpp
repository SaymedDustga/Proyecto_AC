#include "4_EX_MEM.h"

EX_MEM::EX_MEM(sc_module_name nm) : sc_module(nm)
{

	SC_METHOD(operation);
	sensitive << clkIn.neg();
//	dont_initialize();
}

void EX_MEM::operation()
{
	for (int i = 0; i < 3; i++)
		memo_Out[i].write(memo_In[i].read());


	dir_Out.write(dir_In.read());

	alu_to_brachOut.write(alu_to_brachIn.read());
	Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
	Mem_BranchOut.write(Mem_BranchIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}
