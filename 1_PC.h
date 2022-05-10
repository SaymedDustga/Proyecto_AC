#ifndef PC_H
#define PC_H

#include <systemc.h>

class PC : public sc_module
{
public:
	sc_in_clk clk;

	sc_in<sc_int<32>> adressIn;//entrada que le indica al pc cuantas posicioes deb moverse en la pila del programa

	sc_out<sc_int<32>> adressAdderOut;		//salida hacia el adder de IF
	sc_out<sc_int<32>> adressPC_IF_IDOut;	//salida hacia el registro IF_ID
	sc_out<sc_int<32>> adressInstructionMemoryOut;//salida hacia Instrucion Memory

	SC_CTOR(PC);

private:
	sc_int<32> adress;

	void read();
	void write();
};

#endif