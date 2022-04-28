#include "4_Data_Memory.h"

Data_Memory::Data_Memory(sc_module_name nm) : sc_module(nm)
{

	SC_METHOD(write);
	// sensitive << clkIn.neg();
	sensitive << rwIn << raIn << rbIn << weIn << wIn;
	SC_METHOD(read);
	//  sensitive << clkIn.pos();
	sensitive << rwIn << raIn << rbIn << weIn << wIn;
}

void Data_Memory::read()
{
	memory[0] = 0;
	if (weIn.read())
	{
		memory[rwIn.read()] = wIn.read();
	}
}

void Data_Memory::write()
{
	if (!weIn.read())
	{
		aOut.write(memory[raIn.read()]);
		bOut.write(memory[rbIn.read()]);
	}
}
