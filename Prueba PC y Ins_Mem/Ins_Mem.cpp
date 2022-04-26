#include "Ins_Mem.h"
InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName), instructionNumberIn("instructionNumberIn"), operationOut("operationOut")
{

		ifstream instructionFile("Instrucciones.txt", ios::in);
		if (instructionFile.fail())
			exit(EXIT_FAILURE);
		int cont = 0;
		std::string algo;
		while (!instructionFile.eof())
		{
			getline(instructionFile, algo);
			cont++;
		}
		instructionFile.close();
		instructionFile.open("Instrucciones.txt", ios::in);
		aux = new std::string[cont];
		int i = 0;
		while (!instructionFile.eof())
		{
			getline(instructionFile, aux[i]);
			if (aux[i] == "")
				continue;
			i++;
		}
		instructionFile.close();
//		initialized = true;
/*
	for(int g = 0; g< cont; g++){
		std:: cout << aux[g] << endl;
	}*/

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();

}

void InstructionMemory::list(std::string instruction)
{
	std::string aux = instruction.substr(0, instruction.find_first_of(' '));
	if (aux.back() == ':')
	
		aux = instruction.substr(instruction.find_first_not_of(' ', instruction.find_first_of(' ')), instruction.find_first_of(' ', instruction.find_first_not_of(' ', instruction.find_first_of(' '))));
	
	else
	{

		size_t* next_char;
		int insN = 0;
		if( aux=="add" or aux == "sub")
		{
//			std:: cout << "entre njd" << endl;
//Aritmeticas
			if(aux == "add") insN = 1;
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2,next_char);
//			std:: cout << aux2 << endl;
//			std:: cout << aux2.find_first_of(',')+2 << endl;
			std::string aux3(aux2.substr(aux2.find_first_of(',')+3));
//			std::cout << aux3 << endl;
			int dir02 = stoi(aux3,next_char);
//			std:: cout << aux3 << endl;
			std::string aux4(aux3.substr(aux3.find_first_of(',')+3)); 
//			std::cout << aux4 << endl;
			int dir03 = stoi(aux4,next_char);
//			std:: cout << "pase" << endl;
			intAux = dir01;
			intAux <<= 8;
//			intAux << 8;
			intAux += dir02;
			intAux <<= 8;
//			intAux << 8;
			intAux += dir03;
			intAux <<= 8;
		
//			intAux << 8;
			if(insN == 0) insN = 2;
			intAux += insN;
//			std:: cout << "\n\naqui njd x2 "<<intAux << endl;
			operationOut.write(intAux);
			/*
		case "addi":
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			std::string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			std::string aux4(aux3.substr(find_first_of(',')+1)); 
			int dir03 = stoi(aux4);
			break;
//Transferencia de datos
		case "lw":

		case "sw":
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			std::string aux3(aux2.substr(find_first_of(',')+1));
			int dir02 = stoi(aux3);
			std::string aux4(aux3.substr(find_first_of('(')+1)); 
			int dir03 = stoi(aux4);
			break;
//Logicas
		case "sll":
		case "srl":
		case "and":
		case "or":
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			std::string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			std::string aux4(aux3.substr(find_first_of('x')+1)); 
			int dir03 = stoi(aux4);
			break;
		case "slli":
		case "srli":
		case "andi":
		case "ori":
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			std::string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			std::string aux4(aux3.substr(find_first_of(',')+1)); 
			int dir03 = stoi(aux4);
			break;

//Decisiones

		case "beq":

		case "bne":
			std::string aux2(instruction.substr(instruction.find_first_of('x')+1));
			int dir01 = stoi(aux2);
			std::string aux3(aux2.substr(find_first_of('x')+1));
			int dir02 = stoi(aux3);
			std::string aux4(aux3.substr(find_first_of(',')+1)); 
			break;
		case "jalr":

			break;
*/
	}
}
}
void InstructionMemory::operation()
{

	list(aux[instructionNumberIn.read()]);
/*	if (initialized)
	{
		list(aux[instructionNumberIn.read()]);
	}
//	ID_EXOut.write(IF_IDIn.read());
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
		std::string aux[cont];
		int i = 0;
		while (!instructionFile.eof())
		{
			getline(instructionFile, aux[i]);
			if (aux[i] == "")
				continue;
			i++;
		}
		instructionFile.close();
		initialized = true;
	}*/
	// operationOut= .write(instructionNumberIn.read());
}