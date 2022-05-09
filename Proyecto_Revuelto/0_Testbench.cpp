#include "0_Testbench.h"
#include <iomanip>

using namespace std;

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName)
{
	SC_THREAD(operation);
	sensitive << clk.pos();
	dont_initialize();
}

void Testbench::operation()
{
	for (int i = 0; true; i++)
	{
		wait();
		print();
	}
}
void Testbench::print()
{
	cout << "====================CAMINO DE DATOS===================\n";
	cout << "Modulo: INSTRUCTION MEMORY-----------\n";

	sc_uint<4> instruction;
	sc_uint<5> operand1, operand2;
	sc_int<18> operand3;
	for (int i = 0; i < 4; i++)
		instruction[i] = operationOut.read()[i];

	if (instruction == 3 or instruction == 6 or instruction == 7 or instruction == 12 or instruction == 13 or instruction == 8 or instruction == 9 or instruction == 14 or instruction == 15)
	{

		for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
			operand1[j] = operationOut.read()[i];

		for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
			operand2[j] = operationOut.read()[i];

		for (sc_uint<6> i = 14, j = 0; i < 32; i++, j++)
			operand3[j] = operationOut.read()[i];
	}
	else
	{
		for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
			operand1[j] = operationOut.read()[i];

		for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
			operand2[j] = operationOut.read()[i];

		for (sc_uint<5> i = 14, j = 0; i < 19; i++, j++)
			operand3[j] = operationOut.read()[i];
	}

	std::cout << " Time    operand1    operand2    operand3    instruction\n";
	std::cout << "--------------------------------------------------------\n";
	
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(12) << operand1.to_string();
	std::cout << std::setw(12) << operand2.to_string();
	std::cout << std::setw(12) << operand3.to_string();
	std::cout << std::setw(15) << instruction.to_string() << '\n';
	std::cout << "--------------------------------------------------------\n";
	cout << endl;

	cout << "Modulo: Unidad control---------------------------\n";
	cout << " Ex_ALUOpOut  :" << Ex_ALUOpOut.read().to_string() << "\n";
	cout << " Ex_ALUSrcOut  :" << Ex_ALUSrcOut.read() << "\n";
	cout << " Mem_MemWriteOut  :" << Mem_MemWriteOut.read() << "\n";
	cout << " Mem_MemReadOut  :" << Mem_MemReadOut.read() << "\n";
	cout << " Mem_BranchOut  :" << Mem_BranchOut.read() << "\n";
	cout << " Wb_MemtoRegOut  :" << Wb_MemtoRegOut.read() << "\n";
	cout << " Wb_RegWriteOut  :" << Wb_RegWriteOut.read() << "\n";
	cout << endl;

	cout << "Modulo:  REGISTER-----------\n";
	cout << " aOut  :" << aOut.read().to_string() << "\n";
	cout << " bOut  :" << bOut.read().to_string() << "\n";
	cout << endl;

	cout << "Modulo: ALU ------------------------\n";
	cout << "  resultOut :" << resultOut_alu.read().to_string() << "\n";
	cout << endl;

	cout << "Modulo: DATA_MEMORY ------------------------\n";
	cout << "  read_dataOut :" << read_dataOut.read().to_string() << "\n";
	cout << "Modulo: MUX------------------------\n";
	cout << "  cOut :" << cOut.read().to_string() << "\n";
	cout << endl;
}