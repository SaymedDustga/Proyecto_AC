#include "4_EX_MEM.h"

EX_MEM::EX_MEM(sc_module_name nm) : sc_module(nm)
{

	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void EX_MEM::operation()
{

	for (int i = 0; i < 3; i++){
		memo_Out[i].write(memo_In[i].read());
	}
	memo_Out[3].write(memo_In[1].read());//esto es para pasar la ramificacion que se hace en mem
											 //debido a que como ya se dvide el cable para dirigirlo a 
											 //el testbench no se puede dividir mas

	dir_Out.write(dir_In.read());

	alu_to_brachOut.write(alu_to_brachIn.read());
	Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
//	std:: cout << "Estoy en EX_MEM y Mem_branchIn es: " << Mem_BranchIn.read() << endl;
	Mem_BranchOut.write(Mem_BranchIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
	std:: cout << "Estoy en EX_MEM y ALU_to_branch_in: " << alu_to_brachIn.read() << endl;
	std:: cout << "Estoy en EX_MEM y memoIn[0] es: " << memo_In[0].read() << endl;

}
