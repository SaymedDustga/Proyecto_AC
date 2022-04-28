#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H
#include <systemc.h>
const int TAM_MEMORY_MEM = 256;
const int TAM_ADDRESS__ = 32;

class Data_Memory : public sc_module
{
public:
	sc_in<sc_int<TAM_ADDRESS__>> addressIn; // dirección de registro
	sc_out<sc_int<32>> read_dataOut;		// valor a escribir
	sc_in<sc_int<32>> write_dataIn;			// valor
	sc_in<bool> writeIn, readIn;

	// sc_in<bool> clkIn;        //reloj (para controlar el moMemto de lectura y el moMemto de escritura)

	int memory[TAM_MEMORY_MEM];
	SC_CTOR(Data_Memory);

private:
	void read();
	void write();
};

#endif
