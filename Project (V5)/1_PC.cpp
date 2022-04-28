#include "1_PC.h"

PC::PC(sc_module_name moduleName) : sc_module(moduleName), adressIn("adressIn"), adressAdderOut("adressAdderOut"), adressPC_IF_IDOut("adressPC_IF_IDOut"), adressInstructionMemoryOut("adressInstructionMemoryOut")
{
	SC_METHOD(write);
	sensitive << adressIn;
//	sensitive << clk.neg();

	SC_METHOD(read);
	sensitive << adressIn;
//	sensitive << clk.pos();

	//std :: cout << "PC" << endl;
}

void PC::write()
{
	// std::cout << '\n' << sc_time_stamp() << '\n';
  //std:: cout << "\nPC write" << endl;
	adress = adressIn.read();
	// std::cout << "escribiendo\n" << adressIn.read() << '\n';
}

void PC::read()
{
	  //std:: cout << "\nPC read" << endl;
	adressAdderOut.write(adress);
	adressPC_IF_IDOut.write(adress);
	adressInstructionMemoryOut.write(adress);
}