#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder : public sc_module
{
public:
	/*	
		Este modulo simplemente suma dos numeros que reciva por
		number_1In y number__2In y el resultado lo envia por resultOut

		De este modulo se implementan dos en el programa principal
	*/
	sc_in<sc_int<32>> number_1In, number_2In;
	sc_out<sc_int<32>> resultOut;

	SC_CTOR(Adder);
private:
	void operation();
};

#endif
