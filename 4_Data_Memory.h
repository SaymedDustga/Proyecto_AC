#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <systemc.h>
const int TAM_MEMORY__MEM = 256;

class Data_Memory : public sc_module {
public:

	sc_in_clk clkIn;					// reloj (para controlar el momento de lectura y el momento de escritura)
	sc_in<sc_int<32>> addressIn;        // dirección de registro 
	sc_in<sc_int<32>> write_dataIn;		// valor a escribir
	sc_in<bool> writeIn, readIn;		// banderas que habilitan lectura y escritura 

	sc_out<sc_int<32>> read_dataOut;	// valor a escribir

	SC_CTOR(Data_Memory);

private:
	sc_vector<sc_signal<sc_int<32>>> SC_NAMED(memory, TAM_MEMORY__MEM);

	void read();
	void write();

};

#endif
