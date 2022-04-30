#include "2_File.h"

File::File(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(write);
//	sensitive << clkIn.neg();
	sensitive << clkIn.pos();
	SC_METHOD(read);
//	sensitive << clkIn.pos();
	sensitive << clkIn.neg();
}

void File::write()
{
	if (weIn.read() and rwIn.read()){
		memory[rwIn.read()] = wIn.read();
    std:: cout << "En el registro: " << rwIn.read() << " Escribir: " << wIn.read() << endl;
  }
}

void File::read()
{
	if (raIn.read() >= 0 and raIn.read() <= 31)
		aOut.write(memory[raIn.read()]);
	if (rbIn.read() >= 0 and rbIn.read() <= 31)
		bOut.write(memory[rbIn.read()]);
}
