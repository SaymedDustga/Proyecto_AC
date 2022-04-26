#include "IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();														

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

void IF_ID::operation(){

	register1Out.write(5);
	register2Out.write(6);
	ID_EXOut.write(20);
	instruction1Out.write(30);
	instruction2Out.write(40);
	instruction3Out.write(50);

}

	
/*
void IF_ID::read(){

	bOut.write(dataSg[rbIn.read()]);
}

void IF_ID::write(){

	ID_EXOut.write(cpIn.read());
}*/