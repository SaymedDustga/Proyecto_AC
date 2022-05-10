#ifndef FILE_REGISTER_H
#define FILE_REGISTER_H

#include "Register.h"
#include "AndGate.h"

class RegisterFile : public sc_module
{
public:
	sc_in_clk clk;						// Reloj
	sc_in<sc_uint<5>> rwIn, raIn, rbIn;		// Direcciones de registros: rwIn para escribir, raIn y rbIn para leer
	sc_in<sc_int<32>> wIn;					// Valor de escritura para el registro
	sc_in<bool> weIn;						// Booleano que habilita la escritura
	sc_out<sc_int<32>> aOut, bOut;			// Valores A y B le�dos de los registros en las direcciones raIn y rbIn

	SC_CTOR(RegisterFile);
private:
	sc_vector<Register> SC_NAMED(registers, 32);
	sc_vector<sc_signal<bool>> SC_NAMED(weSg,32);
	sc_vector<sc_signal<sc_int<32>>> SC_NAMED(wSg,32);
	sc_vector<sc_signal<sc_int<32>>> SC_NAMED(regSg, 32);
	sc_uint<5> lastRegister;

	AndGate and1;
	sc_signal<bool> aSg, bSg, cSg;

	void readA();
	void readB();
	void write();
};

#endif
