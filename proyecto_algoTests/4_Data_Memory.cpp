#include "4_Data_Memory.h"

Data_Memory::Data_Memory(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(write);
	 sensitive << clkIn.pos();
	SC_METHOD(read);
	 sensitive << clkIn.neg();
}

void Data_Memory::write()
{
	if (writeIn.read())
	{
//		std::cout << "\n\n\n\n\nGUARDANDO EN DATA MEMORY\n\n\n\n\n" <<write_dataIn.read()  << "\n\n\n\n\n";
//		std::cout << "\n\n\n\n\nDIRECCION\n\n\n\n\n" <<addressIn.read()  << "\n\n\n\n\n";
		memory[addressIn.read()] = write_dataIn.read();
	}
}

void Data_Memory::read()
{
	if (readIn.read()){
//		std::cout << "\n\n\n\n\nLEYENDO EN DATA MEMORY\n\n\n\n\n" <<read_dataOut.read() << " SOBRE " << addressIn.read() << "\n\n\n\n\n";
		read_dataOut.write(memory[addressIn.read()]);
		for(int i =0; i < 256 ; i++){
			/*if(memory[i] != 0){
				std::cout << "\n\n\n\nVALGO: " << memory[i] << " EN LA POS: " << i << "\n\n\n\n\n\n\n\n\n\n";
			}*/
		}
	}
}
