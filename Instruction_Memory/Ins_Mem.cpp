#include "Ins_Mem.h"

InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName) {

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();

}

void InstructionMemory::operation()
{
	/*if (initialized)
	{

	}
	ID_EXOut.write(IF_IDIn.read());
	else
	{
		ifstream instructionFile("Instrucciones.txt", ios::in);
		if (instructionFile.fail())
			exit(EXIT_FAILURE);
		int cont = 0;
		while (!instructionFile.eof()) {
			cont++;
		}
		instructionFile.close();
		instructionFile.open("Instrucciones.txt", ios::in);
		string aux[cont];
		int i = 0;
		while (!instructionFile.eof()) {
			getline(instructionFile, aux[i]);
			if (aux[i] == "") {
				continue;
			}
			i++;
		}
		instructionFile.close();
	}*/
	operationOut.write(instructionNumberIn.read())

}