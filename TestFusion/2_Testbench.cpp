#include "2_Testbench.h"
using namespace std;

Testbench1::Testbench1(sc_module_name mn) : sc_module(mn) {

	// Necesitamos PC, IM
	SC_THREAD(operation);
	sensitive << clk.pos();;
	//dont_initialize();
}

void Testbench1::operation()
{
	for(int i = 0; true; i++){
		wait();
		print();
	}
	//sc_stop();
}
void Testbench1::print(){
	cout<<"=========================FASE ID==============================\n";
	//IF ID
	cout<<"Modulo: IF_ID ---------------------------\n";
	cout<<" fileRegister1Out  :"<< fileRegister1Out.read().to_string()<<"\n";
	cout<<" fileRegister2Out  :"<< fileRegister2Out.read().to_string()<<"\n";
	cout<<" immGenOut  :"<< immGenOut.read().to_string()<<"\n";
	cout<<" ID_EX0Out  :"<< ID_EX0Out.read().to_string()<<"\n";
	cout<<" ID_EX1Out :"<< ID_EX1Out.read().to_string()<<"\n";
	cout<<" ID_unidadControl  :"<< ID_unidadControl.read().to_string()<<"\n";
	cout<<" ID_EX2Out  :"<< ID_EX2Out.read().to_string()<<"\n";
	cout<<endl;
	//Unidad control
	cout<<"Modulo: Unidad control---------------------------\n";
	cout<<" Ex_ALUOpOut  :"<< Ex_ALUOpOut.read().to_string()<<"\n";
	cout<<" Ex_ALUSrcOut  :"<< Ex_ALUSrcOut.read()<<"\n";
	cout<<" Mem_MemWriteOut  :"<< Mem_MemWriteOut.read()<<"\n";
	cout<<" Mem_MemReadOut  :"<< Mem_MemReadOut.read()<<"\n";
 	cout<<" Mem_BranchOut  :"<< Mem_BranchOut.read()<<"\n";
 	cout<<" Wb_MemtoRegOut  :"<< Wb_MemtoRegOut.read()<<"\n";
 	cout<<" Wb_RegWriteOut  :"<< Wb_RegWriteOut.read()<<"\n";
	cout<<" dir_In  :"<< dir_In.read().to_string()<<"\n";
	cout<<endl;

  	//imm gem
	cout<<"Modulo: IMM GEM------------------------\n";
	cout<<" IF_IDIn  :"<< IF_IDIn.read().to_string()<<"\n";					
	cout<<" ID_EXOut  :"<< ID_EXOut.read().to_string()<<"\n";
	cout<<endl;

	//register
	cout<<"Modulo:  REGISTER-----------\n";

	cout<<" rwIn  :"<<  rwIn.read().to_string()<<"\n";	  
	cout<<" raIn  :"<<  raIn.read().to_string()<<"\n"; 	  
	cout<<" rbIn  :"<<  rbIn.read().to_string()<<"\n"; 	  
	cout<<" wIn  :"<<  wIn.read().to_string()<<"\n";  	
	cout<<" weIn  :"<<  weIn.read()<<"\n";			   
	cout<<" aOut  :"<<  aOut.read().to_string()<<"\n";  
	cout<<" bOut  :"<<  bOut.read().to_string()<<"\n"; 
	cout<<endl;

  	//id_ex
	cout<<"Modulo: ID EX------------------------\n";	

	cout<<" Ex_ALUSrcIn  :"<< Ex_ALUSrcIn.read()<<"\n";	;
	cout<<" Mem_MemWriteIn  :"<< Mem_MemWriteIn.read()<<"\n";	
	cout<<" Mem_MemReadIn  :"<< Mem_MemReadIn.read()<<"\n";	
	cout<<" Mem_BranchIn  :"<< Mem_BranchIn.read()<<"\n";	
	cout<<" Wb_MemtoRegIn  :"<< Wb_MemtoRegIn.read()<<"\n";	
	cout<<" Wb_RegWriteIn  :"<< Wb_RegWriteIn.read()<<"\n";	
	cout<<" Ex_ALUOpIn  :"<< Ex_ALUOpIn.read().to_string()<<"\n"; 	
	cout<<" Imm_genIn  :"<< Imm_genIn.read().to_string()<<"\n"; 
	cout<<" id_ex0In  :"<< id_ex0In.read().to_string()<<"\n"; 
	cout<<" id_ex1In  :"<< id_ex1In.read().to_string()<<"\n"; 
	cout<<" id_ex2In  :"<< id_ex2In.read().to_string()<<"\n"; 
	cout<<" memo_In[0] (REGISTRO DATA 1) :"<< memo_In[0].read().to_string()<<"\n"; 
	cout<<" memo_In[1] (REGISTRO DATA 2) :"<< memo_In[1].read().to_string()<<"\n"; 


 	cout<<endl;
 	
	

	cout<<"=============================================================\n";

 }