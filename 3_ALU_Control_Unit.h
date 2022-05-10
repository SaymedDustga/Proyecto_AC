#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H

#include <systemc.h>

class ALU_CONTROL : public sc_module
{
public:
	sc_in_clk clk;
	sc_in<sc_uint<2>> Ex_ALUOpIn;           //Esta entrada viene desde el registro id_ex que a su vez viene de la unidad de control
	sc_in<sc_uint<4>> dir_In;				//Esta entrada recibira la instruccion que proviene desde el registro de encausamiento que a su vez viene de instruccion memory
	sc_out<sc_uint<4>> instruction_aluOut;  //Salida que se conecta con la ALU

	SC_CTOR(ALU_CONTROL);

private:
	void operation();
};

#endif
