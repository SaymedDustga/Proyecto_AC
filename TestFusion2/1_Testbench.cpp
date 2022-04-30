#include "1_Testbench.h"

using namespace std;

Testbench0::Testbench0(sc_module_name mn) : sc_module(mn) {

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
	sc_int<8> instruction, register1, immediate, register2, writeRegister;
	//std::cout << "\nLa instrucción es: " << operationIn.read() << '\n';
	for (int i = 0; i < 8; i++)
		instruction[i] = instructionNumberIn.read()[i];
	std::cout << "\nEl número de instrucción es: " << instruction << '\n';

	for (int i = 16; i < 24; i++)
	{
		register1[i - 16] = instructionNumberIn.read()[i];
		immediate[i - 16] = instructionNumberIn.read()[i];
	}
	std::cout << "\nLa dirección de registro 1 y/o valor inmediato de la instrucción son: " << register1 << '\n';

	for (int i = 8; i < 16; i++)
		register2[i - 8] = instructionNumberIn.read()[i];
	std::cout << "\nLa dirección registro 2 de la instrucción es: " << register2 << '\n';

	for (int i = 24; i < 31; i++)
		writeRegister[i - 24] = instructionNumberIn.read()[i];
	std::cout << "\nLa dirección de registro de escritura es: " << writeRegister << '\n';

  	//cout<<"  instructionNumberIn :"<< instructionNumberIn.read().to_string()<<"\n";
  	cout<<"  operationOut :"<< operationOut.read().to_string()<<"\n";
	cout<<endl;

	//mux
	cout<<"Modulo: MUX_PC------------------------\n";	
  	cout<<"  aIn :" <<aIn.read().to_string()<<"\n";
  	cout<<"  bIn :" <<bIn.read().to_string()<<"\n";
  	cout<<"  cOut :"<< cOut.read().to_string()<<"\n";
  	cout<<"  sIn :" << sIn.read()<<"\n";
 	cout<<endl;
 	
  	cout<<"Modulo: IF_ID (REGISTRO ENCAUZAMIENTO)-\n";	
	
  	cout<<"  pcIn :" << pcIn.read().to_string()<<"\n";;
  	cout<<"  insMemIn :" <<insMemIn.read().to_string()<<"\n";;
	cout<<"=============================================================\n";

 }