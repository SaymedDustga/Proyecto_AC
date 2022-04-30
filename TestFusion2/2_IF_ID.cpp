#include "2_IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName), pcIn("pcIn"), insMemIn("insMemIn"), fileRegister1Out("fileRegister1Out"), fileRegister2Out("fileRegister2Out"), ID_EX0Out("ID_EX0Out"), ID_EX1Out("ID_EX1Out"), ID_EX2Out("ID_EX2Out")
{

	SC_METHOD(operation);
	sensitive << clk.pos();
	dont_initialize();
}

void IF_ID::operation()
{

	sc_int<8> writeRegister;
	sc_int<8> register1;
	sc_int<8> register2;
	sc_int<8> imm;
	sc_int<8> instruction;
	// Para testeo:
	ID_EX0Out.write(pcIn.read());

	for (int i = 31, j = 7; i >= 24; i--, j--)
		writeRegister[j] = insMemIn.read()[i];

	for (int i = 23, j = 7; i >= 16; i--, j--)
	{
		register1[j] = insMemIn.read()[i];
		imm[j] = insMemIn.read()[i];
	}
	for (int i = 15, j = 7; i >= 8; i--, j--)
		register2[j] = insMemIn.read()[i];

	for (int i = 7, j = 7; i >= 0; i--, j--)
		instruction[j] = insMemIn.read()[i];

	//std::cout << "\nSoy el If_ID\nRegister01: " << register1 << "\nRegister02: " << register2 << "\nwriteRegister: " << writeRegister << "\nInstruction: " << instruction << endl;

	fileRegister1Out.write(register1);
	fileRegister2Out.write(register2);
	immGenOut.write(imm);
	ID_EX1Out.write(instruction);
	ID_unidadControl.write(instruction);
	ID_EX2Out.write(writeRegister);
}
