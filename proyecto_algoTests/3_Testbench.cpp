#include "3_Testbench.h"
using namespace std;

Testbench2::Testbench2(sc_module_name mn) : sc_module(mn) {

	// Necesitamos PC, IM
	SC_THREAD(operation);
	sensitive << clk.pos();
	//dont_initialize();
}

void Testbench2::operation()
{
	for(int i = 0; true; i++){
		wait();
		print();
	}
//	sc_stop();
}
void Testbench2::print(){
	//cout<<"=========================FASE EX==============================\n";
 // 	//ID_EX
	//cout<<"Modulo: IF ID ------------------------\n";
 // 	cout<<"  Ex_ALUSrcOut :"<< Ex_ALUSrcOut.read()<<"\n";;
	//cout<<"  Ex_ALUOpOut :"<< Ex_ALUOpOut.read().to_string()<<"\n";			
 // 	cout<<"  Mem_MemWriteOut :"<< Mem_MemWriteOut.read()<<"\n";;
 // 	cout<<"  Mem_MemReadOut :"<< Mem_MemReadOut.read()<<"\n";
 // 	cout<<"  Mem_BranchOut :"<< Mem_BranchOut.read()<<"\n";
 // 	cout<<"  Wb_MemtoRegOut :"<< Wb_MemtoRegOut.read()<<"\n";
 // 	cout<<"  Wb_RegWriteOut :"<< Wb_RegWriteOut.read()<<"\n"; 	
 // 	cout<<"  Imm_gen1Out :"<< Imm_gen1Out.read().to_string()<<"\n";
 // 	cout<<"  Imm_gen2Out :"<< Imm_gen2Out.read().to_string()<<"\n";
 // 	cout<<"  id_ex0Out :"<< id_ex0Out.read().to_string()<<"\n";
 // 	cout<<"  id_ex1Out :"<< id_ex1Out.read().to_string()<<"\n";
 // 	cout<<"  id_ex2Out :"<< id_ex2Out.read().to_string()<<"\n";
	//cout<<"  memo_Out[0] (REGISTRO DATA 1) :"<< memo_Out[0].read().to_string()<<"\n";
	//cout<<"  memo_Out[1] (REGISTRO DATA 2):"<< memo_Out[1].read().to_string()<<"\n";
	//cout<<endl;

 // 	cout<<"Modulo: ALU ------------------------\n";
 // 	//alu 
 //	cout<<"  insIn :"<< insIn_alu.read().to_string()<<"\n";
	//cout<<"  number_1In :"<< number_1In_alu.read().to_string()<<"\n";
	//cout<<"  number_2In :"<< number_2In_alu.read().to_string()<<"\n";
 // 	cout<<"  resultOut :"<< resultOut_alu.read().to_string()<<"\n";
	//cout<<endl;

 // 	//ALU CONTROL
	//cout<<"Modulo: ALU CONTROL ------------------------\n";	
 // 	cout<<"  Ex_ALUOpIn :"<< Ex_ALUOpIn.read().to_string()<<"\n";
 // 	cout<<"  dir_In :"<< dir_In.read().to_string()<<"\n";
 // 	cout<<"  instruction_aluOut :"<< instruction_aluOut.read().to_string()<<"\n";
 //	cout<<endl;

	////adders
	//cout<<"Modulo: ADDER------------------------\n";
 // 	cout<<"  number_1In :"<< number_1In.read().to_string()<<"\n";
 // 	cout<<"  number_2In :"<< number_2In.read().to_string()<<"\n";
 // 	cout<<"  resultOut :"<< resultOut.read().to_string()<<"\n";	
	//cout<<endl;

	////mux
	//cout<<"Modulo: MUX_EX------------------------\n";	
 // 	cout<<"  aIn :" <<aIn.read().to_string()<<"\n";
 // 	cout<<"  bIn :" <<bIn.read().to_string()<<"\n";
 // 	cout<<"  cOut :"<< cOut.read().to_string()<<"\n";
 // 	cout<<"  sIn :" << sIn.read()<<"\n";
 //	cout<<endl;

 // 	//ex_mem
	//cout<<"Modulo:  EX MEN------------------------\n";	
 // 	cout<<"  alu_to_brachIn :"<< alu_to_brachIn.read()<<"\n";
 // 	cout<<"  Mem_MemWriteIn :"<< Mem_MemWriteIn.read()<<"\n"; 
 // 	cout<<"  Mem_MemReadIn :"<< Mem_MemReadIn.read()<<"\n";
	//cout<<"  Mem_BranchIn :"<< Mem_BranchIn.read()<<"\n";
 // 	cout<<"  Wb_MemtoRegIn :"<< Wb_MemtoRegIn.read()<<"\n";
	//cout<<"  Wb_RegWriteIn :"<< Wb_RegWriteIn.read()<<"\n";
	//cout<<"  memo_In[0] (addSum_exMem) :"<< memo_In[0].read().to_string()<<"\n";
	//cout<<"  memo_In[1] (alu_exMem_32bit):"<< memo_In[1].read().to_string()<<"\n";
	//cout<<"  memo_In[2] (idEx_muxEx_exMem):"<< memo_In[3].read().to_string()<<"\n";
 // 	cout<<"  dir_In_ :"<< dir_In.read().to_string()<<"\n";

 //	cout<<endl;
 	
	//cout<<"=============================================================\n";

 }