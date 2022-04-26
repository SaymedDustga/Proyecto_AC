#include "PC.h"

PC::PC(sc_module_name moduleName) : sc_module(moduleName), adressIn("adressIn"), adressOut("adressOut")
{
	SC_METHOD(write);
	sensitive << clk.neg();

	SC_METHOD(read);
	sensitive << clk.pos();
}

void PC::write()
{
	//std::cout << '\n' << sc_time_stamp() << '\n';

	adress = adressIn.read();
	//std::cout << "escribiendo\n" << adressIn.read() << '\n';
}

void PC::read()
{
	adressOut.write(adress);
}