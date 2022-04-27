#include "IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName), pcIn("pcIn"), insMemIn("insMemIn"), register1Out("register1Out"), ID_EXOut("ID_EXOut")
{

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();

  std:: cout << "\nIF_ID" << endl;
	/*	ID_EXOut.write(20);
		instruction1Out.write(30);
		instruction2Out.write(40);
		instruction3Out.wdlsajdlksajdlksajdlksajdalsjdalsjdlksajd;*/
	/*
		SC_METHOD(write);
			sensitive << clk.neg();

		SC_METHOD(read);
			sensitive << clk.pos();*/
}

void IF_ID::operation()
{


	// Para testeo:
	ID_EXOut.write(pcIn.read());
	register1Out.write(insMemIn.read());

	/*
		sc_int<8> p1, p2, p3, p4;

		for(int i = 0; i<8;i++){
			p1[i] = insMemIn.read()[i];
		}
		for(int i = 0, j = 7; i<8; i++,j++){
			p2[i] = insMemIn.read()[j];
		}
		for(int i = 0, j = 15; i<8; i++,j++){
			p3[i] = insMemIn.read()[j];
		}
		for(int i = 0, j = 23; i<8; i++,j++){
			p4[i] = insMemIn.read()[j];
		}

		register1Out.write(p2);
		register2Out.write(p3);
		ID_EXOut.write(cpIn.read());
		instruction1Out.write(p2);
		instruction2Out.write(insMemIn.read());
		instruction3Out.write(insMemIn.read());*/
}

/*
void IF_ID::read(){

	bOut.write(dataSg[rbIn.read()]);
}

void IF_ID::write(){

	ID_EXOut.write(cpIn.read());
}*/