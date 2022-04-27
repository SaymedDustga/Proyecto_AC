#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class IF_ID : public sc_module
{

public:
	sc_in_clk clk;
	sc_in<sc_int<32>> pcIn;
	sc_in<sc_int<32>> insMemIn;

	//sc_out<sc_int<8>> controlOut;
	sc_out<sc_int<8>> fileRegister1Out;
	sc_out<sc_int<8>> fileRegister2Out;
	sc_out<sc_int<8>> immGenOut;
	//Aqui se guarda la instruccion actual para el sumador de salto de instruccion
	sc_out<sc_int<32>> ID_EX0Out;
	//Aqui se guarda la instruccion a ejecutar por la ALU
	sc_out<sc_int<8>> ID_EX1Out;
	//Aqui se guarda la direccion del registro de escritura de la instruccion
	sc_out<sc_int<8>> ID_EX2Out;

	//		sc_out<sc_int<32>> instruction1Out;
	//		sc_out<sc_int<32>> instruction2Out;
	//		sc_out<sc_int<32>> instruction3Out;
	SC_CTOR(IF_ID);

private:
	void operation();
};

#endif
