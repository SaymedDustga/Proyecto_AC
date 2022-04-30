#include "1_Testbench.h"
using namespace std;

Testbench0::Testbench0(sc_module_name mn) : sc_module(mn) {

	// Necesitamos PC, IM
	SC_THREAD(operation);
	sensitive << clk.pos();
	//dont_initialize();
}

void Testbench0::operation()
{
	for(int i = 0; true; i++){
		wait();
		print();
	}
	//sc_stop();
}
void Testbench0::print(){
	cout<<"=========================FASE IF==============================\n";
	cout<<"Modulo: UNO---------------------------\n";
	cout<<"  Uno :"<< uno.read().to_string()<<"\n";
	cout<<endl;
	//pc
	cout<<"Modulo: PC---------------------------\n";
	cout<<"  adressIn :"<< adressIn.read().to_string()<<"\n";
	cout<<"  adressAdderOut :"<< adressAdderOut.read().to_string()<<"\n";
	cout<<"  adressPC_IF_IDOut :"<< adressPC_IF_IDOut.read().to_string()<<"\n";
	cout<<"  adressInstructionMemoryOut :"<< adressInstructionMemoryOut.read().to_string()<<"\n";
	cout<<endl;

	//adders
	cout<<"Modulo: ADDER------------------------\n";
  	cout<<"  number_1In :"<< number_1In.read().to_string()<<"\n";
  	cout<<"  number_2In :"<< number_2In.read().to_string()<<"\n";
  	cout<<"  resultOut :"<< resultOut.read().to_string()<<"\n";	
	cout<<endl;

	//ins_men
	cout<<"Modulo: INSTRUCTION MEMORY-----------\n";

  	cout<<"  instructionNumberIn :"<< instructionNumberIn.read().to_string()<<"\n";
  	cout<<"  operationOut :"<< operationOut.read().to_string()<<"\n";
	cout<<endl;

	//mux
	cout<<"Modulo: MUX_PC------------------------\n";	
  	cout<<"  aIn :" <<aIn.read().to_string()<<"\n";
  	cout<<"  bIn :" <<bIn.read().to_string()<<"\n";
  	cout<<"  cOut :"<< cOut.read().to_string()<<"\n";
  	cout<<"  sIn :" << sIn.read()<<"\n";
 	cout<<endl;
 	
  	cout<<"Modulo: IF_ID (REGISTRO ENCAUSAMIENTO)-\n";	
	
  	cout<<"  pcIn :" << pcIn.read().to_string()<<"\n";;
  	cout<<"  insMemIn :" <<insMemIn.read().to_string()<<"\n";;
	cout<<"=============================================================\n";

 }