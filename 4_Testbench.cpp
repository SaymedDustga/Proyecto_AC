#include "4_Testbench.h"
using namespace std;

Testbench3::Testbench3(sc_module_name mn) : sc_module(mn)
{
	SC_THREAD(operation);
	sensitive << clk.pos();
}

void Testbench3::operation()
{
	for (int i = 0; true; i++)
	{
		wait();
		print();
	}
}
void Testbench3::print()
{
	 cout<<"=========================FASE MEM==============================\n";
	 	//ex_men
	 cout<<"Modulo: EX MEM ------------------------\n";
		cout<<"  alu_to_brachOut :"<<  alu_to_brachOut.read()<<"\n";
		cout<<"  Mem_MemWriteOut :"<<  Mem_MemWriteOut.read()<<"\n";
	 cout<<"  Mem_MemReadOut :"<<  Mem_MemReadOut.read()<<"\n";
	 cout<<"  Mem_BranchOut :"<<  Mem_BranchOut.read()<<"\n";
		cout<<"  Wb_MemtoRegOut :"<< Wb_MemtoRegOut.read()<<"\n";
	 cout<<"  Wb_RegWriteOut :"<<  Wb_RegWriteOut.read()<<"\n";
	 cout<<"  memo_Out[0] (exMem_muxPC):"<< memo_Out[0].read().to_string()<<"\n";
	 cout<<"  memo_Out[1] (exMem_dataMemoryAddress):"<< memo_Out[1].read().to_string()<<"\n";
	 cout<<"  memo_Out[2] (exMem_dataMemoryData):"<< memo_Out[2].read().to_string()<<"\n";
	 cout<<"  memo_Out[3] (exMem_MemWb32bits):"<< memo_Out[3].read().to_string()<<"\n";

		cout<<"  dir_Out :"<<  dir_Out.read().to_string()<<"\n";
	 cout<<endl;

	 	cout<<"Modulo: DATA_MEMORY ------------------------\n";
	 	// DATA_MEMORY
//		cout<<"  addressIn :"<<  addressIn.read().to_string()<<"\n";
		cout<<"  read_dataOut :"<<  read_dataOut.read().to_string()<<"\n";
//		cout<<"  write_dataIn :"<< write_dataIn.read().to_string()<<"\n";
//		cout<<"  writeIn :"<<  writeIn.read()<<"\n";
//		cout<<"  readIn :"<<  readIn.read()<<"\n";
	 cout<<endl;

	 	// BRANCH
	 cout<<"Modulo:  BRANCH ------------------------\n";
//	 cout<<"  jumpIn :"<<   jumpIn.read()<<"\n";
//	   cout<<"  addressIn :"<<  addressIn.read()<<"\n";
	 cout<<"  answerOut :"<< answerOut.read()<<"\n";

		cout<<endl;

	//MEM_WB
//	 cout<<"Modulo : MEM_WB ------------------------\n";
//	 cout<<"  Wb_MemtoRegIn :"<<  Wb_MemtoRegIn.read()<<"\n";
//	 	cout<<"  Wb_RegWriteIn :"<<  Wb_RegWriteIn.read()<<"\n";
//	 cout<<"  memo_In[0] (dataMemory_MemWb):"<<  memo_In[0].read().to_string()<<"\n";
//	 cout<<"  memo_In[1] (exMem_dataMemoryAddress_MemWb):"<<  memo_In[1].read().to_string()<<"\n";
//	 cout<<"  dir_In :"<<  dir_In.read().to_string()<<"\n";
	 cout<<endl;

	 cout<<"=============================================================\n";
}