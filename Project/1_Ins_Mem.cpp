#include "1_Ins_Mem.h"
InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName), instructionNumberIn("instructionNumberIn"), operationOut("operationOut")
{
	ifstream instructionFile("ins.txt", ios::in);
	if (instructionFile.fail())
		exit(EXIT_FAILURE);
	numberOfInstructions = 0;
	std::string algo;
	while (!instructionFile.eof())
	{
		getline(instructionFile, algo);
		numberOfInstructions++;
	}
	instructionFile.close();
	instructionFile.open("ins.txt", ios::in);
	instructionList = new std::string[numberOfInstructions];
	int i = 0;
	while (!instructionFile.eof())
	{
		getline(instructionFile, instructionList[i]);
		if (instructionList[i] == "")
			continue;
		i++;
	}
	instructionFile.close();

	SC_METHOD(operation);
//	sensitive << clk.neg();
	sensitive << instructionNumberIn;
	dont_initialize();
	//std:: cout << "\npls" << endl;
}

void InstructionMemory::list(std::string instruction)
{

	// 1 add
	// 2 sub
	// 3 addi
	// 4 sll
	// 5 srl
	// 6 slli
	// 7 srli
	// 8 lw
	// 9 sw
	// 10 and
	// 11 or
	// 12 andi
	// 13 ori
	// 14 beq
	// 15 bne
	// 16 jalr
	std::string aux = instruction.substr(0, instruction.find_first_of(' '));
	if (aux.back() == ':')
	{
		//std::cout << "dos puntos compa";
		// aux es el nombre de la operacion

		instruction = instruction.substr(instruction.find_first_of(' ') + 1);
		std::cout << "\n\n"
				  << instruction << "\n\n";
		aux = instruction.substr(0, instruction.find_first_of(' '));
		std::cout << "\n\n"
				  << aux << "\n\n"; // instruction ahora es la linea de instruccion, sin la etiqueta
	}

	int insN = 0;
	if (aux == "add" || aux == "sub" || aux == "sll" || aux == "srl" || aux == "and" || aux == "or")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		int dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
		int dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 3));
		int dir03 = stoi(aux4);
		intAux = dir01;
		intAux <<= 8;
		intAux += dir02;
		intAux <<= 8;
		intAux += dir03;
		intAux <<= 8;
		if (aux == "add")
			insN = 1;
		else if (aux == "sub")
			insN = 2;
		else if (aux == "sll")
			insN = 4;
		else if (aux == "srl")
			insN = 5;
		else if (aux == "and")
			insN = 10;
		else if (aux == "or")
			insN = 11;
		intAux += insN;
		operationOut.write(intAux);
	}
	else if (aux == "addi" || aux == "slli" || aux == "srli" || aux == "andi" || aux == "ori")
	{
		insN = 3;
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		int dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
		int dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
		int dir03 = stoi(aux4);
		intAux = dir01;
		intAux <<= 8;
		intAux += dir02;
		intAux <<= 8;
		intAux += dir03;
		intAux <<= 8;
		if (aux == "addi")
			insN = 3;
		else if (aux == "slli")
			insN = 6;
		else if (aux == "srli")
			insN = 7;
		else if (aux == "andi")
			insN = 12;
		else if (aux == "ori")
			insN = 13;
		intAux += insN;
		operationOut.write(intAux);
	}
	else if (aux == "lw" || aux == "sw" || aux == "jalr")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		int dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 2));
		sc_int<8> dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of('x') + 1));
		int dir03 = stoi(aux4);
		intAux = dir01;
		intAux <<= 8;
		for (int h = 0; h < 8; h++)
			intAux[h] = dir02[h];
		intAux <<= 8;
		intAux += dir03;
		intAux <<= 8;
		if (aux == "lw")
			insN = 8;
		else if (aux == "sw")
			insN = 9;
		else if (aux == "jalr")
			insN = 16;
		intAux += insN;
		operationOut.write(intAux);
	}
	else if (aux == "beq" || aux == "bne")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		int dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of('x') + 1));
		int dir02 = stoi(aux3);

		std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
		size_t linea = 0;
		for (size_t i = 0; i < numberOfInstructions; i++)
		{
			int pos = instructionList[i].find_first_of(':');
			if (pos != -1)
			{
				std::string temp = instructionList[i].substr(0, pos);
				if (aux4 == temp)
				{
					linea = i;
					break;
				}
			}
		}

		intAux = dir01;
		intAux <<= 8;
		intAux += dir02;
		intAux <<= 8;
		intAux += linea;
		intAux <<= 8;
		if (aux == "beq")
			insN = 14;
		else if (aux == "bne")
			insN = 15;
		intAux += insN;
		operationOut.write(intAux);
	}
}

void InstructionMemory::operation()
{
  	//std:: cout << "\nisnMem" << endl;
	if(instructionNumberIn.read() < 0){
		sc_stop();
	}
	list(instructionList[instructionNumberIn.read()]);
}