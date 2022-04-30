#include "1_Testbench.h"

using namespace std;

Testbench0::Testbench0(sc_module_name mn) : sc_module(mn)
{
	SC_THREAD(operation);
	sensitive << clk.pos();
}

void Testbench0::operation()
{
	for (int i = 0; true; i++)
	{
		wait();
		print();
	}
}
void Testbench0::print()
{
//	cout << "=========================FASE IF==============================\n";
//	cout << "Modulo: UNO---------------------------\n";
//	cout << "  Uno :" << uno.read().to_string() << "\n";
//	cout << endl;
//	// pc
//	cout << "Modulo: PC---------------------------\n";
//	cout << "  adressAdderOut :" << adressAdderOut.read().to_string() << "\n";
//	cout << "  adressPC_IF_IDOut :" << adressPC_IF_IDOut.read().to_string() << "\n";
//	cout << "  adressInstructionMemoryOut :" << adressInstructionMemoryOut.read().to_string() << "\n";
//	cout << endl;

//	// adders
//	cout << "  resultOut :" << resultOut.read().to_string() << "\n";
//	cout << endl;

//	// ins_men
//	cout << "Modulo: INSTRUCTION MEMORY-----------\n";
//	sc_int<8> instruction, register1, immediate, register2, writeRegister;
//	for (int i = 0; i < 8; i++)
//		instruction[i] = operationOut.read()[i];
//	std::cout << "\nEl número de instrucción es: " << instruction << '\n';

//	for (int i = 16; i < 24; i++)
//	{
//		register1[i - 16] = operationOut.read()[i];
//		immediate[i - 16] = operationOut.read()[i];
//	}
//	std::cout << "\nLa dirección de registro 1 y/o valor inmediato de la instrucción son: " << register1 << '\n';

//	for (int i = 8; i < 16; i++)
//		register2[i - 8] = operationOut.read()[i];
//	std::cout << "\nLa dirección registro 2 de la instrucción es: " << register2 << '\n';

//	for (int i = 24; i < 31; i++)
//		writeRegister[i - 24] = operationOut.read()[i];
//	std::cout << "\nLa dirección de registro de escritura es: " << writeRegister << '\n';

//	cout << endl;

//	// mux
//	cout << "  cOut :" << cOut.read().to_string() << "\n";
//	cout << endl;

//	cout << "Modulo: IF_ID (REGISTRO ENCAUZAMIENTO)-\n";

//	cout << "=============================================================\n";
}