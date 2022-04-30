#include "5_Testbench.h"
using namespace std;

Testbench4::Testbench4(sc_module_name mn) : sc_module(mn) {

	SC_THREAD(operation);
	sensitive << clk.pos();
	//dont_initialize();
}

void Testbench4::operation()
{
	for(int i = 0; true; i++){
		wait();
		print();
	}
	//sc_stop();
}
void Testbench4::print(){
	//cout<<"=========================FASE WB==============================\n";
 // 	//ex_men
	//cout<<"Modulo: EX MEM ------------------------\n";
 //  	cout<<"  aIWb_MemtoRegOutn :" <<Wb_MemtoRegOut.read()<<"\n";// Wb_RegWriteOut;
 //  	cout<<"  Wb_RegWriteOut :" <<Wb_RegWriteOut.read()<<"\n";// Wb_RegWriteOut;
 //	cout<<"  memo_Out[0] (MemWb_muxWb1):" <<memo_Out[0].read().to_string()<<"\n";
 //	cout<<"  memo_Out[1] (MemWb_muxWb2):" <<memo_Out[1].read().to_string()<<"\n";
 // 	cout<<"  dir_Out :" << dir_Out.read().to_string()<<"\n";
	//cout<<endl;

	////mux
	//cout<<"Modulo: MUX------------------------\n";	
 // 	cout<<"  aIn :" <<aIn.read().to_string()<<"\n";
 // 	cout<<"  bIn :" <<bIn.read().to_string()<<"\n";
 // 	cout<<"  cOut :"<< cOut.read().to_string()<<"\n";
 // 	cout<<"  sIn :" << sIn.read()<<"\n";
 //	cout<<endl;


 	
	

	//cout<<"=============================================================\n";
	//cout<<"##############################################################\n";
	//cout<<"##############################################################\n";
	//cout<<"##############################################################\n";
	//cout<<"##############################################################\n";

 }