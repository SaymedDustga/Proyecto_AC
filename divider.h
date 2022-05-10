#ifndef DIVIDER_H
#define DIVIDER_H

#include <systemc.h>

class divider : public sc_module{
public:
	sc_in<sc_uint<4>> dir_In;//recibe la instruccione que previamente recivio la unidad de control
	
	/*Salidas de la sc_uint<4> de manera individual bit a bit*/
	sc_out<bool> dir_In_3;
	sc_out<bool> dir_In_0;
	sc_out<bool> dir_In_1;
	sc_out<bool> dir_In_2;

	SC_CTOR(divider);
	~divider();
private:
	void process();

};
#endif