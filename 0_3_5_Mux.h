#ifndef MUX_H
#define MUX_H

#include <systemc.h>

class Mux : public sc_module
{
public:
	//ENTRADA DEL MULTIPLEXOR QUE DECIDIRA QUE SEÑAL SALDRA POR LA SALIDA
	sc_in<bool> sIn;
	//LAS DOS ENTRADAS
	sc_in<sc_int<32>> aIn, bIn;
	//LA SALIDA DEL MUX
	sc_out<sc_int<32>> cOut;

	SC_CTOR(Mux);
private:
	void operation();
};

#endif