#include "4_Branch.h"

Branch::Branch(sc_module_name nm) : sc_module(nm) {

	SC_METHOD(operation);
	sensitive << jumpIn << addressIn;
//	sensitive << clk.neg();
	dont_initialize();
}

void Branch::operation()
{
	std::cout << "branch, salida Control_Unit: " << (jumpIn.read()) << '\n';
	std::cout << "branch, salida zero de alu: " << (addressIn.read()) << '\n';
	answerOut.write(jumpIn.read() and addressIn.read());
}
