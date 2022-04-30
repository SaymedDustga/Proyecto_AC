#include "Testbench.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

Testbench::Testbench(sc_module_name mn) : sc_module(mn), clk("clk") /*, muxSgOut("muxSgOut")*/ /*, ID_EXIn("ID_EXIn")*/, register1In("register1In"), adderIn2("adderIn2"), muxIn2("muxIn2")
{
	// Necesitamos PC, IM
	SC_THREAD(operation);
	sensitive << ;
	dont_initialize();
}

void Testbench::operation()
{

	adderIn2.write(1);
	muxIn2.write(0);
	muxSgOut.write(false);

	wait();
	wait();
	wait();
	wait();

	for (int g = 31; g >= 0; g--)
	{
		std::cout << register1In.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	wait();
	wait();
	wait();
	wait();

	for (int g = 31; g >= 0; g--)
	{
		std::cout << register1In.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	wait();
	wait();
	wait();
	wait();

	for (int g = 31; g >= 0; g--)
	{
		std::cout << register1In.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	wait();
	wait();
	wait();
	wait();

	for (int g = 31; g >= 0; g--)
	{
		std::cout << register1In.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	sc_stop();
}
//
// void Testbench::print() {
//	std::cout << "\n\n------------------------------------------------------------------------------------------------------------\n";
//	std::cout << "Tiempo       cpOut       insMemOut       r1In      r2In       ID_EXIn       ins1In       ins2In       ins3In" << endl;
//	std::cout << "------------------------------------------------------------------------------------------------------------\n";
//	std::cout << std::setw(6) << sc_time_stamp();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(6) << cpOut.read();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(8) << insMemOut.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << register1In.read();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(6) << register2In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << ID_EXIn.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction1In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction2In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction3In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << "\n";
//}