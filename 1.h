#ifndef UNO_H
#define UNO_H

#include <iostream>
#include <systemc.h>

class Uno : public sc_module
{
public:
	/*
	lA UNICA FUNCION DE ESTE MODULO ES MANDAR CONSTANTEMENTE 1 HACIA EL ADDER
	O SUMADOR DE PC EN LA FASE INICIAL 
	*/
	sc_out<sc_int<32>> uno;

	SC_CTOR(Uno);
	~Uno();

private:
	void operation();
};

#endif
