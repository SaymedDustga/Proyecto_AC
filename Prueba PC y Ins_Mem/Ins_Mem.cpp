#include "Ins_Mem.h"

InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName), instructionNumberIn("instructionNumberIn"), operationOut("operationOut")
{

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();
}

void list(string instruction)
{
	string aux = instruction.substr(0, instruction.find_first_of(' '));
	if (aux.back() == ':')
	
		aux = instruction.substr(instruction.find_first_not_of(' ', instruction.find_first_of(' ')), instruction.find_first_of(' ', instruction.find_first_not_of(' ', instruction.find_first_of(' '))));
	
	else
	{

		size_t* next_char;

		switch (aux)
		{
//Aritmeticas
		case "add":

		case "sub":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2,next_char);
			string aux3(aux2.substr(*next_char+3));
			int dir02 = stoi(aux3,next_char);
			string aux4(aux3.substr(*next_char+3)); 
			int dir03 = stoi(aux4);
			break;
		case "addi":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			string aux4(aux3.substr(find_first_of(',')+1)); 
			int dir03 = stoi(aux4);
			break;
//Transferencia de datos
		case "lw":

		case "sw":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			string aux3(aux2.substr(find_first_of(',')+1));
			int dir02 = stoi(aux3);
			string aux4(aux3.substr(find_first_of('(')+1)); 
			int dir03 = stoi(aux4);
			break;
//Logicas
		case "sll":
			/* code */
		case "srl":
		case "and":
		case "or":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			string aux4(aux3.substr(find_first_of('x')+1)); 
			int dir03 = stoi(aux4);
			break;
		case "slli":
			/* code */
		case "srli":
		case "andi":
		case "ori":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			string aux4(aux3.substr(find_first_of(',')+1)); 
			int dir03 = stoi(aux4);
			break;
			/* code */
			/* code */
			/* code */
			/* code */

//Decisiones

		case "beq":
			/* code */
		case "bne":
			string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			string aux4(aux3.substr(find_first_of(',')+1)); 
			break;
		case "jalr":
			/* code */

			break;

		default:
			break;
		}
	}
}

void InstructionMemory::operation()
{
	if (initialized)
	{
		list(aux[instructionNumberIn.read()]);
	}
	ID_EXOut.write(IF_IDIn.read());
	else
	{
		ifstream instructionFile("Instrucciones.txt", ios::in);
		if (instructionFile.fail())
			exit(EXIT_FAILURE);
		int cont = 0;
		while (!instructionFile.eof())
		{
			cont++;
		}
		instructionFile.close();
		instructionFile.open("Instrucciones.txt", ios::in);
		string aux[cont];
		int i = 0;
		while (!instructionFile.eof())
		{
			getline(instructionFile, aux[i]);
			if (aux[i] == "")
				continue;
			i++;
		}
		instructionFile.close();
	}
	// operationOut= .write(instructionNumberIn.read());
}