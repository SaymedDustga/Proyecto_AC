#ifndef BRANCH_H
#define BRANCH_H

#include <systemc.h>


class Branch : public sc_module
{
public:
	sc_in_clk clk;
	sc_in<bool> jumpIn, addressIn; //entradas que vienen desde la ALU y desde la Unidad de Control
	sc_out<bool> answerOut;			//Salida que se dirige al multiplexcor de la fase de Instruction Fech

	SC_CTOR(Branch);

private:
	void operation();
};

#endif
